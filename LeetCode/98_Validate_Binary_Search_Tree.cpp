#include "shared.h"
/*
 Given a binary tree, determine if it is a valid binary search tree (BST).
 
 Assume a BST is defined as follows:
 
 The left subtree of a node contains only nodes with keys less than the node's key.
 The right subtree of a node contains only nodes with keys greater than the node's key.
 Both the left and right subtrees must also be binary search trees.
*/
namespace ValidateBinarySearchTree {

     struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };

    class Solution {
    public:
        bool isValidBST(TreeNode* root){
            bool inited = false;
            int prev = 0;
            return inorderTraverse(root, prev, inited);
        }
    public:
        bool inorderTraverse(TreeNode* root, int& prev, bool& inited){
            if(root == NULL)
                return true;
            if(!inorderTraverse(root->left, prev, inited))
                return false;
            if(!inited){
                inited = true;
                prev = root->val;
            }
            else{
                if(root->val <= prev)
                    return false;
                prev = root->val;
            }
            return inorderTraverse(root->right, prev, inited);
        }
    };
}
