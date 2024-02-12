#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

pair<string,string> divide(string s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ':'){
            string first = s.substr(0, i-1);
            string second = s.substr(i+1, s.size()-1);
            return {first, second};
        }
    }
    return {};
}

vector<string> computeParameterValue(vector<vector<string> > sources){
    unordered_map<string, string> mp;
    
    // number of streams
    int n = sources.size();
    
    // number of entries
    int m = sources[0].size();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            pair<string,string> p = divide(sources[i][j]);
            
            mp[p.first] = p.second;
        }
    }
    vector<string> ans;
    for(auto it : mp){
        ans.push_back(it.second);
    }
    return ans;
}

int main(){
    vector<vector<string> > test;

    test.push_back({"p1:a", "p3:b", "p5:x"}); 
    test.push_back({"p1:b", "p2:q", "p5:x"});
    vector<string> ans = computeParameterValue(test);
    for(auto it : ans){
        cout << it << endl;
    }
}