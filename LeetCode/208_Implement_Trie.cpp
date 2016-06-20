#include "shared.h"

namespace ImplementTrie {
    class TrieNode {
    public:
        // Initialize your data structure here.
        TrieNode() {
            isLeaf = false;
            for(int i = 0; i < 26; ++ i)
                children[i] = nullptr;
        }
    public:
        bool isLeaf;
        TrieNode* children[26];
    };
    
    class Trie {
    public:
        Trie() {
            root = new TrieNode();
        }
        
        // Inserts a word into the trie.
        void insert(string word) {
            TrieNode* node = root;
            for(auto ch : word){
                int index = ch - 'a';
                if(node->children[index]){
                    node = node->children[index];
                }
                else{
                    TrieNode* newNode = new TrieNode();
                    node->children[index] = newNode;
                    node = newNode;
                }
            }
            if(node != root)
                node->isLeaf = true;
        }
        
        // Returns if the word is in the trie.
        bool search(string word) {
            TrieNode* node = root;
            for(auto ch : word){
                int index = ch - 'a';
                if(!node->children[index])
                    return false;
                node = node->children[index];
            }
            return node->isLeaf;
        }
        
        // Returns if there is any word in the trie
        // that starts with the given prefix.
        bool startsWith(string prefix) {
            TrieNode* node = root;
            for(auto ch : prefix){
                int index = ch -  'a';
                if(!node->children[index])
                    return false;
                node = node->children[index];
            }
            return true;
        }
        
    private:
        TrieNode* root;
    };
    TEST(ImplementTrie, Trie){
        Trie t;
        t.insert("abc");
        t.insert("ab");
        ASSERT_EQ(true, t.search("ab"));
    }
}
