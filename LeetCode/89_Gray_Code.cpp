#include "shared.h"
/*
 The gray code is a binary numeral system where two successive values differ in only one bit.
 
 Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
 
 For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 
 00 - 0
 01 - 1
 11 - 3
 10 - 2
 Note:
 For a given n, a gray code sequence is not uniquely defined.
 
 For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
 
 For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/
namespace GrayCode{
    class Solution {
    public:
        vector<int> grayCode(int n) {
            vector<int> ans;
            ans.push_back(0);
            int step = 1;
            for(int i = 1; i <= n; ++ i){
                for(int j = (int)ans.size() - 1; j >= 0; -- j){
                    ans.push_back(ans[j] + step);
                }
                step *= 2;
            }
            return ans;
        }
    };
    class helper{
    public:
        void test(int n){
            Solution sln;
            vector<int> actual = sln.grayCode(n);
//            for(int i = 0; i < actual.size(); ++ i){
//                cout << actual[i] << " ";
//            }
//            cout << endl;
        }
    };
    TEST(GrayCode, grayCode){
        helper h;
        h.test(0);
        h.test(1);
        h.test(2);
        h.test(3);
    }
}
