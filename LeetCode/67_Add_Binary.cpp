#include "shared.h"
/*
 Given two binary strings, return their sum (also a binary string).
 
 For example,
 a = "11"
 b = "1"
 Return "100".
*/

namespace AddBinary {
    class Solution {
    public:
        string addBinary(string a, string b) {
            if(a.size() < b.size())
                return addBinary(b, a);
            
            string ans = "";
            int carry = 0;
            auto aiter = a.rbegin();
            for(auto biter = b.rbegin(); aiter != a.rend() && biter!= b.rend(); aiter++, biter ++){
                int temp = (*aiter - '0') + (*biter - '0') + carry;
                ans += temp % 2 + '0';
                carry = temp / 2;
            }
            while(aiter != a.rend()){
                int temp = (*aiter - '0') + carry;
                ans += temp % 2 + '0';
                carry = temp / 2;
                aiter ++;
            }
            
            if(carry == 1)
                ans += carry + '0';
            
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };
    class helper{
    public:
        void test(string a, string b, string expected){
            Solution sln;
            auto actual = sln.addBinary(a, b);
            ASSERT_EQ(actual, expected);
        }
    };
    TEST(AddBinary, addBinary){
        helper h;
        h.test("11", "1", "100");
        h.test("11", "11", "110");
        h.test("1", "1", "10");
    }
}
