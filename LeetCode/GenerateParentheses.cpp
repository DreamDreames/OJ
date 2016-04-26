#include "stdafx.h"
#include <vector>

using namespace std;

namespace LeetCode
{
	class Solution {
	public:
		vector<string> generateParenthesis(int n) {
			return generate(0, n, 0);
		}
	private:
		vector<string> generate(int left, int n, int right){
			vector<string> ans;
			if (n == 0){
				string str = "";
				while (right++ < left){
					str += ")";
				}
				if (str != "")
					ans.push_back(str);
				return ans;
			}
			if (n > 0){
				auto temp = generate(left + 1, n - 1, right);
				for (auto &t : temp){
					ans.push_back("(" + t);
				}
			}
			if (left > right){
				auto temp = generate(left, n, right + 1);
				for (auto &t : temp){
					ans.push_back(")" + t);
				}
			}
			return ans;
		}
	};

	TEST_CLASS(GenerateParentheses)
	{
	public:
		TEST_METHOD(GenerateParenthesesTest)
		{
			assert_helper(3, 5);
			assert_helper(1, 1);
			assert_helper(0, 0);
		}
	private:
		void assert_helper(int n, int expected){
			Solution sln;
			auto ans = sln.generateParenthesis(n);
			Assert::AreEqual(expected, (int)ans.size());
		}
	};
}


/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

*/