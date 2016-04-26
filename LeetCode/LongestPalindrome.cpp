#include "stdafx.h"
#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

namespace LeetCode
{
	class Solution {
	private:
		void findPalindrome(const string& s, string& current_max, const int low, const int high){
			int max = current_max.length(), len = s.length(), l = low, h = high;
			while (l >= 0 && h < len){
				if (s[l] != s[h])
					break;
				int c = h - l + 1;
				if (c > max){
					current_max = s.substr(l, c);
					max = c;
				}
				l--, h++;
			}
		}
	public:
		string longestPalindrome(string s){
			int len = s.length();
			string max_str = "";
			for (int i = 0; i < len - 1; ++i){
				int l = i, h = i + 1;
				findPalindrome(s, max_str, l, h);
				l = i - 1, h = i + 1;
				findPalindrome(s, max_str, l, h);
			}
			if (max_str.length() == 0)
				return s.substr(0, 1);
			return max_str;
		}
	};

	TEST_CLASS(LongestPalindrome)
	{
	public:
		TEST_METHOD(LongestPalindromeTest)
		{
			Solution s;
			string s1 = "tttt";
			string ans1 = s.longestPalindrome(s1);
			assert(s1 == ans1);
			string s2 = "t";
			string ans2 = s.longestPalindrome(s2);
			assert(s2 == ans2);
			string s3 = "thaahz";
			string ans3 = s.longestPalindrome(s3);
			assert(ans3 == "haah");
			string s4 = "refdashaah";
			string ans4 = s.longestPalindrome(s4);
			assert(ans4 == "haah");
			string s5 = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
			string ans5 = s.longestPalindrome(s5);
			string s6 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
			string ans6 = s.longestPalindrome(s6);
		}
	};
}