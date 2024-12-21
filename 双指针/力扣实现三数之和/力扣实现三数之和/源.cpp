#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        std::ranges::sort(nums);
        int i = 0, j = nums.size() - 1;
        int ans = 0;
        while (i < j) {
            if (nums[i] + nums[j] < target) {
                ans += j - i;
                i++;
            }
            else {
                j--;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = { 1, 3, 2, 4, 5 };  // 示例数据，可以自行修改
    int target = 6;  // 示例目标值，可按需更改
    int result = solution.countPairs(nums, target);
    std::cout << "满足两数之和小于 " << target << " 的数对数量为: " << result << std::endl;
    return 0;
}