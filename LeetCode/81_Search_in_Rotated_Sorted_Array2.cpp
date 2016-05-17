#include "shared.h"
/*
 Follow up for "Search in Rotated Sorted Array":
 What if duplicates are allowed?
 
 Would this affect the run-time complexity? How and why?
 
 Write a function to determine if a given target is in the array.
*/
namespace SearchInRotatedSortedArray2{
    class Solution{
    public:
        bool search(vector<int>& nums, int target) {
            int size = (int)nums.size();
            return find(0, size - 1, target, nums);
        }
    private:
        bool find(int low, int high, int target, vector<int>& nums){
            if (low > high)
                return false;
            if (nums[low] < nums[high] && target < nums[low] && target > nums[high]){
                return false;
            }
            int pivot = (low + high) / 2;
            if (nums[pivot] == target)
                return true;
            int temp = find(low, pivot - 1, target, nums);
            if (temp)
                return true;
            return find(pivot + 1, high, target, nums);
        }
    };
}
