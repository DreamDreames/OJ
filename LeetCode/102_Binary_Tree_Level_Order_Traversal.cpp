#include "shared.h"
/*
 Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 
 For example:
 Given binary tree {3,9,20,#,#,15,7},
 3
 / \
 9  20
 /  \
 15   7
 return its level order traversal as:
 [
 [3],
 [9,20],
 [15,7]
 ]
 */
namespace BinaryTreeLevelOrderTraversal{

    class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root){
            vector<vector<int>> ans;
            traverse(root, 0, ans);
            return ans;
        }
    private:
        void traverse(TreeNode* root, int level, vector<vector<int>>& ans){
            if(root == NULL)
                return;
                
            if(level == ans.size())
                ans.push_back({});
            
            ans[level].push_back(root->val);
            traverse(root->left, level + 1, ans);
            traverse(root->right, level + 1, ans);
        }
        vector<vector<int>> levelOrder1(TreeNode* root) {
            vector<vector<int>> ans;
            if(root == NULL)
                return ans;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                vector<int> result;
                queue<TreeNode*> temp;
                while(!q.empty()){
                    auto node = q.front();
                    q.pop();
                    result.push_back(node->val);
                    if(node->left != NULL)
                        temp.push(node->left);
                    if(node->right != NULL)
                        temp.push(node->right);
                }
                ans.push_back(result);
                q = temp;
            }
            return ans;
        }
    };
}
