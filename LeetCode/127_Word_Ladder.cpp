#include "shared.h"
#include <list>
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
            if(canConcat(beginWord, endWord))
                return 2;
            
            wordList.insert(endWord);
            queue<pair<string,int>> q;
            
            q.push(make_pair(beginWord, 1));
            
            while(!q.empty()){
                auto current = q.front();
                q.pop();
                auto neighbors = findNeighbors(current.first, wordList);
                
                for(auto& w : neighbors){
                    if(w == endWord)
                        return current.second + 1;
                    q.push(make_pair(w, current.second + 1));
                }
                
            }
            return 0;
        }
     private:
        vector<string> findNeighbors(string s, unordered_set<string>& wordList){
            vector<string> result;
            for(int i = 0; i < s.length(); ++ i){
                char ch = s[i];
                for(int j = 0; j < 26; ++ j){
                    char newch = 'a' + j;
                    if(ch == newch)
                        continue;
                    s[i] = newch;
                    if(wordList.find(s) != wordList.end()){
                        wordList.erase(s);
                        result.push_back(s);
                    }
                }
                s[i] = ch;
            }
            return result;
        }
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
