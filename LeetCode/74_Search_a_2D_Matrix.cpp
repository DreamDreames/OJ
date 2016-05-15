#include "shared.h"

/*
 Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 
 Integers in each row are sorted from left to right.
 The first integer of each row is greater than the last integer of the previous row.
 For example,
 
 Consider the following matrix:
 
 [
 [1,   3,  5,  7],
 [10, 11, 16, 20],
 [23, 30, 34, 50]
 ]
 Given target = 3, return true.
*/

namespace Search2DMatrix {
    class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int rows = (int)matrix.size();
            int low = 0, high = rows - 1;
            bool result = false;
            while(low <= high){
                int mid = (low + high) / 2;
                int right = matrix[mid][matrix[mid].size() - 1];
                int left = matrix[mid][0];
                if(target == left || target == right)
                    return true;
                if(target > left && target < right){
                    low = 0; high = (int)matrix[mid].size() - 1;
                    while(low <= high){
                        int pivot = (low + high) / 2;
                        if(matrix[mid][pivot] == target)
                            return true;
                        if(matrix[mid][pivot] < target)
                            low = pivot + 1;
                        else
                            high = pivot - 1;
                    }
                    break;
                }
                if(right < target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            return result;
        }
    };
}
