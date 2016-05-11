#include "shared.h"
#include <stdio.h>

/*
 Given a list, rotate the list to the right by k places, where k is non-negative.
 
 For example:
 Given 1->2->3->4->5->NULL and k = 2,
 return 4->5->1->2->3->NULL.
*/

namespace RotateList {
    struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
    };

    class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
            if(head == NULL)
                return head;
            
            int size = 1;
            ListNode *tail = head;
            while(tail->next != NULL){
                tail = tail->next;
                size ++;
            }
            
            k %= size;
            int step = (size - k) % size;
            ListNode *temp = head;
            ListNode *newTail = tail;
            while(step --){
                newTail = temp;
                temp = temp->next;
            }
            tail->next = head;
            newTail->next = NULL;
            return temp;
        }
    };
}
