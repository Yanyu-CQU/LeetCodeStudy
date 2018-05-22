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
	bool match(const char* str, const char* pattern)
	{
		if (str == nullptr || pattern == nullptr)
		{
			return false;
		}
		if (*str == '\0' && *pattern == '\0')
		{
			return true;
		}
		if (*str != '\0' && *pattern == '\0')
		{
			return false;
		}
		if (*(pattern + 1) == '*')
		{
			if ((*pattern == '.' && *str != '\0') || *pattern == *str)
			{
				//				0 time					one time 						any times
				return match(str, pattern + 2) || match(str + 1, pattern + 2) || match(str + 1, pattern);
			}
			else
				return match(str, pattern + 2);
		}
		else
		{
			if ((*pattern == '.' && *str != '\0') || *pattern == *str)
			{
				return match(str + 1, pattern + 1);
			}
		}
		return false;
	}
	bool isMatch(string s, string p) {
		if (s.size() == p.size() && s.size() == 0)	return true;
		if (s.size() != 0 && p.size() == 0)	return false;
		return match(s.c_str(), p.c_str());
	}
};


int main()
{
	Solution s;
	string str1,str2;
	int num = 0;
	while (cin>>str1>>str2)
	{
		cout << s.isMatch(str1, str2) << endl;
	}
	system("pause");
	return 1;
}
