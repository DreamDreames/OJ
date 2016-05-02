#include <stdio.h>
#include <string>
#include "gtest/gtest.h"

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
            return false;
        }
    };
    
    class wdmhelper{
    public:
        void test(string s, string p, bool expected){
            WildCardMatchingSolution sln;
            bool actual = sln.isMatch(s, p);
            ASSERT_EQ(expected, actual);
        }
        
    };
    TEST(WildcardMaching, isMatch){
        wdmhelper h;
        h.test("aa", "a", false);
        h.test("aa", "aa", true);
        h.test("aaa", "aa", false);
        h.test("aa", "*", true);
        h.test("aa", "a*", true);
        h.test("ab", "?*", true);
        h.test("aab", "c*a*b", false);
    }
}
