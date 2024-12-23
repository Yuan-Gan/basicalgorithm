#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int>tmp(n);
        for (auto e : nums)
        {
            int i = 0;
            if (e)//当不为0时
                tmp[i++] = e;
            //else 为0时
        }
        for (int i = 0; i < n; i++)
        {
            nums[i] = tmp[i];
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