#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;



// Q1 - JUSTIFY TEXT

// Given an array of strings words and a width maxWidth, format the text such that each line has exactly
//  maxWidth characters and is fully (left and right) justified.

// You should pack your words in a greedy approach; that is, pack as many words as you can in each line.
//  Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

// Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line 
// does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots
// on the right.

// For the last line of text, it should be left-justified, and no extra space is inserted between words.

// Note:

// A word is defined as a character sequence consisting of non-space characters only.
// Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
// The input array words contains at least one word.


// Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
// Output:
// [
//    "This   is    an",
//    "example  of text",
//    "justification.  "
// ]

// This is an 
// 4 + 3 + 3 = 10

// temp = "This   is   an"
// "This is an"


// wordCounter, lineLength, 



// 4 + 1 + 2 + 1 + 2  = 10 
// This    is    an
// example 


vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int n = words.size();
    int first = 0;
    int second = 0;
    int lineLength = 0;
    string temp = "";



    while(second < n){
        // find no of words to fit in a line
        if(first == second){
            lineLength += words[second].size();
            second++;
        }

        while(lineLength + words[second].size() + 1 <= maxWidth && lineLength < n){
            lineLength += words[second].size() + 1;
            second++;
        }

        int numWords = second - first + 1;

        // no of remianing spaces that are equally distributed + extra spces for left part
        int remaining = maxWidth - lineLength;
        int gaps = numWords - 1;

        int equalspaces = second<n?remaining/gaps:1;
        int leftspaces = second<n? remaining % gaps: 0;

        //form the temp string
        while(first < second-1){
            temp += words[first];
            if(leftspaces != 0){
                for(int i = 0; i < equalspaces + 1; i++){
                    temp += " ";
                }
            }else{
                for(int i = 0; i < equalspaces; i++){
                    temp += " ";
                }
            }
            first++;
        }
        temp += words[first];
        first++;

        //reset variable
        lineLength = 0;
    }
}




// Q2 - COUNT INVERSIONS

// https://www.codingninjas.com/studio/problems/count-inversions_615?topList=top-array-coding-interview-questions&problemListRedirection=true

// For a given integer array/list 'ARR' of size 'N' containing all distinct values, find the total number of 'Inversions' that may exist.

// An inversion is defined for a pair of integers in the array/list when the following two conditions are met.

// A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

// 1. 'ARR[i] > 'ARR[j]' 
// 2. 'i' < 'j'

// Where 'i' and 'j' denote the indices ranging from [0, 'N').


long long getInversions(long long *arr, int n){
    // brute force approach -> O(N^2) approach

    long long ans = 0;
    // visit every element
    for(int i = 0; i < n; i++){
        
        // check how many smaller elements lie ahead of it
        for(int j = i; j < n; j++){
            if(arr[i] > arr[j])ans++;
        }

    }

    return ans;

}

// 4 2 1 3
/*

stack

3
4

ans = 1 + 2 + 1
*/


long long getInversions(long long *arr, int n){
    // using a stack to keep track of smallest element encountered

    // add to stack (if possible)

    // check how many elements present below the element and add to 
    // ans (if stack not empty)


    // 4 2 1 3
    /*
    
    stack
    
    
    
    4

    ans = 4
    */

   


    stack<long long> st;
    long long ans = 0;

    for(long long i = 0; i < n; i++){
        
        if(st.empty()){
            st.push(arr[i]);
            continue;
        }

        while(!st.empty() && st.top() < arr[i]){
            st.pop();
        }
        
        ans += st.size();

        st.push(arr[i]);

    }

    return ans;
}
// this approach is not working, will troubleshoot later


// optimised approach from discussions -> merge sort




