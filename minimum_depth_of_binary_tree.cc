/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (NULL == root) return 0;
        int depth_l = 1 << 31 -1;
        int depth_r = 1 << 31 -1;
        if (NULL == root->left && NULL == root->right) return 1;
        
        if (NULL != root->left) depth_l = minDepth(root->left);
        if (NULL != root->right) depth_r = minDepth(root->right);
        return 1 + min(depth_l, depth_r);
    }
};
