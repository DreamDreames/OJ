#include "stdafx.h"
#include "ListNode.h"

using namespace std;

namespace SwapNodesInPair
{
	class Solution{
	public:
		ListNode* swapPairs(ListNode* head){
			auto h = swapTwo(head);
			auto current = h;
			while (true){
				auto p = next(current);
				if (!p) break;
				auto temp = swapTwo(p);
				current->next->next = temp;
				current = temp;
			}
			return h;
		}
	private:
		ListNode* next(ListNode* nodes){
			if (!nodes)
				return nullptr;
			auto temp = nodes->next;
			if (temp)
				return temp->next;
			return temp;
		}
		ListNode* swapTwo(ListNode* nodes){
			if (!nodes)
				return nullptr;
			auto first = nodes;
			auto second = nodes->next;
			if (!second)
				return first;
			auto third = second->next;
			second->next = first;
			first->next = third;
			return second;
		}
	};
	TEST_CLASS(SwapNodesInPairs)
	{
	public:
		TEST_METHOD(SwapNodesInPairsTest)
		{
			assert_helper({ 1, 2, 3, 4 }, { 2, 1, 4, 3 });
			assert_helper({ 1}, {1});
			assert_helper({ 1, 2}, {2, 1});
			assert_helper({ 1, 2, 3}, {2, 1, 3});
			assert_helper({}, {});
		}
	private:
		void assert_helper(vector<int> lists, vector<int>expected){
			auto head = ConstructList(lists);
			Solution sln;
			head = sln.swapPairs(head);
			for (auto &e : expected){
				Assert::AreEqual(e, head->val);
				head = head->next;
			}
		}
	};
}
/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/