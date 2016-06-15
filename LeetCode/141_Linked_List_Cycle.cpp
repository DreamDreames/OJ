#include "shared.h"
/*
 Given a linked list, determine if it has a cycle in it.
 
 Follow up:
 Can you solve it without using extra space?
 */
namespace LinkedListCycle {
    class Solution {
    public:
        bool hasCycle(ListNode *head) {
            if(head == NULL)
                return false;
            ListNode *slow = head, *fast = head;
            while(slow != NULL && fast != NULL){
                slow = slow->next;
                if(fast->next != NULL)
                    fast = fast->next->next;
                else break;
                if(slow == fast)
                    return true;
            }
            return false;
        }
    };
}
