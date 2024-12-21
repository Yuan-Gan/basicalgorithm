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
    std::vector<int> nums = { 1, 3, 2, 4, 5 };  // ʾ�����ݣ����������޸�
    int target = 6;  // ʾ��Ŀ��ֵ���ɰ������
    int result = solution.countPairs(nums, target);
    std::cout << "��������֮��С�� " << target << " ����������Ϊ: " << result << std::endl;
    return 0;
}