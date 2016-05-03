#include "stdafx.h"
#include <stdio.h>
#include <string>
//#include "gtest/gtest.h"

using namespace std;

/*
 Implement wildcard pattern matching with support for '?' and '*'.
 
 '?' Matches any single character.
 '*' Matches any sequence of characters (including the empty sequence).
 
 The matching should cover the entire input string (not partial).
 
 The function prototype should be:
 bool isMatch(const char *s, const char *p)
 
 Some examples:
 isMatch("aa","a") → false
 isMatch("aa","aa") → true
 isMatch("aaa","aa") → false
 isMatch("aa", "*") → true
 isMatch("aa", "a*") → true
 isMatch("ab", "?*") → true
 isMatch("aab", "c*a*b") → false
*/

namespace LeetCode {
    class WildCardMatchingSolution {
    public:
        bool isMatch(string s, string p) {
			_slen = s.length();
			_plen = p.length();
			for (int i = 0; i < _slen + 2; ++ i) {
				vector<int> temp(_plen + 2, -1);
				_status.push_back(temp);
			}
			return isMatch(s, 0, p, 0);
        }
	private:
		bool isMatch(string s, int si, string p, int pi){
			if (_status[si][pi] >= 0) {
				return _status[si][pi] == 1;
			}
			bool result;
			if (si == _slen){
				if (pi == _plen) {
					result = true;
				}
				else if (p[pi] == '*')
					result = isMatch(s, si, p, pi + 1) == 1;
				else
					result = false;
			}
			else if (pi == _plen){
				result = si == _slen;
			}
			else if (p[pi] == '?'){
				result = isMatch(s, si + 1, p, pi + 1);
			}
			else if (p[pi] == '*'){
				result = isMatch(s, si + 1, p, pi + 1) || isMatch(s, si + 1, p, pi);
			}
			else{
				result = s[si] == p[pi] && isMatch(s, si + 1, p, pi + 1);
			}
			_status[si][pi] = result ? 1 : 0;
			return result;
		}
	private:
		int _slen;
		int _plen;
		vector<vector<int>> _status;
    };
    
    class wdmhelper{
    public:
        void test(string s, string p, bool expected){
            WildCardMatchingSolution sln;
            bool actual = sln.isMatch(s, p);
			Assert::AreEqual(expected, actual);
        }
        
    };
	TEST_CLASS(WildcardMatching) {
	public:
		TEST_METHOD(WildCardMatchingTest) {
			wdmhelper h;
			h.test("aa", "a", false);
			h.test("aa", "aa", true);
			h.test("aaa", "aa", false);
			h.test("aa", "*", true);
			h.test("aa", "a*", true);
			h.test("ab", "?*", true);
			h.test("aab", "c*a*b", false);
			h.test("aa", "aa*", true);
		}
	};
}
