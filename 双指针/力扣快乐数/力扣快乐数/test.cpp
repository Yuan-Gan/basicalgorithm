#include <iostream>
#include <cmath>
#include <unordered_set>
using namespace std;
//class Solution {
//public:
//    bool isHappy(int n) {
//        unordered_set<int> appeared;
//        while (true)
//        {
//            int sum = 0;
//            while (n)
//            {
//                sum += pow(n % 10, 2);
//                n /= 10;
//            }
//            if (sum == 1) return true;
//            if (appeared.find(sum) != appeared.end()) return false;
//            appeared.insert(sum);
//            n = sum;
//        }
//
//    }
//};
#include <iostream>
using namespace std;

class Solution {
public:
    int get_pow_bit(int n) {
        int sum = 0;
        while (n) {
            int bit = n % 10;
            sum += bit * bit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = get_pow_bit(n);
        while (slow != fast) {
            slow = get_pow_bit(slow);
            fast = get_pow_bit(get_pow_bit(fast));
        }
        return slow == 1;
    }
};

int main() {
    Solution solution;
    int num;
    cout << "请输入一个整数: ";
    cin >> num;
    bool result = solution.isHappy(num);
    if (result) {
        cout << num << " 是快乐数" << endl;
    }
    else {
        cout << num << " 不是快乐数" << endl;
    }
    return 0;
}