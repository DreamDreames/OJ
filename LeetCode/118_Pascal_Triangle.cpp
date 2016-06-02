#include "shared.h"
/*
 Given numRows, generate the first numRows of Pascal's triangle.
 
 For example, given numRows = 5,
 Return
 
 [
 [1],
 [1,1],
 [1,2,1],
 [1,3,3,1],
 [1,4,6,4,1]
 ]
 */
namespace PascalTriangle{
    class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> ans;
            for(int i = 0; i < numRows; ++ i){
                vector<int> temp;
                for(int j = 0; j <= i; ++ j){
                    if(j == 0 || j == i)
                        temp.push_back(1);
                    else
                        temp.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
                }
                ans.push_back(move(temp));
            }

            return ans;
        }
    };
}
