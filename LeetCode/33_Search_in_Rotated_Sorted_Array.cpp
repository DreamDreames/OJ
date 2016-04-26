

#include <stdio.h>
#include <vector>
#include "gtest/gtest.h"

using namespace std;

namespace LeetCode
{
    class Solution {
    public:
        int search(vector<int>& nums, int target) {
            _pivot = 0;
            _size = nums.size();
            for (int i = 0; i < _size - 1; ++i){
                if (nums[i] > nums[i + 1]){
                    _pivot = i + 1;
                    break;
                }
            }
            
            int mid = _size / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target)
                return search(nums, target, mid + 1, _pivot - 1);
            return search(nums, target, _pivot, mid - 1);
        }
    private:
        int search(const vector<int>&nums, const int target, int left, int right){
            //left = roundindex(left);
            //right = roundindex(right);
            int mid = (left + right) / 2;
            if (left > right){
                mid = (mid + _pivot) % _size;
            }
            if (mid < 0 || mid >= _size)
                return -1;
            if (nums[mid] == target)
                return mid;
            if (left == right)
                return -1;
            
            if (nums[mid] < target)
            {
                if (mid + 1 == _pivot)
                    return -1;
                return search(nums, target, mid + 1, target);
            }
            
            if (mid == _pivot)
                return -1;
            return search(nums, target, left, mid - 1);
        }
        int roundindex(int index){
            if (index >= _size)
                index %= _size;
            if (index < 0)
                index = (index + _size) % _size;
            return index;
        }
    private:
        int _pivot;
        int _size;
    };
    
    class testhelper{
    public:
        void static helper(vector<int> nums, int target, int expected){
            Solution sln;
            int ans = sln.search(nums, target);
            ASSERT_EQ(expected, ans);
        }
    };
    TEST(SearchInRotatedSortedArray, Search)
    {
        testhelper helper;
        ASSERT_FALSE(true);
        helper.helper({ 4, 5, 6, 7, 0, 1, 2 }, 4, 0);
        helper.helper({ 4, 5, 6, 7, 0, 1, 2 }, 5, 1);
        helper.helper({ 4, 5, 6, 7, 0, 1, 2 }, 7, 3);
        helper.helper({ 4, 5, 6, 7, 0, 1, 2 }, 0, 4);
        helper.helper({ 4, 5, 6, 7, 0, 1, 2 }, 2, 6);
        helper.helper({ 0, 1, 2, 3, 4, 5, 6, 7 }, 0, 0);
        helper.helper({ 0, 1, 2, 3, 4, 5, 6, 7 }, 1, 1);
        helper.helper({ 0, 1, 2, 3, 4, 5, 6, 7 }, 7, 7);
        helper.helper({ 0 }, 0, 0);
        helper.helper({ 0, 1 }, 0, 0);
        helper.helper({ 0, 1 }, 1, 1);
        helper.helper({ 1, 0 }, 1, 0);
        helper.helper({ 1, 0 }, 0, 1);
        helper.helper({ 1, 3 }, 4, -1);
        helper.helper({ 1, 3 }, 0, -1);
        helper.helper({ 1 }, 0, -1);
        helper.helper({ 3, 1 }, 0, -1);
        helper.helper({ 3, 1 }, 4, -1);
        helper.helper({ 4, 5, 6, 7, 0, 1, 2 }, 9, -1);
        //helper.helper({ 3, 5, 1 }, 2, -1);
    };
}

/*
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 
 You are given a target value to search. If found in the array return its index, otherwise return -1.
 
 You may assume no duplicate exists in the array.
 */