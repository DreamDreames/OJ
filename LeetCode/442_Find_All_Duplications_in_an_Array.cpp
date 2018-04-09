#include "shared.h"

/*
 Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 
 Find all the elements that appear twice in this array.
 
 Could you do it without extra space and in O(n) runtime?
 
 Example:
 Input:
 [4,3,2,7,8,2,3,1]
 
 Output:
 [2,3]
 */

namespace FindAllDuplicationsInAnArray {
    class Solution {
    public:
        vector<int> findDuplicates(vector<int>& nums) {
            vector<int> ans;
            for(int i = 0; i < nums.size(); ++ i) {
                while(nums[i] - 1 != i && nums[i] != 0) {
                    if(nums[i] == nums[nums[i] - 1]){
                        ans.push_back(nums[i]);
                        nums[i] = 0;
                        break;
                    }
                    else
                        swap(nums[i], nums[nums[i] - 1]);
                }
            }
            return ans;
        }
    };
}
