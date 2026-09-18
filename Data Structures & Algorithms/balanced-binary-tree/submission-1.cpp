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

bool balanced;

int dfs(TreeNode* root){
    if(!root) return 0;

    int left = dfs(root->left);
    int right = dfs(root->right);
    cout << "ROOT: " << root->val << " ";
    cout << abs(left - right) << "\n";
    balanced &= !(abs(left-right) > 1);

    return 1 + max(left,right);
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        balanced = true;
        dfs(root);
        return balanced;
    }
};
