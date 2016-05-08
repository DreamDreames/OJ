#include <stdio.h>
#include <vector>
#include <map>
#include "gtest/gtest.h"

using namespace std;

/*
 Given an array of non-negative integers, you are initially positioned at the first index of the array.
 
 Each element in the array represents your maximum jump length at that position.
 
 Your goal is to reach the last index in the minimum number of jumps.
 
 For example:
 Given array A = [2,3,1,1,4]
 
 The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 
 Note:
 You can assume that you can always reach the last index.
*/

namespace JumpGame2 {
    class Solution {
    public:
        int jump(vector<int>& nums) {
            map<int,int> records;
            return dp(nums, 0, records);
        }
    private:
        int dp(vector<int>& nums, int src, map<int, int>& records){
            if(records.find(src) != records.end())
                return records[src];
            
            if(src >= nums.size() - 1)
                return 0;
                
            int step = nums[src] + src;
            if(step >= nums.size() - 1)
                return 1;
            
            int min = (int)nums.size();
            for(int i = step; i > src; -- i){
                int temp = dp(nums, i, records);
                if(temp < min)
                    min = temp;
            }
            records[src] = min + 1;
            return records[src];
        }
    };
    class helper{
    public:
        void test(vector<int> nums, int expected){
            Solution sln;
            auto actual = sln.jump(nums);
            ASSERT_EQ(expected, actual);
        }
    };
    TEST(JumpGame2, jump){
        helper h;
        h.test({2, 3, 1, 1, 4}, 2);
        h.test({2}, 0);
        h.test({2, 0}, 1);
        h.test({1, 2}, 1);
        h.test({1, 2, 3}, 2);
        h.test({1, 1, 1, 1}, 3);
    }
}
