#include <stdio.h>
#include <vector>
#include <iterator>
#include "gtest/gtest.h"

using namespace std;
/*
 Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 
 The same repeated number may be chosen from C unlimited number of times.
 
 Note:
 All numbers (including target) will be positive integers.
 Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 The solution set must not contain duplicate combinations.
 For example, given candidate set 2,3,6,7 and target 7,
 A solution set is:
 [7]
 [2, 2, 3]
*/

namespace LeetCode {
    
    class Solution {
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            _size = (int)candidates.size();
            std::sort(candidates.begin(), candidates.end());
            return combination(candidates, 0, target);
        }
    private:
        vector<vector<int>> combination(vector<int>& candidates, int start, int target){
            vector<vector<int>> ans;
            for(int i = start; i < _size && candidates[i] <= target; ++ i){
                int rest = target - candidates[i];
                if(rest == 0)
                    ans.push_back({candidates[i]});
                else if(rest < 0)
                    continue;
                else {
                    auto temp = combination(candidates, i, rest);
                    if(temp.size() == 0)
                        continue;
                    for(auto& r: temp){
                        vector<int> result = {candidates[i]};
                        result.insert(result.end(), r.begin(), r.end());
                        ans.push_back(result);
                    }
                }
            }
            return ans;
        }
    private:
        int _size;
    };
class helper{
    public:
        void test(vector<int> candidates, int target, vector<vector<int>> expected){
            Solution sln;
            auto actual = sln.combinationSum(candidates, target);
            for(auto &result: actual){
                for(auto r: result)
                    cout << r << ", ";
                cout << endl;
            }
            ASSERT_EQ(expected.size(), actual.size());
        }
    };
    
    TEST(CombinationSUm, combinationSum){
        helper h;
        h.test({2, 3, 6, 7}, 7, {{7}, {2, 2, 3}});
        h.test({8, 7, 4, 3}, 11, {{3, 4, 4}, {3, 8}, {4, 7}});
    }}
