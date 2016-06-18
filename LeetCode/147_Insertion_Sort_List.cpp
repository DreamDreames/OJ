#include "shared.h"
/*
 Sort a linked list using insertion sort.
 */
namespace InsertionSortList{
    class Solution {
    public:
        ListNode* insertionSortList(ListNode* head) {
            if(head == NULL)
                return NULL;
            ListNode* newHead = head, *current = head->next;
            newHead->next = NULL;
            while(current){
                ListNode* temp = newHead, *next = current->next;
                
                if(current->val <= temp->val){
                    current->next = temp;
                    newHead = current;
                }
                else{
                    while(temp->next && temp->next->val < current->val){
                        temp = temp->next;
                    }
                    
                    if(temp->next == NULL){
                        temp->next = current;
                        current->next = NULL;
                    }
                    else{
                        current->next = temp->next;
                        temp->next = current;
                    }
                }
                current = next;
            }
            return newHead;
        }
    };
}
