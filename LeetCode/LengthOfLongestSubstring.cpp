#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;

namespace LeetCode
{
	class Solution{
	public:
		int lengthOfLongestSubstring(string s){
			int len = s.length(), start = 0, max_len = 0, cur_len = 0;
			map<char, int> chars;
			for (int cur = 0; cur < len; ++cur){
				map<char, int>::iterator it = chars.find(s[cur]);
				if (it != chars.end()){
					int pos = it->second;
					for (int i = start; i <= pos; ++i){
						chars.erase(s[i]);
						cur_len--;
					}
					start = pos + 1;
				}
				chars.insert(pair<char, int>(s[cur], cur));
				if (++cur_len > max_len)
					max_len = cur_len;
			}
			return max_len;
		}
	};

	TEST_CLASS(LengthOfLongestSubstring)
	{
	public:
		TEST_METHOD(LengthOfLongestSubstringTest)
		{
			string s1 = "abcabcbb";
			string s2 = "bbbb";
			string s3 = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
			string s4 = "hnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqcac";
			Solution sln;
			assert_ans(sln.lengthOfLongestSubstring(s1), 3);
			assert_ans(sln.lengthOfLongestSubstring(s2), 1);
			assert_ans(sln.lengthOfLongestSubstring(s3), 12);
			assert_ans(sln.lengthOfLongestSubstring(s4), 12);
		}
	private:
		void assert_ans(int actual, int expected)
		{
			cout << "Answer: " << actual << endl;
			assert(actual == expected);
		}
	};
}