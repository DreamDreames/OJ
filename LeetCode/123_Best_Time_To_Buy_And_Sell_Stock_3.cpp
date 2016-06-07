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
            int minValue = INT_MAX, maxValue = -1, leftProfit = 0, profit = 0;
            for(int i = 0; i < prices.size(); ++ i){
                if(i > 0 && prices[i] < prices[i - 1]){
                    int rightMinValue = INT_MAX, rightMaxValue = -1, rightProfit = 0;
                    for(int j = i; j < prices.size(); ++ j){
                        if(prices[j] < rightMinValue){
                            rightMinValue = prices[j];
                            rightMaxValue = rightMinValue;
                        }
                        if(prices[j] > rightMaxValue){
                            rightMaxValue = prices[j];
                            int temp = rightMaxValue - rightMinValue;
                            if(temp > rightProfit)
                                rightProfit = temp;
                        }
                    }
                    if(rightProfit == 0)
                        return profit;
                    profit = max(leftProfit + rightProfit, profit);
                    //continue;
                }
                if(prices[i] < minValue){
                    minValue = prices[i];
                    maxValue = minValue;
                }
                if(prices[i] > maxValue){
                    maxValue = prices[i];
                    int temp = maxValue - minValue;
                    if(temp > leftProfit){
                        leftProfit = temp;
                        if(leftProfit > profit)
                            profit = leftProfit;
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
        h.test({1,2,4}, 3);
        h.test({6,1,3,2,4,7}, 7);
    }
}
/*
 [1,2]
 [1,3,2,7]
 [1,2,4]
 [1,2,4,2,5,7,2,4,9,0]
 */
