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

TreeNode* findAncestor(TreeNode* root,int p,int q){
    int rootV = root->val;
    int minV = min(p,q);
    int maxV = max(p,q);
    if(minV <= rootV && maxV >= rootV) {
        return root;
    }
    else if(maxV < rootV){
        return findAncestor(root->left,p,q);
    }
    else {
        return findAncestor(root->right,p,q);
    }


}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        cout << root->val << p->val << q->val;
        return findAncestor(root,p->val,q->val);
    }
};
