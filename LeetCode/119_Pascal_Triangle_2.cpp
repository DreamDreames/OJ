#include "shared.h"

namespace PascalTriangle2 {
    class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            vector<int> ans (rowIndex + 1, 0);
            int pre = 1;
            for(int i = 0; i <= rowIndex; ++ i){
                for(int j = 0; j <= i; ++ j){
                    if(j == 0 || j == i){
                        ans[j] = 1;
                        pre = 1;
                    }
                    else{
                        int temp = ans[j] + pre;
                        pre = ans[j];
                        ans[j] = temp;
                    }
                }
            }
            return ans;
        }
    };
}
