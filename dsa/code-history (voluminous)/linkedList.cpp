#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


// https://leetcode.com/problems/reverse-linked-list/description/
// reverse a linked list

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// recursive approach
class Solution {

ListNode* helper(ListNode* prev, ListNode* curr){
    if(!curr->next)return curr;

    // make the call first as we need to reverse the pointers on our way back
    ListNode* newHead = helper(prev->next, curr->next);

    // on the way back, reverse the pointers
    curr->next = prev;

    return newHead;
}

public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = helper(head, head->next);
        head->next == nullptr;
        return newHead;
    }
};

// another recursive approach
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)return head;

        ListNode* newHead = reverseList(head->next);

        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;

        return newHead;
    }
};


// iterative solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* temp = head, *newHead = NULL;

        while(temp){
            ListNode* nextNode = temp->next;
            temp -> next = newHead;
            newHead = temp;
            temp = nextNode;
        }        
        return newHead;
    }
};



// https://leetcode.com/problems/middle-of-the-linked-list/description/
// middle of linked list

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(!head)return NULL;
        ListNode* fast = head, *slow = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
//             f
//       s
// 1 2 3 4 5 6 7 8



// https://leetcode.com/problems/merge-two-sorted-lists/description/
// merge two sorted lls

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // assigning temp to the smaller of the two
        ListNode* temp = NULL;
        if(list1-> val > list2-> val){
            temp = list1;
            list1 = list1->next;
        }else{
            temp = list2;
            list2 = list2->next;
        }

        ListNode* head = temp;
        
        while(list1 && list2){
            bool l1 = true;
            if(list1-> val > list2-> val)l1 = false;
            
            if(l1){
                temp -> next = list1;
                temp = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }

        }    

        while(list1){
            temp -> next = list1;
            temp = list1;
            list1 = list1->next;
        }
        while(list2){
            temp -> next = list2;
            temp = list2;
            list2 = list2->next;
        }

        return head;

    }
};


// https://leetcode.com/problems/add-two-numbers/
// add-two-numbers

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* head = NULL;
//         int carry = 0;
//         ListNode* temp = NULL;
//         while(l1 && l2){
//             int totalSum = l1->val + l2->val + carry;
//             int sum = totalSum % 10;
//             carry = totalSum / 10;
//             ListNode* newNode = new ListNode(sum);
//             if(!head){
//                 head = newNode;
//                 temp = newNode;
//             }
//             else{
//                 temp->next = newNode;
//                 temp = newNode;
//             } 
//             l1 = l1->next;
//             l2 = l2->next;

//         }

//         while(l1){
//             temp->next = l1;
//             temp = l1;
//             l1 = l1->next;
//         }
//         while(l2){
//             temp->next = l2;
//             temp = l2;
//             l2 = l2->next;
//         }
//         temp->next = NULL;

//         return head;
//     }
// };

class Solution {
public:
// a lot of usage of ternary operator

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        int carry = 0;

        while(l1 || l2 || carry){
            int d1 = (l1) ? l1->val : 0;
            int d2 = (l2) ? l2->val : 0;

            int totalSum = d1 + d2 + carry;
            carry = totalSum / 10;
            ListNode* temp = new ListNode(totalSum%10);

            tail->next = temp;
            tail = tail->next;

            l1 = (l1) ? l1->next : nullptr;
            l2 = (l2) ? l2->next : nullptr;
        }
        if(head)head = head->next;
        return head;
    }
};

/*

2 4 3
5 6 4

sum = 0
carry = 1
temp = 7
head = 7

7   ->  0       -> 8
                  newNode
head
                temp
*/



// https://leetcode.com/problems/delete-node-in-a-linked-list/
//  delete a node in a linked list 

class Solution {
public:
    void deleteNode(ListNode* node) {
        if(!node)return;
        if(!node->next){
            node = nullptr;
            return;
        }
        
        node->val = node->next->val;
        node->next = node->next->next;
        return;
    }
};


// https://leetcode.com/problems/intersection-of-two-linked-lists/
// intersection-of-two-linked-lists/

// approach 1 : traverse from both nodes and find length of both lists (l1 > l2)always
// move l1 head l1-l2 nodes ahead and then traverse both of them together till they collide
// TC : O(n+m)
// SC : O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = 0, l2 = 0;
        ListNode* temp = headA;
        
        // calculating l1
        while(temp){
            l1++;
            temp = temp->next;
        }
        
        temp = headB;
        while(temp){
            l2++;
            temp = temp->next;
        }


        // always make l1 bigger
        if(l1 < l2){
            // swap l1 and l2
            int tempnum = l1;
            l1 = l2;
            l2 = tempnum;

            // swap headA and headB
            temp = headA;
            headA = headB;
            headB = temp;
        }
        int diff = l1 - l2;
        ListNode *a = headA, *b = headB;
        while(diff){
            a = a->next;
            diff--;
        }

        while(a != b && a && b){
            a = a->next;
            b = b->next;
        }
        return a;
    }
};


// Approach 2 : Hashing
// TC : O(N+M)
// SC : O(N)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> st;

        while(headA){
            st.insert(headA);
            headA = headA->next;
        }

        while(headB){
            if(st.find(headB) == st.end()){
                st.insert(headB);
            }
            else return headB;
            headB = headB->next;
        }
        return NULL;
    }
};


// https://leetcode.com/problems/palindrome-linked-list/
// palindrome-linked-list

// TC : O(N)
// SC : O(1)
class Solution {

    ListNode* reverse(ListNode* head){
        if(!head->next)return head;

        ListNode* newHead = reverse(head->next);

        head->next->next = head;
        head->next = nullptr;
        return newHead;

    }


public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)return true;

        ListNode *fast = head, *slow = head;

        while(fast && fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        slow->next = reverse(slow->next);
        slow = slow->next;
        ListNode *temp = head;

        while(slow){
            if(slow->val == temp->val){
                slow = slow->next;
                temp = temp->next;
            }
            else return false;
        }
        return true;
      
    }
};


// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes 
// is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]

// input :
// 1 -> 2 -> 3 -> 4 -> 5

// output: 
// 2 -> 1 -> 4 -> 3 -> 5

class Solution {
public:
    ListNode* reverse(ListNode* head, int counter, int k){
        if(counter == k-1 || !head){
            return head;
        }

        ListNode* newHead = reverse(head->next, counter+1, k);

        head->next->next = head;
        head->next = NULL;
        return newHead;

    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        
        // make dummy node
        ListNode* dummy = new ListNode;
        dummy->val = -1;
        dummy->next = head;

        // reverse nodes (with counter that terminates at k)
        ListNode* prev = dummy;
        
        while(prev->next){

            ListNode* temp = prev->next;
            ListNode* nextNode = prev->next;
            int counter = 0;
            
            while(counter < k && nextNode){
                nextNode = nextNode->next;
                counter++;
            }
            if(counter != k)return dummy->next;

            ListNode* newHead = reverse(temp, 0, k);
            
            prev->next = newHead;
            temp = newHead;
            counter = 0;
            while(counter < k-1 && temp->next){
                temp = temp->next;
                counter++;
            }
            prev = temp;
            temp->next = nextNode;
        }
        return dummy->next;
        
    }
};


// input :
// dummy -> 1 -> 2 -> 3 -> 4 -> 5
//               temp
//               prev
//                    nextNode
// counter = 1

