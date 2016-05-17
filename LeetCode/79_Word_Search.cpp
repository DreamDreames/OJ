#include "shared.h"
/*
 Given a 2D board and a word, find if the word exists in the grid.
 
 The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 
 For example,
 Given board =
 
 [
 ['A','B','C','E'],
 ['S','F','C','S'],
 ['A','D','E','E']
 ]
 word = "ABCCED", -> returns true,
 word = "SEE", -> returns true,
 word = "ABCB", -> returns false.
*/

namespace WordSearch {
    class Solution {
    public:
        bool exist(vector<vector<char>>& board, string word) {
            if(word.empty())
                return true;
            
            if(board.size() == 0)
                return false;
            
            vector<vector<bool>> status(board.size(), vector<bool>(board[0].size(), false));
            map<char, vector<pair<int,int>>> records;
            for(int i = 0; i < board.size(); ++ i){
                for(int j = 0; j < board[i].size(); ++ j){
                    if(word[0] == board[i][j]){
                        if(search(board, status, word, 0, i, j))
                            return true;
                    }
                }
            }
            return false;
        }
    private:
        bool search(vector<vector<char>>& board, vector<vector<bool>>& status, string& word, int start, int x, int y){
            if(start == word.size())
                return true;
            if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
                return false;
            
            if(status[x][y] || word[start] != board[x][y])
                return false;
            
            status[x][y] = true;
            
            if (search(board, status, word, start + 1, x + 1, y) ||
            search(board, status, word, start + 1, x, y + 1) ||
            search(board, status, word, start + 1, x - 1, y) ||
            search(board, status, word, start + 1, x, y - 1))
                return true;
            
            status[x][y] = false;
            return false;
        }
    };
}
