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
    struct point{
        point(int x, int y, int number): x(x), y(y), number(number) {
            
        }
        int x;
        int y;
        int number;
    };
    class Solution {
    public:
        void solveSudoku(vector<vector<char>>& board) {
            int i, j;
            vector<vector<set<int>>> records;
            stack<point> stk;
            
            set<int> all;
            for(i = 1; i < 10; ++ i){
                all.insert(i);
            }
            for(i = 0; i < board.size(); ++ i){
                vector<set<int>> row;
                for(j = 0; j < board[i].size(); ++ j){
                    row.push_back(all);
                }
                records.push_back(row);
            }
            for(i = 0; i < board.size(); ++ i){
                auto &row = board[i];
                for(j = 0; j < row.size(); ++ j){
                    if(row[j] == '.')
                        continue;
                    int number = row[j] - '0';
                    records[i][j].clear();
                    records[i][j].insert(number);
                    stk.push( {i, j, number});
                }
            }
            
            clear(records, stk);
            
            for(i = 0; i < board.size(); ++ i){
                auto &row = board[i];
                for(j = 0; j < row.size(); ++ j){
//                    if(records[i][j].size() != 1){
//                        cout << "x: " <<  i << " y: " << j << " count: " << records[i][j].size() << endl;
//                    }
                    board[i][j] = *(records[i][j].begin()) + '0';
                }
            }
        }
    private:
        void clear(vector<vector<set<int>>>& records, stack<point>& stk){
            int i, j;
            while(!stk.empty()){
                auto p = stk.top();
                
                for(i = 0; i < records.size(); ++ i){
                    if(i == p.x)
                        continue;
                    auto &temp = records[i][p.y];
                    removeNumber(temp, p.number, i, p.y, stk);
                   
                }
                
                for(j = 0; j < records[p.x].size(); ++ j){
                    if(j == p.y)
                        continue;
                    auto& temp = records[p.x][j];
                    
                    removeNumber(temp, p.number, p.x, j, stk);
                }
                
                int ax = p.x / 3, ay = p.y /3;
                for(i = ax * 3; i < ax * 3 + 3; ++ i){
                    for(j = ay * 3; j < ay * 3 + 3; ++ j){
                        if(i == p.x && j == p.y)
                            continue;
                        auto& temp = records[i][j];
                        removeNumber(temp, p.number, i, j, stk);
                    }
                }
                
                stk.pop();
            }
        }
        
        void removeNumber(set<int>& set, int number, int i, int j, stack<point>& stk){
            auto f = set.find(number);
            if(f == set.end())
                return;
            set.erase(f);
            if(set.size() == 1)
                stk.push(point(i, j, *(set.begin())));
            return;
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
