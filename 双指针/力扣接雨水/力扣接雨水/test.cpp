#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int left = 0, right = n - 1;
        int max_left = 0, max_right = 0;
        while (left <= right) {
            // 更新左边最大高度
            max_left = max(max_left, height[left]);
            // 更新右边最大高度
            max_right = max(max_right, height[right]);
            // 根据左右两边最大高度较小值来计算当前位置可接住的雨水量并累加到ans中
            ans += max_left < max_right ? max_left - height[left++] : max_right - height[right--];
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    int result = solution.trap(height);
    cout << "该数组能接住的雨水量为: " << result << endl;
    return 0;
}