#include "shared.h"
/*
 Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 
 For example,
 "A man, a plan, a canal: Panama" is a palindrome.
 "race a car" is not a palindrome.
 
 Note:
 Have you consider that the string might be empty? This is a good question to ask during an interview.
 
 For the purpose of this problem, we define empty string as valid palindrome.
 */
namespace ValidPalindrome {
    class Solution {
    public:
        bool isPalindrome(string s) {
            for(int i = 0, j = (int)s.length() - 1; i < j;){
                if(!isLetter(s[i])){
                    i ++;
                    continue;
                }
                if (!isLetter(s[j])){
                    j --;
                    continue;
                }
                if(!isSame(s[i], s[j]))
                    return false;
                i ++, j --;
                    
            }
            return true;
        }
    private:
        bool isLetter(char ch){
            return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
        }
        bool isSame(char ch1, char ch2){
            char temp1 = ch1, temp2 = ch2;
            if(ch1 >= 'A' && ch1 <= 'Z')
                temp1 = ch1 - 'A' + 'a';
            if(ch2 >= 'A' && ch2 <= 'Z')
                temp2 = ch2 - 'A' + 'a';
            return temp1 == temp2;
        }
    };
}
