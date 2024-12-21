#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if (numbers.empty()) {  // ������������Ƿ�Ϊ�գ�Ϊ���򷵻ؿ�����
            return {};
        }
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {  // �����ѭ����ֹ��������֤����Խ���ұ������п������
            int sum = numbers[left] + numbers[right];
            if (sum > target) {
                right--;
            }
            else if (sum < target) {
                left++;
            }
            else {
                return { left + 1, right + 1 };  // ���������������������������е��±꣨��1��ʼ������
            }
        }
        return {};  // ���������δ�ҵ�������������ϣ����ؿ�����
    }
};

int main() {
    Solution solution;
    vector<int> numbers = { 2, 7, 11, 15 };  // ʾ����������
    int target = 9;  // ʾ��Ŀ��ֵ
    vector<int> result = solution.twoSum(numbers, target);
    if (result.size() == 2) {  // �ж��Ƿ��ҵ����
        cout << "�ҵ��������������������±�ֱ�Ϊ��" << result[0] << " �� " << result[1] << endl;
    }
    else {
        cout << "δ�ҵ�������������������" << endl;
    }
    return 0;
}