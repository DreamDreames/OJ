#include "stdafx.h"
#include <string.h>
#pragma warning(disable:4146)
#define INT_MAX 2147483647
#define INT_MIN -2147483648

namespace LeetCode
{
	class Solution {
	public:
		int atoi(const char *str) {
			int len = strlen(str);
			int ans = 0;
			bool sig = false;
			char* dupStr = new char[len + 1];
			strcpy_s(dupStr, len + 1, str);
			str = trim(dupStr);
			len = strlen(str);
			for (int i = 0; i < len; ++i){
				if (i == 0){
					if (str[i] == '-'){
						sig = true;
						continue;
					}
					else if (str[i] == '+')
						continue;
				}
				if (!(str[i] >= '0' && str[i] <= '9'))
					break;

				// overflow
				if (ans > 214748364 || (ans == 214748364 && str[i] - '0' > 7))
				{
					ans = INT_MIN;
					break;
				}
				ans *= 10;
				ans += str[i] - '0';
			}
			delete dupStr;
			if (ans == INT_MIN){
				return sig ? INT_MIN : INT_MAX;
			}
			return sig ? -1 * ans : ans;
		}
	private:
		char* trim(char* str){
			while (*str && (*str == ' ' || *str == '\t'))
				str++;
			int len = strlen(str) - 1;
			if (len <= 0) return str;
			while (len && str[len] == ' ' || str[len] == '\t')
				len--;
			str[len + 1] = 0;
			return str;
		}
	};
	TEST_CLASS(atoi)
	{
	public:

		TEST_METHOD(atoiTest)
		{
			Solution sln;
			char* str = "0";
			int ans = sln.atoi(str);
			assert(ans == 0);
			str = "1234";
			ans = sln.atoi(str);
			assert(ans == 1234);
			str = "0123";
			ans = sln.atoi(str);
			assert(ans == 123);

			str = "-123";
			ans = sln.atoi(str);
			assert(ans == -123);

			str = "+3";
			ans = sln.atoi(str);
			assert(ans == 3);

			str = "    010";
			ans = sln.atoi(str);
			assert(ans == 10);

			str = "     +004500";
			ans = sln.atoi(str);
			assert(ans == 4500);

			str = "  -0012a42";
			ans = sln.atoi(str);
			assert(ans == -12);

			str = "2147483648";
			ans = sln.atoi(str);
			assert(ans == INT_MAX);

			str = "-2147483648";
			ans = sln.atoi(str);
			assert(ans == INT_MIN);

			str = "-1";
			ans = sln.atoi(str);
			assert(ans == -1);

			str = "-2147483647";
			ans = sln.atoi(str);
			assert(ans == -2147483647);

			str = "    10522545459";
			ans = sln.atoi(str);
			assert(ans == INT_MAX);
		}

	};
}