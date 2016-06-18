#include "shared.h"

namespace EvaluateReversePolishNotation {
    class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            if(tokens.size() == 0)
                return 0;
            stack<int> stk;
            for(auto& token : tokens){
                if(isNumber(token)){
                    stk.push(toNumber(token));
                }
                else{
                    int num1 = stk.top();
                    stk.pop();
                    int num2 = stk.top();
                    stk.pop();
                    int result = apply(num2, num1, token);
                    stk.push(result);
                }
            }
            return stk.top();
        }
    private:
        bool isNumber(string& str){
            return !((str.length() == 1) && !(str[0] >= '0' && str[0] <= '9'));
        }
        int toNumber(string& str){
            int number = 0;
            int flag = 1;
            for(auto ch : str){
                if(ch == '-')
                    flag = -1;
                else{
                    number *= 10;
                    number += ch - '0';
                }
            }
            return number *= flag;
        }
        int apply(int num1, int num2, string& token){
            if(token == "+")
                return num1 + num2;
            if(token == "-")
                return num1 - num2;
            if(token == "*")
                return num1 * num2;
            if(token == "/")
                return num1 / num2;
            return 0;
        }
    };
}
