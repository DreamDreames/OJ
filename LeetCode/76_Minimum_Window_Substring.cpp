#include "stdafx.h"

/*
 Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

 For example,
 S = "ADOBECODEBANC"
 T = "ABC"
 Minimum window is "BANC".

 Note:
 If there is no such window in S that covers all characters in T, return the empty string "".

 If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

namespace MinimumWindowSubstring {
	struct comparator {
		bool operator()(const pair<char, int>& left, const pair<char, int>& right) {
			return left.second < right.second;
		}
	};
	class Solution {
	public:
		string minWindow(string s, string t) {
			string ans = "";
			unordered_multiset<char> tset;
			for (auto ch : t) {
				tset.insert(ch);
			}
			unordered_multiset<char> tset2(tset);
			int shortest = (int)s.length() + 1, start = 0, end = 0;
			set<pair<char, int>, comparator> counted;
			stack<pair<char, int>> uncounted;
			for (int i = 0; i < s.length(); ++i) {
				char ch = s[i];
				if (tset2.find(ch) == tset2.end())
					continue;

				auto iter = tset.find(ch);
				pair<char, int> current(ch, i);
				if (iter == tset.end()) {
					uncounted.push(current);
					if (!counted.empty() && ch == counted.begin()->first) {
						char toRemove = ch;
						while (true) {
							if (counted.begin()->first == toRemove) {
								counted.erase(counted.begin());
								if (counted.empty()) {
									counted.insert(uncounted.top());
									uncounted.pop();
									break;
								}
							}
							else {
								if (tset.empty()) {
									int larger = max(uncounted.top().second, counted.rbegin()->second);
									int less = min(counted.begin()->second, uncounted.top().second);
									int temp = larger - less + 1;
									if (temp < shortest) {
										shortest = temp;
										start = less;
									}
								}
								counted.insert(uncounted.top());
								uncounted.pop();
								if (uncounted.empty())
									break;
								toRemove = uncounted.top().first;
								if (toRemove != counted.begin()->first)
									break;
							}
						}
					}
				}
				else {
					counted.insert(current);
					tset.erase(iter);
					if (tset.empty() && !counted.empty()) {
						start = counted.begin()->second;
						shortest = counted.rbegin()->second - start + 1;
					}
				}
			}

			if (shortest > s.length())
				return "";
			return s.substr(start, shortest);
		}
	};
	class helper {
	public:
		void test(string s, string t, string expected) {
			Solution sln;
			auto actual = sln.minWindow(s, t);
			Assert::AreEqual(expected, actual);
		}
	};
	TEST_CLASS(minWindow) {
	public:
		TEST_METHOD(MinimumWindowSubstring) {
			helper h;
			//h.test("ADOBECODEBANC", "ABC", "BANC");
			//h.test("a", "aa", "");
			//h.test("bba", "ab", "ba");
			//h.test("aa", "aa", "aa");
			//h.test("bbaa", "aba", "baa");
			//h.test("aaabdabcefaecbef", "abc", "abc");
			//h.test("acbbaca", "aba", "baca");
			h.test("of_characters_and_as", "aas", "and_as");
		}
	};
}
