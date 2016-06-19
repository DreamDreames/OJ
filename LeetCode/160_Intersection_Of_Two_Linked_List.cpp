#include "shared.h"
/*
 Write a program to find the node at which the intersection of two singly linked lists begins.
 
 For example, the following two linked lists:
 
 A:          a1 → a2
                     ↘
                     c1 → c2 → c3
                     ↗
 B:     b1 → b2 → b3
 begin to intersect at node c1.
 
 Notes:
 
 If the two linked lists have no intersection at all, return null.
 The linked lists must retain their original structure after the function returns.
 You may assume there are no cycles anywhere in the entire linked structure.
 Your code should preferably run in O(n) time and use only O(1) memory.
*/
namespace IntersectionOfTwoLinkedList{
    class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            if(headA == NULL || headB == NULL)
                return NULL;
            ListNode* a = headA, *b = headB;
            if(headA == headB)
                return headA;
            int alen = 0, blen = 0;
            while(headA){
                alen ++;
                headA = headA->next;
            }
            while(headB){
                blen ++;
                headB = headB->next;
            }
            
            if(alen > blen){
                for(int i = 0; i < alen - blen; ++ i){
                    a = a->next;
                }
            }
            else if(alen < blen){
                for(int i = 0; i < blen - alen; ++ i){
                    b = b->next;
                }
            }
            while(a && b && a != b){
                a = a->next;
                b = b->next;
            }
            return a;
        }
    };
}

