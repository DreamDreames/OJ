#include "shared.h"

/*
 Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
 
 You have the following 3 operations permitted on a word:
 
 a) Insert a character
 b) Delete a character
 c) Replace a character
*/

namespace EditDistance {
    class Solution {
    public:
        int minDistance(string word1, string word2) {
            vector<vector<int>> status(word1.size(), vector<int>(word2.size(), -1));
            _status = status;
            _word1 = word1;
            _word2 = word2;
            
            return distance(0, 0);
        }
    private:
        string _word1;
        string _word2;
        vector<vector<int>> _status;
        
    private:
        int distance(int i1, int i2){
            if(i1 == _word1.size())
                return (int)_word2.size() - i2;
            
            if(i2 == _word2.size()){
                return (int)_word1.size() - i1;
            }
            
            if(i1 == ((int)_word1.size() - 1) && i2 == ((int)_word2.size() - 1)){
                if(_word1[i1] == _word2[i2])
                    return 0;
                return 1;
            }
            if(_status[i1][i2] > 0)
                return _status[i1][i2];
            
            int d1, d2, d3;
            if(_word1[i1] == _word2[i2]){
                d1 = distance(i1 + 1, i2 + 1);
            }
            else{
                d1 = distance(i1 + 1, i2 + 1) + 1;
            }
            d2 = distance(i1 + 1, i2) + 1;
            d3 = distance(i1, i2 + 1) + 1;
            _status[i1][i2] = min3(d1, d2, d3);
            return _status[i1][i2];
        }
        int min3(int a, int b, int c){
            return min(min(a, b), c);
        }
    };
    
    class helper{
    public:
        void test(string w1, string w2, int expected){
            Solution sln;
            int actual = sln.minDistance(w1, w2);
            ASSERT_EQ(expected, actual);
        }
    };
    
    TEST(MinDistance, minDistance){
        helper h;
        h.test("hello", "helli", 1);
        h.test("hello", "hell", 1);
        h.test("hello", "helloo", 1);
        h.test("hello", "abc", 5);
    }
}
