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

void helper(vector<vector<int>>& adj, vector<int>& vis, vector<int>& dfs, int vertex){
    if(vis[vertex] == 1)return;

    dfs.push_back(vertex);
    for(auto it : adj[vertex]){
        vis[it] = 1;
        helper(adj, vis, dfs, it);
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
    ans.push_back({0});

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            ans[0][0]++;
            vector<int> dfs;
            helper(adj, vis, dfs, i);
            ans.push_back(dfs);
        }
    }

    return ans;
}
