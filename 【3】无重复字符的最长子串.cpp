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

/**
给定一个字符串，找出不含有重复字符的最长子串的长度。

示例：

给定 "abcabcbb" ，没有重复字符的最长子串是 "abc" ，那么长度就是3。

给定 "bbbbb" ，最长的子串就是 "b" ，长度是1。

给定 "pwwkew" ，最长子串是 "wke" ，长度是3。请注意答案必须是一个子串，"pwke" 是 子序列  而不是子串。
*/

class Solution {
	int hash[256];
public:
	Solution()
	{
		memset(hash, -1, sizeof(int) * 256);
	}
	int lengthOfLongestSubstring(string s) {
		if (s.size() == 0)
		{
			return 0;
		}
		int i = 0,count = 0, max = 0, size = s.size(), left = -1;
		while (i < size)
		{
			if (hash[s[i]] != -1)
			{
				left = hash[s[i]] > left ? hash[s[i]] : left;
			}
			count = i - left;
			max = max > count ? max : count;
			
			hash[s[i]] = i;
			i++;
		}
		return max;
	}
};
int main()
{
	string str;
	cin >> str;
	Solution s;
	cout << s.lengthOfLongestSubstring(str);
	system("pause");
	return 1;
}