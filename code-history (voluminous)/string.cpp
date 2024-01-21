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

#define base 256
#define prime 11

class Solution {
public:
    int robinKarp(string a, string b) {
        int m = a.size(), n = b.size();
        int patternHash = 0, textHash = 0, h = 1;

        // hash value
        for(int i = 0; i < m-1; i++){
            h = (h*base) % prime;
        }

        // calculate initial values for patternHash and textHash
        for(int i = 0; i < m; i++){
            patternHash = (base * patternHash + a[i]) % prime;
            textHash = (base * textHash + b[i]) % prime;
        }

        // slide window for indices of text string
        for(int i = 0; i <= n-m; i++){
            if(patternHash == textHash){
                int j;
                for(j = 0; j < m; j++){
                    if(a[j] != b[i+j])break;
                }
                
                // pattern found
                // if(j == m)
            }

            if(i < n-m){
                textHash = (base * (textHash - a[i] * h) + a[i+m]) % prime;
            }
            if(textHash < 0)textHash += prime;
        }

    }
};



// https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/
// Minimum Characters required to make a String Palindromic
// Given a string A. The only operation allowed is to insert characters at the beginning of the string.
// Find how many minimum characters are needed to be inserted to make the string a palindrome string.

bool checkPalindrome(string str, int start, int end){
    while(start <= end){
        if(str[start] != str[end])return false;
        start++, end--;
    }
    return true;
}

int solve(string A) {
    // find the longest palindrome in the string that starts at index 0 and add remaining number of characters to the start of the string

    // iterate from the end and the first palindromic string that is found, break the loop there
    int n = A.size();
    int index = -1;
    
    for(int i = n-1; i > 0; i--){
        if(checkPalindrome(A, 0, i)){
            index = i;
            break;
        }
    }

    if(index == -1)return n-1;

    return n - 1 - index;
    

    // this solution is giving TLE for extremeley large input

}

// KMP algorithm
// https://medium.com/@aakashjsr/preprocessing-algorithm-for-kmp-search-lps-array-algorithm-50e35b5bb3cb#:~:text=LPS%20is%20simply%20the%20name,the%20first%20'i'%20characters.
// will do it later