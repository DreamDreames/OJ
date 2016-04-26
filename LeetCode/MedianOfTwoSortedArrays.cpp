#include "stdafx.h"
#include <vector>
using namespace std;

#define _test

namespace LeetCode{
#ifdef _test
	class SolutionMedianOfTwoSortedArrays {
#elif
	class Solution{
#endif
	public:
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			int n = 0;
			int total = nums1.size() + nums2.size();
			n = total / 2;
			if (total % 2 == 0){
				int temp1 = findNthLarger(nums1, nums2, n);
				int temp2 = findNthLarger(nums1, nums2, n + 1);
				return (temp1 + temp2) * 1.0 / 2;
			}
			return findNthLarger(nums1, nums2, n + 1);
		}
	private:
		int findNthLarger(vector<int>& nums1, vector<int>&nums2, int count){
			int temp = -999999999;
			int n = 0;
			while (n++ < count){
				temp = findLargerThan(nums1, nums2, temp);
			}
			current1 = 0;
			current2 = 0;
			return temp;
		}
		int findLargerThan(vector<int>& nums1, vector<int>& nums2, int target){
			int t1 = findSingleLarger(nums1, current1, nums1.size() - 1, target);
			int t2 = findSingleLarger(nums2, current2, nums2.size() - 1, target);
			bool bfirst = true;
			if (t1 < 0){
				bfirst = false;
			}
			else if (t2 < 0){
				bfirst = true;
			}
			else if (nums1[t1] <= nums2[t2]){
				bfirst = true;
			}
			else
				bfirst = false;
			if (bfirst){
				current1 = t1 + 1;
				return nums1[t1];
			}
			else {
				current2 = t2 + 1;
				return nums2[t2];
			}
		}
		int findSingleLarger(vector<int>&nums, int start, int end, int target){
			if (start > end || nums[end] < target)
				return -1;
			int middle = (start + end) / 2;
			if (middle == 0 && nums[middle] >= target)
				return middle;

			if (nums[middle - 1] <= target && nums[middle] >= target){
				int temp = findSingleLarger(nums, start, middle - 1, target);
				if (temp < 0)
					return middle;
				return temp;
			}
			if (nums[middle] < target){
				return findSingleLarger(nums, middle + 1, end, target);
			}
			if (nums[middle] > target){
				return findSingleLarger(nums, start, middle - 1, target);
			}
			return -1;
		}
	private:
		int current1 = 0;
		int current2 = 0;
	};

	TEST_CLASS(MedianOfTwoSortedArrays)
	{
	public:
		TEST_METHOD(MedianOfTwoSortedArraysTest)
		{
			assert_helper({ 1, 2, 3 }, { 4, 5, 6 }, 3.5);
			assert_helper({ 1, 3, 5, 7, 9 }, { 2, 4, 6 }, 4.5);
			assert_helper({ 1, 3, 5, 7 }, { 2, 4, 6 }, 4);
			assert_helper({ 1 }, { 2 }, 1.5);
			assert_helper({ 1, 1, 3, 3 }, { 1, 1, 3, 3 }, 2);
		}
	private:
		void assert_helper(vector<int> nums1, vector<int> nums2, double expected){
			SolutionMedianOfTwoSortedArrays sln;
			double ans = sln.findMedianSortedArrays(nums1, nums2);
			Assert::AreEqual(expected, ans);
		}
	};
}

/*
There are two sorted arrays nums1 and nums2 of size m and n respectively. 
Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).
*/