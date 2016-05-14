#include "shared.h"
#include <stack>

/*
 Given an absolute path for a file (Unix-style), simplify it.
 
 For example,
 path = "/home/", => "/home"
 path = "/a/./b/../../c/", => "/c"
*/

namespace SimplifyPath {
    class Solution {
    public:
        string simplifyPath(string path) {
            auto elems = split(path, '/');
            stack<string> stk;
            for(auto iter = elems.begin(); iter != elems.end(); ++ iter){
                if(*iter == ".."){
                    if(!stk.empty())
                        stk.pop();
                }
                else if(*iter == ".")
                    continue;
                else
                    stk.push(*iter);
            }
            string ans = "";
            while(!stk.empty()){
                ans = "/" + stk.top() + ans;
                stk.pop();
            }
            if(ans.empty())
                return "/";
            return ans;
        }
    private:
        vector<string> &split(const string&s, char delim, vector<string>& elems){
            stringstream ss(s);
            string item;
            while(getline(ss, item, delim)){
                if(!item.empty())
                    elems.push_back(item);
            }
            return elems;
        }
        vector<string> split(const string &s, char delim){
            vector<string> elems;
            split(s, delim, elems);
            return elems;
        }
    };
    class helper{
    public:
        void test(string path, string expected){
            Solution sln;
            string actual = sln.simplifyPath(path);
            ASSERT_EQ(expected, actual);
        }
    };
    TEST(SimplifyPath, simplifyPath){
        helper h;
        h.test("/home/", "/home");
        h.test("/a/./b/../../c/", "/c");
        h.test("/../", "/");
        h.test("/home//foo", "/home/foo");
        h.test("/home/foo", "/home/foo");
    }
}
