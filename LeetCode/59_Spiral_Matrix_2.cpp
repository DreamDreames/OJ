#include "shared.h"
#include <stdio.h>
/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
 ]
*/
namespace SpiralMatrix2{
    class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            int direction = 0, i = 0, j = 0, current = 1, max = n * n;
            vector<vector<int>> ans(n, vector<int>(n, max + 1));
            while(true){
                if(!(i >= 0 && i < n && j >= 0 && j < n))
                    break;
                if(ans[i][j] <= max)
                    break;
                if(direction == 0){
                    ans[i][j++] = current ++;
                    if(j == n || ans[i][j] < current){
                        j --; i ++;
                        direction = 1;
                    }
                }
                else if(direction == 1){
                    ans[i++][j] = current ++;
                    if(i == n || ans[i][j] < current){
                        i --; j --;
                        direction = 2;
                    }
                }
                else if(direction == 2){
                    ans[i][j--] = current ++;
                    if(j < 0 || ans[i][j] < current){
                        j ++; i --;
                        direction = 3;
                    }
                }
                else if(direction == 3){
                    ans[i--][j] = current ++;
                    if(i < 0 || ans[i][j] < current){
                        i ++; j ++;
                        direction = 0;
                    }
                }
            }
            return ans;
        }
    };
    class helper{
    public:
        void test(int n){
            Solution sln;
            auto ans = sln.generateMatrix(n);
            for(auto &row : ans){
                for(auto n: row){
                    cout << n << " ";
                }
                cout << endl;
            }
            
        }
    };
    TEST(SpiralMatrix2, generateMatrix){
        helper h;
        h.test(3);
    }
}