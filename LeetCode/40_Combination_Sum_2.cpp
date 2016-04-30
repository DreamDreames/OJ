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
            return combination2(candidates, 0, target);
        }
    private:
        vector<vector<int>> combination2(vector<int>& candidates, int start, int target){
            vector<vector<int>> ans;
            for(int i = start; i < _size && candidates[i] <= target; ++ i){
                int rest = target - candidates[i];
                if(rest < 0)
                    continue;
                if(rest == 0)
                    ans.push_back({candidates[i]});
                else {
                    auto temp = combination2(candidates, i + 1, rest);
                    if(temp.size() == 0)
                        continue;
                    for(auto& r: temp){
                        vector<int> result = {candidates[i]};
                        result.insert(result.end(), r.begin(), r.end());
                        ans.push_back(result);
                    }
                }
                while(i < _size && candidates[i] == candidates[i + 1])
                    ++ i;
            }
            return ans;
        }

    private:
        int _size;
    };
class helper2{
    public:
        void test(vector<int> candidates, int target, vector<vector<int>> expected){
            Solution sln;
            auto actual = sln.combinationSum2(candidates, target);
            for(auto &result: actual){
                for(auto r: result)
                    cout << r << ", ";
                cout << endl;
            }
            ASSERT_EQ(expected.size(), actual.size());
        }
    };
    
    TEST(CombinationSum2, combinationSum2){
        helper2 h;
        h.test({10,1,2,7,6,1,5}, 8, {{1, 7}, {1, 2, 5}, {2, 6}, {1, 1, 6}});
        h.test({2,2,2}, 4, {{2, 2}});
        h.test({1, 1}, 1, {{1}});
    }}
