#include "shared.h"
/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/
namespace GasStation{
    class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            unordered_map<int, int> record;
            for (int i = 0; i < gas.size(); ++i){
                if (canReach(gas, cost, i, i, 0, record))
                    return i;
            }
            return -1;
        }
    private:
        bool canReach(vector<int>& gas, vector<int>& cost, int startIndex, int endIndex, int currentGas, unordered_map<int, int>& record){
            if(record.find(startIndex) != record.end()){
                if(record[startIndex] > currentGas)
                    return false;
            }
            int tempGas = currentGas;
            int tempIndex = startIndex;
            
            currentGas = currentGas + gas[startIndex] - cost[startIndex];
            if (currentGas < 0){
                return false;
            }
            
            startIndex = (startIndex + 1) % gas.size();
            if (startIndex == endIndex)
                return true;
            
            if(!canReach(gas, cost, startIndex, endIndex, currentGas, record)){
                if(record.find(tempIndex) != record.end()){
                    if(tempGas > record[tempIndex])
                        record[tempIndex] = tempGas;
                }
                else
                    record[tempIndex] = tempGas;
                return false;
            }
            return true;
        }
        
    };
    class helper{
    public:
        void test(vector<int> gas, vector<int> cost, int expected){
            Solution sln;
            int actual = sln.canCompleteCircuit(gas, cost);
            ASSERT_EQ(expected, actual);
        }
    };
    TEST(GasStation, canCompleteCircuit){
        helper h;
        h.test({5}, {4}, 0);
    }
}