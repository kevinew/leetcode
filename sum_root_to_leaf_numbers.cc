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
      if (NULL == root) return 0;
      int l_val = sumNumbers(root->left->val);
      int r_val = sumNumbers(root->right->val);
      int val = l_val + r_val;
      if (val) return root->val * 10 + val;
      else return root->val;
    }   
};
