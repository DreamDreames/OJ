#include "shared.h"
/*
 Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 
 An example is the root-to-leaf path 1->2->3 which represents the number 123.
 
 Find the total sum of all root-to-leaf numbers.
 
 For example,
 
 1
 / \
 2   3
 The root-to-leaf path 1->2 represents the number 12.
 The root-to-leaf path 1->3 represents the number 13.
 
 Return the sum = 12 + 13 = 25.
 */
namespace SumRootToLeafNumbers {
    class Solution {
    public:
        int sumNumbers(TreeNode* root) {
            if(root == NULL)
                return 0;
            
            long long ans = 0;
            numbers(root, 0, ans);
            if(ans > INT_MAX)
                return INT_MAX;
            return (int)ans;
        }
    private:
        void numbers(TreeNode* root, int currentValue, long long & ans){
            if(root == NULL)
                return;
            
            currentValue = currentValue* 10 + root->val;
            
            if(root->left == NULL && root->right == NULL)
                ans += currentValue;
            
            if(root->left)
                numbers(root->left, currentValue, ans);
            if(root->right)
                numbers(root->right, currentValue, ans);
        }
    };
    
    class helper{
    public:
        TreeNode* buildTreeFrom(vector<int>& arr, int start){
            if(start >= arr.size() || arr[start] == -1)
                return NULL;
            TreeNode* root = new TreeNode(arr[start]);
            root->left = buildTreeFrom(arr, (start + 1) * 2 - 1);
            root->right = buildTreeFrom(arr, (start + 1) * 2 );
            return root;
        }
        void test(vector<int> arr, int expected){
            TreeNode* root = buildTreeFrom(arr, 0);
            Solution sln;
            int actual = sln.sumNumbers(root);
            ASSERT_EQ(expected, actual);
        }
    };
    
    TEST(SumRootToLeafNumbers, sumNumbers){
        helper h;
//        h.test({2,1,-1,4,-1,7,-1,4,-1,8,-1,3,-1,6,-1,4,-1,7}, 2147483647);
        h.test({1,2,3}, 25);
        h.test({0, 1}, 1);
    }
}
