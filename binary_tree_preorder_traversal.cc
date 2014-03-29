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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans, v_left, v_right;
        
        if (NULL == root) return ans;
        ans.push_back(root->val);
        
        v_left = preorderTraversal(root->left);
        v_right = preorderTraversal(root->right);
        ans.insert(ans.end(), v_left.begin(), v_left.end());
        ans.insert(ans.end(), v_right.begin(), v_right.end());
        return ans;
    }
};
