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
            vector<int> transactions(2, 0);
            calculateFrom(0, prices, transactions);
            return transactions[0] + transactions[1];
        }
    private:
        void calculateFrom(int start, vector<int>& prices, vector<int>& transactions){
            if(start >= prices.size())
                return;
            int minValue = prices[start], maxValue = prices[start], index = start + 1, profit = 0;
            while(index < prices.size()){
                if(prices[index] < prices[index - 1]){
                    break;
                }
                if(prices[index] > maxValue){
                    maxValue = prices[index];
                    profit = maxValue - minValue;
                }
                index ++;
            }
            if(profit > transactions[0]){
                transactions[0] = profit;
                if(transactions[1] < transactions[0])
                    swap(transactions[0], transactions[1]);
            }
            return calculateFrom(index, prices, transactions);
        }
    };
}
/*
 [1,2]
 [1,3,2,7]
 [1,2,4]
 [1,2,4,2,5,7,2,4,9,0]
 */
