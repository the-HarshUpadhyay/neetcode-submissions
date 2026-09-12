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
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> result;
        while(curr){
            TreeNode* inorderSuccessor = curr->left;
            //to find inorderSuccesor
            while(inorderSuccessor && inorderSuccessor->right){
                if(inorderSuccessor->right == curr) break; 
                inorderSuccessor = inorderSuccessor->right;
            }

            if(inorderSuccessor == nullptr){
                result.push_back(curr->val);
                curr = curr->right;
                continue;
            }

            if(inorderSuccessor->right == nullptr){
                inorderSuccessor->right = curr;
                result.push_back(curr->val);
                curr = curr->left;
            }
            else{
                inorderSuccessor->right = nullptr;
                curr = curr->right;
            }
        }
        return result;

    }
};