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

void helper(vector<vector<int>> &adj, int n, vector<int> &topo, vector<int>& vis ,stack<int> &s, int node){ 
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it])helper(adj, n, topo, vis, s, it);
    }

    s.push(node);
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

