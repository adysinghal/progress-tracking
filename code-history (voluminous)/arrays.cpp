#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;



// Q1 - JUSTIFY TEXT

// Given an array of strings words and a width maxWidth, format the text such that each line has exactly
//  maxWidth characters and is fully (left and right) justified.

// You should pack your words in a greedy approach; that is, pack as many words as you can in each line.
//  Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

// Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line 
// does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots
// on the right.

// For the last line of text, it should be left-justified, and no extra space is inserted between words.

// Note:

// A word is defined as a character sequence consisting of non-space characters only.
// Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
// The input array words contains at least one word.


// Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
// Output:
// [
//    "This   is    an",
//    "example  of text",
//    "justification.  "
// ]

// This is an 
// 4 + 3 + 3 = 10

// temp = "This   is   an"
// "This is an"


// wordCounter, lineLength, 



// 4 + 1 + 2 + 1 + 2  = 10 
// This    is    an
// example 


vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int n = words.size();
    int first = 0;
    int second = 0;
    int lineLength = 0;
    string temp = "";



    while(second < n){
        // find no of words to fit in a line
        if(first == second){
            lineLength += words[second].size();
            second++;
        }

        while(lineLength + words[second].size() + 1 <= maxWidth && lineLength < n){
            lineLength += words[second].size() + 1;
            second++;
        }

        int numWords = second - first + 1;

        // no of remianing spaces that are equally distributed + extra spces for left part
        int remaining = maxWidth - lineLength;
        int gaps = numWords - 1;

        int equalspaces = second<n?remaining/gaps:1;
        int leftspaces = second<n? remaining % gaps: 0;

        //form the temp string
        while(first < second-1){
            temp += words[first];
            if(leftspaces != 0){
                for(int i = 0; i < equalspaces + 1; i++){
                    temp += " ";
                }
            }else{
                for(int i = 0; i < equalspaces; i++){
                    temp += " ";
                }
            }
            first++;
        }
        temp += words[first];
        first++;

        //reset variable
        lineLength = 0;
    }
}




// Q2 - COUNT INVERSIONS

// https://www.codingninjas.com/studio/problems/count-inversions_615?topList=top-array-coding-interview-questions&problemListRedirection=true

// For a given integer array/list 'ARR' of size 'N' containing all distinct values, find the total number of 'Inversions' that may exist.

// An inversion is defined for a pair of integers in the array/list when the following two conditions are met.

// A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

// 1. 'ARR[i] > 'ARR[j]' 
// 2. 'i' < 'j'

// Where 'i' and 'j' denote the indices ranging from [0, 'N').


long long getInversions(long long *arr, int n){
    // brute force approach -> O(N^2) approach

    long long ans = 0;
    // visit every element
    for(int i = 0; i < n; i++){
        
        // check how many smaller elements lie ahead of it
        for(int j = i; j < n; j++){
            if(arr[i] > arr[j])ans++;
        }

    }

    return ans;

}

// 4 2 1 3
/*

stack

3
4

ans = 1 + 2 + 1
*/


long long getInversions(long long *arr, int n){
    // using a stack to keep track of smallest element encountered

    // add to stack (if possible)

    // check how many elements present below the element and add to 
    // ans (if stack not empty)


    // 4 2 1 3
    /*
    
    stack
    
    
    
    4

    ans = 4
    */

   


    stack<long long> st;
    long long ans = 0;

    for(long long i = 0; i < n; i++){
        
        if(st.empty()){
            st.push(arr[i]);
            continue;
        }

        while(!st.empty() && st.top() < arr[i]){
            st.pop();
        }
        
        ans += st.size();

        st.push(arr[i]);

    }

    return ans;
}
// this approach is not working, will troubleshoot later


// optimised approach from discussions -> merge sort




// approach 3

// merge sort approach -> do normal merge 
// sort but count inversions while two partitions are being merged

long long mergeFunc(long long *arr, long long *temp, int n, int left, int mid, int right){
    int i = left, j = mid+1, k = left;
    long long inversions = 0;

    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
            inversions += mid+1-i;
        }
    }

    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= right){
        temp[k++] = arr[j++];
    }
    
    for(int l = left; l <= right; l++){
        arr[l] = temp[l];
    }

    return inversions;
}

long long mergeSort(long long *arr, long long* temp, int n, int left, int right){
    long long inversions = 0;

    if(left < right){
        int mid = (left + right)/2;
        inversions += mergeSort(arr, temp, n, left, mid);
        inversions += mergeSort(arr, temp, n, mid+1, right);
        inversions += mergeFunc(arr, temp, n, left, mid, right);
    }

    return inversions;
}



long long getInversions(long long *arr, int n){
    long long *temp = new long long [n];
    return mergeSort(arr, temp, n, 0, n-1);

}



// https://leetcode.com/problems/sort-colors/description/

// 75. Sort Colors
// Solved
// Medium
// Topics
// Companies
// Hint
// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 1st O(N) approach -> count number of elements, then update according to frequency
        // not coding this approach, pretty obvious

        // 2nd approach 

    }
};

// coloring problem -> three colors -> three pointers

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int start = 0, mid = 0, end = n-1;

        while(start <= end && mid <= end){
            if(nums[mid] == 0){
                swap(nums[start], nums[mid]);
                start++, mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }else{
                swap(nums[mid], nums[end]);
                end--;
            }
        }
    }
};


// 2 sum problem
// https://leetcode.com/problems/two-sum/description/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // traverse and check if element has been added to the map yet

    }
};


// Majority element (>n/2 times)
// https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // moore voting algo

        // if element element is repeated, increase its score otherwise decrement it
        // keep a element element that is updated every time the score goes below 0

        int score = 0;
        int element = -1;

        for(int i = 0; i < nums.size(); i++){
            if(score <= 0){
                element = nums[i];
            }
            if(element == nums[i])score++;
            else score--;
        }
        return element;
    }
};


// max subarray
// https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        // keep adding elements to a variable called sum
        // keep track of variables being added by a left and right pointer
        // if (sum < 0, reset sum to 0, update left to right then start moving forward)

        int n = nums.size();
        int sum = 0, maxSum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
            maxSum = max(sum, maxSum);

            if(sum <= 0){
                sum = 0;
            }
        }
        return maxSum;        

    }
};


// rearrange array elements by sign
// https://leetcode.com/problems/rearrange-array-elements-by-sign/

// two pointer approach

// TC: O(N)
// SC: O(N)


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n, 0);
        int pos = 0, neg = 0;

        while(nums[pos] < 0 && pos < n)pos++;

        while(nums[neg] > 0 && neg < n)neg++;

        for(int i = 0; i < n; i++){

            // at even index, place positive number

            if(i%2 == 0){
                if(pos < n){
                    arr[i] = nums[pos++];
                    while(pos < n && nums[pos] < 0)pos++;
                }
            }
            // at odd index, place negative integer
            else{
                if(neg < n){
                    arr[i] = nums[neg++];
                    while(neg < n && nums[neg] > 0)neg++;
                }
            }
        }
        return arr;
    }
};


<<<<<<< HEAD
// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/
// Largest subarray with 0 sum

// recursion solution -> O(2^n) TC

class Solution{

    void helper(vector<int>&arr, int n, int &ans, vector<int>& temp, int sum, int index){
        if(index == n){
            return;
        }

        if(sum == 0){
            int x = temp.size();
            ans = max(ans, x);
        }

        // not take
        helper(arr, n, ans, temp, sum, index+1);

        // take 
        temp.push_back(arr[index]);
        helper(arr, n, ans, temp, sum+arr[index], index+1);
        temp.pop_back();

    }
    
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        int ans = -1;
        vector<int> temp;

        helper(arr, n, ans, temp, 0, 0);
        return ans;
    }
};

// TC O(N) solution
// if subarray (continuous elements)
// we caluclate cumulative sum at each index, if same sum is encountered, update value of ans

#include <unordered_map>

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        unordered_map<int,int> mp;
        int sum = 0, ans = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(sum == 0){
                ans = max(ans, i+1);
            }
            else if(mp.find(sum) != mp.end()){
                ans = max(ans, i-mp[sum]);
            }else{
                mp[sum] = i;
            }
        }
        return ans;
    }
};

// 
=======
// https://leetcode.com/problems/next-permutation/
// next permutation problem

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // brute force -> make all possible combinations -> chose next one from there
        // TC: (N! * N)
        // not doing this approach

        // Approach with break point
        int n = nums.size(), bp = -1;

        /*

        {2, 1 ,5,4, 3 ,0,0}
        {2, 3 ,0,0, 1 ,4,5}


        */
        
        // find the break point (bp) -> point from end where nums[i] < nums[i+1]
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                bp = i;
                break;
            }
        }

        // edge case that if it is the last sequence
        if(bp == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        // run loop to find the nge of bp
        for(int i = n-1; i >= 0; i--){
            // swap bp and nge
            if(nums[i] > nums[bp]){
                swap(nums[i], nums[bp]);
                break;
            }
        }

        // reverse all elements from bp + 1 to end

        reverse(nums.begin() + bp + 1, nums.end());
        return;
    }
};

# define vi vector<int>


// permutations
// https://leetcode.com/problems/permutations/

class Solution {

    void helper(vi& nums, vector<vi>& ans, vi& temp, vector<bool>& vis, int n){
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                vis[i] = true;
                temp.push_back(nums[i]);

                helper(nums, ans, temp, vis, n);

                vis[i] = false;
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vi> ans;
        vi temp;
        vector<bool> vis(n, false);

        helper(nums, ans, temp, vis, n);
    }
};


>>>>>>> 0ff172454043bf9c7ce8fd8ea60ecccc83dffd10
