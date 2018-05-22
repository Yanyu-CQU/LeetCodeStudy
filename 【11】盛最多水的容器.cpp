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
	int maxArea(vector<int>& height) {
		if (height.size() == 0)
		{
			return 0;
		}
		int maxArea = 0, left = 0, right = height.size() - 1;
		//贪心的思想，对于左右两个高度，如果保留最低的一个，另一个移动，那么新的容量一定更小！因为最小高度一致的情况，宽度决定容量。
		//因此移动最小的一个，才是唯一有可能比当前容量更大的方法。
		while (left < right)
		{
			int area = min(height[left], height[right]) * (right - left);
			maxArea = max(area, maxArea);
			if (height[left] < height[right])	left++;
			else	right--;
		}
		return maxArea;
	}
};

int main()
{
	Solution s;
	vector<int> v;
	int num = 0;
	while (cin >> num)
	{
		v.push_back(num);
	}
	cout << s.maxArea(v);
	system("pause");
	return 1;
}