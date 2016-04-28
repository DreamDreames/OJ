#include <stdio.h>
#include <vector>
#include "gtest/gtest.h"

using namespace std;

/*
 Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 
 You may assume no duplicates in the array.
 
 Here are few examples.
 [1,3,5,6], 5 → 2
 [1,3,5,6], 2 → 1
 [1,3,5,6], 7 → 4
 [1,3,5,6], 0 → 0
*/

namespace LeetCode {
    class Solution {
    private:
        int _size;
    public:
        int searchInsert(vector<int>& nums, int target) {
            _size = (int)nums.size();
            return search(nums, 0, _size - 1, target);
        }
    private:
        int search(vector<int>&nums, int low, int high, int target){
            if(low > high){
                if(low > _size)
                    return _size;
                if(high < 0)
                    return 0;
                if(nums[high] < target)
                    return high + 1;
                if(nums[low] > target)
                    return low - 1;
            }
            int mid = (low + high) / 2;
            if(nums[mid] == target)
                return mid;
            
            if(nums[mid] < target)
                return search(nums, mid + 1, high, target);
            
            return search(nums, low, mid - 1, target);
        }
    };
    
    class helper{
    public:
        void test(vector<int>nums, int target, int expected){
            Solution sln;
            int actual = sln.searchInsert(nums, target);
            ASSERT_EQ(expected, actual);
        }
    };
    TEST(SearchInsertPosition, searchInsert){
        helper h;
        h.test({1, 3, 5, 6}, 5, 2);
        h.test({1, 3, 5, 6}, 2, 1);
        h.test({1, 3, 5, 6}, 7, 4);
        h.test({1, 3, 5, 6}, 0, 0);
    }
}