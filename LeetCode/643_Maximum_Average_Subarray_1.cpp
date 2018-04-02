#include "shared.h"
/*
 Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.
 
 Example 1:
 Input: [1,12,-5,-6,50,3], k = 4
 Output: 12.75
 Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
 Note:
 1 <= k <= n <= 30,000.
 Elements of the given array will be in the range [-10,000, 10,000].
 */
namespace MaximumAverageSubarray1 {
    class Solution {
    public:
        double findMaxAverage(vector<int>& nums, int k) {
            double avg = 0.0, cur = 0.0;
            int i = 0, head = 0;
            while(i < k) {
                avg += nums[i ++] * 1.0 / k;
            }
            
            cur = avg;
            
            while(i < nums.size()) {
                cur -= nums[head ++] * 1.0 / k;
                cur += nums[i ++] * 1.0 / k;
                if(cur > avg)
                    avg = cur;
            }
            
            return avg;
        }
    };
    
    
    TEST(MaximumAverageSubarray1, findMaxAverage) {
        Solution sln;
        vector<int> nums = {1,12,-5,-6,50,3};
        auto average = sln.findMaxAverage(nums, 4);
        ASSERT_EQ(12.75, average);
    }
}
