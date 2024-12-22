#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // �������飬cur���ڱ����һ������Ԫ��Ӧ�÷��õ�λ��
        for (int cur = -1, i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                // �Ƚ�cur������ָ����ȷ�ķ���λ�ã�Ȼ�󽻻�Ԫ��
                swap(nums[++cur], nums[i]);
            }
        }
    }
};



int main() {
    // ��ʼ��һ�������õ�����
    vector<int> nums = { 0, 1, 0, 3, 12 };
    Solution solution;
    // ���ú����ƶ���Ԫ��
    solution.moveZeroes(nums);
    // ����ƶ���Ԫ�غ������
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}