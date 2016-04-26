#include "stdafx.h"
#include <string>
#include <vector>

using namespace std;

namespace LeetCode
{
	class Solution {
	public:
		string longestCommonPrefix(vector<string> &strs) {
			int count = strs.size();
			if (count == 0) return "";
			vector<int>str_len;
			int min_len = 999999999;
			for (auto i = strs.begin(); i != strs.end(); ++i){
				int len = (*i).length();
				if (len < min_len)
					min_len = len;
				str_len.push_back(len);
			}
			bool stop = false;
			int l;
			for (l = 0; l < min_len; ++l){
				char c = strs[0].at(l);
				for (auto j = strs.begin(); j != strs.end() && !stop; ++j){
					if ((*j).at(l) != c){
						stop = true;
					}
				}
				if (stop)
					break;
			}
			if (l == 0)
				return "";
			else
				return strs[0].substr(0, l);
		}
	};


	TEST_CLASS(LongestCommonPrefix)
	{
	public:
		TEST_METHOD(LongestCommonPrefixTest)
		{
			test({}, "");
			test({ "a", "a" }, "a");
			test({ "a", "ab" }, "a");
			test({ "ab", "ab" }, "ab");
			test({ "ab", "ba" }, "");
		}

	private:
		void test(vector<string>strs, string expected)
		{
			Solution sln;
			string ans = sln.longestCommonPrefix(strs);
			Assert::AreEqual(expected, ans);
		}
	};
}

/*
Write a function to find the longest common prefix string amongst an array of strings.
*/