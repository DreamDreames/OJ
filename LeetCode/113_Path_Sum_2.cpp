#include "shared.h"
/*
 Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 
 For example:
 Given the below binary tree and sum = 22,
 5
 / \
 4   8
 /   / \
 11  13  4
 /  \    / \
 7    2  5   1
 return
 [
 [5,4,11,2],
 [5,8,4,5]
 ]

 */
namespace PathSum2 {
    class Solution {
    public:
        vector<vector<int>> pathSum(TreeNode* root, int sum) {
            vector<vector<int>> ans;
            vector<int> path;
            findPath(root, sum, path, ans);
            return ans;
        }
    private:
        void findPath(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& ans){
            if(root == NULL)
                return;
            
            path.push_back(root->val);
            int remaining = sum - root->val;
            if(root->left == NULL && root->right == NULL && remaining == 0){
                ans.push_back(path);
                path.pop_back();
                return;
            }
            findPath(root->left, sum - root->val, path, ans);
            findPath(root->right, sum - root->val, path, ans);
            path.pop_back();
        }
    };
}
