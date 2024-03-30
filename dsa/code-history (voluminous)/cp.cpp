#include<bits/stdc++.h>
using namespace std;

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


int main(){
    vector<int> v = {3,6,7,11};
    // Solution s;
    // cout << s.minEatingSpeed(v, 18) << "\n";
    // int sum = 0;
    cout << accumulate(v.begin(), v.begin() + 2, 1);
    // cout << sum << endl;
    return 0;
}


