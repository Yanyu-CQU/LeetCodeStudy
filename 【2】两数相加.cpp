#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <exception>
#include <sstream>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <memory.h>
#include <memory>
using namespace std;
/************************************************************************/
/* 给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807                                                                     */
/************************************************************************/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addCore(ListNode *l1, ListNode *l2, int carry, ListNode* node)
	{
		ListNode* head = nullptr;
		if (l1 == l2 && l1 == nullptr && carry == 0)
		{
			return head;
		}

		int num1 = 0, num2 = 0;
		if (l1 != nullptr)
		{
			num1 = l1->val;
		}
		if (l2 != nullptr)
		{
			num2 = l2->val;
		}
		int num = num1 + num2 + carry;
		if (num > 9)
		{
			carry = num / 10;
			num = num % 10;
		}
		else
		{
			carry = 0;
		}

		
		if (node == nullptr)
		{
			node = new ListNode(num);
			head = node;
		}
		else
		{
			node->next = new ListNode(num);
			node = node->next;
		}
		
		if (l1 != nullptr && l2 != nullptr)
		{
			addCore(l1->next, l2->next, carry, node);
		}
		else if (l2 != nullptr)
		{
			addCore(l1, l2->next, carry, node);
		}
		else if (l1 != nullptr)
		{
			addCore(l1->next, l2, carry, node);
		}
		return head;
	}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
        if (l1 == nullptr || l2 == nullptr)
        {
			return nullptr;
        }

		ListNode *head = addCore(l1, l2, 0, nullptr);
		return head;
    }
};
int main()
{
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
	Solution s;
	ListNode *head = s.addTwoNumbers(head1, head2);
	while (head != nullptr)
	{
		cout << head->val << '\t';
		head = head->next;
	}
	system("pause");
	return 1;
}
