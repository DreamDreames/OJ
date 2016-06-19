#include "shared.h"
/*
 Given an input string, reverse the string word by word.
 
 For example,
 Given s = "the sky is blue",
 return "blue is sky the".
 
 Update (2015-02-12):
 For C programmers: Try to solve it in-place in O(1) space.
 */
namespace ReverseWordsInAString{
    class Solution {
    public:
        void reverseWords(string &s) {
            trim(s);
            reverseBetween(s, 0, (int)s.length() - 1);
        }
    private:
        void trim(string& s){
            bool isSpace = false;
            //for(int i = 0; i < s.length(); ++ i){
            for(auto iter = s.begin(); iter != s.end(); ){
                if(*iter == ' ' || *iter == '\t'){
                    if(isSpace){
                        auto temp = iter++;
                        s.erase(temp);
                    }
                    else{
                        isSpace = true;
                        iter ++;
                    }
                }
                else{
                    isSpace = false;
                    iter ++;
                }
            }
            if(s.length() > 0){
                if(s[0] == ' ' || s[0] == '\t')
                    s.erase(s.begin());
            }
            if(s.length() > 0){
                int index = (int)s.length() - 1;
                if(s[index] == ' ' || s[index] == '\t')
                    s.erase(s.end() - 1);
            }
        }
        void reverseBetween(string& s, int start, int end){
            if(start >= end)
                return;
            vector<int> spaces;
            for(int i = start; i <= end; ++ i){
                if(s[i] == ' ')
                    spaces.push_back(i);
            }
            if(spaces.size() == 0)
                return;
            
            int i = spaces[spaces.size() / 2];
            reverseBetween(s, start, i - 1);
            reverseBetween(s, i + 1, end);
            string left = s.substr(i + 1, end - i);
            string right = s.substr(start, i - start);
            int j = start, index = 0;
            while(index < left.length()){
                s[j ++] = left[index++];
            }
            s[j ++] = ' '; index = 0;
            while(index < right.length()){
                s[j ++] = right[index ++];
            }
        }
    };
    class helper{
    public:
        void test(string s, string expected){
            Solution sln;
            sln.reverseWords(s);
            ASSERT_EQ(expected, s);
        }
    };
    TEST(ReverseWordsInAString, reverseWords){
        helper h;
        h.test("hello", "hello");
        h.test("hello world", "world hello");
        h.test("hello , world", "world , hello");
        h.test("     ", "");
        h.test(" 1", "1");
        h.test("   a   ", "a");
    }
}
