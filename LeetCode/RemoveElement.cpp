#include "stdafx.h"
#include <vector>

using namespace std;

namespace LeetCode
{
	class Solution{
	public:
		int removeElement(vector<int>&nums, int val){
			int index = 0, size = nums.size();
			if (size == 0)
				return 0;
			for (int i = 0; i < size; ++i){
				if (nums[i] != val)
					nums[index++] = nums[i];
			}
			return index;
		}
	};
	TEST_CLASS(RemoveElement)
	{
	public:

		TEST_METHOD(RemoveElementTest)
		{
			assert_helper({ 1, 2, 3 }, 2, { 1, 3 });
			assert_helper({ 1 }, 1, {});
			assert_helper({ 1 }, 2, { 1 });
			assert_helper({ 1, 2, 3 }, 1, { 2, 3 });
			assert_helper({ 1, 2, 3 }, 3, { 1, 2 });
			assert_helper({ 1, 2, 2, 3 }, 2, { 1, 3 });
			assert_helper({ 1, 1, 2, 3 }, 1, { 2, 3 });
			assert_helper({ 1, 2, 3, 3 }, 3, { 1, 2 });
			assert_helper({ 1, 2 }, 3, { 1, 2 });
			assert_helper({}, 3, {});
		}

	private:
		void assert_helper(vector<int>nums, int val, vector<int>expected){
			Solution sln;
			int ans = sln.removeElement(nums, val);
			for (int i = 0; i < ans; ++i){
				Assert::AreEqual(expected[i], nums[i]);
			}
		}
	};
}