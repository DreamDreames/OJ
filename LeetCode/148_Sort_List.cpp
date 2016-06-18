#include "shared.h"
/*
 Sort a linked list in O(n log n) time using constant space complexity.
 */
namespace SortList{
    class Solution {
    public:
        ListNode* sortList(ListNode* head) {
            if(head == NULL || head->next == NULL)
                return head;
            vector<ListNode*> slots(64, NULL);
            ListNode* carry;
            int fill = 0;
            while(head){
                carry = head;
                head = head->next;
                carry->next = NULL;
                int i = 0;
                for(i = 0; i <= fill && slots[i]; ++ i){
                    carry = mergeList(carry, slots[i]);
                    slots[i] = NULL;
                }
                slots[i] = carry;
                if(i == fill) fill ++;
            }
            for(int i = 1; i < fill; ++ i){
                slots[i] = mergeList(slots[i - 1], slots[i]);
            }
            return slots[fill - 1];
        }
    private:
        ListNode* mergeList(ListNode* list1, ListNode* list2){
            if(list1 == NULL)
                return list2;
            if(list2 == NULL)
                return list1;
            
            ListNode* newHead = NULL, *newCurrent = NULL;
            while(list1 && list2){
                ListNode* minNode = list2;
                if(list1->val < list2->val){
                    minNode = list1;
                    list1 = list1->next;
                }
                else{
                    list2 = list2->next;
                }
                if(newHead == NULL){
                    newHead = minNode;
                    newCurrent = newHead;
                }
                else {
                    newCurrent->next = minNode;
                    newCurrent = minNode;
                }
                minNode->next = NULL;
            }
            if(list1)
                newCurrent->next = list1;
            else if(list2)
                newCurrent->next = list2;
            return newHead;
        }
    };
}
