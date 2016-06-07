#include "shared.h"
/*
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */
namespace BestTimeToBuyAndSellStock2 {
    class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            return calculateFrom(0, prices);
        }
    private:
        int calculateFrom(int start, vector<int>& prices){
            if(start >= prices.size())
                return 0;
            int minValue = prices[start], maxValue = prices[start], index = start + 1, profit = 0;
            while(index < prices.size()){
                if(prices[index] < prices[index - 1])
                    return profit + calculateFrom(index, prices);
                
                if(prices[index] > maxValue){
                    maxValue = prices[index];
                    profit = maxValue - minValue;
                }
                index ++;
            }
            return profit;
        }
    };
}
