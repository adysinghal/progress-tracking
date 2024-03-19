#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        sort(points.begin(), points.end());

        int i = 0;
        while(i < n){
            int temp = i+1;
            int end = points[i][1];
            while(temp < n && end >= points[temp][0]){
                end = min(end, points[temp][1]);
                temp++;
            }
            
            i = temp;
            ans++;
        }

        return ans;
    }
};

int main(){
    vector<vector<int>> v = {{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}};

    Solution s;
    // cout << s.findMinArrowShots(v);
}