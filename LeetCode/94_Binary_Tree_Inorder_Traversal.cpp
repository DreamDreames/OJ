#include "shared.h"
/*
 Given a binary tree, return the inorder traversal of its nodes' values.
 
 For example:
 Given binary tree {1,#,2,3},
 1
 \
 2
 /
 3
 return [1,3,2].
 
 Note: Recursive solution is trivial, could you do it iteratively?
 
 confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ
*/
namespace BinaryTreeInorderTraversal {
     struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };

    class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> ans;
            if(root == NULL)
                return ans;
            stack<TreeNode*> stk;
            stk.push(root);
            while(!stk.empty()){
                TreeNode* current = stk.top();
                if(current->left != NULL){
                    stk.push(current->left);
                    current->left = NULL;
                }
                else{
                    stk.pop();
                    ans.push_back(current->val);
                    if(current->right != NULL)
                        stk.push(current->right);
                }
            }
            return ans;
        }
    };
}
