#include<bits/stdc++.h>
#define ll long long 

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;

    cin >> t;

    while(t--){
        int x, n;
        cin >> x >> n;

        int ans = 0;
        if(x % n == 0){
            ans = x/n;
        }else{
            for(int i = x/n; i >= 1; i--){
                if(x % i == 0){
                    ans = x/i;
                    break;
                }
            }
        }

        cout << ans << endl;

    }
    return 0;
}
