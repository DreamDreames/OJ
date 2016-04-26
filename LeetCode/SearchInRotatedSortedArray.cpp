#include "stdafx.h"

namespace LeetCode
{
	class Solution{
	public:
		int search(vector<int>& nums, int target) {
			int size = nums.size();
			return find(0, size - 1, target, nums);
		}
	private: 
		int find(int low, int high, int target, vector<int>& nums){
			if (low > high)
				return -1;
			if (nums[low] < nums[high] && target < nums[low] && target > nums[high]){
				return -1;
			}
			int pivot = (low + high) / 2;
			if (nums[pivot] == target)
				return pivot;
			int temp = find(low, pivot - 1, target, nums);
			if (temp >= 0)
				return temp;
			return find(pivot + 1, high, target, nums);
		}
	};


	TEST_CLASS(SearchInRotatedSortedArray)
	{
	public:
		TEST_METHOD(SearchInRotatedSortedArrayTest)
		{
			//Assert::Fail();
			helper({ 4, 5, 6, 7, 0, 1, 2 }, 4, 0);
			helper({ 4, 5, 6, 7, 0, 1, 2 }, 5, 1);
			helper({ 4, 5, 6, 7, 0, 1, 2 }, 7, 3);
			helper({ 4, 5, 6, 7, 0, 1, 2 }, 0, 4);
			helper({ 4, 5, 6, 7, 0, 1, 2 }, 2, 6);
			helper({ 0, 1, 2, 3, 4, 5, 6, 7 }, 0, 0);
			helper({ 0, 1, 2, 3, 4, 5, 6, 7 }, 1, 1);
			helper({ 0, 1, 2, 3, 4, 5, 6, 7 }, 7, 7);
			helper({ 0 }, 0, 0);
			helper({ 0, 1 }, 0, 0);
			helper({ 0, 1 }, 1, 1);
			helper({ 1, 0 }, 1, 0);
			helper({ 1, 0 }, 0, 1);
			helper({ 1, 3 }, 4, -1);
			helper({ 1, 3 }, 0, -1);
			helper({ 1 }, 0, -1);
			helper({ 3, 1 }, 0, -1);
			helper({ 3, 1 }, 4, -1);
			helper({ 4, 5, 6, 7, 0, 1, 2 }, 9, -1);
			helper({ 3, 5, 1 }, 2, -1);
		}
	private:
		void helper(vector<int> nums, int target, int expected){
			Solution sln;
			int ans = sln.search(nums, target);
			Assert::AreEqual(expected, ans);
		}
	};
}









/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/