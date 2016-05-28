#include "shared.h"

namespace MaximumDepthOfBinaryTree {
    class Solution {
    public:
        int maxDepth(TreeNode* root) {
            int ans = 0;
            if(root == NULL)
                return ans;
            
            int left = maxDepth(root->left) + 1;
            int right = maxDepth(root->right) + 1;
            return max(left, right);
        }
    };
}
