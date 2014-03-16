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
    bool isBalanced(TreeNode *root) {
      if (NULL == root) return true;
      int height_left = 0, height_right = 0;

      if (root->left == NULL) height_left = 0;
      else {
        if (!isBalanced(root->left)) return false;
        else height_left = root->left->val;
      }

      if (root->right == NULL) height_right = 0;
      else {
        if (!isBalanced(root->right)) return false;
        else height_right = root->right->val;
      }

      root->val = max(height_left, height_right) + 1;
      if (abs(height_left - height_right) <= 1) return true;
      else return false;
    }
};
