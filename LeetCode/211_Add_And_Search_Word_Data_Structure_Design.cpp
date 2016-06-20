#include "shared.h"

namespace AddAndSearchWordDataStructureDesign {
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
            return wildSearch(word, root, 0);
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
        bool wildSearch(string& word, TrieNode* root, int start){
            if(start == word.size())
                return root->isLeaf;
            
            if(word[start] == '.'){
                for(int i = 0; i < 26; ++ i){
                    if(root->children[i] && wildSearch(word, root->children[i], start + 1))
                        return true;
                }
                return false;
            }
            else{
                return root->children[word[start] - 'a'] && wildSearch(word, root->children[word[start] - 'a'], start + 1);
            }
        }
    private:
        TrieNode* root;
    };
    class WordDictionary {
    public:
        
        // Adds a word into the data structure.
        void addWord(string word) {
            trie.insert(word);
        }
        
        // Returns if the word is in the data structure. A word could
        // contain the dot character '.' to represent any one letter.
        bool search(string word) {
            return trie.search(word);
        }
    private:
        Trie trie;
    };

}
