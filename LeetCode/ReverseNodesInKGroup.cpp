#include "stdafx.h"
#include "ListNode.h"

using namespace std;

namespace LeetCode
{
	class Solution{
	public:
		ListNode* reverseKGroup(ListNode* lists, int k){
			ListNode *current = lists;
			ListNode *head = nullptr, *prehead = nullptr;
			while (true){
				auto pretail = next(current, k - 2);
				if (!pretail)
					break;
				auto tail = pretail->next;
				if (!tail)
					break;
				auto tailNext = tail->next;
				auto temp = reverse(current, k);
				if (!head){
					head = temp;
					prehead = lists;
				}
				else{
					prehead->next = temp;
					prehead = current;
				}

				current->next = tailNext;
				current = tailNext;
			}
			if (head)
				return head;
			return current;
		}
	private:
		ListNode* reverse(ListNode* head, int k){
			if (k <= 1)
				return head;
			if (!head || !head->next)
				return head;
			auto tail = head->next;
			ListNode* newHead = reverse(head->next, k - 1);
			auto temp = tail->next;
			tail->next = head;
			head->next = temp;
			return newHead;
		}
		ListNode* next(ListNode* head, int k){
			while (k --){
				if (!head)
					break;;
				head = head->next;
			}
			return head;
		}
	};
	TEST_CLASS(ReserveNodesInKGroup)
	{
	public:
		
		TEST_METHOD(ReserveNodesInKGroupTest)
		{
			assert_helper({ 1, 2, 3, 4, 5 }, 2, { 2, 1, 4, 3, 5 });
			assert_helper({ 1, 2, 3, 4, 5, 6 }, 2, { 2, 1, 4, 3, 6, 5 });
			assert_helper({ 1, 2, 3, 4, 5, 6 }, 3, {3, 2, 1, 6, 5, 4});
			assert_helper({ 1, 2, 3, 4, 5, 6 }, 4, {4, 3, 2, 1, 5, 6 });
			assert_helper({ 1, 2, 3, 4, 5, 6 }, 6, {6, 5, 4, 3, 2, 1});
			assert_helper({ 1, 2, 3, 4, 5, 6 }, 7, {1, 2, 3, 4, 5, 6});
		}

	private:
		void assert_helper(vector<int> data, int k, vector<int> expected){
			auto l1 = ConstructList(data);
			auto l2 = ConstructList(expected);
			Solution sln;
			auto ans = sln.reverseKGroup(l1, k);
			while (l2){
				Assert::AreEqual(l2->val, ans->val);
				l2 = l2->next;
				ans = ans->next;
			}
		}
	};
}

/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
You may not alter the values in the nodes, only nodes itself may be changed.
Only constant memeory is allowed.
For example,
Give this linked list: 1->2->3->4->5
For k = 2, you should return 2->1->4->3->5
For k = 3, you should return 3->2->1->4->5
*/