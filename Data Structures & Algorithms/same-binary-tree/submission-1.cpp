/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

bool dfs(TreeNode* root1,TreeNode* root2){
    //if both tree reach end of branch together
        if(!root1 && !root2) return true;
        //one tree finished first;
        else if(!root1 || !root2) return false; 
        return (root1->val == root2->val) & dfs(root1->left,root2->left) & dfs(root1->right,root2->right);
        // cout << flag << "\n";
    }

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p,q);
    }
};
