#include "shared.h"
/*
 Given inorder and postorder traversal of a tree, construct the binary tree.
 
 Note:
 You may assume that duplicates do not exist in the tree.
*/
namespace ConstructBinaryTreeFromInorderAndPostorderTraversal{
    class Solution {
    public:
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            if(inorder.size() == 0)
                return NULL;
            
            map<int,int> record;
            for(int i = 0; i < inorder.size(); ++ i){
                record[inorder[i]] = i;
            }
            return buildTreeFrom(inorder, 0, (int)inorder.size() - 1, postorder, 0, (int)postorder.size() - 1, record);
        }
    private:
        TreeNode* buildTreeFrom(vector<int>& inorder, int instart, int inend, vector<int>& postorder, int posstart, int posend, map<int,int>& record){
            if(instart > inend || posstart > posend)
                return NULL;
            
            TreeNode* root = new TreeNode(postorder[posend]);
            int index = record[postorder[posend]];
            
            root->left = buildTreeFrom(inorder, instart, index - 1, postorder, posstart, posstart + index - instart - 1, record);
            root->right = buildTreeFrom(inorder, index + 1, inend, postorder, posstart + index - instart, posend - 1, record);
            return root;
            
        }
    };
}
