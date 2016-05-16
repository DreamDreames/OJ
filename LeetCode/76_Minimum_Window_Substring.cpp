#include "shared.h"

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

namespace MinimumWindowSubstring{
    struct comparator{
        bool operator()(const pair<char, int>& left, const pair<char, int>& right){
            return left.second < right.second;
        }
    };
    class Solution {
    public:
        string minWindow(string s, string t) {
            string ans = "";
            unordered_multiset<char> tset;
            for(auto ch : t){
                tset.insert(ch);
            }
            unordered_multiset<char> tset2(tset);
            int shortest = (int)s.length() + 1, start = 0, end = 0;
            set<pair<char, int>, comparator> counted;
            stack<pair<char, int>> uncounted;
            for(int i = 0; i < s.length(); ++ i){
                char ch = s[i];
                if(tset2.find(ch) == tset2.end())
                    continue;
                
                if(tset.empty()){
                    if(!uncounted.empty() && uncounted.top().first == ch)
                        uncounted.pop();
                    uncounted.push(make_pair(ch, i));

                }
                else{
                    if(tset.find(ch) == tset.end()){
                        
                        if(!uncounted.empty() && uncounted.top().first == ch)
                            uncounted.pop();
                        uncounted.push(make_pair(ch, i));
                    }
                    else{
                        
                    counted.insert(make_pair(ch, i));
                    auto iter = tset.find(ch);
                    if(iter != tset.end()){
                        tset.erase(iter);
                    }
                    if(tset.empty()){
                        start = counted.begin()->second;
                        end = counted.rbegin()->second;
                        shortest = end - start + 1;
                    }
                    }
                }
                while(tset.empty() && !counted.empty() && !uncounted.empty() && counted.begin()->first == uncounted.top().first){
                    counted.erase(counted.begin());
                    int minIndex = min(uncounted.top().second, counted.begin()->second);
                    int maxIndex = max(uncounted.top().second, counted.rbegin()->second);
                    int temp = maxIndex - minIndex + 1;
                    if(temp < shortest){
                        shortest = temp;
                        start = minIndex;
                        end = maxIndex;
                    }
                    counted.insert(uncounted.top());
                    uncounted.pop();
                    
                }

            }
            if(shortest > s.length())
                return "";
            return s.substr(start, shortest);
        }
    };
    class helper{
    public:
        void test(string s, string t, string expected) {
            Solution sln;
            auto actual = sln.minWindow(s, t);
            ASSERT_EQ(expected, actual);
        }
    };
    TEST(MinimumWindowSubstring, minWindow){
        helper h;
//        h.test("ADOBECODEBANC", "ABC", "BANC");
//        h.test("a", "aa", "");
//        h.test("bba", "ab", "ba");
//        h.test("aa", "aa", "aa");
//        h.test("bbaa", "aba", "baa");
        h.test("aaabdabcefaecbef", "abc", "abc");
    }
}
