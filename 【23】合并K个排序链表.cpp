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
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
1->4->5,
1->3->4,
2->6
]
输出: 1->1->2->3->4->4->5->6                                    */
/************************************************************************/


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* getMinNode(vector<ListNode*>& lists)
	{
		if (lists.size() == 0)	return nullptr;
		int minIndex = -1;
		for (auto it = lists.begin(); it != lists.end();)
		{
			if ((*it) != nullptr)
			{
				if (minIndex == -1)	minIndex = it - lists.begin();
				if ((*it)->val < lists[minIndex]->val)
				{
					minIndex = it - lists.begin();
				}
				++it;
			}
			else
			{
				it = lists.erase(it);
			}
		}
		if (minIndex != -1)
		{
			ListNode *res = lists[minIndex];
			lists[minIndex] = lists[minIndex]->next;
			return res;
		}
		else	return nullptr;
	}
	ListNode* mergeCore(vector<ListNode*>& lists)
	{
		ListNode *head = nullptr;
		head = getMinNode(lists);
		if (head != nullptr)
			head->next = mergeCore(lists);
		return head;
	}
	//另一种思路：两两合并
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)	return nullptr;
		stable_sort(lists.begin(), lists.end(), [](ListNode *l1, ListNode *l2)->bool {
			if (l1 == nullptr && l2 != nullptr)	return false;
			if (l1 != nullptr && l2 == nullptr)	return true;
			if (l1 == l2 && l1 == nullptr)	return true;
			return l1->val < l2->val;
		});
		lists.erase(find(lists.begin(), lists.end(), nullptr), lists.end());
		ListNode *head = mergeCore(lists);
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
	vector<ListNode*> list;
	list.push_back(head1);
	list.push_back(head2);
	ListNode *head = s.mergeKLists(list);
	system("pause");
	return 1;
}