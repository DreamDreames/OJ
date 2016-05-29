#include "shared.h"
/*
 Two elements of a binary search tree (BST) are swapped by mistake.
 
 Recover the tree without changing its structure.
 
 Note:
 A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
*/
namespace RecoverBinarySearchTree{
    class Solution {
    public:
        void recoverTree(TreeNode* root) {
            if(root == NULL)
                return;
            if(root->left != NULL && root->val < root->left->val){
                binaryfy(root);
            }
        }
    private:
        TreeNode* binaryfy(TreeNode* root){
            if(root == NULL)
                return root;
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            if(left != NULL && root->val < left->val){
                root->left = left->left;
                root->right = left->right;
                left->left = root;
                left->right = right;
                binaryfy(root);
            }
            else if(right != NULL && root->val > right->val){
                root->left = right->left;
                root->right = right->right;
                right->left = left;
                right->right  = root;
                binaryfy(root);
            }
            
            return left;
        }
    };
}
