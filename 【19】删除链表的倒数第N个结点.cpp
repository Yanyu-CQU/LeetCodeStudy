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

给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：
你能尝试使用一趟扫描实现吗？                                                    */
/************************************************************************/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr)	return nullptr;
		int bkN = n;
		ListNode *node = head;
		while (bkN-- != 0)	node = node->next;
		ListNode *del = head, *preDel = nullptr;
		while (node != nullptr)
		{
			node = node->next;
			del = del->next;
			if (preDel == nullptr)	preDel = head;
			else	preDel = preDel->next;
		}
		if (del != nullptr)
		{
			if (del == head)
			{
				node = head->next;
				delete head;
				head = nullptr;
				return node;
			}
			preDel->next = del->next;
			delete del;
			del = nullptr;
		}
		return head;
    }
};

int main()
{
	Solution s;
	int val = 0;
	ListNode *head = nullptr, *temp = nullptr;
	while (cin >> val)
	{
		if (head == nullptr)
		{
			head = new ListNode(val);
			temp = head;
		}
		else
		{
			temp->next = new ListNode(val);
			temp = temp->next;
		}
	}
	ListNode *h = s.removeNthFromEnd(head, 1);
	system("pause");
	return 1;
}