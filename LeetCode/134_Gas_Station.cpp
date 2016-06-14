#include "stdafx.h"
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
			for (int i = 0; i < gas.size(); ++i){
				if (canReach(gas, cost, i, i, 0))
					return 1;
			}
			return -1;
		}
	private:
		bool canReach(vector<int>& gas, vector<int>& cost, int startIndex, int endIndex, int currentGas){
			currentGas = currentGas + gas[startIndex] - cost[startIndex];
			if (currentGas < 0)
				return false;
			
			startIndex = (startIndex + 1) % gas.size();
			if (startIndex == endIndex)
				return true;

			return canReach(gas, cost, startIndex, endIndex, currentGas);
		}
	};
}