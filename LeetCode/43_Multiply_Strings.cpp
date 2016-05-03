#include <stdio.h>
#include <string>
#include <vector>
#include "gtest/gtest.h"

using namespace std;

/*
 Given two numbers represented as strings, return multiplication of the numbers as a string.
 
 Note:
 The numbers can be arbitrarily large and are non-negative.
 Converting the input string to integer is NOT allowed.
 You should NOT use internal library such as BigInteger.
*/

namespace MultiplyString {
   
    class Solution {
    public:
        string multiply(string num1, string num2) {
            if(num1.size() > num2.size())
                return multiply(num2, num1);
            int i;
            string ans = "0";
            vector<string> adds;
            for(i = (int)num1.size() - 1; i >= 0; -- i){
                string temp = multiply(num2, num1[i]);
                adds.push_back(temp);
            }
            
            for(i = 0; i < adds.size(); ++ i){
                string zero = string(i, '0');
                string current = adds[i];
                current = current + zero;
                ans = add(ans, current);
            }
            return ans;
        }
    private:
        string add(string num1, string num2){
            int i = (int)num1.length() - 1, j = (int)num2.length() - 1;
            int carry = 0;
            string ans = "";
            while( i >= 0 && j >= 0){
                int temp = (num1[i] - '0') + (num2[j] - '0') + carry;
                ans.push_back(temp % 10 + '0');
                carry = temp / 10;
                i --; j --;
            }
            int rest = i;
            string iter = num1;
            if(j > i){
                rest = j;
                iter = num2;
            }
            while(rest >= 0){
                int temp = iter[rest] - '0' + carry;
                ans.push_back(temp % 10 + '0');
                carry = temp / 10;
                rest --;
            }
            if(carry > 0)
                ans.push_back(carry + '0');
            reverse(ans.begin(), ans.end());
            return ans;
        }
        string multiply(string num, char ch){
            if(ch == '0' || num == "0"){
                return "0";
            }
            int carry = 0;
            string sum = "";
            for(int i = (int)num.size() - 1; i >= 0; -- i){
                int temp = (ch - '0') * (num[i] - '0') + carry;
                carry = temp / 10;
                sum.push_back(temp % 10 + '0');
            }
            if(carry > 0)
                sum.push_back(carry + '0');
            
            std::reverse(sum.begin(), sum.end());
            return sum;
        }
    };
 
    class helper{
    public:
        void test (string num1, string num2, string expected){
            Solution sln;
            string actual = sln.multiply(num1, num2);
            ASSERT_EQ(expected, actual);
        }
    };
    TEST(MultiplyStrings, multiply){
        helper h;
        h.test("123", "1", "123");
        h.test("1", "123", "123");
        h.test("123", "456", "56088");
    }}
