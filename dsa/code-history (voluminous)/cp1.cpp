#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
#define ll long long 


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;

    cin >> t;

    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n), b(m);

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < m; i++){
            cin >> b[i];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int numCheck = 1, countA = 0, countB = 0;
        int i = 0, j = 0;
        int common = 0;
        
        bool flag = true;
        
        while((i < n || j < m) && numCheck <= k){
            if(i < n && j < m && a[i] == numCheck && b[j] == numCheck){
                common++;
                while(a[i] == numCheck)i++;
                while(b[j] == numCheck)j++;
            }
            else if(i < n && a[i] == numCheck){
                countA++;
                while(a[i] == numCheck)i++;
            }
            else if(j < m && b[j] == numCheck){
                countB++;
                while(b[j] == numCheck)j++;
            }
            else{
                break;
            }
            numCheck++;
        }
        
        if(numCheck != k+1)flag = false;

        if(countA > k/2 || countB > k/2)flag = false;

        if(common > k - countA - countB)flag = false;
        
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        
    }



    return 0;
}

