#include <iostream>
#include <vector>
#include <set>
using namespace std;


// https://www.geeksforgeeks.org/problems/subset-sums2234/1
// subset sums

class Solution{

    void helper(vector<int> arr, int n, vector<int> &ans, int index, int sum){
        if(index == n){
            ans.push_back(sum);
            return;
        }

        // notTake
        helper(arr, n, ans, index+1, sum);

        // take
        helper(arr, n, ans, index+1, sum+arr[index]);

        return;

    }

public:
    vector<int> subsetSums(vector<int> arr, int n){
        vector<int> ans;
        helper(arr, n, ans, 0, 0);
        return ans;
    }
};




// https://leetcode.com/problems/subsets-ii/description/
// subset sum 2

// same like above, instead of sum, we will push and pop elements

class Solution {

    void helper(vector<int>& nums, int n, int index, set<vector<int>>& ans, vector<int>& temp){
        if(index == n){
            ans.insert(temp);
            return;
        }

        // notTake 
        helper(nums, n, index+1, ans, temp);

        // take
        temp.push_back(nums[index]);
        helper(nums, n, index+1, ans, temp);
        temp.pop_back();
        return;
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        set<vector<int>> ans;

        helper(nums, nums.size(), 0, ans, temp);
        
        vector<vector<int>> v(ans.begin(), ans.end());
        return v;
    }
};


class Solution {

    bool isPalindrome(string s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--])return false;
        }
        return true;
    }

    void helper(int index, string s, vector<string> &path, vector<vector<string>> &res){
        if(index == s.size()){
            res.push_back(path);
            return;
        }

        for(int i = index; i < s.size(); i++){
            if(isPalindrome(s, i, i - index + 1)){
                path.push_back(s.substr(index, i-index+1));
                helper(i+1, s, path, res);
                path.pop_back();
            }
        }
        return;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        helper(0, s, path, res);
        return res;
    }
};




// https://leetcode.com/problems/permutation-sequence/
// permuatation sequence

class Solution {
public:
    string getPermutation(int n, int k) {
        
    }
};