#include <stdio.h>
#include <vector>
#include "gtest/gtest.h"

using namespace std;

namespace NQueens2 {
    class Solution {
    public:
        int totalNQueens(int n) {
            vector<pair<int,int>> occupied;
            int ans = 0;
            solve(occupied, n, 0, ans);
            return ans;
        }
    private:
        void solve(vector<pair<int,int>>& occupied, int n, int row, int& ans){
            for(int i = 0; i < n; ++ i){
                if(!conflict(occupied, row, i)){
                    occupied.push_back(make_pair(row, i));
                    if(row == n - 1){
                        ans ++;
                        occupied.pop_back();
                        return;
                    }
                    solve(occupied, n, row + 1, ans);
                    occupied.pop_back();
                }
            }
        }
        bool conflict(vector<pair<int, int>>&occupied, int x, int y){
            for(auto &pos : occupied){
                if(abs(pos.first - x) == abs(pos.second - y))
                    return true;
                if(pos.first == x || pos.second == y)
                    return true;
            }
            return false;
        }
    };
    class helper{
    public:
        void test(int n, int expected){
            Solution sln;
            auto ans = sln.totalNQueens(n);
            ASSERT_EQ(expected, ans);
        }
    };
    TEST(NQueens2, totalQueens){
        helper h;
        h.test(1, 1);
        h.test(2, 0);
        h.test(4, 2);
        h.test(8, 92);
        
    }
}
