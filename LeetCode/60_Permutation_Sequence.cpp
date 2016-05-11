#include "shared.h"
#include <stdio.h>
/*
 The set [1,2,3,…,n] contains a total of n! unique permutations.
 
 By listing and labeling all of the permutations in order,
 We get the following sequence (ie, for n = 3):
 
 "123"
 "132"
 "213"
 "231"
 "312"
 "321"
 Given n and k, return the kth permutation sequence.
 
 Note: Given n will be between 1 and 9 inclusive.
*/

namespace PermutationSequence {
    class Solution {
    public:
        string getPermutation(int n, int k) {
            vector<int> numbers;
            for(int i = 1; i <= n; ++ i){
                numbers.push_back(i);
            }
            return get(numbers, k);
        }
    private:
        string get(vector<int>& nums, int k){
            int size = (int)nums.size();
            if(size == 0)
                return "";
            
            if(size == 1)
                return to_string(nums[0]);
            
            int count = permutationCount(size - 1);
            if(k <= count){
                int temp = nums[0];
                nums.erase(nums.begin());
                return to_string(temp) + get(nums, k);
            }
            if(k > count * size)
                return "";
            
            int sum = count;
            for(auto iter = nums.begin(); iter != nums.end(); ++ iter){
                if(sum >= k){
                    int temp = *iter;
                    nums.erase(iter);
                    return to_string(temp) + get(nums, k - (sum - count));
                }
                
                sum += count;
            }
            return "";
        }
        int permutationCount(int n){
            int count = 1;
            while(n){
                count *= (n--);
            }
            return count;
        }
    };
    
    class helper{
    public:
        void test(int n, int k, string expected){
            Solution sln;
            string ans = sln.getPermutation(n, k);
            ASSERT_EQ(expected, ans);
        }
    };
    TEST(PermutationSequence, getPermutation){
        helper h;
        h.test(3, 1, "123");
        h.test(3, 2, "132");
        h.test(3, 3, "213");
        h.test(1, 1, "1");
    }
}
