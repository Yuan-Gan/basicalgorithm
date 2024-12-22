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
//};
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        // �ҵ��±�
        int dest = -1, cur = 0, n = arr.size();
        while (cur < n) {
            if (arr[cur]) {
                dest++;
            }
            else {
                dest += 2;
            }
            if (dest >= n - 1) break;
            cur++;
        }

        // ����߽����
        if (dest == n) {
            arr[n - 1] = 0;
            cur--;
            dest -= 2;
        }

        // ����Ԫ�ظ��ƣ�ʵ��0Ԫ���ظ�����
        while (cur >= 0) {
            if (arr[cur]) {
                arr[dest--] = arr[cur--];
            }
            else {
                arr[dest--] = 0;
                arr[dest--] = 0;
                cur--;
            }
        }
    }
};

int main() {
    vector<int> arr = { 1, 0, 2, 3, 0, 4 };
    Solution solution;
    solution.duplicateZeros(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}