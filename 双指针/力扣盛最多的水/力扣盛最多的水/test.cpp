#include <iostream>
#include <vector>
#include <algorithm> // 引入max和min函数所在的头文件

using namespace std;

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int n = height.size(), left = 0, right = n - 1, ret = 0;
        while (left <= right)
        {
            int v = (right - left) * min(height[left], height[right]);
            ret = max(ret, v);
            if (height[right] < height[left])
                right--;
            else
                left++;
        }
        return ret;
    }
};

int main()
{
    Solution solution;
    vector<int> heights = { 1, 8, 6, 2, 5, 4, 8, 3, 7 }; // 这里可以自定义容器高度数组，示例随便给定了一组数据
    int result = solution.maxArea(heights);
    cout << "能容纳的最大水面积为: " << result << endl;
    return 0;
}