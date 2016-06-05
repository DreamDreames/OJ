#include "shared.h"
/*
 Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
 
 For example, given the following triangle
 [
      [2],
     [3,4],
    [6,5,7],
   [4,1,8,3]
 ]
 The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 
 Note:
 Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/
namespace Triangle{
    class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            int size = (int)triangle.size();
            if(size == 0 || triangle[0].size() == 0)
                return 0;
            vector<int> record(size);
            record[0] = triangle[0][0];
            for(int i = 1; i < triangle.size(); ++ i){
                int prev = INT_MAX;
                for(int j = 0; j <= i; ++ j){
                    int minValue = min(j - 1 >= 0 ? prev : record[j], j <= i - 1? record[j] : prev);
                    prev = record[j];
                    record[j] = minValue + triangle[i][j];
                }
            }
            int min = record[0];
            for(int i = 1; i < record.size(); ++ i){
                if(record[i] < min)
                    min = record[i];
            }
            return min;
            
        }
    };
    TEST(Triangle, minimumTotal){
        Solution sln;
        vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
        int actual = sln.minimumTotal(triangle);
        ASSERT_EQ(11, actual);
    }
}
