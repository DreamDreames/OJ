#include "shared.h"
/*
 Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 
 For example, given
 s = "leetcode",
 dict = ["leet", "code"].
 
 Return true because "leetcode" can be segmented as "leet code".
 */
namespace WordBreak{
    class Solution {
    public:
        bool wordBreak(string s, unordered_set<string>& wordDict) {
            if(s.length() == 0)
                return true;
            if(wordDict.size() == 0)
                return false;
            
            vector<int> record(s.length(), -1);
            return canBreak(s, 0, wordDict, record);
        }
    private:
        bool canBreak(string& s, int start, unordered_set<string>& dic, vector<int>& record){
            if(start >= s.length())
                return true;
            if(record[start] >= 0)
                return record[start];
            
            bool result = false;;
            for(int i = start; i < s.length(); ++ i ){
                if(dic.find(s.substr(start, i - start + 1)) != dic.end()){
                    result = canBreak(s, i + 1, dic, record);
                    if(result)
                        break;
                }
            }
            
            record[start] = result;
            return result;
        }
    };
}
