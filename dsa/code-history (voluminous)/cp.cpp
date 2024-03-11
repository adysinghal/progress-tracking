#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        // keep smaller in nums1
        if(nums1.size() > nums2.size()){
            swap(nums1, nums2);
        }

        unordered_set<int> st;
        for(int i = 0; i < nums1.size(); i++){
            st.insert(nums1[i]);
        }

        vector<int> ans;
        for(auto i : nums2){
            if(st.find(i) != st.end()){
                ans.push_back(i);
                st.erase(i);
            }
        }

        return ans;
    }
};