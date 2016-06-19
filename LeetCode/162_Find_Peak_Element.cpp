#include "shared.h"
/*
 A peak element is an element that is greater than its neighbors.
 
 Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
 
 The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
 
 You may imagine that num[-1] = num[n] = -∞.
 
 For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
 
 click to show spoilers.
 
 Note:
 Your solution should be in logarithmic complexity.
*/
namespace FindPeakElement{
    class Solution {
    public:
        int findPeakElement(const vector<int> &num) {
            int left = 0, right = (int)num.size() - 1;
            while(left <= right){
                if(left == right)
                    return left;
                int mid = (left + right) / 2;
                if(num[mid] < num[mid + 1])
                    left = mid + 1;
                else
                    right = mid;
            }
            return -1;
        }
        int findPeakElement1(vector<int>& nums) {
            int size = (int)nums.size();
            int low = 0, high = size - 1;
            while(low <= high){
                if(low == high)
                    return low;
                int middle = (low + high) / 2;
                if(middle == 0){
                    if(nums[middle] > nums[middle + 1])
                        return middle;
                    low = middle + 1;
                }
                else if (middle == size - 1){
                    if(nums[middle] > nums[middle - 1])
                        return middle;
                    high = middle - 1;
                }
                else{
                    if(nums[middle] > nums[middle - 1] && nums[middle] > nums[middle + 1])
                        return middle;
                    if(nums[middle - 1] > nums[middle])
                        high = middle - 1;
                    else low = middle + 1;
                }
            }
            return -1;
        }
    };
    class helper{
    public:
        void test(vector<int> nums, int expected){
            Solution sln;
            int actual = sln.findPeakElement(nums);
            ASSERT_EQ(expected, actual);
        }
    };
    TEST(FindPeakElement, findPeakElement){
        helper h;
        h.test({2, 1}, 0);
    }
}
