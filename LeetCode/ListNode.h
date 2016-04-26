#pragma once
#include <vector>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* ConstructList(std::vector<int>& list);