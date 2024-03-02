#include<bits/stdc++.h>
using namespace std;

bool detectCycleDFShelper(vector<vector<int>> &adj, int n, vector<int>& vis, vector<int>& pathVis, int node){
    vis[node] = 1;
    pathVis[node] = 1;

    for(auto it : adj[node]){
        if(vis[it] && pathVis[it])return false;
        if(!vis[it]){
            if(!detectCycleDFShelper(adj, n, vis, pathVis, it))return false;
        }
    }
    pathVis[node] = 0;
    return true;
}

bool detectCycleDFS(vector<vector<int>> &adj, int n){
    
}


// false -> cycle detected
// true -> no cycle

int main(){
    vector<vector<int>> adj1 = {{1},{2},{0}};
    vector<vector<int>> adj2 = {{1,2},{2},{}};

    cout << detectCycleDFS(adj1, 3, )
}