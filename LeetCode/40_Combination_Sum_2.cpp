#include <stdio.h>
#include <vector>
#include <iterator>
#include "gtest/gtest.h"

using namespace std;
/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
*/

namespace LeetCode {
    
    class Solution {
    public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            _size = (int)candidates.size();
            std::sort(candidates.begin(), candidates.end());
            vector<vector<int>> ans;
            vector<int> result;
            combination2(candidates, 0, target, result, ans);
            return ans;
        }
    private:
        void combination2(vector<int>& candidates, int start, int target, vector<int>& result, vector<vector<int>>& ans){
            for(int i = start; i < _size; ++ i){
                int rest = target - candidates[i];
                if(rest < 0)
                    return;
                result.push_back(candidates[i]);
                if(rest == 0){
                    ans.push_back(result);
                    result.pop_back();
                    return;
                }
                combination2(candidates, i + 1, rest, result, ans);
                result.pop_back();
                while(i < _size - 1 && candidates[i] == candidates[i + 1])
                    ++ i;
            }
        }
    private:
        int _size;
    };
class helper2{
    public:
        void test(vector<int> candidates, int target, vector<vector<int>> expected){
            Solution sln;
            auto actual = sln.combinationSum2(candidates, target);
            ASSERT_EQ(expected.size(), actual.size());
        }
    };
    
    TEST(CombinationSum2, combinationSum2){
        helper2 h;
        h.test({10,1,2,7,6,1,5}, 8, {{1, 7}, {1, 2, 5}, {2, 6}, {1, 1, 6}});
        h.test({2,2,2}, 4, {{2, 2}});
        h.test({1, 1}, 1, {{1}});
        h.test({1, 2}, 3, {{1, 2}});
    }}
