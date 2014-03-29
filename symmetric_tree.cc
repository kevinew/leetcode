// 1A, cong~
// 比较根节点的左右子树是否对称。 将左子树进行（中左右）先序遍历，和右子树（中右左）进行相应对称的先序遍历，
// 且同时进行，一边遍历一边比较大小

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
    bool isSymmetric(TreeNode *root) {
        if (NULL == root) return true;
        return isSame(root->left, root->right);
    }
    
private:
    bool isSame(TreeNode *l, TreeNode *r) {
        if (NULL == l && NULL == r) return true;
        else if (NULL == l || NULL == r) return false;
        
        if (l->val != r->val) return false;
        
        bool outer = isSame(l->left, r->right);
        bool inner = isSame(l->right, r->left);
        return outer && inner;
    }
};
