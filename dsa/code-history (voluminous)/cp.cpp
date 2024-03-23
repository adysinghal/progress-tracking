#include<bits/stdc++.h>
using namespace std;


//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {

    ListNode* reverse(ListNode* head){
        if(!head->next)return head;
        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int count = 0;
        while(fast && fast->next){
            count++;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = reverse(slow);
        ListNode* preserveHead = head;
        
        while(count){
            ListNode *tempHead = head, *tempMid = mid;     
            head = head->next, mid = mid->next;
            tempHead->next = tempMid;
            if(tempMid->next || tempMid->next->next){
                tempMid->next = head;
            }

            count--;
        }
    }
};