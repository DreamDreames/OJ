#include "stdafx.h"
#include <vector>

using namespace std;

namespace RemoveDuplicates {

	class Solution{
	public:
		int removeDuplicates(vector<int>& nums){
			int size = nums.size();
			if (size == 0)
				return 0;

			int current = nums[0];
			int index = 1;
			vector<int>ans = { current };
			for (int i = 1; i < size; ++i){
				if (nums[i] != current){
					current = nums[i];
					nums[index++] = current;
				}
			}
			return index;
		}
	};

	TEST_CLASS(RemoveDuplicatesFromSortedArray)
	{
	public:
		TEST_METHOD(RemoveDuplicatesFromSortedArrayTest){
			assert_helper({ 1, 1, 2 }, { 1, 2 });
			assert_helper({ 1 }, { 1 });
			assert_helper({}, {});
			assert_helper({ 1, 1, 2, 2 }, { 1, 2 });
			assert_helper({ 1, 1, 2, 3, 3 }, { 1, 2, 3 });
		}
	private:
		void assert_helper(vector<int> nums, vector<int>expected){
			Solution sln;
			int count = sln.removeDuplicates(nums);
			while ((--count) >= 0){
				Assert::AreEqual(expected[count], nums[count]);
			}
		}
	};
}