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
            
            for(int i = 0; i < heights.size(); ++ i){
                if(i + 1 < heights.size() && heights[i] <= heights[i + 1])
                    continue;
                
                int minValue = heights[i];
                maxArea = max(heights[i], maxArea);
                
                for(int j = i - 1; j >= 0; -- j){
                    minValue = min(heights[j], minValue);
                    
                    maxArea = max((i - j + 1) * minValue, maxArea);
                }
            }
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
        h.test({2, 1, 5, 6, 2, 3}, 10);
        h.test({3}, 3);
        h.test({3, 4}, 6);
    }
}
