#include "shared.h"
/*
 Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
 
 The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 
 You may assume that each input would have exactly one solution and you may not use the same element twice.
 
 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2
*/
namespace TwoSum2 {
    class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            vector<int> ans;
            int lastj = numbers.size();
            for(int i = 0; i < numbers.size() - 1; ++ i) {
                for(int j = i + 1; j < lastj; ++ j) {
                    if(numbers[i] + numbers[j] > target) {
                        lastj = j;
                        break;
                    }
                    if(numbers[i] + numbers[lastj - 1] < target) {
                        break;
                    }
                    if(numbers[i] + numbers[j] == target) {
                        ans.push_back(i + 1);
                        ans.push_back(j + 1);
                        return ans;
                    }
                }
            }
            return ans;
        }
    };
}
