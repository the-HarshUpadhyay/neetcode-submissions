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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* temp = root;
        int lVal = min(p->val,q->val);
        int hVal = max(q->val,p->val);
        while(true){
            int rVal = temp->val;

            if(lVal <= rVal && hVal >= rVal){
                return temp;
            }else if(hVal < rVal){
                temp = temp->left;
            }else{
                temp = temp->right;
            }
        }
        return nullptr;
    }
};
