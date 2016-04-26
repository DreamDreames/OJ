#include "stdafx.h"

namespace LeetCode
{
	int cmp(const void* l, const void* r){
		return *(int*)l - *(int*)r;
	}
	class Solution {
	public:
		void nextPermutation(vector<int>& nums) {
			int count = nums.size(), i, j;
			if (count < 2)
				return;
			int maxIndex = count - 1;
			int max = nums[maxIndex];
			for (i = count - 2; i >= 0; --i){
				if (nums[i] > max){
					max = nums[i];
					maxIndex = i;
				}
				if (nums[i] < max){
					int swapIndex = maxIndex;
					for (j = i + 1; j < count; ++j){
						if (nums[j] > nums[i] && nums[j] < nums[swapIndex]){
							swapIndex = j;
						}
					}
					std::swap(nums[i], nums[swapIndex]);
					sort(nums, i + 1, count - 1);
					return;
				}
			}
			for (i = 0, j = count - 1; i < j; ++ i, --j){
				std::swap(nums[i], nums[j]);
			}
		}
	private:
		void sort(vector<int>&nums, int start, int end){
			qsort(&nums[start], end - start + 1, sizeof(int), cmp);
		}
	};

	TEST_CLASS(NextPermutation)
	{
	public:
		TEST_METHOD(NextPermutationTest)
		{
			helper({ 1, 2, 3 }, { 1, 3, 2 });
			helper({ 3, 2, 1 }, { 1, 2, 3 });
			helper({ 1, 1, 5 }, { 1, 5, 1 });
			helper({ 1, 1 }, { 1, 1 });
			helper({ 3, 2, 2 }, { 2, 2, 3 });
			helper({ 3, 3, 2, 2 }, { 2, 2, 3, 3 });
			helper({ 1 }, { 1 });
			helper({ 1, 3, 2 }, { 2, 1, 3 });
			helper({ 4, 2, 0, 2, 3, 2, 0 }, { 4, 2, 0, 3, 0, 2, 2 });
		}
	private:
		void helper(vector<int> source, const vector<int>& expected){
			Solution sln;
			sln.nextPermutation(source);
			auto count = source.size();
			Assert::AreEqual(count, expected.size());
			for (int i = 0; i < count; ++i){
				Assert::AreEqual(expected[i], source[i]);
			}
		}
	};
}









/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 ¡ú 1,3,2
3,2,1 ¡ú 1,2,3
1,1,5 ¡ú 1,5,1
*/