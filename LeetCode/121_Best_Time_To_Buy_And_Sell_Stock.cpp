#include "shared.h"
/*
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 */
namespace BestTimeToBuyAndSellStock{
    class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            if(prices.size() == 0)
                return 0;
            int minValue = prices[0], maxValue = prices[0], ans = 0;
            for(int i = 1; i < prices.size(); ++ i){
                if(prices[i] < minValue){
                    minValue = prices[i];
                    maxValue = minValue;
                }
                if(prices[i] > maxValue){
                    maxValue = prices[i];
                    ans = max(maxValue - minValue, ans);
                }
            }
            return ans;
        }
    };
}
