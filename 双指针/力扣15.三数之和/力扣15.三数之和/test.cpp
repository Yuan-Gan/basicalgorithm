#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // �ȱ���һ��
        vector<vector<int>> ans;
        ranges::sort(nums);
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            int x = nums[i];
            if (i && x == nums[i - 1]) continue; // �����ظ�����
            if (x + nums[i + 1] + nums[i + 2] > 0) break; // �Ż�һ
            if (x + nums[n - 2] + nums[n - 1] < 0) continue; // �Ż���
            int j = i + 1, k = n - 1;
            while (j < k) {
                int s = x + nums[j] + nums[k];
                if (s > 0) k--;
                else if (s < 0) j++;
                else {
                    ans.push_back({ x, nums[j], nums[k] });
                    for (j++; j < k && nums[j] == nums[j - 1]; j++);
                    for (k--; k > j && nums[k] == nums[k + 1]; k--);
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = { -1, 0, 1, 2, -1, -4 };
    Solution solution;
    vector<vector<int>> result = solution.threeSum(nums);
    for (const auto& triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}