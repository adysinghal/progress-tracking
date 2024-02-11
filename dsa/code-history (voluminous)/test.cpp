#include <iostream>
#include <vector>
using namespace std;

// struct Tree{
//     int val;
//     Tree *left;
//     Tree *right;

//     Tree(): val(0), left(nullptr), right(nullptr) {}
//     Tree(int x): val(x), left(nullptr), right(nullptr) {}
//     Tree(int x, Tree *left, Tree *right): val(x), left(left), right(right){}
// };

//     // pair -> height, diameter

// pair<int,int> heightAndDiameter(Tree* root, int& ans){

//     pair<int,int> p;
//     if(!root)return p;

//     pair<int,int> left = heightAndDiameter(root->left, ans);
//     pair<int,int> right = heightAndDiameter(root->right, ans);

//     ans = max(ans, left.second + right.second);

//     p.first = 1 + max(left.first, right.first);
//     p.second = 1 + max(left.second, right.second);

//     return p;
// }

// int main(){
//     Tree *head = new Tree(1);
//     Tree *node2 = new Tree(2);
//     Tree *node3 = new Tree(3);
//     Tree *node4 = new Tree(4);
//     Tree *node5 = new Tree(5);
//     Tree *node6 = new Tree(6);
//     Tree *node7 = new Tree(7);
//     head->left = node2;
//     head->right = node3;
//     node2->left = node4;
//     // node2->right = node5;
//     node3->left = node6;
//     // node3->right = node7;
//     node4->left = node7;
//     node7->right = node5;


//     int diameter = 0;
    
//     pair<int,int> p = heightAndDiameter(head, diameter);
//     cout << "Height is: " << p.first << " \n Diameter is: " << diameter << endl;

// }

// /*
//         1
//       /    \
//      2      3
//     / \    / 
//    4   5   6  
//   / 
//  7
// */      

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n), right(n);

        int lmax = 0;
        for(int i = 0; i < n; i++){
            if(height[i] > lmax){
                lmax = height[i];
            }
            left[i] = lmax;
        }

        
        int rmax = 0;
        for(int i = n-1; i >= 0; i--){
            if(height[i] > rmax){
                rmax = height[i];
            }
            right[i] = rmax;
        }

        int ans = 0;
        
        for(int i = 0; i < n; i++){
            int temp = min(left[i], right[i]) - height[i];
            ans += (temp < 0) ? 0 : temp;
        }

        return ans;
    }
};

int main(){
    Solution s;
    vector<int> v = {4,2,0,3,2,5};
    cout << s.trap(v) << endl;
}

