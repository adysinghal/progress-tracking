#include<bits/stdc++.h>
using namespace std;


// https://www.codingninjas.com/studio/problems/bfs-in-graph_973002?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> bfs;
    queue<int> q;

    q.push(0);
    while(!q.empty()){
        int element = q.front();
        q.pop();
    
        bfs.push_back(element);
        for(auto it : adj[element]){
            q.push(it);
        }
    }
    return bfs;
}



// https://www.codingninjas.com/studio/problems/dfs-traversal_630462?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

void helper2(vector<vector<int>>& adj, vector<int>& vis, vector<int>& dfs, int vertex){
    if(vis[vertex] == 1)return;

    vis[vertex] = 1;

    dfs.push_back(vertex);
    for(auto it : adj[vertex]){
        vis[it] = 1;
        helper2(adj, vis, dfs, it);
    }
}

vector<vector<int>> depthFirstSearch(int n, int E, vector<vector<int>> &edges)
{

    // making the adjacency matrix
    vector<vector<int>> adj(n);
    for(auto it : edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> vis(n, 0);
    vector<vector<int>> ans;
    ans[0].push_back(0);

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            ans[0][0]++;
            vector<int> dfs;
            helper2(adj, vis, dfs, i);
            ans.push_back(dfs);
        }
    }

    return ans;
}




// https://leetcode.com/problems/number-of-provinces/

class Solution {

    void dfs(vector<vector<int>>& isConnected, vector<int>& vis, int n, int vertex){
        if(vis[vertex] == 1)return;

        vis[vertex] = 1;

        for(int i = 0; i < n; i++){
            if(i == vertex)continue;
            if(isConnected[vertex][i] && !vis[i]){
                dfs(isConnected, vis, n, i);
            }
        }
        return;
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> vis(n, 0);

        queue<int> q;
        int num = 1;
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                num++;
                dfs(isConnected, vis, n, i);
            }
        }
        return num;
    }
};




// https://leetcode.com/problems/rotting-oranges/

// keep one thing in mind -> all intially rotten oranges are at level 0 and all other oranges are calculated from there
class Solution {

    void rot(vector<vector<int>>& grid, int n, int m, queue<pair<int,int>> &q, vector<int>& delrow, vector<int>& delcol, int& ans){
        int time = 0;

        while(!q.empty()){
            time++;
            ans = max(ans, time-1);
            int sz = q.size();

            for(int i = 0; i < sz; i++){
                int tempRow = q.front().first;
                int tempCol = q.front().second;
                q.pop();

                for(int i = 0; i < 4; i++){
                    int nrow = tempRow + delrow[i];
                    int ncol = tempCol + delcol[i];
                    
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1){
                        q.push({nrow, ncol});
                        grid[nrow][ncol] = 2;
                    }
                }

            }

        }
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;

        vector<int> delrow = {0,1,0,-1};
        vector<int> delcol = {1,0,-1,0};

        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }

        rot(grid, n, m, q, delrow, delcol, ans);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1)return -1;
            }
        }

        return ans;
    }
};





// https://leetcode.com/problems/flood-fill/

// dfs approach

class Solution {

    void helper(int n, int m, int row, int col, vector<vector<int>>& image, vector<vector<bool>>& vis, int color, int original, vector<int>& delrow, vector<int>& delcol){
        if(vis[row][col] == 1)return;

        vis[row][col] = 1;
        image[row][col] = color;
        
        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && image[nrow][ncol] == original){
                helper(n, m, nrow, ncol, image, vis, color, original, delrow, delcol);
            }
        }

    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans(image);
        int n = image.size(), m = image[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<int> delrow = {0,1,0,-1};
        vector<int> delcol = {1,0,-1,0};

        helper(n, m, sr, sc, ans, vis, color, image[sr][sc], delrow, delcol);

        return ans;
    }
};



// https://leetcode.com/problems/01-matrix/
// for such problems, don't apply bfs indiviudally, always push all actionable nodes into a queue and then start to apply bfs on that queue

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));      
        vector<vector<int>> dist(n, vector<int>(m, 0));      
    
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    vis[i][j] = 1;
                    q.push({{i,j}, 0});
                }
            }
        }

        vector<int> delrow = {0,1,0,-1};
        vector<int> delcol = {1,0,-1, 0};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            dist[row][col] = steps;

            for(int i = 0; i < 4; i++){
                int nrow = row + delrow[i]; 
                int ncol = col + delcol[i];

                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;   
                    q.push({{nrow,ncol}, steps+1});
                }
            }
        }

        return dist;
    }

};





// https://leetcode.com/problems/word-ladder/

// brute force -> check all words (how is this a graph question?)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
    }
};



// https://leetcode.com/problems/is-graph-bipartite/

class Solution {

    bool dfs(vector<vector<int>>& graph, vector<int>& color, int vertex, int c){
        if(color[vertex] == !c)return false;
        if(color[vertex] == c)return true;

        color[vertex] = c;

        for(auto it : graph[vertex]){
            if(!dfs(graph, color, it, !c))return false;
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(!dfs(graph, color, i, 0))return false;
            }
        }

        return true;
    }
};




// https://www.codingninjas.com/studio/problems/cycle-detection-in-undirected-graph_1062670

bool helper1(vector<vector<int>>& adj, vector<int>& vis, int parent, int node){

    vis[node] = 1;

    for(int it = 0; it < adj[node].size(); it++){
        if(!vis[it]){
            if(helper1(adj, vis, node, it))
                return true;
        } else if(vis[it] == 1 && it != parent) {
            return true;
        }
    }
    return false; 
}

string cycleDetection (vector<vector<int>>& edges, int n, int m){
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> vis(n+1, 0);
    // vis[0] = 1;
    bool flag = false;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            if(helper1(adj, vis, -1, i)){
                flag = true;
                break;
            }
        }
    }
    
    return (flag ? "Yes" : "No");
}




// https://leetcode.com/problems/course-schedule-ii/description/

class Solution {

    void helper(int n, vector<vector<int>>& adj, vector<int> &vis, int node, vector<int> &ans){
        for(auto it:adj[node]){

        }
    }

public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<int> vis(n, 0);
        vector<int> ans;

        for(int i = 0; i < n; i++){
            // if(!vis[i])
        }


    }
};



// https://www.codingninjas.com/studio/problems/topological-sorting_973003?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

void helper(vector<vector<int>> &adj, int n, vector<int> &topo, vector<int>& vis ,stack<int> &st, int node){ 
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it])helper(adj, n, topo, vis, st, it);
    }

    st.push(node);
    return;
}

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int n) {
    vector<int> topo;
    stack<int> st;
    vector<int> vis(n, 0);

    vector<vector<int>> adj(n);
    for(int i = 0; i < edges; i++){
        adj[graph[i][0]].push_back(graph[i][1]);
    }

    for(int i = 0; i < n; i++){
        if(!vis[i])helper(adj, n, topo, vis, st, i);
    }

    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }

    return topo;

}


// MARCH
class ninjas{

public:
    void dfs(vector<int> &vis, vector<vector<int>> &adj , int node, int n, stack<int> &st){
        vis[node] = true;
        for(auto it : adj[node]){   
            if(!vis[it]){
                dfs(vis, adj, it, n, st);
            }
        }

        st.push(node);
    }


    // dfs approach
    vector<int> topologicalSort(vector<vector<int>> &graph, int e, int n) {
        vector<int> vis(n, 0);
        stack<int> st;
        vector<vector<int>> adj(n);
        for(auto it : graph){
            adj[it[0]].push_back(it[1]);
        }

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(vis, adj, i, n, st);
            }
        }

        vector<int> ans;
        int sz = st.size();
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};

class ninjas{

public:
    // BFS approach
    vector<int> topologicalSort(vector<vector<int>> &edges, int e, int n) {
        vector<int> in(n, 0);
        vector<int> ans;
        queue<int> q;
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }

        for(auto it : edges){
            in[it[1]]++;
        }

        for(auto it : in){
            if(it == 0){
                q.push(it);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : adj[node]){
                in[it]--;
                if(in[it] == 0)q.push(it);
            }
            
            ans.push_back(node);
        }

        return ans;

    }
};


// https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
    }
};

class Ninja{
    // https://www.codingninjas.com/codestudio/problems/single-source-shortest-path_8416371?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
    vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {
        vector<vector<int>> adj(n);
        vector<int> dist(n, INT_MAX);

        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        queue<pair<int,int>> q;       // {node, dist}
        q.push({src, 0});
        dist[src] = 0;

        while(!q.empty()){
            int node = q.front().first;
            int depth = q.front().second;
            q.pop();

            for(auto i : adj[node]){
                if(depth + 1 < dist[i]){
                    q.push({i,depth+1});
                    dist[i] = depth + 1;
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }

        return dist;

    }



    // https://www.codingninjas.com/studio/problems/shortest-path-in-dag_8381897?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
    // advisable to use topo sort as it guarantees the presence of DAG
    vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges){
        vector<vector<pair<int,int>>> adj(n);

        for(auto i : edges){
            adj[i[0]].push_back({i[1], i[2]});
        }

        vector<int> dist(n, 1e9);

        int src = 0;
        queue<int> q;
        q.push(src);
        dist[src] = 0;

        while(!q.empty()){
            int node = q.front();
            int depth = dist[node];
            q.pop();

            for(auto i : adj[node]){
                if(depth + i.second < dist[i.first]){
                    dist[i.first] = depth + i.second;
                    q.push(i.first);
                }
            }
        }

        for(auto &i : dist){
            if(i == 1e9)
                i = -1;
        }

        return dist;
    }

    // vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges){
    //     vector<vector<pair<int,int>>> adj(n);

    //     for(auto i : edges){
    //         adj[i[0]].push_back({i[1], i[2]});
    //     }

    //     vector<int> dist(n, 1e9);

    //     int src = 0;
    //     queue<pair<int,int>> q;
    //     q.push({src,0});
    //     dist[src] = 0;

    //     while(!q.empty()){
    //         int node = q.front().first;
    //         int depth = q.front().second;
    //         q.pop();

    //         for(auto i : adj[node]){
    //             if(depth + i.second < dist[i.first]){
    //                 dist[i.first] = depth + i.second;
    //                 q.push({i.first, dist[i.first]});
    //             }
    //         }
    //     }

    //     for(auto &i : dist){
    //         if(i == 1e9)
    //             i = -1;
    //     }

    //     return dist;
    // }


};

// DIJKSTRA'S ALGORITHM
// Why not use topo sort method? 
// cannot handle cycles

// https://www.codingninjas.com/studio/problems/dijkstra's-shortest-path_985358?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

class Dijkstra_ninjas{
    // using pq
    vector<int> dijkstra(vector<vector<int>> &edge, int n, int edges, int source){
        vector<int> distance(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<vector<pair<int,int>>> adj(n);

        distance[source] = 0;
        pq.push({0, source});

        for(auto it : edge) {
            adj[it[0]].push_back({it[2], it[1]}); // {dist, node}
        }

        while(!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]) {
                if(dist + it.first < distance[it.second]) {
                    distance[it.second] = dist + it.first;
                    pq.push({distance[it.second], it.second});
                }
            }
        }

        return distance;
    }

    vector<int> dijkstra(vector<vector<int>> &edge, int n, int edges, int source){
        set<pair<int,int>> st;
        vector<int> distance(n, INT_MAX);
        distance[source] = 0;
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : edge){
            adj[it[0]].push_back({it[2], it[1]});
            adj[it[1]].push_back({it[2], it[0]});
        }

        st.insert({0, source});

        while(!st.empty()){
            auto i = *(st.begin());
            int node = i.second;
            int dist = i.first;
            st.erase(i);

            for(auto it : adj[node]){
                if(dist + it.first < distance[it.second]){
                    distance[it.second] = dist + it.first;
                    st.insert({distance[it.second], it.second});
                }
            }
        }

        return distance;
    }
};




// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
class Solution {
public:


    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n); // outgoing edges
        vector<vector<int>> in(n);  // incoming edges
        vector<int> vis(n, 0);
        int ans = 0;
        queue<int> q;
        q.push(0);
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            in[it[1]].push_back(it[0]);
        }


        while(!q.empty()){
            int node = q.front();
            vis[node] = 1;
            q.pop();

            for(auto it:adj[node]){
                if(!vis[it]){
                    q.push(it);
                    ans++;
                }
            }
            for(auto it : in[node]){
                if(!vis[it]){
                    q.push(it);
                }
            }
        }
        return ans;
    }


};



// https://leetcode.com/problems/shortest-path-in-binary-matrix/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)return -1;
        if(n == 1)return 1;
        // vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,pair<int,int>>> q;   // {dist,{row,col}}
        q.push({1,{0,0}});
        

        while(!q.empty()){
            int dist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    if(i == 0 && j == 0)continue;
                    int nrow = row + i, ncol = col + j;
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol] == 0){
                        if(nrow == n-1 && ncol == n-1)return dist+1;
                        grid[nrow][ncol] = -1;
                        q.push({dist+1, {nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};




// https://leetcode.com/problems/path-with-minimum-effort/
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> q;
        q.push({0, {0,0}});
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        vector<int> delrow = {0,-1,0,1};
        vector<int> delcol = {1,0,-1,0};

        int ans = INT_MAX;

        while(!q.empty()){
            int dist = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();

            if(vis[row][col])continue;

            if(row == n-1 && col == m-1){
                ans = min(ans, dist);
                break;
            }

            vis[row][col] = 1;

            for(int i = 0; i < 4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m) {
                    int new_dist = max(dist, abs(heights[row][col] - heights[nrow][ncol]));
                    q.push({new_dist, {nrow, ncol}});
                }

            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};



// https://leetcode.com/problems/cheapest-flights-within-k-stops/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<vector<int>> pq;     // vector = {cost, city, no. of stops}
        pq.push({0, src, 0});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // int ans = INT_MAX;
        vector<vector<pair<int, int>>> adj(n);

        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});   // {destination city, price}
        }

        while(!pq.empty()){
            vector<int> temp = pq.front();
            pq.pop();

            int cost = temp[0];
            int city = temp[1];
            int stops = temp[2];
            if(stops > k)continue;
            // cout << "cost: " << cost << "city: " << city << "stops: " << stops << "\n";


            for(auto it : adj[city]){
                // if(it.first == dst)ans = min(ans, cost + it.second);

                if(cost + it.second < dist[it.first]){
                    dist[it.first] = cost + it.second;
                    pq.push({dist[it.first], it.first, stops+1});
                }
            }
        }

        return dist[dst]==INT_MAX ? -1 : dist[dst];
    }
};


#define pi pair<int,int>

// https://leetcode.com/problems/network-delay-time/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int source) {
        
        vector<vector<pi>> adj(n);
        for(auto it : times){
            adj[it[0]].push_back({it[2], it[1]});      // {dist, node}
        }

        priority_queue<pi, vector<pi>, greater<pi>> pq;     // {dist, node}
        vector<int> distance(n, INT_MAX);
        pq.push({0, source});
        distance[source] = 0;

        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){
                if(dist + it.first < distance[it.second]){
                    distance[it.second] = dist + it.first;
                    pq.push({distance[it.second], it.second});
                }
            }
        }

        return *max(distance.begin(), distance.end());
        
    }
};