#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 遍历数组，cur用于标记下一个非零元素应该放置的位置
        for (int cur = -1, i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                // 先将cur自增，指向正确的放置位置，然后交换元素
                swap(nums[++cur], nums[i]);
            }
        }
    }
};



int main() {
    // 初始化一个测试用的数组
    vector<int> nums = { 0, 1, 0, 3, 12 };
    Solution solution;
    // 调用函数移动零元素
    solution.moveZeroes(nums);
    // 输出移动零元素后的数组
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}