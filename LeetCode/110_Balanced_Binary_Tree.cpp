#include "shared.h"
/*
 Given a binary tree, determine if it is height-balanced.
 
 For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 */
namespace BalancedBinaryTree{
    class Solution {
    public:
        bool isBalanced(TreeNode* root) {
            return checkBalance(root) >= 0;
        }
    private:
        int checkBalance(TreeNode* root){
            if(root == NULL)
                return 0;
            int left = checkBalance(root->left);
            if(left < 0)
                return -1;
            int right = checkBalance(root->right);
            if(right < 0)
                return -1;
            if(left - right > 1 || right - left > 1)
                return -1;
            return max(left, right) + 1;
            
        }
    };
}
