#include "shared.h"
/*
 Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 
 Note:
 You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/
namespace MergeSortedArray{
    class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int index = m + n - 1;
            int i = m - 1, j = n - 1;
            while(i >= 0 && j >= 0){
                if(nums1[i] >= nums2[j]){
                    nums1[index --] = nums1[i];
                    i --;
                }
                else{
                    nums1[index--] = nums2[j];
                    j --;
                }
            }
            while (i >= 0) {
                nums1[index --] = nums1[i --];
            }
            while(j >= 0){
                nums1[index --] = nums2[j--];
            }
        }
    };
}
