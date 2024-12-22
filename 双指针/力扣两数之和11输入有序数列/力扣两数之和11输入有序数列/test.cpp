#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (true) {
            int s = numbers[left] + numbers[right];
            if (s > target) right--;
            else if (s < target) left++;
            else return { left + 1, right + 1 };  // 题目可能要求返回的索引是从1开始计数，所以这里加1
        }
    }
};

int main() {
    Solution solution;
    vector<int> numbers = { 2, 7, 11, 15 };  // 可以自行修改这个测试数组
    int target = 9;  // 同样可以修改目标值
    vector<int> result = solution.twoSum(numbers, target);
    cout << "满足两数之和等于目标值的两个数的索引为: (" << result[0] << ", " << result[1] << ")" << endl;
    return 0;
}