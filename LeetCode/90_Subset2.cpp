#include "shared.h"
/*
 Given a collection of integers that might contain duplicates, nums, return all possible subsets.
 
 Note:
 Elements in a subset must be in non-descending order.
 The solution set must not contain duplicate subsets.
 For example,
 If nums = [1,2,2], a solution is:
 
 [
 [2],
 [1],
 [1,2,2],
 [2,2],
 [1,2],
 []
 ]
*/
namespace Subset2{
    class Solution {
    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<vector<int>> ans;
            sort(nums.begin(), nums.end());
            for(int i = 0; i <= nums.size(); ++ i){
                subsetsWithLength(nums, i, ans);
            }
            return ans;
        }
    private:
        void subsetsWithLength(vector<int>& nums, int len,  vector<vector<int>>& ans){
            if(len == 0)
                ans.push_back({});
            
            vector<int> result;
            for(int i = 0; i + len <= nums.size(); ++ i){
                if(i > 0 && nums[i] == nums[i - 1])
                    continue;
                result.push_back(nums[i]);
                subsetsFromStart(nums, len, i + 1, result, ans);
                result.pop_back();
            }
        }
        void subsetsFromStart(vector<int>& nums, int len, int start, vector<int>& result, vector<vector<int>>& ans){
            if(result.size() == len){
                ans.push_back(result);
                return;
            }
            int size = (int)nums.size();
            for(int i = start; i < size && (len - (int)result.size()) + i <= size; ++ i){
                
                if(i > start && nums[i] == nums[i - 1])
                    continue;
                result.push_back(nums[i]);
                subsetsFromStart(nums, len, i + 1, result, ans);
                result.pop_back();
            }
        }
    };
    class helper{
    public:
        void test(vector<int> arr){
            Solution sln;
            auto actual = sln.subsetsWithDup(arr);
//            for(int i = 0; i < actual.size(); ++ i){
//                for(int j = 0; j < actual[i].size(); ++ j){
//                    cout << actual[i][j] << " ";
//                }
//                cout << endl;
//            }
        }
    };
    
    TEST(Subsets2, subsetsWithDup){
        helper h;
//        h.test({1, 2, 2});
        h.test({1, 2, 2, 3});
    }
}
