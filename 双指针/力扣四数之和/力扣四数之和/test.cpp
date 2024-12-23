#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> ret;
        int n = nums.size();
        //排序
        sort(nums.begin(), nums.end());
        //确定一个i
        for (int i = 0; i < n - 3; i++) {
            long long int x = nums[i];
            if (i && nums[i] == nums[i - 1]) continue;
            if (x + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if (x + nums[n - 1] + nums[n - 2] + nums[n - 3] < target) continue;
            //确定一个j
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                long long int y = nums[j]; 
                if (x + y + nums[j + 1] + nums[j + 2] > target) break;
                if (x + y + nums[n - 1] + nums[n - 2] < target) continue;
                int left = j + 1, right = n - 1;
                while (left < right) {
                    int s = x + y + nums[left] + nums[right];
                    if (s > target) right--;
                    else if (s < target) left++;
                    else {
                        ret.push_back({ (int)x, (int)y, nums[left], nums[right] });
                        for (left++; left < right && nums[left] == nums[left - 1]; left++);
                        for (right--; right > left && nums[right] == nums[right + 1]; right--);
                    }
                }
            }
        }
        return ret;
    }
};
int main() {
    vector<int> nums = { -2,-1,-1,1,1,2,2 };
    int target = 0;
    Solution solution;
    vector<vector<int>> result = solution.fourSum(nums, target);
    for (const auto& quadruplet : result) {
        for (int num : quadruplet) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}