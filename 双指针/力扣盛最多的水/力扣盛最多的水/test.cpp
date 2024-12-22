#include <iostream>
#include <vector>
#include <algorithm> // ����max��min�������ڵ�ͷ�ļ�

using namespace std;

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int n = height.size(), left = 0, right = n - 1, ret = 0;
        while (left <= right)
        {
            int v = (right - left) * min(height[left], height[right]);
            ret = max(ret, v);
            if (height[right] < height[left])
                right--;
            else
                left++;
        }
        return ret;
    }
};

int main()
{
    Solution solution;
    vector<int> heights = { 1, 8, 6, 2, 5, 4, 8, 3, 7 }; // ��������Զ��������߶����飬ʾ����������һ������
    int result = solution.maxArea(heights);
    cout << "�����ɵ����ˮ���Ϊ: " << result << endl;
    return 0;
}