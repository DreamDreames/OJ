#include "shared.h"
/*
 Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 
 For example, given the array [2,3,-2,4],
 the contiguous subarray [2,3] has the largest product = 6.
 */
namespace MaximumProductSubarray {
    class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            if(nums.size() == 0)
                return 0;
            int ans = nums[0], currentMin = nums[0], currentMax = nums[0];
            for(int i = 1; i < nums.size(); ++ i){
                int temp = currentMax;
                currentMax = max(max(currentMax * nums[i], currentMin * nums[i]), nums[i]);
                currentMin = min(min(currentMin * nums[i], temp * nums[i]), nums[i]);
                if(currentMax > ans)
                    ans = currentMax;
            }
            return ans;
        }
    };
    class helper{
    public:
        void test(vector<int> nums, int expected){
            Solution sln;
            int actual = sln.maxProduct(nums);
            ASSERT_EQ(expected, actual);
        }
    };
    TEST(MaximumProductSubarray, maxProduct){
        helper h;
        h.test({1,0,-1,2,3,-5,-2}, 60);
        h.test({-1, -2, -9, -6}, 108);
    }
}
