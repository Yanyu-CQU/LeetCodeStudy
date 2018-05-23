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
/* 

给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。                                                             */
/************************************************************************/
const string val[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
class Solution {
public:
	void comCore(vector<int> & num, vector<string> & res, string & str, int size, int index)
	{
		if (index >= size)	return ;
		string temp = val[num[index]];
		for (int i = 0; i < temp.size(); ++i)
		{
			str[index] = temp[i];
			comCore(num, res, str, size, index + 1);
			if (index == size - 1)	res.push_back(str);
		}
	}
	vector<string> letterCombinations(string digits) {
		vector<string> res;
		vector<int> nums;
		if (digits.size() == 0)	return res;
		for (auto it = digits.cbegin(); it != digits.cend(); ++it)
		{
			int num = *it - '0';
			nums.push_back(num);
		}
		string str(nums.size(), '0');
		comCore(nums, res, str, nums.size(), 0);
		return res;
	}
};

int main()
{
	Solution s;
	string str;
	/*vector<int> v;
	int num = 0,tartget = 0;
	cin >> tartget;
	while (cin >> num)
	{
		v.push_back(num);
	}*/
	cin >> str;
	//vector<vector<int>> res =  s.threeSum(v);
	vector<string> res =  s.letterCombinations(str);
	system("pause");
	return 1;
}