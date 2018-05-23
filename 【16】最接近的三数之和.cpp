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
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).                                                                 */
/************************************************************************/
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.size() < 3)	return 0;
		sort(nums.begin(), nums.end(), less<int>());
		int minDif = 0x7FFFFFFF, resSum = 0, sum = 0;
		for (auto base = nums.begin(); base < nums.end() - 2; ++base)
		{
			if (base != nums.begin() && *base == *(base - 1))	continue;
			auto left = base + 1, right = nums.end() - 1;
			while (left < right)
			{
				sum = *base + *left + *right;
				if (abs(sum - target) < minDif)
				{
					minDif = abs(sum - target);
					resSum = sum;
				}
				if (sum == target)	return sum;
				else if (sum < target)
				{
					left++;
					while (left < right && *left == *(left - 1))	left++;
				}
				else
				{
					right--;
					while (right > left && *right == *(right + 1))	right--;
				}
			}//while
		}//for
		return resSum;
	}
};

int main()
{
	Solution s;
	string str;
	vector<int> v;
	int num = 0,tartget = 0;
	cin >> tartget;
	while (cin >> num)
	{
		v.push_back(num);
	}
	//vector<vector<int>> res =  s.threeSum(v);
	cout << s.threeSumClosest(v, tartget);
	system("pause");
	return 1;
}
