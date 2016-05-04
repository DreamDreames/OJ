#include <stdio.h>
#include <vector>
#include "gtest/gtest.h"

using namespace std;

/*
 Given an array of non-negative integers, you are initially positioned at the first index of the array.
 
 Each element in the array represents your maximum jump length at that position.
 
 Your goal is to reach the last index in the minimum number of jumps.
 
 For example:
 Given array A = [2,3,1,1,4]
 
 The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 
 Note:
 You can assume that you can always reach the last index.
*/

namespace JumpGame2 {
    class Solution {
    public:
        int jump(vector<int>& nums) {
            if(nums.size() <= 1)
                return 0;
            int i, max = nums[0], pivot = max;
            int end = (int)nums.size() - 1;
            if(max >= end)
                return 1;
            int steps = 0;
            for(i = 1; i < end ;  ++ i){
                if(i == pivot){
                    steps ++;
                    pivot = max;
                }
                if(nums[i] + i > max){
                    max = nums[i] + i;
                    if(max >= end){
                        steps ++;
                        break;
                    }
                }
            }
            if(i < pivot)
                steps ++;
            return steps;
        }
    };
    class helper{
    public:
        void test(vector<int> nums, int expected){
            Solution sln;
            auto actual = sln.jump(nums);
            ASSERT_EQ(expected, actual);
        }
    };
    TEST(JumpGame2, jump){
        helper h;
        h.test({2, 3, 1, 1, 4}, 2);
        h.test({2}, 0);
        h.test({2, 0}, 1);
        h.test({1, 2}, 1);
        h.test({1, 2, 3}, 2);
    }
}
