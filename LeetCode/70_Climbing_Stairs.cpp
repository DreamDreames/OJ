#include "shared.h"

/*
 You are climbing a stair case. It takes n steps to reach to the top.
 
 Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

namespace ClimbingStairs{
    class Solution {
    public:
        int climbStairs(int n) {
            vector<int>records(n, -1);
            
            return climb(records, n - 1) + climb(records, n - 2);
        }
    private:
        int climb(vector<int>& records, int n){
           if(n < 0)
                return 0;
            if(n <= 1)
                return 1;
            if(n == 2)
                return 2;
            
            if(records[n] >= 0)
                return records[n];
            records[n] = climb(records, n - 1) + climb(records, n - 2);
            return records[n];
        }
    };
}
