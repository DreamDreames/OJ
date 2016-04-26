#include "stdafx.h"
#include <vector>
#include <cassert>

using namespace std;

namespace LeetCode
{
	class Solution{
	private:
		int min(int l, int r) {
			return l < r ? l : r;
		}
	public:
		int maxArea(vector<int>&height){
			int count = height.size();
			int curMax = 0;
			for (int i = 0, j = count - 1; i <= j;){
				int temp = (j - i) * min(height[j], height[i]);
				if (temp > curMax)
					curMax = temp;
				if (height[i] < height[j])
					i++;
				else
					j--;
			}
			return curMax;
		}
	};

	TEST_CLASS(ContainerWithMostWaterUnitTest)
	{
	public:
		TEST_METHOD(ContainerWithMostWaterTest)
		{
			assert_test({ 1, 2 }, 1);
			assert_test({ 1, 2, 3 }, 2);
			assert_test({ 1, 2, 4, 3 }, 4);
			assert_test({ 0, 2 }, 0);
			assert_test({ 2, 3, 10, 5, 7, 8, 9 }, 36);
			assert_test({ 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 }, 25);
		}
	private:
		void assert_test(vector<int> heights, int expected)
		{
			Solution sln;
			int ans = sln.maxArea(heights);
			printf("Expected: %d, Acutal: %d\r\n", expected, ans);
			assert(ans == expected);
		}
	};
}

/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that two endpoints of line i is at (i, ai) and (i, 0).
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container
*/
