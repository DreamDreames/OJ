#include "shared.h"
/*
 Given a non-empty list of words, return the k most frequent elements.
 
 Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.
 
 Example 1:
 Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
 Output: ["i", "love"]
 Explanation: "i" and "love" are the two most frequent words.
 Note that "i" comes before "love" due to a lower alphabetical order.
 Example 2:
 Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
 Output: ["the", "is", "sunny", "day"]
 Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
 with the number of occurrence being 4, 3, 2 and 1 respectively.
 Note:
 You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 Input words contain only lowercase letters.
 Follow up:
 Try to solve it in O(n log k) time and O(n) extra space.
 */
namespace TopKFrequentWords {
    struct cmp {
        bool operator()(const pair<string, int>& left, const pair<string, int>& right) {
            if(left.second == right.second)
                return left.first > right.first;
            return left.second < right.second;
        }
    };
    class Solution {
    public:
        vector<string> topKFrequent(vector<string>& words, int k) {
            vector<string> ans;
            unordered_map<string, int> wordCounts;
            for(auto &word : words) {
                if(wordCounts.find(word) != wordCounts.end())
                    wordCounts[word] ++;
                else
                    wordCounts[word] = 1;
            }
            priority_queue<pair<string,int>, vector<pair<string,int>>, cmp> heap;
            for(auto &element: wordCounts) {
                heap.push(element);
            }
            while (k --) {
                auto word = heap.top();
                ans.push_back(word.first);
                heap.pop();
            }
            return ans;
        }
    };
    
    class helper {
    public:
        void test(vector<string> words, int k, vector<string> expected) {
            Solution sln;
            auto actual = sln.topKFrequent(words, k);
            ASSERT_EQ(expected.size(), actual.size());
            for(int i = 0; i < expected.size(); ++ i) {
                ASSERT_EQ(expected[i], actual[i]);
            }
        }
    };
    TEST(TopKFrequentWords, TopKFrequent) {
        helper h;
        h.test({"i", "love", "leetcode", "i", "love", "coding"}, 2, {"i","love"});
        h.test({"i"}, 1, {"i"});
        h.test({"aaa","aa","a"}, 2, {"a", "aa"});
    }
}
