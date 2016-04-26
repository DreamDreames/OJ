#include "stdafx.h"
#include "ListNode.h"
#include <vector>
#include <algorithm>
using namespace std;

#define _test

namespace LeetCode
{
	class MinHeap{
	public:
		void add(ListNode* node){
			if (!node)
				return;
			_heap.push_back(node);
			adjustHeap(_heap.size() - 1);
		}
		ListNode* pop(){
			if (_heap.empty())
				return nullptr;
			int size = _heap.size();
			auto front = _heap[0];
			swap(_heap[0], _heap[size-1]);
			_heap.pop_back();
			minHeap(0);
			return front;
		}
	private:
		void minHeap(int root){
			int size = _heap.size();
			if (_heap.empty())
				return;
			int ri = rightindex(root), li = leftindex(root);
			int least = root;
			if (ri < size && _heap[ri]->val < _heap[root]->val){
				least = ri;
			}
			if (li < size && _heap[li]->val < _heap[least]->val){
				least = li;
			}
			if (least != root){
				swap(_heap[root], _heap[least]);
				minHeap(least);
			}
		}
		void adjustHeap(int index){
			if (index == 0)
				return;
			int pi = parentindex(index);
			auto p = _heap[pi];
			auto c = _heap[index];
			if (c->val < p->val){
				swap(_heap[index], _heap[pi]);
				adjustHeap(pi);
			}
		}
		int parentindex(int index){
			return (index + 1) / 2 - 1;
		}
		int leftindex(int index){
			return (index + 1) * 2 - 1;
		}
		int rightindex(int index){
			return (index + 1) * 2;
		}
	private:
		template<typename T>
		void swap(T& left, T& right){
			T temp = left;
			left = right;
			right = temp;
		}
	private:
		vector<ListNode*> _heap;
	};

#ifdef _test
	class SolutionMergeKSortedLists {
#elif
	class Solution{
#endif
	public:
		ListNode* mergeKLists(vector<ListNode*>& lists) {
			MinHeap heap;
			for (auto &list : lists){
				if (list)
					heap.add(list);
			}
			ListNode *head, *current;
			head = current = heap.pop();
			if (head)
				heap.add(head->next);
			while (true){
				auto temp = heap.pop();
				if (!temp)
					return head;
				heap.add(temp->next);
				current->next = temp;
				current = temp;
			}
			return nullptr;
		}
	};

	TEST_CLASS(MergeKSortedLists)
	{
	public:

		TEST_METHOD(MergeKSortedListsTest)
		{
			assert_helper({ { 1, 2 }, { 1, 3 }, { 2, 3, 4 } }, { 1, 1, 2, 2, 3, 3, 4 });
			assert_helper({ { 1 } }, { 1 });
			assert_helper({ { 4, 5 }, { 1, 2 } }, { 1, 2, 4, 5 });
			assert_helper({ { 1 }, { 0 } }, { 0, 1 });
			assert_helper({ { 1, 8 }, { 6 }, { 2, 10 } }, { 1, 2, 6, 8, 10 });
			assert_helper({ { -8, -7, -7, -5, 1, 1, 3, 4 }, { -2 }, { -10, -10, -7, 0, 1, 3 }, { 2 } }, { -10, -10, -8, -7, -7, -7, -5, -2, 0, 1, 1, 1, 2, 3, 3, 4 });

			assert_helper({ { -8, -8, -3, -2, 0, 2, 2, 3, 3 }, { -5, -3, 1 }, { -9, -7, -1, 4 }, { -10, -4, -4, -4, 0, 3 }, { -2, 4 }, { -9, -6, -5, -5, -3, -3, -2, 2 }, { 1, 3 }, { -8, -3, -2, 1, 3 } }, { -10, -9, -9, -8, -8, -8, -7, -6, -5, -5, -5, -4, -4, -4, -3, -3, -3, -3, -3, -2, -2, -2, -2, -1, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4 });
			assert_helper({ {} }, {});
			assert_helper({ { -8, 2, 4 }, { -9, -9, -9, -9, -8, -5, -3, -2, 1 }, { -9, -7, -5, -3, -3, -1, 0, 3, 4 }, { -9, -7, -6, -4, -2, -1, 3, 4 }, { -10, -3, 0 }, { -9, 0, 4 }, { -8, -8 } }, { -10, -9, -9, -9, -9, -9, -9, -9, -8, -8, -8, -8, -7, -7, -6, -5, -5, -4, -3, -3, -3, -3, -2, -2, -1, -1, 0, 0, 0, 1, 2, 3, 3, 4, 4, 4, 4 });
		}
	private:
		void assert_helper(vector<vector<int>> lists, vector<int> expected){
			vector<ListNode*> data;
			for (auto list : lists){
				auto head = buildLinkedList(list);
				if (head)
					data.push_back(head);
			}

			SolutionMergeKSortedLists sln;
			auto ans = sln.mergeKLists(data);
			assert_list(ans, expected);
		}
		void assert_list(ListNode* ans, vector<int> expected){
			int i = 0;
			while (ans){
				Assert::AreEqual(expected[i++], ans->val);
				ans = ans->next;
			}
		}
		ListNode* buildLinkedList(vector<int> list){
			if (list.empty())
				return nullptr;
			auto head = new ListNode(list[0]);
			auto current = head;
			for (int i = 1; i < list.size(); ++i){
				auto temp = new ListNode(list[i]);
				current->next = temp;
				current = temp;
			}
			return head;
		}
	};
}
/*
Merge k sorted linked lists and return it as one sorted list.
Analyze and describe its complexity.
*/