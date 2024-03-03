#include<bits/stdc++.h>
using namespace std;


class Solution {

public:

    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ansGrid(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ansGrid[i][j] += grid[i][j];
                if(i+1 < n)ansGrid[i+1][j] += grid[i][j];
                if(j+1 < m)ansGrid[i][j+1] += grid[i][j];
                if(i+1 < n && j+1 < m)ansGrid[i+1][j+1] += grid[i][j];
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(ansGrid[i][j] < k)ans++;
                else break;
            }
        }

        return ans;
    }
};