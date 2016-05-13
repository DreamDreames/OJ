#include "shared.h"
/*
 Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
 
 You should pack your words in a greedy approach; 
 
 that is, pack as many words as you can in each line. 
 
 Pad extra spaces ' ' when necessary so that each line has exactly L characters.
 
 Extra spaces between words should be distributed as evenly as possible. 
 
 If the number of spaces on a line do not divide evenly between words,
 
 the empty slots on the left will be assigned more spaces than the slots on the right.
 
 For the last line of text, it should be left justified and no extra space is inserted between words.
 
 For example,
 words: ["This", "is", "an", "example", "of", "text", "justification."]
 L: 16.
 
 Return the formatted lines as:
 [
 "This    is    an",
 "example  of text",
 "justification.  "
 ]
 Note: Each word is guaranteed not to exceed L in length.
 */

namespace TextJustification {
    class Solution {
    public:
        vector<string> fullJustify(vector<string>& words, int maxWidth) {
            vector<string> ans;
            int i, lastPos = 0, count = 0, length = 0;
            for(i = 0; i < words.size(); ++ i){
                int temp = (int)words[i].length();
                if(temp + length + count > maxWidth){
                    int betweenCount = count == 1 ? 1 : count - 1;
                    int space = maxWidth - length;
                    int averageSpace = space / betweenCount;
                    int extraSpace = space % betweenCount;
                    string row = "";
                    for(int j = lastPos; j < i; ++ j){
                        row += words[j];
                        if(extraSpace -- > 0)
                            row += getSpace(averageSpace + 1);
                        else if (j < i - 1)
                            row += getSpace(averageSpace);
                    }
                    if(row.length() < maxWidth){
                        row += getSpace(maxWidth - (int)row.length());
                    }
                    ans.push_back(row);
                    lastPos = i;
                    count = 1;
                    length = temp;
                }
                else{
                    count ++;
                    length += words[i].length();
                }
            }
            string row = "";
            for(i = lastPos; i < words.size(); ++ i){
                row += words[i];
                maxWidth -= words[i].length();
                if(i + 1 != words.size()){
                    row += " ";
                    maxWidth --;
                }
                else{
                    row += getSpace(maxWidth);
                    ans.push_back(row);
                }
            }
            
            return ans;
        }
    private:
        string getSpace(int count){
            return string(count, ' ');
        }
    };
    class helper{
    public:
        void test(vector<string> words, int maxWidth, vector<string> expected){
            Solution sln;
            auto ans = sln.fullJustify(words, maxWidth);
            ASSERT_EQ(expected.size(), ans.size());
            for(int i = 0; i < expected.size(); ++ i){
                ASSERT_EQ(expected[i], ans[i]);
            }
        }
    };
    TEST(TextJustification, fullJustify){
        helper h;
        h.test({"This", "is", "an", "example", "of", "text", "justification."},
               16,
        { "This    is    an", "example  of text", "justification.  "});
        h.test({""}, 0, {""});
        h.test(
        {"Don't","go","around","saying","the","world","owes","you","a","living;","the","world","owes","you","nothing;","it","was","here","first."}, 30,
        {"Don't  go  around  saying  the","world  owes  you a living; the","world owes you nothing; it was","here first.                   "});
        h.test(
        {"Listen","to","many,","speak","to","a","few."},
            6,
        {"Listen","to    ","many, ","speak ","to   a","few.  "});
    }
}
