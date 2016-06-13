#include "shared.h"
/*
 Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 
 A region is captured by flipping all 'O's into 'X's in that surrounded region.
 
 For example,
 X X X X
 X O O X
 X X O X
 X O X X
 After running your function, the board should be:
 
 X X X X
 X X X X
 X X X X
 X O X X
 */
namespace SurroundedRegions {
    class Solution {
    public:
        void solve(vector<vector<char>>& board) {
            int row = (int) board.size();
            if(row == 0)
                return;
            int col = (int)board[0].size();
            queue<pair<int,int>> q;
            for(int i = 0; i < row; ++ i){
                if(board[i][0] == 'O')
                    q.push({i, 0});
                if(board[i][col - 1] == 'O')
                    q.push({i, col -1});
            }
            
            for(int j = 0; j < col; ++ j){
                if(board[0][j] == 'O')
                    q.push({0, j});
                if(board[row - 1][j] == 'O')
                    q.push({row - 1, j});
            }
            while(!q.empty()){
                auto c = q.front();
                q.pop();
                int x = c.first, y = c.second;
                if(board[x][y] != 'O')
                    continue;
                board[x][y] = 'W';
                if(isValid(board, x, y + 1))
                    q.push({x, y + 1});
                if(isValid(board, x, y - 1))
                    q.push({x, y - 1});
                if(isValid(board, x - 1, y))
                    q.push({x - 1, y});
                if(isValid(board, x + 1, y))
                    q.push({x + 1, y});
            }
            for(int i = 0; i < row; ++ i){
                for(int j = 0; j < col; ++ j){
                    if(board[i][j] == 'W')
                        board[i][j] = 'O';
                    else if(board[i][j] == 'O')
                        board[i][j] = 'X';
                }
            }
        }
    private:
        bool isValid(vector<vector<char>>&board, int x, int y){
            if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
                return false;
            return board[x][y] == 'O';
        }
    };
}
