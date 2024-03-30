#include<bits/stdc++.h>
using namespace std;

// intuition : split array into contiguous segments such that max(min) or min(max)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target)return mid;
            
            /*
            IN CASE THE ARRAY MAY HAVE DUPLICATES, ADDING THIS CONDITION IS ABSOLUTELY NECESSARY
            */
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
            }
            
            // left sorted
            else if(nums[low] <= nums[mid]){
                if(target <= nums[mid] && target >= nums[low])high = mid-1;
                else low = mid + 1;
            }
            else{
                if(target >= nums[mid] && target <= nums[high])low = mid + 1;
                else high = mid - 1;
            }
        }
        return -1;
    }
};
/*
target = 3
nums =
[3,1]

low     = 0
mid     = 0
high    = 1
*/


// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int low = 0, high = n-1;
        
        while(low <= high){
            int mid = (low + high)/2;

            // left sorted
            if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]);
                low = mid + 1;
            }else{
                ans = min(ans, nums[mid]);
                high = low + 1;
            }
        }
    }
};



// https://leetcode.com/problems/koko-eating-bananas/
class Solution {

    bool possible(vector<int>& piles, int h, int k){
        int sum = 0;
        for(auto i : piles){
            sum += (int)ceil((double)i/(double)k);
        }
        if(sum <= h)return true;
        return false;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // int n = piles.size();
        if(piles.size() == 1)return ceil((double)piles[0]/(double)h);
        int low = 1, high = *max_element(piles.begin(), piles.end());

        while(low <= high){
            int mid = (low+high)/2;

            if(possible(piles, h, mid)){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};

// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

#define ll long long
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        ll low = 1;
        ll high = *max_element(nums.begin(), nums.end());

        while(low <= high){
            ll mid = (low+high)/2;

            ll sum = 0;
            for(int i = 0; i < n; i++){
                sum += ceil((double)nums[i]/double(mid));
            }

            if(sum <= threshold){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};



// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end()), high = accumulate(weights.begin(), weights.end(), 0);
        while(low <= high){
            int mid = (low+high)/2;
            ll d = 1;
            ll w = 0;
            for(int i = 0; i < weights.size(); i++){
                if(w + weights[i] <= mid){
                    w += weights[i];
                }else{
                    w = weights[i];
                    d++;
                }
            }

            if(d <= days){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};



// https://leetcode.com/problems/kth-missing-positive-number/
class Solution {
public:
// O(n) solution
    int findKthPositive(vector<int>& arr, int k) {
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] <= k)k++;
            else break;
        }
        return k;
    }
};



class Solution {
public:
    // BS solution
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n-1;

        while(low <= high){
            int mid = (low + high)/2;
            
            int missing = arr[mid] - (mid + 1);

            if(missing < k){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return arr[high] + k - (arr[high] - (high + 1));
        // return arr[high] + more;
    }
};



class Ninja_cow{

public:
    bool possible(vector<int> &arr, int cows, int step){
        int num = 1;
        int last = arr[0];
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - last > step){
                last = arr[i];
                num++;
            }
            if(num >= cows)break;
        }
        return (num >= cows);
    }

    int aggressiveCows(vector<int> &arr, int cows){
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int low = 1, high = arr[n-1] - arr[0];
        int ans = -1;
        while(low <= high){
            int mid = (low + high)/2;
            
            if(possible(arr, cows, mid)){
                ans = low;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};


class Ninja_books{

    bool possible(vector<int>& arr, int n, int numStudents, int maxPages){
        int students = 1;
        long long pages = 0;
        for(int i = 0; i < n; i++){
            if(pages + arr[i] <= maxPages){
                pages += arr[i];
            }else{
                students++;
                pages = arr[i];
            }
            if(students < numStudents)return false;
        }
        return true;
    }

    int findPages(vector<int>& arr, int n, int numStudents) {
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        while(low <= high){
            int mid = (low+high)/2;

            if(possible(arr, n, numStudents, mid)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }

};

// https://leetcode.com/problems/split-array-largest-sum/
class Solution {

    bool possible(vector<int>& nums, int k, int sum){
        int splits = 1;
        int tempSum = 0;

        for(int i = 0; i < nums.size(); i++){
            if(tempSum + nums[i] <= sum){
                tempSum += nums[i];
            }
            else{
                splits++;
                tempSum = nums[i];
            }

            if(splits > k)return false;
        }
        return true;
    }


public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high){
            int mid = (low+high)/2;
            
            if(possible(nums, k, mid)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};

