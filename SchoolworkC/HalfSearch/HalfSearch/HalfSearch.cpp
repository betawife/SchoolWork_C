#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 二分查找函数，返回查找长度
int binarySearch(const vector<int>& studentIDs, int K) {
    int left = 0, right = studentIDs.size() - 1;
    int searchLength = 0; // 查找长度

    while (left <= right) {
        searchLength++; // 每次进入循环增加一次查找长度
        int mid = left + (right - left) / 2; // 防止溢出

        if (studentIDs[mid] == K) {
            cout << "学号 " << K << " 找到，位置为: " << mid +1<< endl; //空间位置记得转为逻辑位置
            return searchLength;
        }
        if (studentIDs[mid] < K) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << "学号 " << K << " 未找到。" << endl;
    return searchLength;
}

int main() {
    // 假设班级30人的学号（已排序）
    vector<int> studentIDs = { 1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010,
                              1011, 1012, 1013, 1014, 1015, 1016, 1017, 1018, 1019, 1020,
                              1021, 1022, 1023, 1024, 1025, 1026, 1027, 1028, 1029, 1030 };

    // 输入要查找的学号
    int K;
    cout << "请输入要查找的学号: ";
    cin >> K;

    // 调用二分查找函数
    int searchLength = binarySearch(studentIDs, K);

    // 输出查找长度
    cout << "查找长度为: " << searchLength << endl;

    return 0;
}
