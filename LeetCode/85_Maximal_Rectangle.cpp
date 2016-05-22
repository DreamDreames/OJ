#include "shared.h"

/*
Given a 2D binary matrix filled with 0's and 1's, 
find the largest rectangle containing all ones and return its area.
*/

namespace MaximalRectangle{
    class Solution {
    public:
        int maximalRectangle(vector<vector<char>>& matrix) {
            if(matrix.size() == 0)
                return 0;
            vector<vector<int>> records(matrix.size(), vector<int>(matrix[0].size(), 0));
            for(int i = 0; i < matrix.size(); ++ i){
                for(int j = 0; j < matrix[i].size(); ++ j){
                    if(matrix[i][j] == '0')
                        records[i][j] = 0;
                    else
                        records[i][j] = i > 0 ? records[i - 1][j] + 1 : 1;
                }
            }
            int area = 0;
            for(int i = 0; i < records.size(); ++ i){
                int temp = maxArea(records[i]);
                if(temp > area)
                    area = temp;
            }
            return area;
        }
    private:
        int maxArea(vector<int>& bars){
            int area = bars[0];
            for(int i = 0; i < bars.size(); ++ i){
                if(i + 1 < bars.size() && bars[i] <= bars[i + 1])
                    continue;
                
                int minHeight = bars[i];
                if(minHeight > area)
                    area = minHeight;
                for(int j = i - 1; j >= 0; --j){
                    if(bars[j] < minHeight)
                        minHeight = bars[j];
                    int temp = (i - j + 1) * minHeight;
                    if(temp > area)
                        area = temp;
                }
            }
            return area;
        }
    };
    class helper{
    public:
        void test(vector<string> matrix, int expected){
            Solution sln;
            vector<vector<char>> newMatrix;
            for(int i = 0; i < matrix.size(); ++ i){
                vector<char> temp (matrix[i].begin(), matrix[i].end());
                newMatrix.push_back(move(temp));
            }
            int actual = sln.maximalRectangle(newMatrix);
            ASSERT_EQ(expected, actual);
        }
    };
    TEST(MaximalRectangle, MaximalRectangle){
        helper h;
//        h.test({"01"}, 1);
        h.test({"1101","1101","1111"}, 6);
        h.test({"01101","11010","01110","11110","11111","00000"}, 9);
    }
}
