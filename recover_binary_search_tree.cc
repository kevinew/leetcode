// In-order to travel the tree. Find first node which is bigger then the just
// right one; second node which is smaller then the left one; exchage the first
// and the second.

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
    void recoverTree(TreeNode *root) {                                              

      visitTree(root);                                                              
      int tmp;                                                                      
      tmp = first_abnormal->val;                                                    
      first_abnormal->val = second_abnormal->val;                                   
      second_abnormal->val = tmp;                                                
    }                                                                               
  private:                                                                          
    TreeNode *first_abnormal, *second_abnormal;                                     
    TreeNode *node1, *node2;                                                        

    void visitTree(TreeNode *node) {                                                
      if (NULL == node) return;                                                     
      visitTree(node->left);                                                        
      node1 = node2;                                                                
      node2 = node;                                                                 
      if (NULL != node1) {                                                          
        if (node1->val > node2->val) {                                              
          if (NULL == first_abnormal) {
            first_abnormal = node1;     
            second_abnormal = node2;     
          } else second_abnormal = node2;                                             
        }                                                                           
      }                                                                          
      visitTree(node->right);                                                    
    }                                                                            
};
