#include<bits/stdc++.h>
using namespace std;


// https://leetcode.com/problems/next-greater-element-i/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // make nextGreaterArray for all elements in nums2
        int n = nums2.size();
        vector<int> nge(n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--){
            // remove smaller
            while(!st.empty() && nums2[i] > st.top())st.pop();
            
            // mark the smallest
            if(st.empty())nge[i] = -1;
            else nge[i] = st.top();

            // add top element 
            st.push(nums2[i]);
        }

        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < n; j++){
                if(nums1[i] == nums2[j]){
                    ans.push_back(nge[j]);
                    break;
                }
            }
        }
        return ans;
    }
};




// https://leetcode.com/problems/next-greater-element-ii/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;

        for(int i = (2*n)-1; i >= 0; i--){
            // remove smaller
            while(!st.empty() && nums[i%n] >= st.top())st.pop();
            
            // mark the smallest
            if(st.empty())nge[i%n] = -1;
            else nge[i%n] = st.top();

            // add top element 
            st.push(nums[i%n]);
        }

        return nge;
    }
};





// https://www.interviewbit.com/problems/nearest-smaller-element/
// vector<int> Solution::prevSmaller(vector<int> &arr) {
//     int n1 = arr.size();
//     if(n1 == 0){
//         return {};
//     }
    
//     vector<int> result(n1);
    
//     stack<int> st;
//     for(int i = 0; i < n1; i++){
//         // remove from the top
//         while(!st.empty() && arr[i] <= st.top())st.pop();
        
//         // fill the ans
//         (st.empty()) ? result[i] = -1 : result[i] = st.top();
        
//         st.push(arr[i]);
//     }
    
//     return result;
// }



// https://leetcode.com/problems/sliding-window-maximum/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1)return nums;
        
        deque<int> dq;
        int n = nums.size();
        vector<int> ans;



        for(int i = 0; i < n; i++){

            // ensure sliding window
            if(!dq.empty() && dq.front() == i-k){
                dq.pop_front();
            }

            // remove smaller elements
            while(!dq.empty() && nums[dq.back()] <= nums[i])dq.pop_back();

            dq.push_back(i);
            
            
            if(i >= k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};




// https://leetcode.com/problems/online-stock-span/description/
class StockSpanner {
    stack<pair<int,int>> st;

public:
    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1;

        while(!st.empty() && st.top().first <= price){
            span += st.top().second;
            st.pop();
        }

        pair<int,int> p;
        p.first = price;
        p.second = span;
        st.push(p);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */




// https://leetcode.com/problems/asteroid-collision/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        stack<int> st;

        for(int i = 0; i < arr.size(); i++){
            
            bool destroy = false;
            // positive value
            if(arr[i] > 0){
                st.push(arr[i]);
            }
            else{
                if(st.empty() || st.top() < 0){
                    st.push(arr[i]);
                    continue;
                }
                else{
                    while(!st.empty() && st.top() > 0){
                        if(abs(arr[i]) == st.top()){
                            destroy = true;
                            st.pop();
                            break;
                        }
                        else if(abs(arr[i]) > st.top()){
                            st.pop();
                        }else{
                            destroy = true;
                            break;
                        }
                    }
                    if(!destroy){
                        st.push(arr[i]);
                    }
                }
            }
        }

        vector<int> ans(st.size());
        // after processing all entries
        for(int i = st.size()-1; i>= 0; i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};  





// https://leetcode.com/problems/trapping-rain-water/
// O(N) space solution
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n), right(n);

        int lmax = 0;
        for(int i = 0; i < n; i++){
            if(height[i] > lmax){
                lmax = height[i];
            }
            left[i] = lmax;
        }

        
        int rmax = 0;
        for(int i = n-1; i >= 0; i--){
            if(height[i] > rmax){
                rmax = height[i];
            }
            right[i] = rmax;
        }

        int ans = 0;
        
        for(int i = 0; i < n; i++){
            int temp = min(left[i], right[i]) - height[i];
            ans += (temp < 0) ? 0 : temp;
        }

        return ans;
    }
};

// O(1) space solution
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int ans = 0;
        int leftMax = 0, rightMax = 0;

        while(left <= right){
            if(height[left] <= height[right]){
                if(height[left] > leftMax){
                    leftMax = height[left]; 
                }else{
                    ans += leftMax - height[left];
                }
                left++;
            }
            else{
                if(height[right] > rightMax){
                    rightMax = height[right];
                }else{
                    ans += rightMax - height[right];
                }
                right--;
            }
        }
        return ans;
    }
};