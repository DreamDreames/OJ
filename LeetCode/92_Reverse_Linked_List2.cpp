#include "stdafx.h"
//#include "ListNode.h"
/*
 Reverse a linked list from position m to n. Do it in-place and in one-pass.
 
 For example:
 Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 
 return 1->4->3->2->5->NULL.
 
 Note:
 Given m, n satisfy the following condition:
 1 ≤ m ≤ n ≤ length of list.
 */
namespace ReverseLinkedList2{
     struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };
    class Solution {
    public:
        ListNode* reverseBetween(ListNode* head, int m, int n) {
			ListNode* current = head;
			ListNode* prev = head;
			int step = 1;
			for (int i = 0; i + 1 < m; ++i){
				current = current->next;
			}
			prev = current;
			current = current->next;

			for (int i = 0; i < n - m; ++i){
				ListNode* next = current->next->next;
				current->next->next = prev->next;
				prev->next = current->next;
				current->next->next->next = next;
			}
			return head;
        }
    };


	TEST_CLASS(reverseTest){
	public:
		TEST_METHOD(reverseLinkedListTest){
			test({ 1, 2, 3, 4, 5 }, 2, 4, { 1, 4, 3, 2, 5 });
		}
	private:
		ListNode* ConstructList(std::vector<int>& list){
			if (list.empty())
				return nullptr;
			ListNode *head = new ListNode(list[0]);
			ListNode* cur = head;
			for (int i = 1; i < list.size(); ++i){
				ListNode* node = new ListNode(list[i]);
				cur->next = node;
				cur = node;
			}
			return head;
		}
		void test(vector<int> input, int m, int n, vector<int> expected){
			auto head = ConstructList(input);
			Solution sln;
			auto actual = sln.reverseBetween(head, m, n);
			auto exp = ConstructList(expected);
			while (actual != NULL && exp != NULL){
				Assert::AreEqual(exp->val, actual->val);
				actual = actual->next;
				exp = exp->next;
			}
			Assert::AreEqual(exp, actual);
		}
	};
}
