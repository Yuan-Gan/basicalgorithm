
#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

using namespace std;
//暴力
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
    vector<int> nums = { 2, 2, 3, 4 };  // 这里可以自行修改测试的数组元素
    int result = solution.triangleNumber(nums);
    cout << "能组成三角形的三元组数量为: " << result << endl;
    return 0;
}