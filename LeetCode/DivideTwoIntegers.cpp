#include "stdafx.h"

namespace LeetCode
{
	class Solution{
	public:
		int divide(int dividend, int divisor){
			if (divisor == 1)
				return dividend;

			if (divisor == -1){
				if (dividend <= INT_MIN)
					return INT_MAX;
				return -dividend;
			}
			if (isNegative(dividend)){
				if (isNegative(divisor))
					return shiftDivide(dividend, divisor);
				return -shiftDivide(dividend, -divisor);
			}

			// dividend not negative
			if (isNegative(divisor))
				return -shiftDivide(-dividend, divisor);

			return shiftDivide(-dividend, -divisor);
		}
	private:
		// both dividend and divisor are negative
		int shiftDivide(int dividend, int divisor){
			if (divisor < dividend)
				return 0;
			if (divisor == dividend)
				return 1;

			int i = -1;
			long long log = divisor;
			while (log >= dividend){
				log = log << 1;
				i++;
			}
			int base = 1 << i;
			int re = shiftDivide(dividend - (log >> 1), divisor);
			return base + re;
		}
		bool isNegative(int v){
			return v < 0;
		}
	};

	TEST_CLASS(DivideTwoIntegers)
	{
	public:
		TEST_METHOD(DivideTwoIntegersTest)
		{
			helper(4, 2, 2);
			helper(9, 3, 3);
			helper(9, 2, 4);
			helper(4, 4, 1);
			helper(4, 5, 0);
			helper(4, 1, 4);
			helper(-4, 1, -4);
			helper(4, -1, -4);
			helper(-4, -1, 4);
			helper(-2147483648, -3, 715827882);
			helper(1004958205, -2137325331, 0);
		}
	private:
		void helper(int dd, int di, int expected){
			Solution sln;
			int ans = sln.divide(dd, di);
			Assert::AreEqual(expected, ans);
		}
	};
}

/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/