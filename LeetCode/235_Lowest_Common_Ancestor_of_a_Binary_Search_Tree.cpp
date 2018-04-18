#include "shared.h"

namespace LowestCommonAncestorOfABinarySearchTree {
    /**
     * Definition for a binary tree node.
     * struct TreeNode {
     *     int val;
     *     TreeNode *left;
     *     TreeNode *right;
     *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     * };
     */
    class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(p == root || q == root)
                return root;
            
            int low = p->val, high = q->val;
            if(low > high)
                swap(low, high);
            
            if(root->val > low && root->val > high)
                return lowestCommonAncestor(root->left, p, q);
            else if(root->val < low && root->val < high)
                return lowestCommonAncestor(root->right, p, q);
            
            return root;
        }
    }; 
}
