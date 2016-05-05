#include <stdio.h>
#include <vector>
#include "gtest/gtest.h"

using namespace std;

/*
 Given a collection of distinct numbers, return all possible permutations.
 
 For example,
 [1,2,3] have the following permutations:
 [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

namespace Permutations {
    class Solution {
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> ans;
            iter(nums, 0, ans);
            return ans;
        }
    private:
        void iter(vector<int>&nums, int start, vector<vector<int>> &ans){
            if(start == nums.size() - 1){
                ans.push_back({nums[start]});
                return;
            }
            auto value = nums[start];
            iter(nums, start + 1, ans);
            int size = (int)ans.size();
            for(int i = 0; i < size; ++ i){
                for(int j = 0; j < ans[i].size(); ++ j){
                    vector<int> newp = ans[i];
                    newp.insert(newp.begin() + j, value);
                    ans.push_back(newp);
                }
                ans[i].push_back(value);
            }
        }
    };
    class helper {
    public:
        void test(vector<int> nums, vector<vector<int>> expected){
            Solution sln;
            auto ans = sln.permute(nums);
//            for(auto &p : ans){
//                for(auto number: p){
//                    cout << number << " ";
//                }
//                cout << endl;
//            }
            ASSERT_EQ(expected.size(), ans.size());
        }
        
    };
    TEST(Permutations, permute){
        helper h;
        h.test({1, 2, 3}, {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}});
    }
}
