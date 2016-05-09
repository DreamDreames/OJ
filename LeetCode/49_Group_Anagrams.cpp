#include "stdafx.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;
/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
["ate", "eat","tea"],
["nat","tan"],
["bat"]
]
Note:
For the return value, each inner list's elements must follow the lexicographic order.
All inputs will be in lower-case.
*/
namespace GroupAnagrams {
	class Solution {
	public:
		vector<vector<string>> groupAnagrams(vector<string>& strs) {
			unordered_map<string, multiset<string>> collection;
			for (auto& str : strs) {
				string copy = str;
				sort(copy.begin(), copy.end());
				collection[copy].insert(str);
			}
			vector<vector<string>> ans;
			for (auto &iter : collection) {
				ans.push_back(vector<string>(iter.second.begin(), iter.second.end()));
			}
			return ans;
		}
	};
	TEST_CLASS(Group) {
	public:
		TEST_METHOD(GroupAnagrams) {
			test({ "eat", "tea", "tan", "ate", "nat", "bat" }, { {"ate", "eat","tea"}, {"nat","tan"}, {"bat"} });
			test({ "", "" }, { {"", ""} });
		}
	private:
		void test(vector<string> strs, vector<vector<string>> expected) {
			Solution sln;
			auto& ans = sln.groupAnagrams(strs);
		}
	};
}