#include "shared.h"
#include <stdio.h>

/*
 Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 
 For example,
 Given the following matrix:
 
 [
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
 ]
 You should return [1,2,3,6,9,8,7,4,5].
*/

namespace SpiralMatrix{
    class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> ans;
            int m = (int)matrix.size();
            if(m == 0)
                return ans;
            int n = (int)matrix[0].size();
            int top = 0, bottom = m - 1, left = 0, right = n - 1, i = 0, j = 0;
            while(true){
                ans.push_back(matrix[i][j]);
                if(i == top && j < right){
                    j ++;
                    if(j == right)
                        top ++;
                    if(i == bottom)
                        left ++;
                }
                else if(j == right && i < bottom){
                    i ++;
                    if(i == bottom)
                        right --;
                    if(j == left)
                        top ++;
                    
                }
                else if (i == bottom && j > left){
                    j --;
                    if(j == left)
                        bottom --;
                    if(i == top)
                        right --;
                }
                else if(j == left && i > top){
                    i --;
                    if(i == top)
                        left ++;
                    if(j == right)
                        bottom --;
                }
                else
                    break;
                
            }
            return ans;
        }
    };
    class helper{
    public:
        void test(vector<vector<int>>nums, vector<int> expected){
            Solution sln;
            auto ans = sln.spiralOrder(nums);
            ASSERT_EQ(expected.size(), ans.size());
            for(int i = 0; i < expected.size(); ++ i){
                ASSERT_EQ(expected[i], ans[i]);
            }
        }
    };
    TEST(SpiralMatrix, spiralOrder ){
        helper h;
        h.test({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {1,2,3,6,9,8,7,4,5});
        h.test({}, {});
        h.test({{2, 3}}, {2, 3});
        h.test({{3},{2}}, {3, 2});
        h.test({{2, 5, 8}, {4, 0, -1}}, {2,5,8,-1,0,4});
    }
}
