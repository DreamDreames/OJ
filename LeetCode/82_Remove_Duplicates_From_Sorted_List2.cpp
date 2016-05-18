#include "shared.h"

/*
 Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 
 For example,
 Given 1->2->3->3->4->4->5, return 1->2->5.
 Given 1->1->1->2->3, return 2->3.
*/

namespace RemoveDuplicatesFromSortedList2{
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            if(head == NULL)
                return head;
            
            ListNode* newHead = NULL;
            ListNode* newIter = NULL;
            ListNode* pre = head;
            ListNode* iter = pre;
            int steps = 1;
            iter = iter->next;
            while(iter != NULL){
                if(pre->val != iter->val){
                    if(steps == 1){
                        if(newIter == NULL){
                            newIter = pre;
                            newHead = newIter;
                        }
                        else{
                            newIter->next = pre;
                            newIter = pre;
                        }
                        newIter->next = NULL;
                    }
                    pre = iter;
                    steps = 1;
                }
                else{
                    steps ++;
                }
                iter = iter->next;
            }
            if(steps == 1){
                if(newIter != NULL)
                    newIter->next = pre;
                else
                    newHead = pre;
                
                newIter = pre;
                newIter->next = NULL;
                
            }

            return newHead;
        }
    };
    class helper{
    public:
        void test(vector<int> list, vector<int>expected){
            ListNode* head = NULL;
            ListNode* current = NULL;
            for(int i = 0; i < list.size(); ++ i){
                if(head == NULL){
                    head = new ListNode(list[i]);
                    current = head;
                }
                else{
                    current->next = new ListNode(list[i]);
                    current = current->next;
                }
                
            }
            Solution sln;
            ListNode* actual = sln.deleteDuplicates(head);
            for(int i = 0; i < expected.size(); ++ i){
                ASSERT_EQ(expected[i], actual->val);
                actual = actual->next;
            }
            ASSERT_EQ(NULL, actual);
        }
    };
    TEST(RemoveDuplicatesFromSortedList2, deleteDuplicates){
        helper h;
        h.test({}, {});
        h.test({1}, {1});
        h.test({1, 2}, {1, 2});
        h.test({1, 1, 2}, {2});
        h.test({1, 1, 1, 2}, {2});
        h.test({1, 1, 1}, {});
        h.test({1, 2, 2}, {1});
    }
}
