#include "stdafx.h"
#include <string>
#include <sstream>

using namespace std;

namespace LeetCode
{
	class Solution {
	public:
		bool isMatch(const char *s, const char* p){
			int slen = strlen(s), plen = strlen(p);
			if (plen == 0)
				return slen == 0;
			if (plen == 1){
				if (slen == 1){
					return p[0] == '.' || p[0] == s[0];
				}
				return false;
			}
			if (p[1] == '*'){
				if (p[0] == '.')
					return isMatch(s + 1, p) || isMatch(s + 1, p + 2);
				if (s[0] != p[0])
					return isMatch(s, p + 2);
				return isMatch(s + 1, p + 2) || isMatch(s + 1, p);
			}
			if (p[0] == '.')
				return isMatch(s + 1, p + 1);
			if (s[0] == p[0])
				return isMatch(s + 1, p + 1);
			return false;
		}
	};
	TEST_CLASS(RegularExpression)
	{
	public:
		TEST_METHOD(RegularExpressionTest)
		{
			assertMatch("aa", "a", false);
			assertMatch("aa", "aa", true);
			assertMatch("aaa", "aa", false);

			assertMatch("aa", "a*", true);
			assertMatch("aa", ".*", true);
			//assertMatch("ab", ".*", true);
			//assertMatch("aab", "c*a*b", true);
			//assertMatch("ab", ".*c", false);
			//assertMatch("aaa", "ab*a*c*a", true);
			//assertMatch("bbbba", ".*a*a", true);
			//assertMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*a*a*b", true);
			//assertMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c", false);
			//assertMatch("a", ".*..a*", false);
		}
	private:
		void assertMatch(const char *s, const char *p, bool expected)
		{
			Solution sln;
			bool ans;
			ans = sln.isMatch(s, p);
			if (expected != ans) {
				std::ostringstream oss;
				oss << "Match " << s << " with " << p << " failed.";
				throw(oss.str());
			}
		}
	};
}

/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true 
isMatch("ab", ".*") → true (In this case, * can repeat . which is any character)
isMatch("aab", "c*a*b") → true
*/