#include "stdafx.h"
#include "ListNode.h"
#include <vector>

using namespace std;

namespace LeetCode
{
	class Solution {
	public:
		ListNode *removeNthFromEnd(ListNode *head, int n) {
			if (n <= 0)
				return head;
			vector<ListNode*> nodes;
			ListNode* cur = head;
			do{
				nodes.push_back(cur);
				cur = cur->next;
			} while (cur != nullptr);
			if (nodes.size() == 1){
				delete head;
				return nullptr;
			}

			int r = nodes.size() - n;
			if (n == 1) 
				nodes[r - 1]->next = nullptr;
			else if (n == nodes.size())
				head = head->next;
			else
				nodes[r - 1]->next = nodes[r + 1];

			delete nodes[r];
			return head;
		}
	};

	TEST_CLASS(RemoveNthNodeFromEndOfList)
	{
	public:
		TEST_METHOD(RemoveNthNodeFromEndOfListTest)
		{
			assert_helper({ 1, 2, 3, 4, 5 }, 2, { 1, 2, 3, 5 });
			assert_helper({ 1, 2, 3 }, 1, { 1, 2 });
			assert_helper({ 1, 2, 3 }, 3, { 2, 3 });
			assert_helper({ 1 }, 1, {});
		}
	private:
		void assert_helper(vector<int> src, int n, vector<int> tar){
			ListNode *head = new ListNode(src[0]);
			ListNode* cur = head;
			for (int i = 1; i < src.size(); ++i){
				ListNode* node = new ListNode(src[i]);
				cur->next = node;
				cur = node;
			}
			Solution sln;
			ListNode* ans = sln.removeNthFromEnd(head, n);
			for (auto v : tar){
				Assert::AreEqual(v, ans->val);
				ans = ans->next;
			}
			Assert::IsNull(ans);
		}
	};
}


/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/