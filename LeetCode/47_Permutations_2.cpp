#include <stdio.h>
#include <vector>
#include "gtest/gtest.h"

using namespace std;

/*
 Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 
 For example,
 [1,1,2] have the following unique permutations:
 [1,1,2], [1,2,1], and [2,1,1].
*/

namespace Permutations2 {
    class Solution {
    public:
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<int> per;
            vector<vector<int>> ans;
            vector<bool> status(nums.size(), false);
            iter(nums, status, per, ans);
            return ans;
        }
    private:
        void iter(vector<int>&nums, vector<bool>& status, vector<int>& per, vector<vector<int>>& ans){
            if(per.size() == nums.size()){
                ans.push_back(per);
                return;
            }
                
            for(int i = 0; i < nums.size(); ++ i){
                if(status[i])
                    continue;
                
                if(i > 0 && nums[i] == nums[i - 1] && !status[i - 1])
                    continue;
                
                status[i] = true;
                per.push_back(nums[i]);
                iter(nums, status, per, ans);
                per.pop_back();
                status[i] = false;
            }
        }
    };
    class helper {
    public:
        void test(vector<int> nums, vector<vector<int>> expected){
            Solution sln;
            auto ans = sln.permuteUnique(nums);
            ASSERT_EQ(expected.size(), ans.size());
        }
        
    };
    TEST(Permutations2, permuteUnique){
        helper h;
        h.test({1, 1, 2}, {{1, 1, 2},{1, 2, 1},{2, 1, 1}});
        h.test({1, 2}, {{1, 2},{2, 1}});
        h.test({1, 1, 2, 2}, {{1, 1, 2, 2},{1, 2, 1, 2}, {1, 2, 2, 1}, {2, 1, 2, 1}, {2, 1, 1, 2}, {2, 2, 1, 1}});
        h.test({1, 2, 3}, {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}});
        h.test({2, 2, 1, 1}, {{1,1,2,2},{1,2,1,2},{1,2,2,1},{2,1,1,2},{2,1,2,1},{2,2,1,1}});
    }
}
