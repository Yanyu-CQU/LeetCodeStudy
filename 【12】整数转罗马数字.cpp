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
/* 罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。

示例 1:
输入: 3
输出: "III"

示例 2:
输入: 4
输出: "IV"

示例 3:
输入: 9
输出: "IX"

示例 4:
输入: 58
输出: "LVIII"
解释: C = 100, L = 50, XXX = 30, III = 3.

示例 5:
输入: 1994
输出: "MCMXCIV"
解释: M = 1000, CM = 900, XC = 90, IV = 4.                                                                    */
/************************************************************************/
class Solution {
	//map<char, int> val;
public:
	/*Solution()
	{
		val['I'] = 1;
		val['V'] = 5;
		val['X'] = 10;
		val['L'] = 50;
		val['C'] = 100;
		val['D'] = 500;
		val['M'] = 1000;
	}*/
	inline int getVal(char c)
	{
		switch (c) 
		{
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		default: return 0;
		}
	}
	int romanToInt(string s) {
		if (s.size() == 0)
		{
			return 0;
		}
		int res = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (i != 0 && getVal(s[i]) > getVal(s[i - 1]))
			{
				res += getVal(s[i]);
				res -= 2 * getVal(s[i - 1]);
			}
			else
			{
				res += getVal(s[i]);
			}
		}
		return res;
	}
	/*string intToRoman(int num) {
		if (num <= 0)
		{
			return "";
		}
		string str;
		//M
		int M_Count = num / 1000;
		while (M_Count-- != 0) str += "M";
		num %= 1000;
		if (num >= 900)
		{
			str += "CM";
			num -= 900;
		}

		//D
		int D_Count = num >= 500;
		if (D_Count)	str += "D";
		num %= 500;
		if (num >= 400)
		{
			str += "CD";
			num -= 400;
		}

		//C
		int C_Count = num / 100;
		while (C_Count-- != 0)	str += "C";
		num %= 100;
		if (num >= 90)
		{
			str += "XC";
			num -= 90;
		}

		//L
		int L_Count = num >= 50;
		if (L_Count)	str += "L";
		num %= 50;
		if (num >= 40)
		{
			str += "XL";
			num -= 40;
		}

		//X
		int X_Count = num / 10;
		while (X_Count-- != 0)	str += "X";
		num %= 10;
		if (num >= 9)
		{
			str += "IX";
			num -= 9;
		}

		//V
		int V_Count = num >= 5;
		if (V_Count)	str += "V";
		num %= 5;
		if (num >= 4)
		{
			str += "IV";
			num -= 4;
		}

		//I
		int I_Count = num;
		while (I_Count-- != 0)	str += "I";

		return str;
	}*/
	string intToRoman(int num) {
		const int val[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
		const string symbol[] = {"M", "CM", "D", "CD", "C", "XC",
			"L", "XL", "X", "IX", "V", "IV", "I"}; 
		if (num == 0)
		{
			return "";
		}
		string str;
		int size = sizeof(val) / sizeof(int);
		for (int i = 0; i < size; ++i)
		{
			while (val[i] <= num)
			{
				str += symbol[i];
				num -= val[i];
			}
		}
		return str;
	}
};


int main()
{
	Solution s;
	string str;
	int num = 0;
	while (cin >> num)
	{
		//int num = s.romanToInt(str);
		str = s.intToRoman(num);
		cout << str << endl;
	}
	system("pause");
	return 1;
}