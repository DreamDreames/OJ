#include "stdafx.h"
#include "ListNode.h"
namespace LeetCode
{
#define compare(l1, l2)(l1->val <= l2->val)

	class Solution {
	public:
		ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
			if (l2 == nullptr) return l1;
			if (l1 == nullptr) return l2;
			ListNode* head;
			if (compare(l1, l2)){
				head = l1;
				l1 = l1->next;
			}
			else{
				head = l2;
				l2 = l2->next;
			}
			auto cur = head;

			while (l1 != nullptr && l2 != nullptr){
				ListNode* temp;

				if (compare(l1, l2)){
					temp = l1;
					l1 = l1->next;
				}
				else{
					temp = l2;
					l2 = l2->next;
				}
				cur->next = temp;
				cur = cur->next;
			}
			if (l1 == nullptr)
				cur->next = l2;
			else
				cur->next = l1;

			return head;
		}
	};

	TEST_CLASS(MergeTwoSortedLists)
	{
	public:
		TEST_METHOD(MergeTwoSortedListsTest)
		{
			assert_helper({ 1, 2, 3 }, { 4 }, { 1, 2, 3, 4 });
			assert_helper({1, 2, 3}, { 0 }, {0, 1, 2, 3});
			assert_helper({1, 3}, { 2 }, {1, 2, 3});
			assert_helper({ 3 }, { 1, 2 }, {1, 2, 3});
			assert_helper({ 2 }, {1, 3}, {1, 2, 3});
			assert_helper({ 1 }, {2, 3}, {1, 2, 3});
			assert_helper({ 1 }, {2}, {1, 2});
			assert_helper({ 2 }, {1}, {1, 2});
		}
	private:
		void assert_helper(vector<int> list1, vector<int> list2, vector<int> expected){

			auto l1 = ConstructList(list1);
			auto l2 = ConstructList(list2);

			Solution sln;
			auto actual = sln.mergeTwoLists(l1, l2);

			for (auto v : expected){
				Assert::AreEqual(v, actual->val);
				actual = actual->next;
			}
			Assert::IsNull(actual);
		}
	};
}


/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/