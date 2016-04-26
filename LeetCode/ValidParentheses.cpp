#include "stdafx.h"
#include <string>
#include <stack>

using namespace std;

namespace LeetCode
{
	class Solution {
	public:
		bool isValid(string s) {
			stack<char> st;
			for (auto &c : s){
				if (c == '{' || c == '(' || c == '[')
					st.push(c);
				else if (c == '}' || c == ')' || c == ']')
				{
					if (st.empty())
						return false;
					char top = st.top();
					st.pop();
					if (!match(top, c))
						return false;
				}
					
			}
			return st.empty();
		}
	private:
		bool match(char left, char right){
			if (left == '{')
				return right == '}';
			if (left == '(')
				return right == ')';
			if (left == '[')
				return right == ']';
		}
	};

	TEST_CLASS(ValidParentheses)
	{
	public:
		
		TEST_METHOD(ValidParenthesesTest)
		{
			assert_helper("{}", true);
			assert_helper("()", true);
			assert_helper("[]", true);
			assert_helper("", true);
			assert_helper("((({[{])})})", false);
			assert_helper("([)]", false);
			assert_helper("([])", true);
		}
	private:
		void assert_helper(string str, bool expected){
			Solution sln;
			bool ans = sln.isValid(str);
			Assert::AreEqual(ans, expected);
		}

	};
}

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

*/