#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <exception>
#include <sstream>
#include <map>
#include <unordered_map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <memory.h>
#include <memory>
using namespace std;

/************************************************************************/
/* 
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.
说明:

你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。                                   */
/************************************************************************/


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr) return nullptr;
		if (head->next != nullptr)	
		{
			ListNode *node = head->next;
			if (node->next != nullptr)
			{
				head->next = node->next;
				node->next = head;
				ListNode *res = node;
				node = node->next;
				node->next = swapPairs(node->next);
				return res;
			}
			else
			{
				node->next = head;
				head->next = nullptr;
				return node;
			}
		}
		else return head;
	}
};

int main()
{
	Solution s;
	int val = 0;
	ListNode *head1 = nullptr, *head2 = nullptr, *temp = nullptr;
	while (cin >> val)
	{
		if (head1 == nullptr)
		{
			head1 = new ListNode(val);
			temp = head1;
		}
		else
		{
			temp->next = new ListNode(val);
			temp = temp->next;
		}
	}
	
	ListNode *head = s.swapPairs(head1);
	system("pause");
	return 1;
}