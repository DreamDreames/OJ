#include "stdafx.h"
#include <stdio.h>
#include <vector>
#include "gtest/gtest.h"


using namespace std;
/*
 Given a sorted array of integers, find the starting and ending position of a given target value.
 
 Your algorithm's runtime complexity must be in the order of O(log n).
 
 If the target is not found in the array, return [-1, -1].
 
 For example,
 Given [5, 7, 7, 8, 8, 10] and target value 8,
 return [3, 4].
*/

namespace LeetCode {
    class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> ans;
            return ans;
        }
    };
    
    class helper{
    public:
        void test(vector<int> nums, int target, vector<int> expected){
            Solution sln;
            auto ans = sln.searchRange(nums, target);
            ASSERT_EQ(expected[0], ans[0]);
            ASSERT_EQ(expected[1], ans[1]);
        }
    };
    TEST(SEARCH_for_a_RANGE, searchRange){
        helper h;
        h.test({5, 7, 7, 8, 8, 10}, 8, {3, 4});
    }
}