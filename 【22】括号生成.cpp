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

给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]                                     */
/************************************************************************/


class Solution {
public:
	void genCore(int leftCount, int rightCount, int n, string & str, vector<string> & res)
	{
		if (leftCount == n && rightCount == n) return;
		if (leftCount < n)//左括号未满时可以添加
		{
			str[leftCount + rightCount] = '(';
			genCore(leftCount + 1, rightCount, n, str, res);
		}
		//这两个是或的关系，但是总是右括号结尾，左括号开头
		if (rightCount < leftCount)//右括号比左括号少时可以添加
		{
			str[leftCount + rightCount] = ')';
			if (leftCount == n && (rightCount + 1) == n)
			{
				res.push_back(str);
				return;
			}
			genCore(leftCount, rightCount + 1, n, str, res);
		}
		
	}
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		if (n == 0)	return res;
		string str(n * 2, '0');
		genCore(0, 0, n, str, res);
		return res;
	}
};

int main()
{
	Solution s;
	int val = 0;
	cin >> val;
	vector<string> v = s.generateParenthesis(val);
	system("pause");
	return 1;
}
