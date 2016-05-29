#include "shared.h"
/*
 Given preorder and inorder traversal of a tree, construct the binary tree.
 
 Note:
 You may assume that duplicates do not exist in the tree.
*/
namespace ConstructBinaryTreeFromPreorderAndInorderTraversal{
    class Solution {
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            if(preorder.size() == 0)
                return NULL;
            
            map<int,int> record;
            for(int i = 0; i < inorder.size(); ++ i){
                record[inorder[i]] = i;
            }
            
            return buildTreeFrom(preorder, 0, (int)preorder.size() - 1, inorder, 0, (int)inorder.size() - 1, record);
        }
    private:
        TreeNode* buildTreeFrom(vector<int>& preorder, int prestart, int preend, vector<int>& inorder, int instart, int inend, map<int, int>& record){
            if(prestart > preend || instart > inend)
                return NULL;
            TreeNode *root = new TreeNode(preorder[prestart]);
            
            int index = record[preorder[prestart]];
            
            root->left = buildTreeFrom(preorder, prestart + 1, prestart + index - instart, inorder, instart, index - 1, record);
            root->right = buildTreeFrom(preorder, prestart + index - instart + 1, preend, inorder, index + 1, inend, record);
            return root;
            
        }

    };
}
