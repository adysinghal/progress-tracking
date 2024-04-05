#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int source) {
        
        vector<vector<pi>> adj(n+1);
        for(auto it : times){
            adj[it[0]].push_back({it[2], it[1]});      // {dist, node}
        }

        priority_queue<pi, vector<pi>, greater<pi>> pq;     // {dist, node}
        pq.push({0, source});
        vector<int> distance(n+1, INT_MAX);
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
        return *max_element(distance.begin()+1, distance.end());
        
    }
};

int main(){
    vector<vector<int>> v = {{2,1,1},{2,3,1},{3,4,1}};
    Solution s;
    cout << s.networkDelayTime(v, 4, 2);
    return 0;
}

