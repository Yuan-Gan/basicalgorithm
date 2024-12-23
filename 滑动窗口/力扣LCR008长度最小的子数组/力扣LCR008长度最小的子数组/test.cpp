#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//class Solution {
//public:
//    int minSubArrayLen(int target, vector<int>& nums) {
//        int sum = 0, n = nums.size(), left = 0;
//        int ans = n + 1;
//        for (int right = 0; right < n;right++)
//        {
//            
//            sum += nums[right];
//            while (sum - nums[left] >= target)
//            {
//                sum -= nums[left++];
//            }
//            if (sum >= target) {
//                ans = min(ans, right - left + 1);
//            }
//        }
//        return ans <= n ? ans : 0;
//    }
//};
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), ret = n + 1, sum = 0;
        for (int left = 0, right = 0; right < n; right++)
        {
            sum += nums[right];//������
            while (sum >= target)//�ж�
            {
                ret = min(ret, right - left + 1);//���½��
                sum -= nums[left++];//������
            }

        }
        return ret == n + 1 ? 0 : ret;
    }
};
int main() {
    Solution solution;
    vector<int> nums = { 2, 3, 1, 2, 4, 3 };
    int target = 7;
    int result = solution.minSubArrayLen(target, nums);
    cout << "��������鳤��Ϊ: " << result << endl;
    return 0;
}