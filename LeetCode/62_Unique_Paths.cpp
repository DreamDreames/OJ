#include "shared.h"
#include <stdio.h>

/*
 A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 
 The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 
 How many possible unique paths are there?
 
 
 Above is a 3 x 7 grid. How many possible unique paths are there?
 
 Note: m and n will be at most 100.
*/

namespace UniquePaths {
    class Solution {
    public:
        int uniquePaths(int m, int n) {
            int t = min(m, n) - 1;
            int sum = m + n - 2;
            long long total = 1;
            int temp = t;
            for(int i = 0; i < temp; ++ i){
                total *= sum;
                sum --;
                while(t > 1 && total % t == 0){
                    total /= (t--);
                }
            }
            return static_cast<int>(total);
        }
    };
    
    class helper{
    public:
        void test(int m, int n, int expected){
            Solution sln;
            int ans = sln.uniquePaths(m, n);
            ASSERT_EQ(expected, ans);
        }
    };
    TEST(UniquePaths, uniquePaths){
        helper h;
        h.test(100, 1, 1);
        h.test(1, 100, 1);
        h.test(3, 3, 6);
        h.test(19, 13, 86493225);
       // h.test(100, 100, 1);
    }
}
