#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x)
    {
        int sum = 0, middle_sum = 0, len = 0, n = nums.size(), ans = -1;
        // 先计算数组所有元素的总和
        for (auto e : nums) sum += e;
        int target = sum - x;
        if (target < 0) return -1;
        // 使用双指针滑动窗口的思路来查找符合条件的子数组
        for (int left = 0, right = 0; right < n; right++) {
            middle_sum += nums[right];
            while (middle_sum > target) middle_sum -= nums[left++];
            if (middle_sum == target) ans = max(ans, right - left + 1);
        }
        if (ans == -1) return ans;
        else return n - ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 1, 1, 4, 2, 3 };
    int x = 5;
    int result = solution.minOperations(nums, x);
    cout << "最小操作次数为: " << result << endl;
    return 0;
}