#include<bits/stdc++.h>
using namespace std;

int countOddSetBits(int num) {
    // int count = 0;
    // int position = 0;

    if(num < 3)return 1;
    if((num & 0b11) == 0)return -1;
    // if(num == 5)return 2;

    // Iterate through binary digits
    // while (num > 0) {
    //     // Check if the corresponding position is odd
    //     if ((position % 2 == 0) && (num & 1)) {
    //         count++;
    //     }

    //     // Move to the next binary digit
    //     num >>= 1;
    //     position++;
    // }
        int ans = 0;
        int position = 0;

    while (num > 0) {
        if (position >= 2) {
            // Check if the corresponding position is odd or even
            if ((position % 2 == 0) && (num & 1)) {
                // Set bit at an odd position, add 1 to the ans
                ans += 1;
            } else if ((position % 2 != 0) && (num & 1)) {
                // Set bit at an even position, add 2 to the ans
                ans += 2;
            }
        }

        // Move to the next binary digit
        num >>= 1;
        position++;
    }


    return ans;
}


vector<int> getMinimumKValues(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n);
    
    for(int i = 0; i < n; i++){
        ans[i] = countOddSetBits(arr[i]);
    }

    return ans;
    
}

    

int main(){
    vector<int> arr = {5,1,4,6,10};
    vector<int> ans = getMinimumKValues(arr);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}