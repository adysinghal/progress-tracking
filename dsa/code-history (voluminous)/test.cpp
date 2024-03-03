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

        priority_queue<int> pq;
        for(int i = 0; i < 2*n ; i++){
            int x;
            cin >> x;
            pq.push(x);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            pq.pop();
            ans += pq.top();
            pq.pop();
        }

        cout << ans << endl;


    }
    return 0;
}

