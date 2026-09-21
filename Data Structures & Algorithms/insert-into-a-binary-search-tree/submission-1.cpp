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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp = root;
        TreeNode* prev = root;
        while(temp){
            prev = temp;
            if(temp->val > val){
                temp = temp->left;
            }else{
                temp = temp->right;
            }
        }
        TreeNode* dummy = new TreeNode(val);
        if(!prev) return dummy;
        else if(prev->val < val){
            prev->right = dummy;
        }else{
            prev->left = dummy;
        }
        return root;
    }
};