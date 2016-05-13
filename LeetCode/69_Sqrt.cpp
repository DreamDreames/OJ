#include "stdafx.h"

/*
 Implement int sqrt(int x).
 
 Compute and return the square root of x.
*/

namespace Sqrt{
    class Solution {
    public:
        int mySqrt(int x) {
			if (x <= 1)
				return x;
			return iter(x, 2.0);
        }
	private:
		double iter(double x, double guess) {
			if (abs(guess * guess - x) < 0.0001)
				return guess;

			return iter(x, (guess + x / guess) / 2);
		}
    };
	TEST_CLASS(sqrt) {
	public:
		TEST_METHOD(Sqrt) {
			Solution sln;
			Assert::AreEqual(2, sln.mySqrt(4));
			Assert::AreEqual(1, sln.mySqrt(1));
			Assert::AreEqual(3, sln.mySqrt(9));
			Assert::AreEqual(1, sln.mySqrt(2));
		}
	};
}
