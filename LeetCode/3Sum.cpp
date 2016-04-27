#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <iterator>

using namespace std;

namespace LeetCode
{
	class Solution {
	public:
		vector<vector<int> > threeSum(vector<int> &num) {
			vector<vector<int> > ans;
			sort(num.begin(), num.end());
			int count = num.size();
			for (int i = 0; i < count - 2; ++i){
				if (i > 0 && num[i] == num[i - 1])
					continue;
				findTwo(num, i + 1, 0 - num[i], num[i], ans);
			}
			return ans;
		}
	private:
		void findTwo(vector<int>&num, int start, int sum, int pre, vector<vector<int> >&cls){
			int count = num.size();
			for (int i = start; i < count - 1; ++i){
				if (i > start && num[i] == num[i - 1])
					continue;
				int cur = num[i], target = sum - cur;
				for (int j = i + 1; j < count; ++j){
					if (j > i + 1 && num[j] == num[j - 1])
						continue;
					if (num[j] != target)
						continue;
					if (num[j] > target)
						break;
					cls.push_back(vector<int>({ pre, cur, num[j] }));
				}
			}
		}
	};

	TEST_CLASS(ThreeSum)
	{
	public:

		TEST_METHOD(ThreeSumTest)
		{
			assert_helper({ -4, -1, -1, 0, 1, 2 }, { { -1, 0, 1 }, { -1, -1, 2 } });
			assert_helper({ -1, 0, 1, 2, -1, -4 }, { { -1, 0, 1 }, { -1, -1, 2 } });
			assert_helper({ -1, 1, 0 }, { { -1, 0, 1 } });
			assert_helper({ 0, 0, 0 }, { { 0, 0, 0 } });
			assert_helper({ 0, 0, -1 }, {});
			assert_helper({ 0, 0 }, {});
			assert_helper({ -1, -1, -1, -1, 2 }, {{ -1, -1, 2 }});
		}
	private:
		void assert_helper(vector<int>num, vector<vector<int> > expected)
		{
			Solution sln; 
			vector<vector<int> > ans = sln.threeSum(num);
			Assert::AreEqual(expected.size(), ans.size());
			for (auto &v : expected){
				if (find(ans.begin(), ans.end(), v) == ans.end()){
					string msg = toString(v);
					cout << msg;
					Assert::Fail();
				}
			}
		}
		string toString(vector<int>& v)
		{
			if (v.size() == 0)
				return "";
			stringstream oss;
			oss << "Can not find ";
			copy(v.begin(), v.end() - 1, ostream_iterator<int>(oss, ","));
			oss << v.back();
			return oss.str();
		}
	};
}

/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:
(-1, 0, 1)
(-1, -1, 2)
*/