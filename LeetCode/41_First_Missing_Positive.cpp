#include <stdio.h>
#include <vector>
#include "gtest/gtest.h"

using namespace std;

/*
 Given an unsorted integer array, find the first missing positive integer.
 
 For example,
 Given [1,2,0] return 3,
 and [3,4,-1,1] return 2.
 
 Your algorithm should run in O(n) time and uses constant space.
*/

namespace LeetCode {
    class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            int size = (int)nums.size(), i = 0;
            while( i < size){
                if(nums[i] <= 0 || nums[i] > size || nums[i] == i + 1 || nums[i] == nums[nums[i] - 1]){
                    i ++;
                    continue;
                }
                
                swap(nums[i], nums[nums[i] - 1]);
            }

            for(i = 0; i < size; ++ i){
                if(nums[i] != i + 1)
                    return i + 1;
            }
            return size + 1;
        }
    };
    class helper{
    public:
        void test(vector<int> nums, int expected){
            Solution sln;
            int actual = sln.firstMissingPositive(nums);
            ASSERT_EQ(expected, actual);
        }
    };
    TEST(FirstMissingPositive, firstMissingPositive){
        helper h;
        h.test({1, 2, 0}, 3);
        h.test({3, 4, -1, 1}, 2);
        h.test({1, 1}, 2);
        h.test({1}, 2);
    }
}
