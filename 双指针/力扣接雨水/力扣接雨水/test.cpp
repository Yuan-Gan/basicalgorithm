#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int left = 0, right = n - 1;
        int max_left = 0, max_right = 0;
        while (left <= right) {
            // ����������߶�
            max_left = max(max_left, height[left]);
            // �����ұ����߶�
            max_right = max(max_right, height[right]);
            // ���������������߶Ƚ�Сֵ�����㵱ǰλ�ÿɽ�ס����ˮ�����ۼӵ�ans��
            ans += max_left < max_right ? max_left - height[left++] : max_right - height[right--];
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    int result = solution.trap(height);
    cout << "�������ܽ�ס����ˮ��Ϊ: " << result << endl;
    return 0;
}