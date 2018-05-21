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
/* 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。

示例 1：
输入: "babad"
输出: "bab"
注意: "aba"也是一个有效答案。

示例 2：
输入: "cbbd"
输出: "bb"                                                                     */
/************************************************************************/

//暴力

class Solution {
public:
	pair<int,int> getSubLen(const string & s, int left, int right)
	{
		int count = 0;
		if (left == right)
		{
			count++;
		}
		else
		{
			count += 2;
		}
		left--;right++;
		while (left >= 0 && right < s.size())
		{
			if (s[left] == s[right])
			{
				count += 2;
			}
			else
			{
				break;
			}
			left--;right++;
		}
		int startIndex = ++left;
		return make_pair(count, startIndex);
	}
	string longestPalindrome(string s) {
		
		if (s.size() < 2)
		{
			return s;
		}
		pair<int, int> longest;
		for (int i = 0; i < s.size() - 1; ++i)
		{
			pair<int,int> res = getSubLen(s, i, i);
			if (s[i] == s[i + 1])
			{
				pair<int, int> cmp = getSubLen(s, i, i + 1);
				if (cmp.first > res.first)
				{
					res = cmp;
				}
			}
			if (res.first > longest.first)
			{
				longest = res;
			}
		}
		return s.substr(longest.second, longest.first);
	}
};


int main()
{
	string str;
	cin >> str;
	Solution s;
	cout << s.longestPalindrome(str);
	system("pause");
	return 1;
}