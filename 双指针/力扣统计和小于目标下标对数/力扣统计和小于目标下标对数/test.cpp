#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

using namespace std;
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i = 0, j = nums.size() - 1;
        int ans = 0;
        while (i < j)
        {
            if (nums[i] + nums[j] < target)
            {
                ans += j - i;
                i++;
            }

            else j--;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int>& nums = *new vector<int>{ 1, 3, 2, 4, 0 };
    int target = 5;
    int result = solution.countPairs(nums, target);
    cout << "满足两数之和小于 " << target << " 的数对数量为: " << result << endl;
    return 0;
}