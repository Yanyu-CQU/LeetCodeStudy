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
/* 给定一个 32 位有符号整数，将整数中的数字进行反转。

示例 1:
输入: 123
输出: 321
示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。根据这个假设，如果反转后的整数溢出，则返回 0。                                                                     */
/************************************************************************/

const int MAX_INT[] = {2,1,4,7,4,8,3,6,4,7};
const int MIN_INT[] = {2,1,4,7,4,8,3,6,4,8};
class Solution {
public:
	int reverse(int x) 
	{
		if (x == 0x80000000)
		{
			return 0;
		}
		bool isNega = x < 0;
		int res = 0;
		x = x < 0 ? -x : x;
		bool isPassibleOverFlow = x > 1000000000;
		int count = 0;
		while (x !=0)
		{
			int num = x % 10;
			if (isPassibleOverFlow)
			{
				if (isNega)
				{
					if (num > MIN_INT[count])
					{
						return 0;
					}
					else if (num < MIN_INT[count])
					{
						isPassibleOverFlow = false;
					}
				}
				else
				{
					if (num > MAX_INT[count])
					{
						return 0;
					}
					else if (num < MAX_INT[count])
					{
						isPassibleOverFlow = false;
					}
				}
			}
			res *= 10;
			res += num;
			x /= 10;
			count++;
		}
		if (isNega)
		{
			res = -res;
		}
		return res;
	}
};


int main()
{
	Solution s;
	int num = 0;
	cin >> num;
	cout << s.reverse(num);
	system("pause");
	return 1;
}