#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x)
    {
        int sum = 0, middle_sum = 0, len = 0, n = nums.size(), ans = -1;
        // �ȼ�����������Ԫ�ص��ܺ�
        for (auto e : nums) sum += e;
        int target = sum - x;
        if (target < 0) return -1;
        // ʹ��˫ָ�뻬�����ڵ�˼·�����ҷ���������������
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
    cout << "��С��������Ϊ: " << result << endl;
    return 0;
}