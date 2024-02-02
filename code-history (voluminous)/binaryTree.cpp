#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode *right): val(x), left(left), right(right) {}

};


// https://leetcode.com/problems/binary-tree-level-order-traversal/

// approach 1
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {{}};
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> ans;
        int treeLevel = -1;

        q.push({root, 0});

        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

            if(node->left)q.push({node->left, level+1});
            if(node->right)q.push({node->right, level+1});

            if(treeLevel < level){
                ans.push_back({});
                treeLevel++;
            }
            ans[level].push_back(node->val);
        }
        return ans;

    }
};



// approach 2
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<int> temp;

            for(int i = 0; i < s; i++){
                TreeNode* front = q.front();
                q.pop();
                if(front->left)q.push(front->left);
                if(front->right)q.push(front->right);
                temp.push_back(front->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};




// https://leetcode.com/problems/maximum-depth-of-binary-tree/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return 1 + max(left, right);
    }
};


// https://leetcode.com/problems/diameter-of-binary-tree/
class Solution {

    int helper(TreeNode* root, int& ans){
        if(!root)return 0;

        int left = helper(root->left, ans);
        int right = helper(root->right, ans);

        ans = max(ans, left + right);

        return 1 + max(left, right);
    }


public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;    
    }
};


    //     1
    //    /  \
    //   2    3
    //  / \    \
    // 4   5     7





// https://leetcode.com/problems/balanced-binary-tree/


// simple solution
class Solution {
public:

    int helper(TreeNode* root){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(!root)return 0;
        
        int left = helper(root->left);
        int right = helper(root->right);

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(!root)return true;
        // calculate height for left and right subtrees
        // if abs(left - right) > 1
        // return false
        // else return true at the end
        
        bool leftans = isBalanced(root->left);
        bool rightans = isBalanced(root->right);
        if(!leftans || !rightans)return false;

        int left = helper(root->left);
        int right = helper(root->right);

        if(abs(left-right) > 1)return false;
        else return true;
    }
};


// memoized solution
class Solution {
public:

    int height(TreeNode* root){
        if(!root)return 0;
        
        int left = height(root->left);
        int right = height(root->right);

        return 1 + max(left, right);
    }

    bool helper(TreeNode* root, unordered_map<TreeNode*, int> &mp){
        if(!root)return true;
        // calculate height for left and right subtrees
        // if abs(left - right) > 1
        // return false
        // else return true at the end
        
        bool leftans = isBalanced(root->left);
        bool rightans = isBalanced(root->right);

        if(!leftans || !rightans)return false;

        int left, right;

        if(mp.find(root->left) == mp.end()){
            left = height(root->left);
            mp[root->left] = left;
        }
        else left = mp[root->left];

        if(mp.find(root->right) == mp.end()){
            right = height(root->right);
            mp[root->right] = right;
        }
        else right = mp[root->right];

        if(abs(left-right) > 1)return false;
        else return true;
    }

    bool isBalanced(TreeNode* root) {
        unordered_map<TreeNode*, int> mp;
        return helper(root, mp);
    }
};



// https://leetcode.com/problems/same-tree/


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)return true;
        if(!p || !q)return false;

        if(p->val != q->val)return false;

        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);

        if(!left || !right)return false;
        return true;
    }
};





// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        int level = 0;

        while(!q.empty()){
            level++;
            vector<int> temp;
            int s = q.size();
            
            for(int i = 0; i < s; i++){
                TreeNode* node = q.front();
                q.pop();
                
                temp.push_back(node->val);
                
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(level % 2 == 0)reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};



// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/



class Solution {

    int dfs(TreeNode* root, int &ans){
        // we will return the node -> val + max(left, right)
        // also update the ans variable with left + right + node->val

        if(!root)return 0;
        
        int left = max(dfs(root->left, ans), 0);
        int right = max(dfs(root->right, ans), 0);

        // update ans
        ans = max(ans, left + right + root->val);

        return root->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};




// https://leetcode.com/problems/symmetric-tree/


class Solution {

    bool helper(TreeNode* leftNode, TreeNode* rightNode){
        if(!leftNode && !rightNode)return true;
        if(!leftNode || !rightNode)return false;

        bool leftCheck = helper(leftNode->left, rightNode->right);
        bool rightCheck = helper(leftNode->right, rightNode->left);

        if(!leftCheck || !rightCheck)return false;

        if(leftNode->val == rightNode->val)return true;

        return false;        
    }

public:
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return helper(root, root);
    }
};

// cleaner code, combined all conditions in the return statement with &&
class Solution {

    bool helper(TreeNode* leftNode, TreeNode* rightNode){
        // if both are nullptr, it will return a true, otherwise a false      
        if(!leftNode || !rightNode)return leftNode == rightNode;

        return (leftNode->val == rightNode->val) && helper(leftNode->left, rightNode->right) && helper(leftNode->right, rightNode->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return helper(root, root);
    }
};

// https://www.codingninjas.com/studio/problems/boundary-traversal-of-binary-tree_790725?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode* root){
    return !root->left && !root->right;
}

void inorder(TreeNode* root, vector<int>& ans){
    if(!root)return;
    
    if(isLeaf(root))ans.push_back(root->val);

    inorder(root->left, ans);
    inorder(root->right, ans);
    
    return;
}


vector<int> traverseBoundary(TreeNode *root)
{
    // we need to print in the following fashion
    // root of the tree
    // left boundary (excluding leaves)
    // leaf nodes
    // right boundary (excluding leaves)

    vector<int> ans;
    ans.push_back(root->val);

    // now for left boundary
    TreeNode* temp = root->left;
    // while(temp){
    //     ans.push_back(temp->data);
    //     if(temp->left){
    //         if(!isLeaf(temp->left))temp = temp->left;
    //         else temp = nullptr;
    //     }
    //     else if(temp->right){
    //         if(!isLeaf(temp->right))temp = temp->right;
    //         else temp = nullptr;
    //     }
    //     else break;
    // }

    while (temp) {
        if(!isLeaf(temp))ans.push_back(temp->val);
        if (temp->left)temp = temp->left;
        else temp = temp->right;
        
    }

    // now push the leaf nodes
    inorder(root, ans);


    // right boundary in reverse
    vector<int> tempAns;
    temp = root->right;
    
    // while(temp){
    //     tempAns.push_back(temp->data);
    //     if(temp->right){
    //         if(!isLeaf(temp->right))temp = temp->right;
    //         else temp = nullptr;
    //     }
    //     else if(temp->left){
    //         if(!isLeaf(temp->left))temp = temp->left;
    //         else temp = nullptr;
    //     }
    //     else break;
    // }

    while (temp) {
        if(!isLeaf(temp))tempAns.push_back(temp->val);
        if (temp->left)temp = temp->left;
        else temp = temp->right;
    }
    
    for(int i = tempAns.size()-1; i >= 0; i--){
        ans.push_back(tempAns[i]);
    }
    return ans;
}



// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

class Solution {
    TreeNode* prev = NULL;
public:


    void flatten(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // we traverse in reverse preorder fashion
        // make a class variable called prev
        // every time we visit a node, update (root->right = prev), (root->left = NULL) and make (prev = root)

        if(!root)return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};



// https://www.codingninjas.com/studio/problems/children-sum-property_8357239?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION
// Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};


bool isParentSum(Node *root){
    if(!root)return true;
    
    // return true if leaf node
    if(!root->left && !root->right)return true;


    bool leftAns = isParentSum(root->left);
    bool rightAns = isParentSum(root->right);
    if(!leftAns || !rightAns)return false;

    // calculate values of leftsum and rightsum
    int leftSum = (root->left) ? root->left->data : 0;
    int rightSum = (root->right) ? root->right->data : 0;

    if(root->data == leftSum + rightSum)return true;
    else return false;
}


