#include "shared.h"
/*
 Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 
 For example,
 Given:
 s1 = "aabcc",
 s2 = "dbbca",
 
 When s3 = "aadbbcbcac", return true.
 When s3 = "aadbbbaccc", return false.
*/
namespace InterleavingString{
    class Solution {
    public:
        bool isInterleave(string s1, string s2, string s3) {
            if(s1.length() + s2.length() != s3.length())
                return false;
            
            vector<vector<int>> record(s1.length() + 1, vector<int>(s2.length() + 1, -1));
            return validate(s1, s2, s3, 0, 0, 0, record);
        }
    private:
        bool validate(string& s1, string& s2, string& s3, int i1, int i2, int i3, vector<vector<int>>& record){
            if(i1 == s1.length() && i2 == s2.length() && i3 == s3.length())
                return true;
            
            if(i3 == s3.length() - 1){
                if(i1 == s1.length() - 1)
                    return (s1[i1] == s3[i3]) && (i2 == s2.length());
                if(i2 == s2.length() - 1){
                    return (s2[i2] == s3[i3]) && (i1 == s1.length());
                }
                return false;
            }
            
            if(i1 > s1.length() || i2 > s2.length())
                return false;
            if(record[i1][i2] >= 0)
                return record[i1][i2];
            
            bool result = false;
            bool temp1 = (s3[i3] == s1[i1] && validate(s1, s2, s3, i1 + 1, i2, i3 + 1, record));
            
            bool temp2 = (s3[i3] == s2[i2] && validate(s1, s2, s3, i1, i2 + 1, i3 + 1, record));
            
            result = temp1 || temp2;
            
            record[i1][i2] = result;
            return result;
        }
    };
    
    class helper{
    public:
        void test(string s1, string s2, string s3, bool expected){
            Solution sln;
            bool actual = sln.isInterleave(s1, s2, s3);
            ASSERT_EQ(expected, actual);
        }
    };
    TEST(InterleavingString, isInterleave){
        helper h;
        h.test("aabcc", "dbbca", "aadbbcbcac", true);
        h.test("aabcc", "dbbca", "aadbbbaccc", false);
        h.test("aa", "ab", "abaa", true);
        h.test("baababbabbababbaaababbbbbbbbbbbaabaabaaaabaaabbaaabaaaababaabaaabaabbbbaabbaabaabbbbabbbababbaaaabab", "aababaaabbbababababaabbbababaababbababbbbabbbbbababbbabaaaaabaaabbabbaaabbababbaaaababaababbbbabbbbb", "babbabbabbababbaaababbbbaababbaabbbbabbbbbaaabbabaababaabaaabaabbbaaaabbabbaaaaabbabbaabaaaabbbbababbbababbabaabababbababaaaaaabbababaaabbaabbbbaaaaabbbaaabbbabbbbaaabaababbaabababbbbababbaaabbbabbbab", false);
    }
}
