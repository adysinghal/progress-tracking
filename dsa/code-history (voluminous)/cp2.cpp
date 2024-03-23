#include<bits/stdc++.h>
#define ll long long 

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;

    cin >> t;

    while(t--){
        ll n, k;
        cin >> n >> k;
        vector<ll> arr(n);
        ll totalSum = 0;
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
            totalSum += arr[i];
        }

        ll startIndex = -1;
        ll sum = 0;
        bool positive = false;
        ll maxSum = -1e9;
        int MOD = 1000000007;

        for(ll i = 0; i < n; i++){
            sum += arr[i];
            // sum %= MOD;
            // sum %= (1000000007);
            maxSum = max(maxSum, sum);
            if(sum < 0)sum = 0;
        }

        // totalSum %= MOD;
        // maxSum %= MOD;

        if(maxSum < 0){
            cout << MOD + (totalSum%MOD) << "\n";
        }
        else if (maxSum == 0){
            cout << "0" << "\n";

        }else if(maxSum > 0){
            ll temp = 0;
            int powerof2 = 1;
            for(int i = 0; i < k; i++){
                temp += (maxSum * (powerof2%MOD))%MOD;
            }
            temp += (totalSum);
            cout << totalSum << endl;
            cout << maxSum << endl;
            // cout << totalSum << endl;

            cout << temp << "\n";
        }

    }
    return 0;
}