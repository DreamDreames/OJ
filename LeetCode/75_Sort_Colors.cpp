#include "shared.h"
/*
 Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 
 Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 
 Note:
 You are not suppose to use the library's sort function for this problem.
*/
namespace SortColors {
    class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int redstart = 0, bluestart = (int)nums.size() - 1;
            for(int i = 0; i <= bluestart;){
                if(nums[i] == 0){
                    if(i == redstart)
                        i ++;
                    else
                        swap(nums[i], nums[redstart]);
                    redstart ++ ;
                }
                else if(nums[i] == 2 ){
                    if(i == bluestart)
                        i ++;
                    else
                        swap(nums[i], nums[bluestart]);
                    bluestart --;
                }
                else
                    i ++;
            }
        }
    };
    class helper{
    public:
        void test(vector<int> nums, vector<int> expected){
            Solution sln;
            sln.sortColors(nums);
            for(int i = 0; i < expected.size(); ++ i){
                ASSERT_EQ(expected[i], nums[i]);
            }
        }
    };
    TEST(SortColors, sortColors){
        helper h;
        h.test({1}, {1});
        h.test({2}, {2});
        h.test({0}, {0});
        h.test({0, 1, 2}, {0, 1, 2});
        h.test({2, 1, 0}, {0, 1, 2});
        h.test({2, 1, 0, 1, 2, 0}, {0, 0, 1, 1, 2, 2});
    }
    
}
