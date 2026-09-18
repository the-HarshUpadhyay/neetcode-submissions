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

int diameter = 0;
int depth(TreeNode* root){
    if(!root) return 0;

    int lefth = depth(root->left);
    int righth = depth(root->right);

    diameter = max(diameter,lefth+righth);
    return 1 + max(lefth,righth);
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        depth(root);
        return diameter;
    }
};
