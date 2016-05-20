#include "shared.h"
/*
 Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 
 You should preserve the original relative order of the nodes in each of the two partitions.
 
 For example,
 Given 1->4->3->2->5->2 and x = 3,
 return 1->2->2->4->3->5.
*/
namespace PartitionList {

     struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };

    class Solution {
    public:
        ListNode* partition(ListNode* head, int x) {
            ListNode *h = head;
            ListNode *pivot = NULL;
            ListNode *pre = NULL;
            
            for(ListNode* h = head; h != NULL; pre = h, h = h->next){
                if(h->val >= x){
                    pivot = h;
                    break;
                }
            }
            bool beforePivot = true;
            ListNode *pre2 = NULL;
            for(h = head; h != NULL; h = h->next){
                if(h == pivot)
                    beforePivot = false;
                if(h->val < x && !beforePivot){
                    pre2->next = h->next;
                    
                    if(pre == NULL){
                        pre = h;
                        h->next = pivot;
                        head = h;
                    }
                    else{
                        pre->next = h;
                        h->next = pivot;
                        pre = h;
                    }
                    
                    h = pre2;
                }
                else if(h->val >= x && beforePivot){
                    pre2->next = h->next;
                    
                    h->next = pivot->next;
                    pivot->next = h;
                    
                    h = pre2;
                }
                else
                    pre2 = h;
            }
        return head;
        }

    };
    class helper{
    public:
        void test(vector<int> list, int x, vector<int>expected){
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
            ListNode* actual = sln.partition(head, x);
            for(int i = 0; i < expected.size(); ++ i){
                ASSERT_EQ(expected[i], actual->val);
                actual = actual->next;
            }
            ASSERT_EQ(NULL, actual);
        }
    };
    TEST(PartitionList, partition){
        helper h;
        h.test({1, 4, 3, 2, 5, 2}, 3, {1, 2, 2, 4, 3, 5});
        h.test({3, 2}, 3, {2, 3});
        h.test({3, 4}, 3,{3, 4});
    }
}
