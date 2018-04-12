#include "shared.h"
/*
 Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
 
 get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 
 Follow up:
 Could you do both operations in O(1) time complexity?
 
 Example:
 
 LRUCache cache = new LRUCache( 2 );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

namespace LRUCache {
    struct DoublyListNode {
        DoublyListNode *prev, *next;
        int key, val;
        
        DoublyListNode(int k, int v) : prev(NULL), next(NULL), key(k), val(v){}
    };
    
    class LRUCache {
    private:
        int capacity;
        map<int, DoublyListNode*> cache;
        DoublyListNode *head, *tail;
        
    public:
        LRUCache(int capacity) {
            this->capacity = capacity;
            head = NULL;
            tail = NULL;
        }
        
        int get(int key) {
            if(cache.find(key) == cache.end())
                return -1;
            
            DoublyListNode* current = cache[key];
            update(current);
            return current->val;
        }
        
        void put(int key, int value) {
            if(capacity == 0)
                return;
            
            if(cache.find(key) != cache.end()){
                DoublyListNode* current = cache[key];
                current->val = value;
                update(current);
                return;
            }
            
            if(cache.size() == capacity)
                release();
            
            DoublyListNode* node = new DoublyListNode(key, value);
            cache[key] = node;
            insert(node);
        }
        
    private:
        void insert(DoublyListNode* node) {
            if(head == NULL) {
                head = node;
                tail = node;
                return;
            }
            
            node->next = head;
            head->prev = node;
            head = node;
        }
        
        void release() {
            if(tail == NULL)
                return;
            
            cache.erase(tail->key);
            
            if(head == tail) {
                delete tail;
                head = NULL;
                tail = NULL;
                return;
            }
            
            DoublyListNode* newTail = tail->prev;
            newTail->next = NULL;
            delete tail;
            tail = newTail;
        }
        
        void update(DoublyListNode* current) {
            if(head == current)
                return;
            
            if(tail == current)
                tail = current->prev;
            
            current->prev->next = current->next;
            current->next = head;
            current->prev = NULL;
            head->prev = current;
            head = current;
        }
    };
}
