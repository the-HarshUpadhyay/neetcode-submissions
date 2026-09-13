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

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        vector<TreeNode*> stack;
        if(root) stack.push_back(root);
        while(!stack.empty()){
            TreeNode* curr = stack.back();
            stack.pop_back();
            swap(curr->left,curr->right);
            if(curr->left) stack.push_back(curr->left);
            if(curr->right) stack.push_back(curr->right);
        }
        return root;
    }
};
