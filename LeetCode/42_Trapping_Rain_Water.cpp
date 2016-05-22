#include <stdio.h>
#include <vector>
#include <stack>
#include "gtest/gtest.h"

using namespace std;

/*
 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 
 For example,
 Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 
 
 The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*/
namespace TrappingRainWater {
    class Solution {
    public:
        int trap(vector<int>& height) {
            int maxWater = 0;
            for(int i = 1; i < (int)height.size() - 1; ++ i){
                if(!(height[i] <= height[i - 1] && height[i] <= height[i + 1]))
                    continue;
                
                int gap = min(height[i - 1], height[i + 1]) - height[i];
                maxWater += gap;
                height[i] += gap;
                
                int left = i - 1, right = i + 1;
                
                move(height, left, right);
                while(left >= 0 && right < height.size() && height[left] >= height[left + 1] && height[right] >= height[right- 1]){
                    int outerSmall = min(height[left], height[right]);
                    int innerLarge = height[left + 1], innerSmall = height[right - 1];
                    if(innerLarge < innerSmall)
                        swap(innerLarge, innerSmall);
                    maxWater += (outerSmall - innerLarge) * (right - left - 1);
                    for(int j = left + 1; j < right; ++ j){
                        height[j] += (outerSmall - innerLarge);
                    }
                    move(height, left, right);
                }
            }
            return maxWater;
        }
    private:
        void move(vector<int>& height, int& left, int & right){
            if(height[left] < height[right]){
                left --;
            }
            else if (height[left] > height[right]){
                right ++;
            }
            else{
                left --;
                right ++;
            }
        }
        
    };
    
    class helper{
    public:
        void test(vector<int> bars, int expected){
            Solution sln;
            int actual = sln.trap(bars);
            ASSERT_EQ(expected, actual);
        }
    };
    TEST(TrappingRainWater, Trap){
        helper h;
        h.test({0,1,0,2,1,0,1,3,2,1,2,1}, 6);
        h.test({}, 0);
        h.test({2, 1, 0, 2}, 3);
        h.test({5, 2, 1, 2, 1, 5}, 14);
        h.test({5,5,1,7,1,1,5,2,7,6}, 23);
    }
}