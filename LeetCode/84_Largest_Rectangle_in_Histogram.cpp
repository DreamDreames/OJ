#include "shared.h"
/*
 Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
 
 
 Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
 
 
 The largest rectangle is shown in the shaded area, which has area = 10 unit.
 
 For example,
 Given heights = [2,1,5,6,2,3],
 return 10.
*/

namespace LargestRectangleInHistogram {
    class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            int maxArea = 0;
//            for(int i = 0; i < heights.size(); ++ i){
//                
//            }
            return maxArea;
        }
    };
    class helper{
    public:
        void test(vector<int> arr, int expected){
            Solution sln;
            int actual = sln.largestRectangleArea(arr);
            ASSERT_EQ(expected, actual);
        }
    };
    TEST(LargestRectangleInHistogram, largestRectangleArea){
        helper h;
//        h.test({2, 1, 5, 6, 2, 3}, 10);
    }
}
