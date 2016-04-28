#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
/*
 Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 
 The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 
 
 A partially filled sudoku which is valid.
 
 Note:
 A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
 
*/

namespace LeetCode {
    class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            vector<vector<pair<int, int> > > records;
            int i,j;
            for(i = 0; i < 10; ++ i){
                vector<pair<int,int>> t;
                records.push_back(t);
            }
            for( i = 0; i < board.size(); ++ i){
                auto& row = board[i];
                for(j = 0; j < row.size(); ++ j){
                    if(row[j] == '.')
                        continue;
                    int index = row[j] - '0';
                    
                    if(!valid(records[index], i,j))
                        return false;
                    records[index].push_back(make_pair(i, j));
                }
            }
            
            return true;
        }
    private:
        bool valid(vector<pair<int, int> > &recs, int x, int y){
            for(auto &point: recs){
                if(point.first == x || point.second == y)
                    return false;
                if((point.first / 3 == x / 3) && (point.second / 3 == y / 3) && (abs(point.first - x) < 3) && (abs(point.second - y) < 3))
                    return false;
            }
            return true;
        }
    };
}
