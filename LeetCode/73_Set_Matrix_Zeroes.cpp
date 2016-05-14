#include "shared.h"
/*
 Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 
 click to show follow up.
 
 Follow up:
 Did you use extra space?
 A straight forward solution using O(mn) space is probably a bad idea.
 A simple improvement uses O(m + n) space, but still not the best solution.
 Could you devise a constant space solution?
*/
namespace SetMatrixZeroes {
    class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            bool row = false, col = false;
            for(int i = 0; i < matrix.size(); ++ i){
                for(int j = 0; j < matrix[i].size(); ++ j){
                    if(matrix[i][j] == 0){
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                        if(i == 0) row = true;
                        if(j == 0) col = true;
                    }
                }
            }
            
            for(int i = 1; i < matrix.size(); ++ i){
                for(int j = 1; j < matrix[i].size(); ++ j){
                    if(matrix[i][0] == 0 || matrix[0][j] == 0)
                        matrix[i][j] = 0;
                }
            }
            
            if(row){
                for(int j = 0; j < matrix[0].size(); ++ j){
                    matrix[0][j] = 0;
                }
            }
            if(col){
                for(int i = 0; i < matrix.size(); ++ i){
                    matrix[i][0] = 0;
                }
            }
        }
    };
}
