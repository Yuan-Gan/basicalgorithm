#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k)
    {
        int len = 0;
        for (int right = 0, zero = 0, left = 0; right < nums.size(); right++)
        {
            if (nums[right] == 0) zero++;
            while (zero > k) if (nums[left++] == 0) zero--;
            len = max(len, right - left + 1);
        }
        return len;
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0 };
    int k = 2;
    int result = solution.longestOnes(nums, k);
    cout << "�������滻 " << k << " ��0������£�����1��������鳤��Ϊ: " << result << endl;
    return 0;
}