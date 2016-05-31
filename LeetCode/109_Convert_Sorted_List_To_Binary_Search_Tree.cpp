#include "shared.h"
/*
 Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/
namespace ConvertSortedListToBinarySearchTree{
    class Solution {
    public:
        TreeNode* sortedListToBST(ListNode* head) {
            if(head == NULL)
                return NULL;
            ListNode* slow = head, *fast = head, *pre = NULL;
            while(fast != NULL && fast->next != NULL){
                pre = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            if(pre != NULL)
                pre->next = NULL;
            else
                head = NULL;
            TreeNode* root = new TreeNode(slow->val);
            root->left = sortedListToBST(head);
            root->right = sortedListToBST(slow->next);
            return root;
        }
    };
}
