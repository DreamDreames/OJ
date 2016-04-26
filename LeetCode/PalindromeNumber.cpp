#include "stdafx.h"
#include <assert.h>

namespace LeetCode
{
	class Solution {
	public:
		bool isPalindrome(int x) {
			if (x < 0) return false;
			int y = x;
			int reversedX = 0;
			while (x){
				reversedX *= 10;
				reversedX += x % 10;
				x /= 10;
			}
			return reversedX == y;
		}
	};

	TEST_CLASS(PalindromeNumber)
	{
	public:

		TEST_METHOD(PalindromeNumberTest)
		{
			Solution s;
			int x = 1;
			assert(s.isPalindrome(x) == true);
			x = 22;
			assert(s.isPalindrome(x) == true);
			x = 121;
			assert(s.isPalindrome(x) == true);
			x = 21;
			assert(s.isPalindrome(x) == false);
			x = -2147447412;
			assert(s.isPalindrome(x) == false);
		}
	};
}