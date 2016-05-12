#include "shared.h"

/*
 Validate if a given string is numeric.
 
 Some examples:
 "0" => true
 " 0.1 " => true
 "abc" => false
 "1 a" => false
 "2e10" => true
 Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
*/

namespace ValidNumber {
    class Solution {
    public:
        bool isNumber(string s) {
            s = trim(s);
            if(s.length() == 0)
                return false;
            if(s[0] == '.')
                return isPureNumber(s, 1);
            bool hasNumber = false;
            if(s[0] == '+' || s[0] == '-')
                hasNumber = false;
            else if(isCharNumber(s[0]))
                hasNumber = true;
            else
                return false;
            
            for(int i = 1; i < s.length(); ++ i){
                if(s[i] == 'e' || s[i] == '^' || s[i] == '/')
                    return hasNumber && isInteger(s, i + 1);
                
                if(s[i] == '.')
                    return (i == (int)s.length() - 1 && hasNumber) || isEorNumber(s, i + 1);
                if(!isCharNumber(s[i]))
                    return false;
                hasNumber = true;
            }
            return true;
        }
    private:
        string trim(string s){
            auto endpos = s.find_last_not_of(" \t");
            if(endpos != string::npos)
                s = s.substr(0, endpos + 1);
            auto startpos = s.find_first_not_of(" \t");
            if(startpos != string::npos)
                s = s.substr(startpos);
            return s;
        }
        bool isEorNumber(string&s, int start){
            if((int)s.length() - start <= 0)
                return false;
            if(s[start] == 'e')
                return isPureNumber(s, start + 1);
            return isPureNumber(s, start);
        }
        bool isPureNumber(string &s, int start){
            if((int)s.length() - start <= 0)
                return false;
            for(int i = start; i < s.length(); ++ i){
                if(! isCharNumber(s[i]))
                    return false;
            }
            return true;
        }
        bool isInteger(string& s, int start){
            if((int)s.length() - start <= 0)
                return false;
            if(s[0] == '+' || s[0] == '-')
                return isPureNumber(s, start + 1);
            
            return isPureNumber(s, start);
        }
        bool isCharNumber(char n){
            return n >= '0' && n <= '9';
        }

    };
    class helper{
    public:
        void test(string input, bool expected){
            Solution sln;
            bool actual = sln.isNumber(input);
            ASSERT_EQ(expected, actual);
        }
    };
    TEST(ValidNumber, isNumber){
        helper h;
        h.test("0", true);
        h.test("abc", false);
        h.test("1 a", false);
        h.test("2e10", true);
        h.test("1 ", true);
        h.test(" 1 ", true);
        h.test(" .1 ", true);
        h.test(".", false);
        h.test("3.", true);
        h.test("0..", false);
        h.test(" -.", false);
        h.test(" -1.", true);
        h.test("46.e3", true);
//        h.test(".2e18", true);
    }
}