// #include<bits/stdc++.h>
// #define ll long long 

// using namespace std;


// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t;

//     cin >> t;

//     while(t--){

//         int n, x, y;
//         cin >> n >> x >> y;

//         vector<int> arr(n);
//         for(int i = 0; i < n; i++){
//             cin >> arr[i];
//         }   
//         int ans = 0;

//         vector<int> sum;
//         vector<int> diff;

//         for(int i = 0; i < n; i++){
//             if(find(sum.begin(), sum.end(), arr[i]%x) != sum.end()){
//                 if(find(diff.begin(), diff.end() ,arr[i]%y) != diff.end()){
//                     ans++;
//                 }
//             }
//             sum.push_back(x-(arr[i]%x));
//             diff.push_back(arr[i]%y);
//         }


//         cout << "sum array: ";
//         for(int i = 0; i < n; i++){
//             cout << sum[i] << " ";
//         }
//         cout << endl;
//         cout << "diff array: ";
//         for(int i = 0; i < n; i++){
//             cout << diff[i] << " ";
//         }
//         cout << endl;


//         cout << ans << endl;

//     }
//     return 0;
// }


// #include<bits/stdc++.h>
// #define ll long long 

// using namespace std;

// #include <iostream>
// #include <unordered_set>

// struct PairHash {
//     template <typename T1, typename T2>
//     std::size_t operator()(const std::pair<T1, T2>& p) const {
//         auto hash1 = std::hash<T1>{}(p.first);
//         auto hash2 = std::hash<T2>{}(p.second);

//         // Combining the hash values for the two elements
//         return hash1 ^ hash2;
//     }
// };

// int  factorial(int n) {
//     if (n == 0 || n == 1) {
//         return 1;
//     } else {
//         return n * factorial(n - 1);
//     }
// }

// int main() {

//     int t;

//     cin >> t;

//     while(t--){

//         int n, x, y;
//         cin >> n >> x >> y;

//         vector<int> arr(n);
//         for(int i = 0; i < n; i++){
//             cin >> arr[i];
//         }   
//         int ans = 0;

//         std::unordered_set<std::pair<int, int>, PairHash> p;

        // for(int i = 0; i < n; i++){
        //     if(p.find({arr[i]%x, arr[i]%y}) != p.end())ans++;

        //     p.emplace(x-(arr[i]%x), arr[i]%y);
        // }

//         unordered_map<int,int> mp;
//         // to handle duplicate values
//         for(int i = 0; i < n; i++){
//             mp[arr[i]]++;
//         }

//         for(auto it:mp){
//             if(it.second == 1)continue;
//             if((it.first * 2) % x == 0){
//                 ans += ((it.second)*(it.second-1)/2);;
//             }
//         }


//         cout << ans << endl;
        
        
//     }
//     return 0;
// }


#include<bits/stdc++.h>
// #define ll long long 

// using namespace std;


// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t;

//     cin >> t;

//     while(t--){

//         int n, x, y;
//         cin >> n >> x >> y;

//         vector<int> arr(n);
//         for(int i = 0; i < n; i++){
//             cin >> arr[i];
//         }   
//         int ans = 0;

//         vector<int> sum;
//         vector<int> diff;

//         for(int i = 0; i < n; i++){
//             if(find(sum.begin(), sum.end(), arr[i]%x) != sum.end()){
//                 if(find(diff.begin(), diff.end() ,arr[i]%y) != diff.end()){
//                     ans++;
//                 }
//             }
//             sum.push_back(x-(arr[i]%x));
//             diff.push_back(arr[i]%y);
//         }


//         cout << "sum array: ";
//         for(int i = 0; i < n; i++){
//             cout << sum[i] << " ";
//         }
//         cout << endl;
//         cout << "diff array: ";
//         for(int i = 0; i < n; i++){
//             cout << diff[i] << " ";
//         }
//         cout << endl;


//         cout << ans << endl;

//     }
//     return 0;
// }

#include<bits/stdc++.h>
#define ll long long 

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;

    cin >> t;

    while(t--){

        int n, x, y;
        cin >> n >> x >> y;

        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }   
        int ans = 0;

        // unordered_map<int, pair<int,int>> mp;
        // unordered_map<unordered_map<int,int>, int> mp;

        // unordered_set<pair<int,int>> p;

        // {1, 0} {1, 0}
        // 5=x, 2=y
        // 4 6

        // for(int i = 0; i < n; i++){

        // }

        cout << ans << endl;

    }
    return 0;
}


/*

6 5 2
1 9, 4 6

20 10
{5,0}


<pair<int,int>, int>

compare
{{arr[i]%x, arr[i]%}, freq}
{4,1}

add
{{(x-(arr[i]%x))%x, arr[i]%y}, freq}


mp
{{4,1}, 1}

ans = 1

*/