#include "shared.h"

namespace ExcelSheetColumnTitle {
    class Solution {
    public:
        string convertToTitle(int n) {
            string ans = "";
            while(n != 0){
                n --;
                ans.push_back(n % 26 + 'A');
                n /= 26;
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };
    class helper{
    public:
        void test(int n, string expected){
            Solution sln;
            string actual = sln.convertToTitle(n);
            ASSERT_EQ(expected, actual);
        }
    };
    TEST(ExcelSheetColumnTitle, convertToTitle){
        helper h;
        h.test(1, "A");
        h.test(26, "Z");
        h.test(27, "AA");
        h.test(28, "AB");
        h.test(29, "AC");
    }
}
