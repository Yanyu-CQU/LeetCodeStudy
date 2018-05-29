#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <exception>
#include <sstream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <memory.h>
#include <memory>
using namespace std;

/************************************************************************/
/* 
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

示例 1:
给定数组 nums = [1,1,2], 
函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 
你不需要考虑数组中超出新长度后面的元素。

示例 2:
给定 nums = [0,0,1,1,1,2,2,3,3,4],
函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
你不需要考虑数组中超出新长度后面的元素。
说明:
为什么返回数值是整数，但输出的答案是数组呢?
请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:
// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
int len = removeDuplicates(nums);
// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
for (int i = 0; i < len; i++) {
print(nums[i]);
}                                   */
/************************************************************************/
/*
class Solution {
public:
	void move(vector<int>& nums, int index1, int index2,int offset, int count)
	{
		int start = index1 + offset;
		int end = index2;
		while (start <= end)
		{
			nums[start - count] = nums[start];
			start++;
		}
		return;
	}
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		map<int, int> index;
		int count = 0;
		for (int i = 0; i < nums.size() - 1; ++i)
		{
			int j = i + 1;
			if (nums[i] == nums[j])
			{
				
				while (j != nums.size() && nums[i] == nums[j])
				{
					count++;
					j++;
				}
				index.insert(make_pair(i, j - i));
				nums[i + 1] = count;
				i = j - 1;
			}
		}
		auto it = index.begin();
		auto next = it; 
		if (next != index.end()) ++next;

		while (it != index.end())
		{
			if (next != index.end())
			{
				//		index1		index2			offset		count
				move(nums, it->first, next->first, it->second, nums[it->first + 1]);
				++next;
			}
			else
				move(nums, it->first, nums.size() - 1, it->second, nums[it->first + 1]);
			++it;
		}
		return nums.size() - count;
	}
};
*/
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int last = 1;
		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[i] != nums[last - 1])
			{
				nums[last++] = nums[i];
			}
		}
		return last;
	}
};

int main()
{
	Solution s;
	int val = 0, K = 0;
	vector<int> num;
	while (cin >> val)
		num.push_back(val);
	cout << s.removeDuplicates(num);
	system("pause");
	return 1;
}


int main()
{
	Solution s;
	int val = 0, K = 0;
	vector<int> num;
	while (cin >> val)
		num.push_back(val);
	cout << s.removeDuplicates(num);
	system("pause");
	return 1;
}