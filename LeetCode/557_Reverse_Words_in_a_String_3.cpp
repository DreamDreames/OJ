#include "shared.h"

namespace ReverseWordsInAString3 {
    class Solution {
    public:
        string reverseWords(string s) {
            int head, tail;
            for(head = 0, tail = 0; tail < s.size(); ++ tail) {
                if(s[tail] == ' ') {
                    reverse(s, head, tail - 1);
                    head = ++ tail;
                }
            }
            reverse(s, head, tail - 1);
            return s;
        }
    private:
        void reverse(string& s, int head, int tail) {
            if(head >= tail)
                return;
            while(head < tail) {
                swap(s[head ++], s[tail --]);
            }
        }
    };
}
