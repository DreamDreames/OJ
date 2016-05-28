#include "shared.h"
/*
 Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 
 For example, this binary tree is symmetric:
 
 1
 / \
 2   2
 / \ / \
 3  4 4  3
 But the following is not:
 1
 / \
 2   2
 \   \
 3    3
 Note:
 Bonus points if you could solve it both recursively and iteratively.
*/
namespace SymmetricTree{
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    
    class Solution {
    public:
        bool isSymmetric(TreeNode* root) {
            return traverse(root, root);
        }
    private:
        bool traverse(TreeNode* p, TreeNode* q){
            if(p == NULL && q == NULL)
                return true;
            if(p == NULL || q == NULL)
                return false;
            if(p->val != q->val)
                return false;
            
            if(!traverse(p->left, q->right))
                return false;
            
            return traverse(p->right, q->left);
        }

    };
}
