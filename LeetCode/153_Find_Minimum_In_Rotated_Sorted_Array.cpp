#include "shared.h"
/*
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 
 Find the minimum element.
 
 You may assume no duplicate exists in the array.
 */
namespace FindeMinimumInRotatedSortedArray{
    class Solution {
    public:
        int findMin(vector<int>& nums) {
            int middle = (int) nums.size() / 2;
            return min(findInRange(nums, nums[middle], 0, middle - 1), findInRange(nums, nums[middle], middle + 1, (int)nums.size() - 1));
        }
    private:
        int findInRange(vector<int>& nums, int currentMin, int start, int end){
            if(start > end)
                return currentMin;
            if(start == end)
                return min(currentMin, nums[start]);
            
            if(nums[start] < nums[end]){
                if(nums[start] >= currentMin)
                    return currentMin;
                return nums[start];
            }
            int middle = (start + end) / 2;
            currentMin = min(currentMin, nums[middle]);
            return min(findInRange(nums, currentMin, start, middle - 1), findInRange(nums, currentMin, middle + 1, end));
        }
    };
}
