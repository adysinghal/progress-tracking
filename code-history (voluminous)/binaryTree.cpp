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



