#include "shared.h"

/*
 Given a set of distinct integers, nums, return all possible subsets.
 
 Note:
 Elements in a subset must be in non-descending order.
 The solution set must not contain duplicate subsets.
 For example,
 If nums = [1,2,3], a solution is:
 
 [
 [3],
 [1],
 [2],
 [1,2,3],
 [1,3],
 [2,3],
 [1,2],
 []
 ]
*/

namespace Subsets{
    class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> ans;
            for(int i = 0; i <= nums.size(); ++ i){
                subsetsOfLength(nums, i, ans);
            }
            return ans;
        }
    private:
        void subsetsOfLength(vector<int>& nums, int len, vector<vector<int>>& ans){
            if(len == 0){
                ans.push_back({});
                return;
            }
            int size = (int)nums.size();
            for(int i = 0; i < size && i + len <= size; ++ i){
                vector<int> temp {nums[i]};
                subsetsFromIndex(nums, temp, ans, i + 1, len);
            }
        }
        void subsetsFromIndex(vector<int>& nums, vector<int>& result, vector<vector<int>>& ans, int start, int len){
            if(result.size() == len){
                ans.push_back(result);
                return;
            }
            
            int size = (int)nums.size();
            int currentLen = len - (int)result.size();
            for(int i = start; i < size && currentLen + i <= size; ++ i){
                result.push_back(nums[i]);
                subsetsFromIndex(nums, result, ans, i + 1, len);
                result.pop_back();
            }
                
        }
    };
    class helper{
    public:
        void test(vector<int> nums){
            Solution sln;
            auto result = sln.subsets(nums);
            for(auto & row: result){
                for(auto n : row){
                    cout << n << " ";
                }
                cout << endl;
            }
        }
    };
    TEST(Subsets, subsets){
        helper h;
        h.test({1, 2, 3, 4});
    }
}
