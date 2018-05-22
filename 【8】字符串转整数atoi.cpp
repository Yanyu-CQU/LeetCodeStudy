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

class Solution {
public:
	int myAtoi(string str) 
	{
		long long num = 0;
		int index = 0;
		bool isNega = false;
		if (str.size() == 0) return 0;
		while (str[index] == ' ') index++;
		if (str[index] == '-') 
		{
			isNega = true;
			index++;
		}
		else if (str[index] == '+')	index++;
		while (index != str.size())
		{
			if (isdigit(str[index]) == 0)
			{
				return num = isNega ? -num : num;
			}
			else
			{
				num *= 10;
				num += str[index] - '0';
				if (isNega && num >= (long long)0x80000000)
				{
					return (int)0x80000000;
				}
				else if (isNega == false && num >= 0x7FFFFFFF)
				{
					return 0x7FFFFFFF;
				}
			}
			index++;
		}
		num = isNega ? -num : num;
		return (int)num;
	}
};


int main()
{
	Solution s;
	string str;
	int num = 0;
	while (getline(cin, str))
	{
		//int num = s.romanToInt(str);
		num = s.myAtoi(str);
		cout << num << endl;
	}
	system("pause");
	return 1;
}