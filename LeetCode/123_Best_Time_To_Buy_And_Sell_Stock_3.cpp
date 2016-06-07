#include "shared.h"
/*
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 Design an algorithm to find the maximum profit. You may complete at most two transactions.
 
 Note:
 You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */
namespace BestTimeToBuyAndSellStock3 {
    class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            if(prices.size() == 0)
                return 0;
            int minIndex = -1, maxIndex = -1;
            int ans = profit(prices, minIndex, maxIndex);
            if(ans == 0)
                return ans;
            return ans + profit(prices, minIndex, maxIndex);
        }
    private:
        int profit(vector<int>& prices, int& minIndex, int& maxIndex){
            int escape1 = minIndex, escape2 = maxIndex;
            int minValue = INT_MAX, maxValue = -1, tempMinIndex = -1, profit = 0;
            for(int i = 0; i < prices.size(); ++ i){
                if(i == escape1 || i == escape2)
                    continue;
                
                if(prices[i] < minValue){
                    minValue = prices[i];
                    tempMinIndex = i;
                    maxValue = prices[i];
                }
                else if(prices[i] > maxValue){
                    maxValue = prices[i];
                    int temp = maxValue - minValue;
                    if(profit < temp){
                        profit = temp;
                        maxIndex = i;
                        minIndex = tempMinIndex;
                    }
                }
            }
            return profit;
        }
    };
    class helper{
    public:
        void test(vector<int> input, int expected){
            Solution sln;
            int actual = sln.maxProfit(input);
            ASSERT_EQ(expected, actual);
        }
    };
    TEST(BestTimeToBuyAndSellStock3, maxProfit){
        helper h;
        h.test({1,2,4,2,5,7,2,4,9,0}, 13);
        h.test({1,3,2,7}, 7);
    }
}
/*
 [1,2]
 [1,3,2,7]
 [1,2,4]
 [1,2,4,2,5,7,2,4,9,0]
 */
