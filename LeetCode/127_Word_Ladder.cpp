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
            
            int size = (int)wordList.size() + 2;
            vector<vector<int>> matrix (size, vector<int>(size, -1));
            wordList.insert(beginWord);
            wordList.insert(endWord);
            int startPos = 0, endPos = 0;
            auto iter1 = wordList.begin(), iter2 = wordList.begin();
            for(int i = 0; i < size; ++ i, ++ iter1){
                if(*iter1 == beginWord)
                    startPos = i;
                else if(*iter1 == endWord)
                    endPos = i;
                for(int j = 0; j < size; ++ j, ++ iter2){
                    if(i == j)
                        matrix[j][i] = matrix[i][j] = 0;
                    else if(canConcat(*iter1, *iter2))
                        matrix[j][i] = matrix[i][j] = 1;
                }
            }
            
            unordered_set<int> traversed;
            list<int> untraversed;
            for(int i = 0; i < size; ++ i){
                if(i != startPos)
                    untraversed.push_back(i);
            }
            queue<int> q;
            q.push(startPos);
            while(!q.empty()){
                int current = q.front();
                q.pop();
                for(auto iter = untraversed.begin(); iter != untraversed.end(); ++ iter){
                    int index = *iter;
                    if(index == current || traversed.find(index) != traversed.end())
                        continue;
                    if(matrix[current][index] == 1){
                        q.push(index);
                        for(auto iter = traversed.begin(); iter != traversed.end(); ++ iter){
                            int temp = *iter;
                            matrix[temp][index] = matrix[temp][current] + 1;
                        }
                    }
                }
                traversed.insert(current);
                untraversed.remove(current);
            }
            if(matrix[startPos][endPos] == -1)
                return 0;
            return matrix[startPos][endPos];
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
