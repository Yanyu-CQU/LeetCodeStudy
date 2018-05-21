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

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> res;
	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = i + 1; j < nums.size(); ++j)
		{
			if (nums[i] + nums[j] == target)
			{
				res.push_back(i);
				res.push_back(j);
				return res;
			}

		}
	}
}
int main()
{
	vector<int> data, res;
	int num;
	while (cin >> num)
	{
		data.push_back(num);
	}
	res = twoSum(data, 6);
	system("pause");
	return 1;
}
