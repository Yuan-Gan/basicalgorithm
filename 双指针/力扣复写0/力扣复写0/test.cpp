#include<iostream>
#include<vector>
using namespace std;
//class Solution {
//public:
//    void duplicateZeros(vector<int>& arr) {
//        int originalSize = arr.size();
//        for (int i = 0; i < arr.size(); i++) {
//            if (arr[i] == 0) {
//                arr.insert(arr.begin() + i, 0);
//                i++;
//            }
//            while (arr.size() > originalSize) arr.pop_back();
//        }
//    }
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        //先找到下标
        int cur = 0, dest = -1;
        while (dest < n - 1)
        {
            if (arr[cur])
            {
                dest++;
                if (dest < n - 1)
                    cur++;
            }
            else
            {
                dest += 2;
                if (dest < n - 1)
                    cur++;
            }
        }
        //处理特殊情况
        if (dest == n)
        {
            arr[n - 1] = 0;
            dest -= 2;
            cur--;
        }
        //进行复写操作
        while (dest >= 0)
        {
            if (arr[cur] == 0)
            {
                arr[dest--] = arr[cur];
                if (dest >= 0)
                    arr[dest--] = arr[cur--];
            }
            else  arr[dest--] = arr[cur--];
        }
    }
};

int main() {
    vector<int> arr = { 8,4,5,0,0,0,0,7 };
    Solution solution;
    solution.duplicateZeros(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

