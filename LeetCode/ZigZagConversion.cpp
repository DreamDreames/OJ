#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

namespace LeetCode
{
	class Solution{
	public:
		string convert(string s, int nRows){
			int len = s.length(), i, j;
			int nCol = (len * 2) / nRows;
			char ** table = new char*[nRows + 3];
			for (i = 0; i < nRows; ++i){
				table[i] = new char[nCol];
				memset(table[i], 0, nCol);
			}

			int r = 0, c = 0;
			bool rowInc = true;
			for (i = 0; i < len; ++i) {
				if (r == 0)
					rowInc = true;
				if (r == nRows){
					rowInc = false;
				}
				table[r][c] = s[i];

				if (rowInc)
					r++;
				else {
					r--; c++;
				}
			}

			string ans = "";
			for (i = 0; i < nRows; ++i) {
				for (j = 0; j < nCol; ++j)
					if (table[i][j] != 0)
						ans.push_back(table[i][j]);
			}
			for (i = 0; i < nRows; ++i)
				delete(table[i]);
			delete table;
			return ans;
		}
	};

	TEST_CLASS(ZigZagConversion)
	{
	public:
		TEST_METHOD(ZigZagConversionTest)
		{
			Solution s;
			string s1 = "PAYPALISHIRING";
			string ans1 = s.convert(s1, 3);
			assert(ans1 == "PAHNAPLSIIGYIR");
			string s2 = "ABC";
			string ans2 = s.convert(s2, 2);
			assert(ans2 == "ACB");
			string s3 = "ABCD";
			string ans3 = s.convert(s3, 2);
			assert(ans3 == "ACBD");
			string str = "ABCDE";
			string ans = s.convert(str, 4);
			assert(ans == "ABCED");
		}
	};
}