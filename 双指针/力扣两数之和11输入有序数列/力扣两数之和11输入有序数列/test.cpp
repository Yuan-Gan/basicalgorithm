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
            else return { left + 1, right + 1 };  // ��Ŀ����Ҫ�󷵻ص������Ǵ�1��ʼ���������������1
        }
    }
};

int main() {
    Solution solution;
    vector<int> numbers = { 2, 7, 11, 15 };  // ���������޸������������
    int target = 9;  // ͬ�������޸�Ŀ��ֵ
    vector<int> result = solution.twoSum(numbers, target);
    cout << "��������֮�͵���Ŀ��ֵ��������������Ϊ: (" << result[0] << ", " << result[1] << ")" << endl;
    return 0;
}