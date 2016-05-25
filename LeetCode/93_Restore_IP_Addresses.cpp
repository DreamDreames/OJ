#include "stdafx.h"

/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/
namespace RestoreIpAddresses{
	class Solution {
	public:
		vector<string> restoreIpAddresses(string s) {
			vector<string> ans;
			if (s.length() > 12)
				return ans;
			string result = "";
			restore(s, 0, 0, result, ans);
			return ans;
		}
	private:
		void restore(string& s, int depth, int start, string& result, vector<string>& ans){
			if (start >= s.length()){
				return;
			}

			if (depth == 3){
				string field = s.substr(start);
				int num = stoi(field);
				if (s[start] == '0' && start + 1 < s.length())
					return;
				if (num >= 0 && num <= 255){
					result += "." + field;
					ans.push_back(result);
				}
				return;
			}
			for (int i = 1; i <= 3 && start + i <= s.length(); ++i){
				string temp = s.substr(start, i);
				int num = stoi(temp);
				if (num > 255)
					break;
				string dup = result;
				if (depth == 0)
					result = temp;
				else
					result += "." + temp;
				restore(s, depth + 1, start + i, result, ans);
				result = dup;
				if (s[start] == '0')
					break;
			}
		}
	};

	TEST_CLASS(restoreIpAddresses){
	public:
		TEST_METHOD(RestoreIpAddresses){
			test("25525511135", { "255.255.11.135", "255.255.111.35" });
			test("0000", { "0.0.0.0" });
			test("010010", { "0.10.0.10", "0.100.1.0" });
			test("00000", {});
		}
	private:
		void test(string s, vector<string> expected){
			Solution sln;
			auto actual = sln.restoreIpAddresses(s);
			Assert::AreEqual(expected.size(), actual.size());
			for (int i = 0; i < expected.size(); ++i){
				Assert::AreEqual(expected[i], actual[i]);
			}
		}
	};
}