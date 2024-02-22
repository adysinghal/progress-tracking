#include<bits/stdc++.h>
using namespace std;


// https://leetcode.com/problems/assign-cookies/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0, ans = 0;
        while(i < g.size() && j < s.size()){
            if(s[j] >= g[i]){
                ans++, i++, j++;
            }else{
                j++;
            }
        }
        return ans;


    }
};



// https://leetcode.com/problems/lemonade-change/description/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int bills5 = 0, bills10 = 0;

        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5)bills5++;
            
            else if(bills[i] == 10){
                if(bills5 == 0){
                    cout << i << "th iteration\n";
                    return false;
                    }
                else{
                    bills5--;
                    bills10++;
                }
            }

            else{
                if(bills10 > 0 && bills5 > 0){
                    bills10--, bills5--;
                }
                else if(bills10 == 0 && bills5 >= 3){
                    bills5 -= 3;
                }
                else{
                    cout << i << "th iteration\n";
                    return false;
                }
            }
        }
        return true;
    }
};



// https://leetcode.com/problems/valid-parenthesis-string/

class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0, maxOpen = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                minOpen++, maxOpen++;
            }else if(s[i] == '*'){
                minOpen--, maxOpen++;
            }else{
                minOpen--, maxOpen--;
            }
            minOpen = max(minOpen, 0);
            if(maxOpen < 0)return false;
        }
        if(minOpen > 0)return false;
        return true;
    }
};

