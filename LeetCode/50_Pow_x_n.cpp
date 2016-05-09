#include "stdafx.h"

using namespace std;

namespace Powxn {
	class Solution {
	public:
		double myPow(double x, int n) {
			if (x == 1)
				return 1;
			if (x == -1) {
				if(n % 2 == 0) 
					return 1;
				return -1;
			}
			if (x == 0)
				return 0;
			if (n == 0)
				return 1;
			if (n == 1)
				return x;
			if (n == -1)
				return 1 / x;
			if (n % 2 == 0) {
				double half = myPow(x, n / 2);
				return half * half;
			}
			if (n > 0) {
				return x * myPow(x, n - 1);
			}
			return (1 / x) * myPow(x, n + 1);
		}
	};
}