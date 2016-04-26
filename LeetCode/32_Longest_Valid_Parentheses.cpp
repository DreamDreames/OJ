

#include <stdio.h>
#include <string>
#include <stack>
#include "gtest/gtest.h"

using namespace std;

namespace LeetCode {
    
    class Solution {
    private:
        stack<char> _stk;
        
    private:
        bool isValid(){
            if(_stk.empty())
                return false;
            return _stk.top() == '(';
        }
        void clear(){
            while (!_stk.empty()){
                _stk.pop();
            }
        }
        
    public:
        int longestValidParentheses(string s) {
            int longest = 0;
            int current = 0;
            clear();
            for(auto &c : s){
                if (c == ')'){
                    if(isValid()){
                        _stk.pop();
                        current += 2;
                    }
                    else{
                        if(current > longest)
                            longest = current;
                        clear();
                        current = 0;
                    }
                }
                else{
                    _stk.push(c);
                }
            }
            if(current > longest)
                longest = current;
            return longest;
        }
    };
    
    
    class testhelper{
    public:
        static void test(string str, int expected){
            Solution _sln;
            int ans =  _sln.longestValidParentheses(str);
            ASSERT_EQ(expected, ans);
        }
        
    };
    TEST(Solution, LongestValidParentheses){
        testhelper helper;
        helper.test("(()", 2);
        helper.test(")()())", 4);
        helper.test("())()", 2);
        helper.test("()(()", 2);
    }
    
}

/*
 Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 
 For "(()", the longest valid parentheses substring is "()", which has length = 2.
 
 Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 */