#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        int prefix = 1, postfix = 1;

        vector<int> result(n, 1);
        for(int i = 0; i < n; i++){
            result[i] *= prefix;
            prefix *= nums[i];
        }

        for(int i = n-1 ; i >= 0; i--){
            result[i] *= postfix;
            postfix *= nums[i];
        }

        return result;
    }
};