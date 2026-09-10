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
    TreeNode* inorderPredecessor(TreeNode* root){
        TreeNode* curr = root->left;
        while(curr && curr->right && curr->right!=root){
            curr = curr->right;
        }
        return curr;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* predecessor = nullptr;
        vector<int> inorder;
        while(curr){
            predecessor = inorderPredecessor(curr);
            // if(curr->left == nullptr){
            //     inorder.push_back(curr->val);
            // }

            if(predecessor && !predecessor->right){
                predecessor->right = curr;
                curr = curr->left;
            }else{
                inorder.push_back(curr->val);
                if(predecessor) predecessor->right = nullptr;
                curr = curr->right;
            }
        }
        return inorder;
    }
};