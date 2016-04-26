#include "stdafx.h"
#include "ListNode.h"
#include <iostream>
using namespace std;

namespace LeetCode
{
	class Solution {
	public:
		ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
			int carry = 0;
			ListNode *l1_cur = l1, *l2_cur = l2;
			ListNode head(0); ListNode *cur_node = &head;
			while (l1_cur != NULL || l2_cur != NULL){
				int sum = (l1_cur == NULL ? 0 : l1_cur->val) + (l2_cur == NULL ? 0 : l2_cur->val) + carry;
				carry = sum / 10; sum %= 10;

				cur_node->next = new ListNode(sum);
				cur_node = cur_node->next;
				if (l1_cur != NULL) l1_cur = l1_cur->next;
				if (l2_cur != NULL) l2_cur = l2_cur->next;
			}
			if (carry > 0)
				cur_node->next = new ListNode(carry);

			return head.next;
		}
	};
	
	TEST_CLASS(AddTwoNumbers)
	{
	public:
		
		TEST_METHOD(AddTwoNumbersTest)
		{
			ListNode l1(2), l2(4), l3(3);
			l1.next = &l2; l2.next = &l3;

			ListNode t1(5), t2(6), t3(4);
			t1.next = &t2; t2.next = &t3;

			Solution sln;
			ListNode* l = sln.addTwoNumbers(&l1, &t1);
			while (l != NULL){
				cout << l->val << " " << endl;
				l = l->next;
			}
		}
	};
}