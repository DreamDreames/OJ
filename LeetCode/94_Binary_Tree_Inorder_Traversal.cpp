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
        vector<int> inorderTraversal(TreeNode* root){
            vector<int> ans;
            traverse(root, ans);
            return ans;
        }
    private:
        void traverse(TreeNode* node, vector<int>& ans){
            if(node == NULL)
                return;
            if(node != NULL){
                traverse(node->left, ans);
                ans.push_back(node->val);
                traverse(node->right, ans);
            }
        }
        vector<int> inorderTraversal1(TreeNode* root) {
            vector<int> ans;
            if(root == NULL)
                return ans;
            stack<TreeNode*> stk;
            
            while(root!=NULL || !stk.empty()){
                while(root!=NULL){
                    stk.push(root);
                    root = root->left;
                }
                root = stk.top();
                stk.pop();
                ans.push_back(root->val);
                root = root->right;
            }
            return ans;
        }
    };
    TEST(BinaryTreeInorderTraversal, inorderTraversal){
        TreeNode* root = new TreeNode(1);
        TreeNode* node1 = new TreeNode(2);
        TreeNode* node2 = new TreeNode(3);
        node1->left = node2;
        root->right = node1;
        Solution sln;
        auto actual = sln.inorderTraversal(root);
        vector<int> expected{1,3,2};
        ASSERT_EQ(expected, actual);
    }
}
