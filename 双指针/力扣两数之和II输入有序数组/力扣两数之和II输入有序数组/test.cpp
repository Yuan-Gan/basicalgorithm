#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if (numbers.empty()) {  // 检查输入数组是否为空，为空则返回空向量
            return {};
        }
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {  // 合理的循环终止条件，保证不会越界且遍历所有可能组合
            int sum = numbers[left] + numbers[right];
            if (sum > target) {
                right--;
            }
            else if (sum < target) {
                left++;
            }
            else {
                return { left + 1, right + 1 };  // 返回满足条件的两个数在数组中的下标（从1开始计数）
            }
        }
        return {};  // 如果遍历完未找到满足条件的组合，返回空向量
    }
};

int main() {
    Solution solution;
    vector<int> numbers = { 2, 7, 11, 15 };  // 示例有序数组
    int target = 9;  // 示例目标值
    vector<int> result = solution.twoSum(numbers, target);
    if (result.size() == 2) {  // 判断是否找到结果
        cout << "找到满足条件的两个数，下标分别为：" << result[0] << " 和 " << result[1] << endl;
    }
    else {
        cout << "未找到满足条件的两个数。" << endl;
    }
    return 0;
}