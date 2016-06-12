#include "shared.h"
/*
 Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
 
 Only one letter can be changed at a time
 Each intermediate word must exist in the word list
 For example,
 
 Given:
 beginWord = "hit"
 endWord = "cog"
 wordList = ["hot","dot","dog","lot","log"]
 As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 return its length 5.
 
 Note:
 Return 0 if there is no such transformation sequence.
 All words have the same length.
 All words contain only lowercase alphabetic characters.
 */
namespace WordLadder{
    class Solution {
    public:
        int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
            unordered_set<string> traversed;
            unordered_map<string, int> record;
            for(auto iter = wordList.begin(); iter != wordList.end(); ++ iter){
                
            }
            int currentShortest = (int)wordList.size() + 3;
            int ans = iterLadderLength(beginWord, endWord, wordList, traversed, currentShortest);
            if(ans > wordList.size() + 2)
                return 0;
            return ans;
        }
     private:
        bool canConcat(const string& word1, const string& word2){
            int diff = 0;
            for(int i = 0; i < word1.length(); ++ i){
                if(word1[i] != word2[i]){
                    if(++diff > 1)
                        return false;
                }
            }
            return true;
        }
        int iterLadderLength(const string& startWord, const string& endWord, unordered_set<string>& wordList, unordered_set<string>& traversed, int currentShortest){
            if(canConcat(startWord, endWord))
                return 2;
            if(traversed.size() + 2 >= currentShortest)
                return currentShortest;
            
            for(auto iter = wordList.begin(); iter != wordList.end(); ++iter){
                if(traversed.find(*iter) != traversed.end())
                    continue;
                if(canConcat(startWord, *iter)){
                    string current = *iter;
                    traversed.insert(*iter);
                    int temp = iterLadderLength(*iter, endWord, wordList, traversed, currentShortest);
                    if(temp < wordList.size() + 3)
                        temp ++;
                    if(temp < currentShortest){
                        currentShortest = temp;
                    }
                    traversed.erase(*iter);
                }
            }
            return currentShortest;
        }
    };
    class helper{
    public:
        void test(string startWord, string endWord, vector<string> wordList, int expected){
            Solution sln;
            unordered_set<string> wordSet;
            for(auto iter = wordList.begin(); iter != wordList.end(); ++ iter){
                wordSet.insert(*iter);
            }
            int actual = sln.ladderLength(startWord, endWord, wordSet);
            ASSERT_EQ(expected, actual);
        }
    };
    TEST(WordLadder, ladderLength){
        helper  h;
        h.test("hit", "abc", {}, 0);
        h.test("hit", "hot", {}, 2);
        h.test("hit", "dot", {"hot", "abc"}, 3);
        h.test("hit", "cog", {"hot", "dot", "dog", "lot", "log"}, 5);
        h.test("qa", "sq", {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye" }, 5);

    }
}
