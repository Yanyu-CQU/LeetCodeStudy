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
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4                                       */
/************************************************************************/



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
	{
		if (l1 == l2 && l1 == nullptr)	return nullptr;
		if (l1 != nullptr && l2 == nullptr)	return l1;
		if (l1 == nullptr && l2 != nullptr)	return l2;

		ListNode *head = nullptr;
		if (l1->val < l2->val)
		{
			head = l1;
			head->next = mergeTwoLists(l1->next, l2);
		}
		else
		{
			head = l2;
			head->next = mergeTwoLists(l1, l2->next);
		}
		return head;
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
	cin.clear();
	while (cin >> val)
	{
		if (head2 == nullptr)
		{
			head2 = new ListNode(val);
			temp = head2;
		}
		else
		{
			temp->next = new ListNode(val);
			temp = temp->next;
		}
	}
	ListNode* head = s.mergeTwoLists(head1, head2);
	system("pause");
	return 1;
}