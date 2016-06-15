#include "shared.h"
/*
 Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 
 Note: Do not modify the linked list.
 
 Follow up:
 Can you solve it without using extra space?
 */
namespace LinkedListCycle2{
    class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            if(head == NULL)
                return NULL;
            ListNode *slow = head, *fast = head;
            while(slow && fast){
                slow = slow->next;
                if(fast->next)
                    fast = fast->next->next;
                else
                    break;
                if(slow == fast)
                    break;
            }
            if(slow == NULL || fast == NULL)
                return NULL;
            
            fast = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            };
            return fast;
        }
    };
}
