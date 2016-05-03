#include <stdio.h>
#include <string>
#include <sstream>
#include "gtest/gtest.h"

using namespace std;

namespace RegularExpressionMatching
{
    class Solution {
    private:
        int ** _status;
        
    public:
        bool isMatch(string& s, string& p){
            auto slen = s.length(), plen = p.length();
            _status = new int* [slen + 3];
            for(int i = 0; i < slen + 3; ++ i){
                _status[i] = new int[plen + 3];
                for(int j = 0; j < plen + 3; ++ j)
                    _status[i][j] = -1;
            }
            auto result =  _isMatch(s.c_str(), p.c_str());
            
            for(int i = 0; i < slen + 3; ++ i){
                delete[] _status[i];
            }
            delete[] _status;
            return result;
        }
    private:
        bool _isMatch(const char *s, const char* p){
            auto slen = strlen(s), plen = strlen(p);
            if(_status[slen][plen] >= 0)
                return _status[slen][plen] == 1;
            bool result = false;
            if (plen == 0)
                result = ( slen == 0);
            else if (plen == 1){
                if (slen == 1)
                    result = ( p[0] == '.' || p[0] == s[0]);
                
                else
                    result =  false;
            }
            else if (p[1] == '*'){
                if(slen == 0)
                    result = _isMatch(s, p + 2);
                
                else if (p[0] == '.')
                    result = _isMatch(s + 1, p) || _isMatch(s + 1, p + 2) || _isMatch(s, p + 2);
            
                else if (s[0] != p[0])
                    result = _isMatch(s, p + 2);
                else
                    result = _isMatch(s + 1, p + 2) || _isMatch(s + 1, p) || _isMatch(s, p + 2);
            }
            else if(slen == 0)
                result = false;
            else if (p[0] == '.')
                result = _isMatch(s + 1, p + 1);
            else if (s[0] == p[0])
                result = _isMatch(s + 1, p + 1);
            
            _status[slen][plen] = result ? 1: 0;
           
            return result;
        }
    };
    class helper{
    public:
        void assertMatch(string s, string p, bool expected) {
            Solution sln;
            bool ans;
            ans = sln.isMatch(s, p);
            ASSERT_EQ(expected, ans);
        }
    };
    TEST(RegularExpression, isMatch)
    {
        helper h;
        h.assertMatch("aa", "a", false);
        h.assertMatch("aa", "aa", true);
        h.assertMatch("aaa", "aa", false);
        h.assertMatch("aa", "a*", true);
        h.assertMatch("aa", ".*", true);
        h.assertMatch("ab", ".*", true);
        h.assertMatch("ab", ".*..", true);
        h.assertMatch("aab", "c*a*b", true);
        h.assertMatch("ab", ".*c", false);
        h.assertMatch("aaa", "ab*a*c*a", true);
        h.assertMatch("bbbba", ".*a*a", true);
        h.assertMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*a*a*b", true);
        h.assertMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c", false);
        h.assertMatch("a", ".*..a*", false);
    }

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

