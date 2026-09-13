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

TreeNode* invert(TreeNode* root){
    //end of tree
    if(!root) return nullptr;
    //child node    
    if(root->left == nullptr && root->right == nullptr){
        // cout << root->val << " ";
        return root;

    }
    TreeNode* temp = root->right;
    root->right = invert(root->left);
    root->left = invert(temp);
    return root;
}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        return invert(root);
    }
};
