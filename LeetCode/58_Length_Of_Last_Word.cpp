#include <stdio.h>
#include <string>
#include "gtest/gtest.h"

using namespace std;

/*
 Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 
 If the last word does not exist, return 0.
 
 Note: A word is defined as a character sequence consists of non-space characters only.
 
 For example,
 Given s = "Hello World",
 return 5.
 */
namespace LengthOfLastWord {
    class Solution {
    public:
        int lengthOfLastWord(string s) {
            int length = 0;
            for(auto iter = s.rbegin(); iter != s.rend(); ++ iter){
                if(*iter == ' '){
                    if(length > 0)
                        return length;
                }else{
                    length ++;
                }
            }
        return length;
        }
    };
    
    TEST(LengthOfLastWord, LengthOfLastWord){
        Solution sln;
        ASSERT_EQ(5, sln.lengthOfLastWord("Hello World"));
        ASSERT_EQ(0, sln.lengthOfLastWord("  "));
        ASSERT_EQ(5, sln.lengthOfLastWord("hello"));
        ASSERT_EQ(1, sln.lengthOfLastWord("a "));
    }
}
