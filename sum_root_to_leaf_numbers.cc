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
    int sumNumbers(TreeNode *root) {
      int ret = 0;
      if (NULL == root) return 0;

      if (NULL == root->left && NULL == root->right) return root->val;  // leaf node
      if (NULL != root->left) {
        root->left->val += root->val * 10;
        ret += sumNumbers(root->left);
      }
      if (NULL != root->right) {
        root->right->val += root->val * 10;
        ret += sumNumbers(root->right);
      }                                                                                                                                                                                                                                      
      return ret;
    }
};
