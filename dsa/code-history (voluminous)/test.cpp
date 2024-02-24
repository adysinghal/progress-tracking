#include<bits/stdc++.h>
#define ll long long 

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;

    cin >> t;

    while(t--){
        
        ll n, q;
        cin >> n >> q;

        // 1-index based arrays
        vector<ll> preSum(1, 0);
        vector<int> count1(1, 0);
        
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            
            preSum.push_back(preSum.back() + temp);
            count1.push_back(count1.back() + (temp == 1));
        }

        while(q--){
            int l, r;
            cin >> l >> r;
            l--;

            int c1 = count1[r] - count1[l];
            int sum = preSum[r] - preSum[l];

            cout << ((r-l > 1 && sum - (r-l) - c1 >= 0) ? "YES" : "NO") << endl;
        }

    }
    return 0;
}
