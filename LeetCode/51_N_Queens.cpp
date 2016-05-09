#include <stdio.h>
#include <vector>
#include "gtest/gtest.h"

using namespace std;
/*
 The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 
 
 Given an integer n, return all distinct solutions to the n-queens puzzle.
 
 Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 
 For example,
 There exist two distinct solutions to the 4-queens puzzle:
 
 [
 [".Q..",  // Solution 1
 "...Q",
 "Q...",
 "..Q."],
 
 ["..Q.",  // Solution 2
 "Q...",
 "...Q",
 ".Q.."]
 ]
*/

namespace NQueens {
    class Solution {
    public:
        vector<vector<string>> solveNQueens(int n) {
            vector<vector<string>> ans;
            vector<pair<int,int>> occupied;
            solve(occupied, n, 0, ans);
            return ans;
        }
    private:
        void solve(vector<pair<int,int>>& occupied, int n, int row, vector<vector<string>>& ans){
            for(int i = 0; i < n; ++ i){
                if(!conflict(occupied, row, i)){
                    occupied.push_back(make_pair(row, i));
                    if(row == n - 1){
                        ans.push_back(move(createMatrix(n, occupied)));
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
        vector<string> createMatrix(int n, vector<pair<int,int>>& occupied){
            vector<string> result(n, string(n, '.'));
            for(auto& pos: occupied){
                result[pos.first][pos.second] = 'Q';
            }
            return result;
        }
    };
    class helper{
    public:
        void test(int n, int expected){
            Solution sln;
            auto ans = sln.solveNQueens(n);
            ASSERT_EQ(expected, ans.size());
        }
    };
    TEST(NQueens, solveNQueens){
        helper h;
        h.test(1, 1);
        h.test(2, 0);
        h.test(4, 2);
        h.test(8, 92);
    }
}
