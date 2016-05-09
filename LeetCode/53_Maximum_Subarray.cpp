#include "shared.h"
#include <stdio.h>

/*
 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 
 For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 
 click to show more practice.
 
 More practice:
 If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

namespace MaximumSubarray {
    class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int currentSum = 0;
            int ans = nums[0];
            for(int i = 0; i < nums.size(); ++ i){
                if(nums[i] > 0){
                    if(currentSum >= 0)
                        currentSum += nums[i];
                    else
                        currentSum = nums[i];
                    
                    if(ans < currentSum)
                        ans = currentSum;
                }
                else{
                    currentSum += nums[i];
                    if(ans < nums[i])
                        ans = nums[i];
                }
            }
            return ans;
        }
    };
    class helper{
    public:
        void test(vector<int> nums, int expected){
            Solution sln;
            int actual = sln.maxSubArray(nums);
            ASSERT_EQ(expected, actual);
        }
    };
    TEST(MaximumSubarray, maxSubArray){
        helper h;
        h.test({-2,1,-3,4,-1,2,1,-5,4}, 6);
        h.test({4,-1,2,1}, 6);
        h.test({4}, 4);
        h.test({-1, -2, -3, 0}, 0);
    }
}
