#include "shared.h"
/*
 Given a string s, partition s such that every substring of the partition is a palindrome.
 
 Return all possible palindrome partitioning of s.
 
 For example, given s = "aab",
 Return
 
 [
 ["aa","b"],
 ["a","a","b"]
 ]
*/
namespace PalindromePartitioning {
    class Solution {
    public:
        vector<vector<string>> partition(string s) {
            vector<vector<string>> ans;
            vector<string> result;
            iterPartition(s, 0, result, ans);
            return ans;
        }
    private:
        bool isPalindrome(const string& s, int start, int end){
            while(start <= end){
                if(s[start++] != s[end--])
                    return false;
            }
            return true;
        }
        void iterPartition(string& s, int start, vector<string>& result, vector<vector<string>>& ans){
            if(start == s.length()){
                ans.push_back(result);
                return;
            }
            
            for(int i = start; i < s.length(); ++ i){
                if(isPalindrome(s, start, i)){
                    result.push_back(s.substr(start, i - start + 1));
                    iterPartition(s, i + 1, result, ans);
                    result.pop_back();
                }
            }
        }
    };
}
