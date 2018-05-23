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
给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。

示例 :
给定这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5

说明 :

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
	ListNode* reverse(ListNode* head, ListNode* end)//不包括end
	{
		ListNode *pre = head, *cur = head->next, *temp = nullptr;
		ListNode *res = pre;
		while (cur != end)
		{
			temp = cur->next;
			cur->next = pre;
			pre = cur;
			res = cur;
			cur = temp;
		}
		head->next = end;
		return res;
	}
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == nullptr) return nullptr;
		int bkK = k;
		ListNode *node = head;
		while (bkK != 0)
		{
			if (node->next != nullptr)
			{
				node = node->next;
				bkK--;
			}
			else break;
		}
		if (bkK != 0)
		{
			if (bkK == 1) return reverse(head, nullptr);
			return head;
		}
		else
		{
			ListNode *res = reverse(head, node);
			head->next = node;
			head->next = reverseKGroup(head->next, k);
			return res;
		}
	}
};

int main()
{
	Solution s;
	int val = 0, K = 0;
	cin >> K;
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
	
	ListNode *head = s.reverseKGroup(head1, K);
	system("pause");
	return 1;
}