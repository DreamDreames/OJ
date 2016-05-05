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
            vector<vector<int>> ans;
            ans.push_back(nums);
            vector<int> p = nums;
            int i, j;
            for(i = 1; i < p.size(); ++ i){
                if(p[i] == p[i - 1]){
                    continue;
                }
                for(j = i; j >= 1; -- j){
                    if(p[j] == p[j - 1])
                        break;
                    swap(p[j - 1], p[j]);
                    ans.push_back(p);
                }
              
            }
            return ans;
        }
    };
    class helper {
    public:
        void test(vector<int> nums, vector<vector<int>> expected){
            Solution sln;
            auto ans = sln.permuteUnique(nums);
            for(auto &p : ans){
                for(auto number: p){
                    cout << number << " ";
                }
                cout << endl;
            }
            ASSERT_EQ(expected.size(), ans.size());
        }
        
    };
    TEST(Permutations2, permuteUnique){
        helper h;
        h.test({1, 1, 2}, {{1, 1, 2},{1, 2, 1},{2, 1, 1}});
        h.test({1, 2}, {{1, 2},{2, 1}});
        h.test({1, 1, 2, 2}, {{1, 1, 2, 2},{1, 2, 1, 2}, {1, 2, 2, 1}, {2, 1, 2, 1}, {2, 2, 1, 1}});
        h.test({1, 2, 3}, {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}});
    }
}
