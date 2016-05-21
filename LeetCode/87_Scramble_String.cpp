#include "shared.h"
/*
 Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
 
 Below is one possible representation of s1 = "great":
 
 great
 /    \
 gr    eat
 / \    /  \
 g   r  e   at
 / \
 a   t
 To scramble the string, we may choose any non-leaf node and swap its two children.
 
 For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
 
 rgeat
 /    \
 rg    eat
 / \    /  \
 r   g  e   at
 / \
 a   t
 We say that "rgeat" is a scrambled string of "great".
 
 Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
 
 rgtae
 /    \
 rg    tae
 / \    /  \
 r   g  ta  e
 / \
 t   a
 We say that "rgtae" is a scrambled string of "great".
 
 Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

namespace ScrambleString {
    class Solution {
    public:
        bool isScramble(string s1, string s2) {
            int len = (int)s1.size();
            return dp(s1.c_str(), s2.c_str(), len);

        }
    private:
        bool dp(const char* p1, const char* p2, int len){
            if(!strncmp(p1, p2, len))
                return true;
            
            vector<int> rec (26, 0);
            for(int i = 0; i < len; ++ i){
                rec[p1[i] - 'a'] ++;
                rec[p2[i] - 'a'] --;
            }
            for(int i = 0; i < 26; ++ i){
                if(rec[i] > 0)
                    return false;
            }
                
            
            for(int i = 1; i < len; ++ i){
                if((dp(p1, p2, i) && dp(p1 + i, p2 + i, len - i)) ||
                   (dp(p1, p2 + len - i, i) && dp(p1 + i, p2, len - i)))
                    return true;
            }
            return false;
        }

    };
    
    class helper{
    public:
        void test(string s1, string s2, bool expected){
            Solution sln;
            bool actual = sln.isScramble(s1, s2);
            ASSERT_EQ(expected, actual);
        }
    };
    TEST(ScrambleString, isScramble){
        helper h;
        h.test("great", "rgeat", true);
        h.test("great", "rgtae", true);
        h.test("at", "ta", true);
        h.test("at", "at", true);
        h.test("a", "a", true);
    }
}
