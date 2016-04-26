#include "stdafx.h"
#include "ListNode.h"


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