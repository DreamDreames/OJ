#include <stdio.h>
#include <vector>
#include "gtest/gtest.h"


using namespace std;
/*
 Given a sorted array of integers, find the starting and ending position of a given target value.
 
 Your algorithm's runtime complexity must be in the order of O(log n).
 
 If the target is not found in the array, return [-1, -1].
 
 For example,
 Given [5, 7, 7, 8, 8, 10] and target value 8,
 return [3, 4].
*/

namespace SearchForaRange {
    class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> ans;
            int len = (int)nums.size();
            int l = searchLeft(nums, 0, len - 1, target);
            int r = searchRight(nums, 0, len -1, target);
            ans.push_back(l);
            ans.push_back(r);
            return ans;
        }
        int searchLeft(vector<int>& nums, int low, int high, int target){
            if(low > high)
                return -1;
            
            int mid = (low + high) / 2;
            if(nums[mid] == target){
                if(mid > 0 && nums[mid - 1] < target)
                    return mid;
                if(mid == 0)
                    return 0;
                return searchLeft(nums, low, mid - 1, target);
            }
            if(nums[mid] < target){
                return searchLeft(nums, mid + 1, high, target);
            }
            return searchLeft(nums, low, mid - 1, target);
        }
        
        int searchRight(vector<int>& nums, int low, int high, int target){
            if(low > high)
                return -1;
            
            int mid = (low + high) / 2;
            if(nums[mid] == target){
                if(mid < high && nums[mid + 1] > target){
                    return mid;
                }
                if(mid == high){
                    return high;
                }
                return searchRight(nums, mid + 1, high, target);
            }
            if(nums[mid] > target)
                return searchRight(nums, low, mid - 1, target);
            
            return searchRight(nums, mid + 1, high, target);
        }
    };
    
    class helper{
    public:
        void test(vector<int> nums, int target, vector<int> expected){
            Solution sln;
            auto ans = sln.searchRange(nums, target);
            ASSERT_EQ(expected[0], ans[0]);
            ASSERT_EQ(expected[1], ans[1]);
        }
    };
    TEST(SEARCH_for_a_RANGE, searchRange){
        helper h;
        h.test({5, 7, 7, 8, 8, 10}, 8, {3, 4});
        h.test({5, 7, 7, 8, 8, 10}, 9, {-1, -1});
        h.test({5, 7, 7, 8, 8, 10}, 5, {0, 0});
        h.test({5, 7, 7, 8, 8, 10}, 10, {5, 5});
        h.test({5, 6, 7, 7, 8, 8, 10}, 6, {1, 1});
    }
}