#include "shared.h"
/*
 Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
 
 For example,
 Given n = 3, your program should return all 5 unique BST's shown below.
 
 1         3     3      2      1
 \       /     /      / \      \
 3     2     1      1   3      2
 /     /       \                 \
 2     1         2                 3
*/
namespace UniqueBinarySearchTree2{

     struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };

    class Solution {
    public:
        vector<TreeNode*> generateTrees(int n) {
            if(n <= 0)
                return {};
            return subTree(1, n);
        }
    private:
        vector<TreeNode*> subTree(int start, int end){
            vector<TreeNode*> ans;
            if(start > end){
                ans.push_back(NULL);
                return ans;
            }
            
            for(int i = start; i <= end; ++ i){
                auto leftTree = subTree(start, i - 1);
                auto rightTree = subTree(i + 1, end);
                for(int j = 0; j < leftTree.size(); ++ j){
                    for(int k = 0; k < rightTree.size(); ++ k){
                        TreeNode* root = new TreeNode(i);
                        root->left = leftTree[j];
                        root->right = rightTree[k];
                        ans.push_back(root);
                    }
                }
                
            }
            return ans;
        }
    };
}
