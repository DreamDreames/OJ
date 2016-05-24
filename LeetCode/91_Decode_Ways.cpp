#include "shared.h"
/*
 A message containing letters from A-Z is being encoded to numbers using the following mapping:
 
 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
 Given an encoded message containing digits, determine the total number of ways to decode it.
 
 For example,
 Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 
 The number of ways decoding "12" is 2.
*/
namespace DecodeWays {
    class Solution {
    public:
        int numDecodings(string s) {
            int len = (int)s.length();
            if(len == 0 || s[0] == '0')
                return 0;
            vector<int> records(len + 1, 0);
            records[0] = 1; records[1] = 1;
            
            for(int i = 2; i <= len; ++ i){
                int sum = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
                if(s[i - 1] == '0'){
                    if(s[i - 2] > '2' || s[i - 2] == '0')
                        records[i] = 0;
                    else
                        records[i] = records[i - 2];
                }
                else if(sum > 26 || s[i - 2] == '0')
                    records[i] = records[i - 1];
                else
                    records[i] = records[i - 1] + records[i - 2];
            }
            
            return records[len];
        }
    };
    class helper{
    public:
        void test(string s, int expected){
            Solution sln;
            int actual = sln.numDecodings(s);
            ASSERT_EQ(expected, actual);
        }
    };
    TEST(DecodeWays, numDecodings){
        helper h;
        h.test("12", 2);
        h.test("1", 1);
        h.test("0", 0);
        h.test("27", 1);
        h.test("01", 0);
        h.test("012", 0);
        h.test("100", 0);
        h.test("110", 1);
        h.test("10", 1);
        h.test("101", 1);
        h.test("1029", 1);
        h.test("611", 2);
        h.test("11", 2);
        h.test("111", 3);
    }
}
