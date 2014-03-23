// Discuss 5 condition to solve this problem, always can get 1AC.

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
    bool hasPathSum(TreeNode *root, int sum) {
        if (NULL == root) {  // condition 1 - null
            return false;
        }
        if (NULL == root->left) {
            if (NULL == root->right) {  // condition 2 
                if (root->val == sum) return true;
                else return false;
            } else {  // condition 3
                return hasPathSum(root->right, sum - root->val);
            }
        } else {
            if (NULL == root->right) {  // condition 4
                return hasPathSum(root->left, sum - root->val);
            } else {  // condition 5
                return hasPathSum(root->left, sum - root->val) ||
                hasPathSum(root->right, sum - root->val);
            }
        }
    }
};
