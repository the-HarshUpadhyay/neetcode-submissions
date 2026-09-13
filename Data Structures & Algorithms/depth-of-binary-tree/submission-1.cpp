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
    int maxDepth(TreeNode* root) {
        vector<pair<TreeNode*,int>> stack;
        if(root) stack.push_back({root,0});
        int res = 0;
        while(!stack.empty()){
            auto [curr,depth] = stack.back();
            stack.pop_back();
            if(curr->left) stack.push_back({curr->left,depth+1});
            if(curr->right) stack.push_back({curr->right,depth+1});
            res = max(res,depth+1);
        }
        return res;
    }
};
