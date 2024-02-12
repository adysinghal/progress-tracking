#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// https://leetcode.com/problems/kth-largest-element-in-an-array/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > pq;
        for(int i = 0; i < k; i++){
            pq.push(nums[i]);
        }

        for(int i = k; i < nums.size(); i++){
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();
    }
};





// https://leetcode.com/problems/merge-k-sorted-lists/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        priority_queue<int, vector<int>, greater<int> > pq;
        ListNode* head = new ListNode(-1);
        ListNode* dummy = head;

        int n = lists.size();

        // fill pq with all values in the lists        
        for(int i = 0; i < n; i++){
            ListNode* temp1 = lists[i];
            while(temp1){
                pq.push(temp1->val);
                temp1 = temp1->next;
            }
        }

        // make new lists with values from pq
        while(!pq.empty()){
            ListNode* newNode = new ListNode(pq.top());
            pq.pop();
            head->next = newNode;
            head = head->next;
        }
        
        // temp is the dummy node before the head
        return dummy->next;

    }
};



// https://leetcode.com/problems/task-scheduler/
// pq solution
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> freq(26, 0);
        for(auto ch : tasks){
            freq[ch-'A']++;
        }

        // default is max pq
        priority_queue<int> pq;
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0)pq.push(freq[i]);
        }
        int ans = 0;

        while(!pq.empty()){
            int counter = n+1;
            vector<int> processed;

            while(!pq.empty() && counter){
                int maxFreq = pq.top();
                pq.pop();
                counter--;
                processed.push_back(maxFreq-1);
            }

            for(int i:processed){
                if(i != 0)pq.push(i);
            }
            
            if(!pq.empty()){
                ans += (n+1);
            }else{
                ans += (n+1-counter);
            }
            
        }
        return ans;
    }
};

// math formula solution
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int maxSizeFreq = 0, sz = tasks.size(), maxSize = 0;
        
        // update hash and also the maxSize
        for(auto ch : tasks){
            freq[ch-'A']++;
            maxSize = max(maxSize, freq[ch-'A']);
        }

        for(int i : freq){
            if(i == maxSize)maxSizeFreq++;
        }

        int time = ((n+1) * maxSize) + maxSizeFreq;
        
        return max(time, sz);
    }
};
