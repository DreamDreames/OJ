#include "stdafx.h"
#include <vector>
using namespace std;

namespace LeetCode
{
	class Solution {
	public:
		vector<string> letterCombinations(string digits) {
			int len = digits.length();
			if (len == 0)
				return{};
			if (len == 1){
				int number = digits[0] - '0';
				return _numberStrMap[number];
			}

			int mid = len / 2;
			auto left = letterCombinations(digits.substr(0, mid));
			auto right = letterCombinations(digits.substr(mid, len - mid));
			return join(left, right);
		}

	private:
		vector<string>join(vector<string>&left, vector<string>&right){
			if (left.size() == 0)
				return right;
			if (right.size() == 0)
				return left;

			vector<string> ans;
			for (auto &l : left){
				for (auto&r : right){
					ans.push_back(l + r);
				}
			}
			return ans;
		}
	public:
		Solution() {
			_numberStrMap[0] = { " " };
			_numberStrMap[1] = { " " };
			_numberStrMap[2] = { "a", "b", "c" };
			_numberStrMap[3] = { "d", "e", "f" };
			_numberStrMap[4] = { "g", "h", "i" };
			_numberStrMap[5] = { "j", "k", "l" };
			_numberStrMap[6] = { "m", "n", "o" };
			_numberStrMap[7] = { "p", "q", "r", "s" };
			_numberStrMap[8] = { "t", "u", "v" };
			_numberStrMap[9] = { "w", "x", "y", "z" };
		}

	private:
		vector<string> _numberStrMap[11];
	};



	TEST_CLASS(LetterCombinationOfPhoneNumber)
	{
	public:
		TEST_METHOD(LetterCombinationOfPhoneNumberTest)
		{
			assert_helper("23", { "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" });
			assert_helper("234", { "adg", "adh", "adi", "aeg", "aeh", "aei", "afg", "afh", "afi", "bdg", "bdh", "bdi", "beg", "beh", "bei", "bfg", "bfh", "bfi", "cdg", "cdh", "cdi", "ceg", "ceh", "cei", "cfg", "cfh", "cfi" });
			assert_helper("2", {"a", "b", "c"});
			assert_helper("", {});
		}
	private:
		void assert_helper(string str, vector<string> expected){
			Solution sln;
			auto actual = sln.letterCombinations(str);
			Assert::AreEqual(expected.size(), actual.size());
			int size = expected.size();
			for (int i = 0; i < size; ++i){
				Assert::AreEqual(expected[i], actual[i]);
			}
		}

	};
}
/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/