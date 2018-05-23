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
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
[-1,  0, 0, 1],
[-2, -1, 1, 2],
[-2,  0, 0, 2]
]                                                             */
/************************************************************************/
class Solution {
	unordered_map<int, vector<pair<int,int> > > cache;
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> res;
		vector<int>	temp(4);
		if (nums.size() < 4)	return res;
		sort(nums.begin(), nums.end(), less<int>());
		for (int i = 0; i < nums.size() - 1; ++i)
		{
			for (int j = i + 1; j < nums.size(); ++j)
			{
				int sum = nums[i] + nums[j];
				cache[sum].push_back(make_pair(i,j));//首先使用hash缓存所有可能出现的两数之和
			}
		}
		for (int i = 0; i < nums.size() - 3; ++i)
		{
			if (i != 0 && nums[i] == nums[i - 1])	continue;;
			for (int j = i + 1; j < nums.size() - 2; ++j)
			{
				if (j != i + 1 && nums[j] == nums[j - 1])	continue;
				int key = target - nums[i] - nums[j];
				if (cache.find(key) == cache.end())	continue;//接下来需要两数之和为key，如果缓存没有可以直接跳过
				
				auto v = cache[key];
				for (auto it = v.begin(); it != v.end(); ++it)
				{
					if (it->first <= j)	continue;//注意是小于等于
					temp[0] = nums[i]; temp[1] = nums[j]; temp[2] = nums[it->first]; temp[3] = nums[it->second];
					res.push_back(temp);
				}
			}//for j
		}//for i
		sort(res.begin(), res.end());
		res.erase(unique(res.begin(), res.end()), res.end());
		return res;
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
	vector<vector<int> > res =  s.fourSum(v, tartget);
	system("pause");
	return 1;
}