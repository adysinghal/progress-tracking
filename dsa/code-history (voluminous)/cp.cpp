#include<bits/stdc++.h>
#define ll long long 

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;

    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> ps(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(i == 0)ps[i] = arr[i];
            else (ps[i] = ps[i-1] + arr[i]);
        }

        int q;
        cin >> q;

        vector<pair<int,int>> query(q);
        for(int i = 0; i < q; i++){
            cin >> query[i].first;
            cin >> query[i].second;
        }

        for(int temp = 0; temp < q; temp++){
            int l = query[temp].first;
            l--;
            // cout << l << " ";
            int u = query[temp].second;
            
            int ansIndex = l;
            int sum = 0;
            int ans = u;
            for(int i = l; i < n;i++){
                sum = ps[i] - ps[l];
                if(abs(u - sum) <= ans){
                    ans = abs(u - sum);
                    ansIndex = i;
                }else break;
            }
            
            cout << ansIndex + 1 << endl;
        }

        cout << endl;

    }
    return 0;
}
