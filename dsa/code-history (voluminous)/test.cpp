#include<bits/stdc++.h>
using namespace std;


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

int main(){
    Solution s;
    vector<int> v = {5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5};
    cout << s.lemonadeChange(v);
}