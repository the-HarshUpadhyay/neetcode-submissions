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

bool isSubtreeFlag;
bool DFScompare(TreeNode* root,TreeNode* subRoot){
    if(!subRoot && !root) return true;
    if(!subRoot || !root) return false;
    if(root->val != subRoot->val) return false;
    bool left = DFScompare(root->left,subRoot->left);
    bool right = DFScompare(root->right,subRoot->right);
    
    return (left && right);
}

void singleDFS(TreeNode*root,TreeNode*subRoot){
    if(!root) return;
    isSubtreeFlag |= DFScompare(root,subRoot);
    if(isSubtreeFlag) return;
    singleDFS(root->left,subRoot);
    singleDFS(root->right,subRoot);
}


class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        isSubtreeFlag = false;
        singleDFS(root,subRoot);
        return isSubtreeFlag;
    }
};
