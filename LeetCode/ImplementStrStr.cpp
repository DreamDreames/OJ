#include "stdafx.h"
#include <string>

using namespace std;

namespace LeetCode
{
	class Solution{
	public:
		int strStr(string heyStack, string needle){
			int stackSize = heyStack.size(), needleSize = needle.size();
			if (needleSize == 0)
				return 0;
			if (stackSize == 0 || needleSize == 0)
				return -1;
			for (int i = 0; i < stackSize; ++i){
				if (i + needleSize > stackSize)
					return -1;
				for (int j = 0; j < needleSize; ++j){
					if (heyStack[i + j] != needle[j])
						break;
					if (j == needleSize - 1)
						return i;
				}
			}
			return -1;
		}
	};

	TEST_CLASS(ImplementStrStr)
	{
	public:
		TEST_METHOD(ImplementStrStrTest)
		{
			assert_helper("hey", "h", 0);
			assert_helper("hey", "he", 0);
			assert_helper("hey", "ey", 1);
			assert_helper("hey", "y", 2);
			assert_helper("hey", "hey", 0);
			assert_helper("h", "h", 0);
			assert_helper("hey", "ht", -1);
			assert_helper("hey", "t", -1);
			assert_helper("", "", 0); 
			assert_helper("mississippi", "issip", 4);
		}
	private:
		void assert_helper(string heyStack, string needle, int expected){
			Solution sln;
			int ans = sln.strStr(heyStack, needle);
			Assert::AreEqual(expected, ans);
		}
	};
}