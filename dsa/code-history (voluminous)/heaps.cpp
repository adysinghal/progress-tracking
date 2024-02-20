#include <iostream>
#include <vector>
#include <queue>
#include <map>

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

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
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

        int time = ((n+1) * (maxSize-1)) + maxSizeFreq;
        
        return max(time, sz);
    }
};




// https://leetcode.com/problems/hand-of-straights/

// approach using array and map
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = hand.size();
        if(n%groupSize != 0)return false;

        map<int,int> mp;
        for(auto i : hand){
            mp[i]++;
        }
        
        while(!mp.empty()){
            vector<int> temp;
            for(auto it : mp){
                temp.push_back(it.first);
                mp[it.first]--;

                // remove value if freq is zero
                if(mp[it.first] == 0){
                    mp.erase(it.first);
                }

                // end for loop after making the 
                if(temp.size() == groupSize)break;
            }

            if(temp.size() != groupSize)return false;

            for(int i = 0; i < temp.size()-1; i++){
                if(temp[i+1] - temp[i] != 1)return false;
            }
        }

        return true;

    }
};



// priority queue approach
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(hand.size() % groupSize != 0)return false;

        priority_queue<int, vector<int>, greater<int> > pq;
        for(int i : hand){
            pq.push(i);
        }

        while(!pq.empty()){
            vector<int> repeat;
            int prev = pq.top();
            pq.pop();
            int counter = 1;

            while(!pq.empty() && counter < groupSize){
                
                // case of repeat characters
                if(pq.top() == prev){
                    repeat.push_back(pq.top());
                    pq.pop();
                }else if(pq.top() == prev+1){
                    prev = pq.top();
                    counter++;
                    pq.pop();
                }
                else{
                    return false;
                }

            }

            if(counter != groupSize)return false;
            for(int it : repeat){
                pq.push(it);
            }

        }
        return true;
    }
};

// https://leetcode.com/problems/merge-k-sorted-lists/description/

class Solution {

    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy, *left = l1, *right = l2;

        while(left && right){
            if(left->val <= right->val){
                curr->next = left;
                curr = curr->next;
                left = left->next;
            }else{
                curr->next = right;
                curr = curr->next;
                right = right->next;
            }
        }

        if(left){
            curr->next = left;
        }

        if(right){
            curr->next = right;
        }

        return dummy->next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)return nullptr;
        else if(lists.size() == 1)return lists[0];
        
        int n = lists.size();
        ListNode* head = lists[0];
        for(int i = 1; i < n; i++){
            head = merge(head, lists[i]);
        }

        return head;
    }
};




// https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;  // min heap

public:
    KthLargest(int k, vector<int>& nums) {
        for(int i = 0; i < k; i++){
            pq.push(nums[i]);
        }

        for(int i = k+1; i < nums.size(); i++){
            if(pq.top() < nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(val > pq.top()){
            pq.pop();
            pq.push(val);
        }
        int ans = pq.top();
        return ans;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */