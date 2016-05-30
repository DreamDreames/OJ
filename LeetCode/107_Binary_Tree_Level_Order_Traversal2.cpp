#include "shared.h"
#include <deque>
/*
 Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 
 For example:
 Given binary tree {3,9,20,#,#,15,7},
 3
 / \
 9  20
 /  \
 15   7
 return its bottom-up level order traversal as:
 [
 [15,7],
 [9,20],
 [3]
 ]
 */
namespace BinaryTreeLevelOrderTraversal2 {
    class Solution {
    public:
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            vector<vector<int>> ans;
            if(root != NULL)
                traverse(root, 0, ans);
            reverse(ans.begin(), ans.end());
            return ans;
        }
    private:
        void traverse(TreeNode* root, int level, vector<vector<int>>& ans){
            if(level == ans.size())
                ans.push_back({});
            ans[level].push_back(root->val);
            
            if(root->left != NULL)
                traverse(root->left, level + 1, ans);
            if(root->right != NULL)
                traverse(root->right, level + 1, ans);
        }
    };
}
