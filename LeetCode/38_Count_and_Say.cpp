#include <stdio.h>
#include <string>
#include "gtest/gtest.h"

using namespace std;
/*
 The count-and-say sequence is the sequence of integers beginning as follows:
 1, 11, 21, 1211, 111221, ...
 
 1 is read off as "one 1" or 11.
 11 is read off as "two 1s" or 21.
 21 is read off as "one 2, then one 1" or 1211.
 Given an integer n, generate the nth sequence.
 
 Note: The sequence of integers will be represented as a string.
*/

namespace LeetCode {
    class Solution {
    public:
        string countAndSay(int n) {
            string str = "1";
            while(-- n){
                str = sequence(str);
            }
            return str;
        }
    private:
        string sequence(string input){
            string str = "";
            char pre = input[0];
            char count = '1';
            for(auto it = input.begin() + 1; it != input.end(); ++ it){
                if(pre == *it){
                    count ++;
                }
                else{
                    str.push_back(count);
                    str.push_back(pre);
                    pre = *it;
                    count = '1';
                }
            }
            if(pre != 0){
                str.push_back(count);
                str.push_back(pre);
            }
            return str;
        }
    };
    
    class helper{
    public:
        void test(int n, string expected){
            Solution sln;
            auto ans = sln.countAndSay(n);
            ASSERT_EQ(expected, ans);
            
        }
    };
    TEST(CountAndSay, countAndSay){
        helper h;
        h.test(1, "1");
        h.test(2, "11");
        h.test(3, "21");
        h.test(4, "1211");
        h.test(5, "111221");
    }
}