#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;


namespace LeetCode
{
	class Solution {
	public:
		int threeSumClosest(vector<int> &num, int target) {
			int count = num.size(), ans = 999999999;
			if (count == 0) return 0;
			int max = -99999999;
			for (auto n : num){
				if (max < n)
					max = n;
			}
			if (max > target)
				sort(num.begin(), num.end());
			else
				sort(num.rbegin(), num.rend());

			for (int i = 0; i < count - 2; ++i){
				if (i > 0 && num[i] == num[i - 1])
					continue;

				int temp = num[i] + twoSumClosest(num, i + 1, target - num[i]);
				if (abs(temp - target) >= abs(ans - target))
					continue;

				ans = temp;
				if (ans == target)
					return ans;
			}
			return ans;
		}

	private:
		int twoSumClosest(vector<int>&num, int start, int target){
			int count = num.size(), ans = 999999999;
			for (int i = start; i < count - 1; ++i){
				if (i > start && num[i] == num[i - 1])
						continue;

				int s = start + 1;
				for (int j = s; j < count; ++j){
					int temp = num[i] + num[j];
					if (abs(temp - target) < abs(ans - target))
						ans = temp;
					if (ans == target)
						return ans;
				}
			}
			return ans;
		}
	};


	TEST_CLASS(ThreeSumClosest)
	{
	public:
		TEST_METHOD(ThreeSumClosestTest)
		{
			assert_helper({ -4, -1, 1, 2 }, 1, 2);
			assert_helper({ -1, 2, 1, -4 }, 1, 2);
			assert_helper({ -1, -1, -1 }, -3, -3);
			assert_helper({ -1, -1, -1 }, 10, -3);
			assert_helper({ -1, -1, -1 }, -5, -3);
			assert_helper({ -1, 2, 1, -4 }, -1, -1);
			assert_helper({ -1, 2, 1, -4 }, 7, 2);
			assert_helper({ -1, 2, 1, -4 }, -6, -4);
			assert_helper({ -10, 0, -2, 3, -8, 1, -10, 8, -8, 6, -7, 0, -7, 2, 2, -5, -8, 1, -4, 6 }, 18, 17);
			assert_helper({ 43, 75, -90, 47, -49, 72, 17, -31, -68, -22, -21, -30, 65, 88, -75, 23, 97, -61, 53, 87, -3, 33, 20, 51, -79, 43, 80, -9, 34, -89, -7, 93, 43, 55, -94, 29, -32, -49, 25, 72, -6, 35, 53, 63, 6, -62, -96, -83, -73, 66, -11, 96, -90, -27, 78, -51, 79, 35, -63, 85, -82, -15, 100, -82, 1, -4, -41, -21, 11, 12, 12, 72, -82, -22, 37, 47, -18, 61, 60, 55, 22, -6, 26, -60, -42, -92, 68, 45, -1, -26, 5, -56, -1, 73, 92, -55, -20, -43, -56, -15, 7, 52, 35, -90, 63, 41, -55, -58, 46, -84, -92, 17, -66, -23, 96, -19, -44, 77, 67, -47, -48, 99, 51, -25, 19, 0, -13, -88, -10, -67, 14, 7, 89, -69, -83, 86, -70, -66, -38, -50, 66, 0, -67, -91, -65, 83, 42, 70, -6, 52, -21, -86, -87, -44, 8, 49, -76, 86, -3, 87, -32, 81, -58, 37, -55, 19, -26, 66, -89, -70, -69, 37, 0, 19, -65, 38, 7, 3, 1, -96, 96, -65, -52, 66, 5, -3, -87, -16, -96, 57, -74, 91, 46, -79, 0, -69, 55, 49, -96, 80, 83, 73, 56, 22, 58, -44, -40, -45, 95, 99, -97, -22, -33, -92, -51, 62, 20, 70, 90 }, 284, 284);
		}

	private:
		void assert_helper(vector<int> num, int target, int expected){
			Solution sln;
			int ans = sln.threeSumClosest(num, target);
			Assert::AreEqual(expected, ans);
		}
	};
}


/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/