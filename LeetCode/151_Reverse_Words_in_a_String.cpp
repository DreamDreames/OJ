#include "shared.h"
/*
 Given an input string, reverse the string word by word.
 
 For example,
 Given s = "the sky is blue",
 return "blue is sky the".
 
 Update (2015-02-12):
 For C programmers: Try to solve it in-place in O(1) space.
 */
namespace ReverseWordsInAString{
    class Solution {
    public:
        void reverseWords(string &s) {
            if(s == "")
                return;
            string ans = "";
            int start = -1, end = -1;
            for(int i = (int)s.length() - 1; i >= 0; -- i){
                if(s[i] == ' '){
                    if(end != -1){
                        start = i + 1;
                        if(ans == "")
                            ans = s.substr(start, end - start + 1);
                        else
                            ans += " " + s.substr(start, end - start + 1);
                    }
                    start = end = -1;
                    continue;
                }
                if(end == -1){
                    end = i;
                }
            }
            if(s[0] != ' '){
                if(end != -1){
                    start = 0;
                }
                if(ans == "")
                    ans = s.substr(start, end - start + 1);
                else
                    ans += " " + s.substr(start, end - start + 1);
            }
            s = ans;
        }
    };
    class helper{
    public:
        void test(string s, string expected){
            Solution sln;
            sln.reverseWords(s);
            ASSERT_EQ(expected, s);
        }
    };
    TEST(ReverseWordsInAString, reverseWords){
        helper h;
        h.test("hello", "hello");
        h.test("hello world", "world hello");
        h.test("hello , world", "world , hello");
        h.test("     ", "");
        h.test(" 1", "1");
        h.test("   a   ", "a");
    }
}
