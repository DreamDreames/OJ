#include "shared.h"
/*
 Given a sorted linked list, delete all duplicates such that each element appear only once.
 
 For example,
 Given 1->1->2, return 1->2.
 Given 1->1->2->3->3, return 1->2->3.
*/
namespace RemoveDuplicatesFromSortedList{
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
            
            ListNode* iter = head;
            ListNode* pre = iter;
            int current = head->val;
            while(iter->next != NULL){
                iter = iter->next;
                if(current != iter->val){
                    pre->next = iter;
                    pre = iter;
                    current =iter->val;
                }
            }
            pre->next = NULL;
            return head;
        }
    };
}
