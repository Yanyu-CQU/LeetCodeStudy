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

/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。
请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。

示例 1:
nums1 = [1, 3]
nums2 = [2]
中位数是 2.0

示例 2:
nums1 = [1, 2]
nums2 = [3, 4]
中位数是 (2 + 3)/2 = 2.5
*/

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() == 0 && nums2.size() == 0)
		{
			return 0;
		}
		if (nums1.size() == 0)
		{
			return (nums2[nums2.size() / 2] + nums2[(nums2.size() - 1) / 2]) / 2.0;
		}
		if (nums2.size() == 0)
		{
			return (nums1[nums1.size() / 2] + nums1[(nums1.size() - 1) / 2]) / 2.0;
		}
		int len = nums1.size() + nums2.size();
		double res = 0.0;
		if (len % 2 == 1)
		{
			res = getKthNumber(nums1, nums2, len / 2);//找两个数组的第K大的数，本题是中位数
		}
		else
		{
			double left = getKthNumber(nums1, nums2, (len - 1) / 2);
			double right = getKthNumber(nums1, nums2, len / 2);
			res = (left + right) / 2;
		}

		return res;
	}
	double getKthNumber(vector<int>& nums1, vector<int>& nums2, int k)
	{
		int Kth = k,start1 = 0, start2 = 0;
		//Kth其实的真实含义是，还需要排除多少个数？
		//从 A 和 B 中分别取前 k/2 个元素，其中必然有一部分是是在数组 C 的前 k 个数里。
		//设 mid = k / 2，当 A[mid - 1] < B[mid - 1] 时，可以断定 A 的前 mid 个元素是在 C 的前 k 个数里，
		//那么我们则舍弃 A 的前 mid 个元素。反之则舍弃 B 的前 mid 个元素。现在数组 A 或者 B 已经舍弃掉 k/2 个元素，
		//现在剩下总共 (L - mid) 个元素，且 A 和 B 依旧有序，要找的是第 (k - mid) 大的元素
		//可以按照上面的方法继续递归选择下去，直到找到目标元素！
		if (Kth == 0)
		{
			return nums1[start1] < nums2[start2] ? nums1[start1] : nums2[start2];
		}
		int left1 = k / 2 - 1, left2 = k / 2 - 1;
		int size1 = nums1.size();
		int size2 = nums2.size();
		left1 = left1 < 0 ? 0 : left1;
		left2 = left2 < 0 ? 0 : left2;
		if ((start1 + left1) > (size1 - 1))
		{
			left1 = (size1 - 1 - start1);
		}
		if ((start2 + left2) > (size2 - 1))
		{
			left2 = (size2 - 1 - start2);
		}
		
		while (Kth != 0)
		{

			if (nums1[start1 + left1] < nums2[start2 + left2])
			{
				if (start1 == nums1.size() - 1)//一个数组走到头了，直接从另一个里面找
				{
					Kth--;
					return nums2[Kth + start2];
				}
				if (left1 == 0)//当前坐标不是最后元素，至少向前走一格
				{
					start1++;
					Kth--;
				}
				else
				{
					start1 += left1;
					Kth -= left1;
				}
				if (Kth == 0)//排除完毕
				{
					return nums1[start1] < nums2[start2] ? nums1[start1] : nums2[start2];
				}
			}
			else
			{
				if (start2 == nums2.size() - 1)
				{
					Kth--;
					return nums1[Kth + start1];
				}
				if (left2 == 0)
				{
					start2++;
					Kth--;
				}
				else
				{
					start2 += left2;
					Kth -= left2;
				}
				if (Kth == 0)
				{
					return nums1[start1] < nums2[start2] ? nums1[start1] : nums2[start2];
				}
			}
			left1 = left2 = Kth / 2 - 1;
			left1 = left1 < 0 ? 0 : left1;
			left2 = left2 < 0 ? 0 : left2;
			left1 = start1 + left1 < nums1.size() - 1 ? left1 : nums1.size() - 1 - start1;
			left2 = start2 + left2 < nums2.size() - 1 ? left2 : nums2.size() - 1 - start2;
		}
		
	}
};
int main()
{
	vector<int> num1, num2;
	int num = 0;
	while (cin >> num)
	{
		num1.push_back(num);
	}
	cin.clear();
	while (cin >> num)
	{
		num2.push_back(num);
	}
	Solution s;
	cout << s.findMedianSortedArrays(num1, num2);
	system("pause");
	return 1;
}