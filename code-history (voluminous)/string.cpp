#include <iostream>
#include <vector>
#include <string>
using namespace std;

// https://leetcode.com/problems/reverse-words-in-a-string/


class Solution {
public:
    string reverseWords(string s) {

                
        // we will traverse from the end to front using two pointers
        // every time space is encountered, we will copy the content between the two pointers


        int end = s.size() - 1;
        string ans = "";
        while(end >= 0){
            while(end >= 0 && s[end] == ' ')end--;
            if(end < 0)break;

            if(!ans.empty())ans += ' ';

            int start = end;
            while(start >= 0 && s[start] != ' ')start--;

            ans += s.substr(start + 1, end - start);
            end = start;
        }

        return ans;
    }
};



// https://leetcode.com/problems/longest-palindromic-substring/

// Longest Palindromic Substring

class Solution {

    void check(int l, int r, string& s, string& res, int& reslen, int n){
        while(l >= 0 && r < n && s[l] == s[r]){
            int len = r - l + 1;
            if(len > reslen){
                reslen = len;
                res = s.substr(l, r-l+1);
            }
            r++, l--;
        }
        return;
    }

public:
    string longestPalindrome(string s) {
        // brute force -> check all possible combinations of strings for palindrome then chose the longest length that is a plaindrome

        // trick -> go inside out

        int reslen = 0;
        string res = "";
        int n = s.size();

        for(int i = 0; i < n; i++){
            // odd length
            check(i, i, s, res, reslen, n);

            // even length
            check(i, i+1, s, res, reslen, n);
        }
        return res;
    }
};


// https://leetcode.com/problems/longest-common-prefix/
// longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs){

        // approach -> assuming the first string to be the longest common prefix, we start comparing each of the other strings to it and we update ans to be the longest common substring out of these

        string ans = strs[0], temp = "";
        
        for(auto s:strs){
            for(int i = 0; i < min(ans.size(), s.size()); i++){
                if(s[i] == ans[i])temp.push_back(s[i]);
                else break;
            }
            ans = temp;
            temp.clear();
        }
        return ans;
    }
};



// https://leetcode.com/problems/repeated-string-match/
// Repeated String Match (Rabin Karp algorithm)

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
    }
};