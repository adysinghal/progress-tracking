#include<bits/stdc++.h>
#define ll long long 

using namespace std;

bool check(ll start, ll end, vector<ll> &arr){
    unordered_map<ll,ll> freq;
    
    int threshold = (end-start+1)/2;
    
    for(ll i = start; i <= end; i++){
        freq[arr[i]]++;
        if(freq[arr[i]] > threshold)return false;
    }
    
    return true;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;

    cin >> t;

    while(t--){
        
        ll n, q;
        cin >> n >> q;
        vector<ll> arr(n);

        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }

        vector<pair<ll,ll>> query(q);

        for(ll i = 0; i < q; i++){
            cin >> query[i].first;
            cin >> query[i].second;
        }


        for(ll i = 0; i < q; i++){
            bool ans = check((query[i].first) - 1, (query[i].second) - 1, arr);

            cout << ((ans) ? "YES" : "NO") << endl;
        }

    }
    return 0;
}
