// 写完后提交1次就AC了，太爽了，看来最朴实的分类讨论才是最稳当的玩法。

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
    int maxPathSum(TreeNode *root) {
        // Return max_path_sum.
        // In the end, root->val store the path_sum from some sub node to current node. In order to be used to add to parent node.
        
        if (NULL == root) return 0;
        if (NULL == root->left) {
            if (NULL == root->right) {
                return root->val;
            } else {
                int right_max_path_sum = maxPathSum(root->right);
                if (root->right->val > 0) {
                    root->val += root->right->val;
                }
                return right_max_path_sum > root->val ? right_max_path_sum : root->val;
            }
        } else {
            if (NULL == root->right) {
                int left_max_path_sum = maxPathSum(root->left);
                if (root->left->val > 0) {
                    root->val += root->left->val;
                }
                return left_max_path_sum > root->val ? left_max_path_sum : root->val;
            } else {
                int right_max_path_sum = maxPathSum(root->right);
                int left_max_path_sum = maxPathSum(root->left);
                int ret = root->val;
                if (root->left->val > 0) ret += root->left->val;
                if (root->right->val > 0) ret += root->right->val;
                ret = max(ret, left_max_path_sum);
                ret = max(ret, right_max_path_sum);
                
                int sub_path_sum = max(root->left->val, root->right->val);
                if (sub_path_sum > 0) root->val += sub_path_sum;
                return ret;
            }
        }
        
        
    }
};
