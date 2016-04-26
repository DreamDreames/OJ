#include "stdafx.h"
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

// Solution1 from http://bangbingsyb.blogspot.com/2014/11/leetcode-longest-valid-parentheses.html
// Solution2 from http://fisherlei.blogspot.com/2013/03/leetcode-longest-valid-parentheses.html

namespace LeetCode
{
	class Solution2{
	public:
		int longestValidParentheses(string s){
			const char* str = s.c_str();
			const char* p = str;
			stack<const char*> stk;
			int longest = 0, current = 0;
			while (*p != 0){
				if (*p == '('){
					stk.push(p);
				}
				else{
					if (stk.empty() || (*stk.top()) != '(')
						stk.push(p);
					else{
						stk.pop();
						int current = p - (stk.empty() ? (str - 1) : stk.top());
						longest = max(current, longest);
					}
				}
				p++;
			}
			return longest;
		}
	};
	class Solution1 {
	public:
		int longestValidParentheses(string s) {
			stack<pair<int,int>> stk;
			int longest = 0, current = 0, len = s.length();
			for (int index = 0; index < len; ++index){
				if (s[index] == '('){
					stk.push(make_pair(index, 0));
					continue;
				}

				if (stk.empty() || stk.top().second != 0){
					stk.push(make_pair(index, 1));
					continue;
				}

				stk.pop();
				current = stk.empty() ? index + 1 : index - stk.top().first;
				longest = max(longest, current);
			}
			return longest;
		}
	};

	TEST_CLASS(LongestValidParentheses)
	{
	public:

		TEST_METHOD(LongestValidParenthesesTest)
		{
			helper("(", 0);
			helper(")", 0);
			helper("()", 2);
			helper("(())", 4);
			helper("(()()", 4);
			helper("()(()", 2);
			helper("()(())", 6);
			helper("((()))())", 8);
			helper(")()())()()(", 4);
		}
	private:
		void helper(string s, int expected){
			Solution2 sln;
			int ans = sln.longestValidParentheses(s);
			Assert::AreEqual(expected, ans);

		}
	};
}

/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/