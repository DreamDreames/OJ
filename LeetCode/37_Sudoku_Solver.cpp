#include <stdio.h>
#include <vector>
#include <set>
#include <stack>
#include "gtest/gtest.h"

using namespace std;

/*
 Write a program to solve a Sudoku puzzle by filling the empty cells.
 
 Empty cells are indicated by the character '.'.
 
 You may assume that there will be only one unique solution.
*/

namespace LeetCode {
    class Solution {
    public:
        void solveSudoku(vector<vector<char>>& board) {
            solve(board);
        }
        
        bool solve(vector<vector<char>>& board) {
            int i, j, t;
            for(i = 0; i < board.size(); ++ i){
                auto &row = board[i];
                for(j = 0; j < row.size(); ++ j){
                    if(row[j] != '.')
                        continue;
                    for(t = 1; t <= 9; ++ t){
                        board[i][j] = t + '0';
                        if(isValidSudoku(board, i, j) && solve(board))
                            return true;
                        
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
            return true;
        }
    private:
        
        bool isValidSudoku(vector<vector<char>>& board, int x, int y) {
            auto ch = board[x][y];
            int i, j;
            for(i = 0; i < board.size(); ++ i){
                if( i == x)
                    continue;
                if( board[i][y] == ch)
                    return false;
            }
            
            for( j = 0; j < board[x].size(); ++ j){
                if(j == y)
                    continue;
                if(board[x][j] == ch)
                    return false;
            }
            
            int ax = x / 3, ay = y / 3;
            for(i = ax * 3; i < ax * 3 + 3; ++ i){
                for(j = ay * 3; j < ay * 3 + 3; ++ j){
                    if(i == x && j == y)
                        continue;
                    if(board[i][j] == ch)
                        return false;
                }
            }
            return true;
        }
    };
    
    class helper{
    public:
        void test(vector<vector<char>> input, vector<vector<char>> expected){
            Solution sln;
            sln.solveSudoku(input);
            for(int i = 0; i < expected.size(); ++ i){
                auto &row = expected[i];
                for(int j = 0; j < row.size(); ++ j){
                    ASSERT_EQ(expected[i][j], input[i][j]);
                }
            }
        }
        void test(vector<string> input, vector<string> expected){
            vector<vector<char>> newInput, newExpected;
            for(auto& str : input){
                vector<char> chs;
                for(auto ch: str){
                    chs.push_back(ch);
                }
                newInput.push_back(chs);
            }
            for(auto& str: expected){
                vector<char> chs;
                for(auto ch: str){
                    chs.push_back(ch);
                }
                newExpected.push_back(chs);
            }
            test(newInput, newExpected);
        }
    };
    TEST(Sudoku_Solver, solveSudoku){
        helper h;
        h.test({"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."}, {"519748632","783652419","426139875","357986241","264317598","198524367","975863124","832491756","641275983"});
    }
}
