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
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:
输入: "()"
输出: true

示例 2:
输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false

示例 4:
输入: "([)]"
输出: false

示例 5:
输入: "{[]}"
输出: true                                                */
/************************************************************************/

class Solution {
public:
	bool isValid(string s) {
		stack<char> left;
		if (s.size() == 0)	return true;
		for (auto it = s.cbegin(); it != s.cend(); ++it)
		{
			if (*it == '(' || *it == '[' || *it == '{')	left.push(*it);
			else
			{
				switch(*it)
				{
				case ')':
					if (left.empty() || left.top() != '(')	return false;
					left.pop();
					break;
				case  ']':
					if (left.empty() || left.top() != '[')	return false;
					left.pop();
					break;
				case '}':
					if (left.empty() || left.top() != '{')	return false;
					left.pop();
					break;
				default:
					break;
				}
			}
		}
		if (left.size() == 0)	return true;
		return false;
	}
};

int main()
{
	Solution s;
	string str;
	cin >> str;
	cout << s.isValid(str);
	system("pause");
	return 1;
}