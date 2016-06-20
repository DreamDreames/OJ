#include "shared.h"

namespace ExcelSheetColumnTitle {
    class Solution {
    public:
        string convertToTitle(int n) {
            string ans = "";
            while(n){
                if (n / 27 > 0){
                    ans += (n / 27 + 'A' - 1);
                    n /= 27;
                }
                else{
                    ans += (n % 27) + 'A' - 1;
                }
            }
            return ans;
        }
    };
}
