
#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

using namespace std;
//����
//
//class Solution {
//public:
//
//    int triangleNumber(vector<int>& nums)
//    {
//        ranges::sort(nums);
//        int ret = 0;
//        int n = nums.size();
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = i + 1; j < n; j++)
//            {
//                for (int k = j + 1; k < n; k++)
//                    if (nums[i] + nums[j] > nums[k]) ret++;
//            }
//        }
//        return ret;
//    }
//};
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ret = 0;
        int n = nums.size();
        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    ret += j - i;
                    j--;
                }
                else
                    i++;
            }
        }

        return ret;
    }
};


int main()
{
    Solution solution;
    vector<int> nums = { 2, 2, 3, 4 };  // ������������޸Ĳ��Ե�����Ԫ��
    int result = solution.triangleNumber(nums);
    cout << "����������ε���Ԫ������Ϊ: " << result << endl;
    return 0;
}