#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

#define _test

namespace LeetCode
{
	class Solution {
	public:
		vector<vector<int> > fourSum(vector<int> &num, int target) {
			vector<vector<int> > ans;

			sort(num.begin(), num.end());
			int count = num.size();
			for (int i = 0; i < count - 3; ++i){
				if (i > 0 && num[i] == num[i - 1])
					continue;
				if (canStop(num, i + 1, 3, target - num[i]))
					break;
				findThree(num, i + 1, target - num[i], num[i], ans);
			}
			
			return ans;
		}
	private:
		bool canStop(vector<int>& num, int start, int forward, int target){
			int sum = 0;
			while (forward--){
				sum += num[start++];
			}
			return sum > target;
		}
		vector<vector<int> > findThree(vector<int> &num, int start, int sum, int pre, vector<vector<int> >& ans) {
			int count = num.size();
			for (int i = start; i < count - 2; ++i){
				if (i > start && num[i] == num[i - 1])
					continue;
				if (canStop(num, i + 1, 2, sum - num[i]))
					break;
				findTwo(num, i + 1, sum - num[i], pre, num[i], ans);
			}
			return ans;
		}
		void findTwo(vector<int>&num, int start, int sum, int pre_pre, int pre, vector<vector<int> >&cls){
			int count = num.size();
			for (int i = start; i < count - 1; ++i){
				if (i > start && num[i] == num[i - 1])
					continue;
				if (canStop(num, i + 1, 1, sum - num[i]))
					break;
				int target = sum - num[i];
				if (searchFound(num, i + 1, count - 1, target))
					cls.push_back(vector<int>({ pre_pre, pre, num[i], target}));
			}
		}
		bool searchFound(vector<int>&num, int l, int r, int target){
			if (l > r)
				return false;

			int mid = l + (r - l) / 2;
			if (num[mid] == target)
				return true;
			if (num[mid] < target)
				return searchFound(num, mid + 1, r, target);
			return searchFound(num, l , mid - 1, target);
		}
#ifdef _test
		friend class FourSum;
#endif
	};

	TEST_CLASS(FourSum)
	{
	public:
		TEST_METHOD(FourSumTest)
		{
			assert_helper({ 1, 0, -1, 0, -2, 2 }, 0, { { -1, 0, 0, 1 }, { -2, -1, 1, 2 }, { -2, 0, 0, 2 } });
			assert_helper({ 91277418, 66271374, 38763793, 4092006, 11415077, 60468277, 1122637, 72398035, -62267800, 22082642, 60359529, -16540633, 92671879, -64462734, -55855043, -40899846, 88007957, -57387813, -49552230, -96789394, 18318594, -3246760, -44346548, -21370279, 42493875, 25185969, 83216261, -70078020, -53687927, -76072023, -65863359, -61708176, -29175835, 85675811, -80575807, -92211746, 44755622, -23368379, 23619674, -749263, -40707953, -68966953, 72694581, -52328726, -78618474, 40958224, -2921736, -55902268, -74278762, 63342010, 29076029, 58781716, 56045007, -67966567, -79405127, -45778231, -47167435, 1586413, -58822903, -51277270, 87348634, -86955956, -47418266, 74884315, -36952674, -29067969, -98812826, -44893101, -22516153, -34522513, 34091871, -79583480, 47562301, 6154068, 87601405, -48859327, -2183204, 17736781, 31189878, -23814871, -35880166, 39204002, 93248899, -42067196, -49473145, -75235452, -61923200, 64824322, -88505198, 20903451, -80926102, 56089387, -58094433, 37743524, -71480010, -14975982, 19473982, 47085913, -90793462, -33520678, 70775566, -76347995, -16091435, 94700640, 17183454, 85735982, 90399615, -86251609, -68167910, -95327478, 90586275, -99524469, 16999817, 27815883, -88279865, 53092631, 75125438, 44270568, -23129316, -846252, -59608044, 90938699, 80923976, 3534451, 6218186, 41256179, -9165388, -11897463, 92423776, -38991231, -6082654, 92275443, 74040861, 77457712, -80549965, -42515693, 69918944, -95198414, 15677446, -52451179, -50111167, -23732840, 39520751, -90474508, -27860023, 65164540, 26582346, -20183515, 99018741, -2826130, -28461563, -24759460, -83828963, -1739800, 71207113, 26434787, 52931083, -33111208, 38314304, -29429107, -5567826, -5149750, 9582750, 85289753, 75490866, -93202942, -85974081, 7365682, -42953023, 21825824, 68329208, -87994788, 3460985, 18744871, -49724457, -12982362, -47800372, 39958829, -95981751, -71017359, -18397211, 27941418, -34699076, 74174334, 96928957, 44328607, 49293516, -39034828, 5945763, -47046163, 10986423, 63478877, 30677010, -21202664, -86235407, 3164123, 8956697, -9003909, -18929014, -73824245 }, -236727523, { { -79583480, -70078020, -65863359, -21202664 }, { -76072023, -59608044, -58094433, -42953023 } });
			assert_helper({ 1, -2, -5, -4, -3, 3, 3, 5 }, -11, { { -5, -4, -3, 1 } });
		}
	private:
		void TestBinarySearch(vector<int> num, int target, bool expected){
			Solution sln;
			bool actual = sln.searchFound(num, 0, num.size() - 1, target);
			if (expected != actual)
				printf("error\r\n");
			Assert::AreEqual(expected, actual);
		}
		void assert_helper(vector<int>num, int target, vector<vector<int> > expected)
		{
			Solution sln;
			auto ans = sln.fourSum(num, target);
			Assert::AreEqual(expected.size(), ans.size());
			for (auto &e : expected){
				findExpected(e, ans);
			}
		}
		void findExpected(vector<int>& expected, vector<vector<int> >& ans){
			bool found = false;
			for (auto &a : ans){
				if (equal(expected, a))
					found = true;
			}
			if (!found)
				Assert::Fail();
		}
		bool equal(vector<int> &e, vector<int>& a){
			if (e.size() != a.size())
				return false;
			for (int i = 0; i < e.size(); ++i){
				if (e[i] != a[i])
					return false;
			}
			return true;
		}
		
	};
}

/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a <= b <= c <= d)
The solution set must not contain duplicate quadruplets.
For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

A solution set is:
(-1,  0, 0, 1)
(-2, -1, 1, 2)
(-2,  0, 0, 2)
*/