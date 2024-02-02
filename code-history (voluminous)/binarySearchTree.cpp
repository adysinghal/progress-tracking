#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// TC : O(N)

class Solution {
public:
    Node* connect(Node* root) {

        if(!root)return nullptr;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int s = q.size();
            
            vector<Node*> temp;

            // store each level in the temp vector
            for(int i = 0; i < s; i++){
                Node* currNode = q.front();
                q.pop();
                temp.push_back(currNode);
                
                if(currNode->left)q.push(currNode->left);
                if(currNode->right)q.push(currNode->right);
            }

            // traverse the level and link the next nodes
            for(int i = 0; i < temp.size(); i++){
                
                // to mark the last node as NULL
                if(i == temp.size()-1){
                    temp[i]->next = nullptr;
                    continue;
                }
                
                temp[i]->next = temp[i+1];
            }
        }
        return root;
    }
    
};


class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return nullptr;

        if(root->left){
            root->left->next = root->right;
        }
        if(root->right && root->next){
            root->right->next = root->next->left;
        }

        connect(root->left);
        connect(root->right);

        return root;
    }
};


// Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)return nullptr;
        if(val == root->val)return root;
        if(val > root->val)return searchBST(root->right, val);
        if(val < root->val)return searchBST(root->left, val);
    }
};




// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/1162958456/

// create the function s.t. every time, middle element of left and right is picked up and made the node using the principles of binary search
class Solution {

    TreeNode* helper(vector<int>& nums, int left, int right){
        if(left > right)return nullptr;

        int mid = (left + right)/2;

        TreeNode* newNode = new TreeNode(nums[mid]);
        newNode->left = helper(nums, left, mid-1);
        newNode->right = helper(nums, mid+1, right);

        return newNode;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
};




// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/


// basic concept is that the root node is the last element in the postorder traversal 
// we can get to know which nodes are to its left and which are to its right using the inorder traversal

class Solution {
public:

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int inLow, int inHigh, int postLow, int postHigh){
        if(inLow > inHigh || postLow > postHigh)return nullptr;

        int rootValue = postorder[postHigh];
        int inorderRootIndex = -1;
        TreeNode* root = new TreeNode(rootValue);

        for(int i = inLow; i <= inHigh; i++){
            if(inorder[i] == rootValue){
                inorderRootIndex = i;
                break;
            }
        }

        int numIndex = inorderRootIndex - inLow;

        root->left = helper(inorder, postorder, inLow, inLow + numIndex-1, postLow, postLow + numIndex-1);
        root->right = helper(inorder, postorder, inLow + numIndex + 1, inHigh, postLow + numIndex, postHigh - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};



// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

class Solution {

    TreeNode* helper(vector<int>& preorder, int &index, int start, int end){
        if(start > end){
            return nullptr;
        }

        int curr = preorder[index++];
        TreeNode* root = new TreeNode(curr);

        int j;
        for(j = index; j <= end; j++){
            if(preorder[j] > curr)break;
        }

        root->left = helper(preorder, index, start, j-1);
        root->right = helper(preorder, index, start, j-1);
        
        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return helper(preorder, index, 0, preorder.size()-1);
    }
};