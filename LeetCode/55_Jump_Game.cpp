#include <stdio.h>
#include <vector>
#include "gtest/gtest.h"

using namespace std;

/*
 Given an array of non-negative integers, you are initially positioned at the first index of the array.
 
 Each element in the array represents your maximum jump length at that position.
 
 Determine if you are able to reach the last index.
 
 For example:
 A = [2,3,1,1,4], return true.
 
 A = [3,2,1,0,4], return false.
*/

namespace JumpGame {
    class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int max = nums[0];
            int end = (int)nums.size() - 1;
            for(int i = 1; i <= end && max <= end; ++ i){
                if(i > max)
                    return false;
                if(nums[i] + i > max){
                    max = nums[i] + i;
                }
            }
            return true;
        }
    };
    class helper{
    public:
        void test(vector<int> nums, bool expected){
            Solution sln;
            auto actual = sln.canJump(nums);
            ASSERT_EQ(expected, actual);
        }
    };
    TEST(JumpGame, canJump){
        helper h;
        h.test({2, 0, 0}, true);
        h.test({2, 3, 1, 1, 4}, true);
        h.test({3, 2, 1, 0, 4}, false);
        h.test({2}, true);
        h.test({2, 0}, true);
        h.test({2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6}, false);
    }
}
