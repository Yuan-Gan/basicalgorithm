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
            if (e)//����Ϊ0ʱ
                tmp[i++] = e;
            //else Ϊ0ʱ
        }
        for (int i = 0; i < n; i++)
        {
            nums[i] = tmp[i];
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