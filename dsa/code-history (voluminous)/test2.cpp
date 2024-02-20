#include <iostream>
#include <vector>
#include <string>
using namespace std;

int getMinimumMoves(string word){
    vector<int> hsh(26,0);
    for(int i = 0; i < word.size(); i++){
        hsh[word[i]-'a']++;
    }
    int ans = 0;
    for(int i = 0; i < 26; i++){
        ans += hsh[i]/2;
    }
    return ans;
}


int main(){
    cout << getMinimumMoves("aditya") << endl;
}