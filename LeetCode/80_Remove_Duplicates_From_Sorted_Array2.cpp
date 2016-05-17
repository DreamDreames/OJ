#include "shared.h"

/*
 Follow up for "Remove Duplicates":
 What if duplicates are allowed at most twice?
 
 For example,
 Given sorted array nums = [1,1,1,2,2,3],
 
 Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

namespace RemoveDuplicatesFromSortedArray2{
    class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if(nums.size() == 0)
                return 0;
            
            int current = nums[0], index = 1, count = 1;
            
            for(int i = 1; i < nums.size(); ++ i){
                if(current == nums[i]){
                    if( count ++ == 1){
                        nums[index++] = current;
                    }
                }
                else{
                    count = 1;
                    nums[index ++] = nums[i];
                    current = nums[i];
                }
            }
            return index;
        }
    };
    class helper{
    public:
        void test(vector<int> nums, vector<int> expected){
            Solution sln;
            int actual = sln.removeDuplicates(nums);
            ASSERT_EQ(expected.size(), actual);
            for(int i = 0; i < expected.size(); ++ i){
                ASSERT_EQ(expected[i], nums[i]);
            }
        }
    };
    TEST(RemoveDuplicatesFromSortedArray2, removeDuplicates){
        helper h;
        h.test({1, 2, 2, 2}, {1, 2, 2});
        h.test({1, 1, 1, 1, 3, 3}, {1, 1, 3, 3});
    }
}
