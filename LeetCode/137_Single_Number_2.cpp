#include "shared.h"
/*
 Given an array of integers, every element appears three times except for one. Find that single one.
 
 Note:
 Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */
namespace SingleNumber2{
    class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            vector<int> bits(32, 0);
            for(auto n : nums){
                for(int i = 0; i < 32; ++ i){
                    bits[i] += n & 1;
                    n >>= 1;
                    if(n == 0) break;
                }
            }
            
            int number = 0;
            for(int i = 0; i < 32; ++ i){
                number += (bits[i] % 3) << i;
            }
            return number;
        }
    };
    
    class helper{
    public:
        void test(vector<int> nums, int expected){
            Solution sln;
            int actual = sln.singleNumber(nums);
            ASSERT_EQ(expected, actual);
        }
    };
    TEST(SingleNumber2, singleNumber){
        helper h;
        h.test({-2,-2,1,1,-3,1,-3,-3,-4,-2}, -4);
    }
}
