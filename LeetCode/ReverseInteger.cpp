#include "stdafx.h"

namespace LeetCode
{
	class Solution {
	public:
		int reverse(int x) {
			if (x < 0)
				return (-1 * reverse(-1 * x));

			int ans = 0;
			while (x){
				ans *= 10;
				ans += x % 10;
				x /= 10;
			}
			return ans;
		}
	};

	TEST_CLASS(ReverseInteger)
	{
	public:

		TEST_METHOD(ReverseIntegerTest)
		{
			Solution sln;
			int x = 123;
			int ans = sln.reverse(x);
			assert(ans == 321);
			x = -123;
			ans = sln.reverse(x);
			assert(ans == -321);
			x = 0;
			ans = sln.reverse(x);
			assert(ans == 0);
		}
	};
}