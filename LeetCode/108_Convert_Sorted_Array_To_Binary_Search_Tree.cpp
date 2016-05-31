#include "shared.h"
/*
 Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/
namespace ConvertSortedArrayToBinarySearchTree{
    class Solution {
    public:
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            return convertToBinaryTree(nums, 0, (int)nums.size() - 1);
        }
    private:
        TreeNode* convertToBinaryTree(vector<int>& nums, int start, int end){
            if(start > end)
                return NULL;
            int middle = (start + end) / 2;
            TreeNode* root = new TreeNode(nums[middle]);
            root->left = convertToBinaryTree(nums, start, middle - 1);
            root->right = convertToBinaryTree(nums, middle + 1, end);
            return root;
        }
    };
}
