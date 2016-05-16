#include "shared.h"

/*
 Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 
 For example,
 If n = 4 and k = 2, a solution is:
 
 [
 [2,4],
 [3,4],
 [2,3],
 [1,2],
 [1,3],
 [1,4],
 ]
*/
namespace Combinations {
    class Solution {
    public:
        vector<vector<int>> combine(int n, int k) {
            vector<vector<int>> ans;
            vector<int> result;
            iter(1, n, k, result, ans);
            return ans;
        }
    private:
        void iter(int start, int end, int k, vector<int>& result, vector<vector<int>>& ans){
            if(k == 0){
                ans.push_back(result);
                return;
            }
            for(int i = start; i <= end - k + 1; ++ i){
                result.push_back(i);
                iter(i + 1, end, k - 1, result, ans);
                result.pop_back();
            }
        }
    };
    class helper{
    public:
        void test(int n, int k){
            Solution sln;
            auto actual = sln.combine(n, k);
            for(auto &row: actual){
                for(auto n: row){
                    cout << n << " " ;
                }
                cout << endl;
            }
        }
        
    };
    TEST(Combinations, combine){
        helper h;
        h.test(4, 2);
    }
}
