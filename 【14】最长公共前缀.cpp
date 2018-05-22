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
/* 编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。                                                                     */
/************************************************************************/
class Solution {
public:
	bool isSame(vector<string>& strs, int index)
	{
		for (auto it = strs.begin(); it != strs.end(); ++it)
		{
			if (index >= it->size())	return false;
			char c = strs[0][index];
			if ((*it)[index] != c)	return false;
		}
		return true;
	}
	string longestCommonPrefix(vector<string>& strs)
	{
		string str;
		if (strs.size() == 0) return str;
		int index = 0;
		while (true)
		{
			if (isSame(strs, index) == false)	break;
			index++;
		}
		return strs[0].substr(0, index);
	}
};

int main()
{
	Solution s;
	string str;
	vector<string> v;
	int num = 0;
	while (cin >> str)
	{
		v.push_back(str);
	}
	cout << s.longestCommonPrefix(v);
	system("pause");
	return 1;
}