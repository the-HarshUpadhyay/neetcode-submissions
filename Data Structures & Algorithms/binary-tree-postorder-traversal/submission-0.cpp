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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> res;
        while(curr){
            TreeNode* inorderSuccessor = curr->right;

            while(inorderSuccessor && inorderSuccessor->left && inorderSuccessor->left != curr){
                inorderSuccessor = inorderSuccessor->left;
            }


            if(inorderSuccessor && inorderSuccessor->left != curr){
                res.push_back(curr->val);
                inorderSuccessor->left = curr;
                curr = curr->right;
            }
            else{
                if(inorderSuccessor == nullptr){
                    res.push_back(curr->val);
                }
                else inorderSuccessor->left = nullptr;
                curr = curr->left;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};