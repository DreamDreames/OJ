#include "shared.h"

/*
 Given a binary tree, flatten it to a linked list in-place.
 
 For example,
 Given
 
 1
 / \
 2   5
 / \   \
 3   4   6
 The flattened tree should look like:
 1
 \
 2
 \
 3
 \
 4
 \
 5
 \
 6
 */

namespace FlattenBinaryTreeToLinkedList {
    class Solution {
    public:
        void flatten(TreeNode* root) {
            root = convert(root);
        }
    private:
        TreeNode* convert(TreeNode* root){
            if(root == NULL)
                return NULL;
            TreeNode* left = convert(root->left);
            TreeNode* right = convert(root->right);
            root->left = NULL;
            root->right = left;
            while(left != NULL && left->right != NULL){
                left = left->right;
            }
            if(left == NULL)
                root->right = right;
            else
                left->right = right;
            return root;
        }
    };
}
