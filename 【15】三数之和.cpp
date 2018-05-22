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
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
[-1, 0, 1],
[-1, -1, 2]
]                                                                     */
/************************************************************************/

/*
先排序，然后左右夹逼，复杂度 O(n )。
这个方法可以推广到 k-sum ，先排序，然后做 k-2 次循环，在最内层循环左右夹逼，
时间复杂度是	O(max{n log n, n })。
*/
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() < 3)	return res;
		vector<int> temp(3);
		
		sort(nums.begin(), nums.end(), less<int>());
		int left = 0, right = nums.size() - 1, mid = 0;
		for (; mid < nums.size() - 2; ++mid)
		{
			if (mid > 0 && nums[mid] == nums[mid - 1])	continue;
			left = mid + 1; right = nums.size() - 1;
			while (left < right && left != mid && right != mid)
			{
				int sum = nums[left] + nums[mid] + nums[right];
				if (sum == 0)
				{
					temp[0] = nums[left]; temp[1] = nums[mid]; temp[2] = nums[right];
					res.push_back(temp);
					left++;
					while (left < right && nums[left] == nums[left - 1]) left++;
				}
				else if (sum < 0){
					left++;
					while (left < right && nums[left] == nums[left - 1]) left++;
				}
				else{
					right--;
					while (right > left && nums[right] == nums[right + 1]) right--;
				}
			}
		}
		return res;
	}
};

int main()
{
	Solution s;
	string str;
	vector<int> v;
	int num = 0;
	while (cin >> num)
	{
		v.push_back(num);
	}
	vector<vector<int>> res =  s.threeSum(v);
	system("pause");
	return 1;
}