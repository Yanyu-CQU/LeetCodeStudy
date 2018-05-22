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
/* 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:
输入: 121
输出: true

示例 2:
输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

示例 3:
输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。

进阶:
你能不将整数转为字符串来解决这个问题吗？                                                                     */
/************************************************************************/
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
		{
			return false;
		}
		int cmp = 0, cal = x;
		int d = 1;
		while (x / d >= 10) d *= 10;
		while (cal != 0 && x !=0)
		{
			int front = x /d;
			int back = x % 10;
			if (front != back)
			{
				return false;
			}
			x %= d;
			x /= 10;
			d /= 100;
		}
		return true;
	}
};


int main()
{
	int num = 0;
	Solution s;
	while (cin >> num)
	{
		cout << s.isPalindrome(num) << endl;
	}
	system("pause");
	return 1;
}