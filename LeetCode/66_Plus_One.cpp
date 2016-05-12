#include "shared.h"
/*
 Given a non-negative number represented as an array of digits, plus one to the number.
 
 The digits are stored such that the most significant digit is at the head of the list.
*/

namespace PlusOne{
    class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            int carry = 1;
            vector<int> ans;
            for(auto iter = digits.rbegin(); iter != digits.rend(); ++ iter){
                int temp = *iter + carry;
                carry = temp / 10;
                ans.push_back(temp % 10);
            }
            if(carry > 0){
                ans.push_back(carry);
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };
    class helper{
    public:
        void test(vector<int> digits, int expected){
            Solution sln;
            auto ans = sln.plusOne(digits);
            int actual = 0;
            for(auto iter = ans.begin(); iter != ans.end(); ++ iter){
                actual = actual * 10 + *iter;
            }
            ASSERT_EQ(actual, expected);
        }
    };
    TEST(PlusOne, plusONe){
        helper h;
        h.test({}, 1);
        h.test({0}, 1);
        h.test({9}, 10);
        h.test({9,9}, 100);
    }
}
