#include "stdafx.h"
/*
 Given a string S and a string T, count the number of distinct subsequences of T in S.
 
 A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 
 Here is an example:
 S = "rabbbit", T = "rabbit"
 
 Return 3.
 */
namespace DistinctSubsequences{
	class Solution {
	public:
		int numDistinct(string s, string t) {
			if (s.length() == 0 || t.length() == 0)
				return 0;
			vector<vector<int>> record(t.length(), vector<int>(s.length(), 0));

			if (s[0] == t[0])
				record[0][0] = 1;
			for (int i = 0; i < t.length(); ++i) {
				for (int j = 1; j < s.length(); ++j) {
					if (t[i] == s[j])
						record[i][j] = (i > 0 ? record[i - 1][j - 1] : 1) + record[i][j - 1];
					else
						record[i][j] = record[i][j - 1];
				}
			}
			return record[t.length() - 1][s.length() - 1];
		}
	};
}
