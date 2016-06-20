#include "shared.h"

namespace MajorityElement {
    class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            stack<int> stk;
            for(auto num : nums){
                if(stk.empty()){
                    stk.push(num);
                }
                else if(num == stk.top()){
                    stk.push(num);
                }
                else{
                    stk.pop();
                }
            }
            if(stk.empty())
                return 0;
            return stk.top();
        }
    };
}
