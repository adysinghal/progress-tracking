
bool helper(vector<vector<int>>& adj, vector<int>& vis, int parent, int node){

    vis[node] = 1;

    for(auto it : adj[node]){
        if(!vis[it] && helper(adj, vis, node, it))return true;
        if(vis[it] == 1 && it != parent)return true;
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
    vis[0] = 1;
    bool flag = false;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            if(helper(adj, vis, -1, i)){
                flag = true;
                break;
            }
        }
    }
    
    return (flag ? "Yes" : "No");
}

What is the error in this code, if an