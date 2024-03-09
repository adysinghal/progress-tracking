#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i : nums){
            mp[i]++;
        }      
        int ans = 0;
        int maxFreq = 0;
        for(auto it : mp){
            if(it.second > maxFreq){
                maxFreq = it.second;
                ans = it.second;
            }
            else if(it.second == maxFreq){
                ans += it.second;
            }
        }
        return ans;
    }
};