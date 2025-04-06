#include <iostream>
#include <string>
#include <vector>

using namespace std;

void High_precision2(string num1, string num2) {
    // 去除前导零
    num1.erase(0, min(num1.find_first_not_of('0'), num1.size() - 1));
    num2.erase(0, min(num2.find_first_not_of('0'), num2.size() - 1));

    // 处理字符串为空/零情况
    if (num1.empty()) num1 = "0";
    if (num2.empty()) num2 = "0";

    int n = num1.length(), m = num2.length();
    char flag = '+';

    // 判断大小并决定是否交换
    if (n < m || (n == m && num1 < num2)) {
        flag = '-';
        swap(num1, num2);
        swap(n, m);
    }

    vector<int> arr1(n, 0), arr2(n, 0), arr3(n, 0);  // 两个数组补零等长，防止计算时有一者越界

    // 逆序存储数字
    for (int i = 0; i < n; i++) {
        arr1[i] = num1[n - 1 - i] - '0';
    }
    for (int i = 0; i < m; i++) {
        arr2[i] = num2[m - 1 - i] - '0';
    }

    // 高精度减法
    for (int i = 0; i < n; i++) {
        if (arr1[i] < arr2[i]) {
            arr1[i] += 10;
            arr1[i + 1]--;          //借位
        }
        arr3[i] = arr1[i] - arr2[i];
    }

    // 查找最高有效位（从最高位向低位找第一个非零）
    int index = n - 1;
    while (index >= 0 && arr3[index] == 0) {
        index--;
    }

    // 输出结果
    if (index < 0) {  // 说明结果是 0
        cout << "0";
    }
    else {
        if (flag == '-') cout << '-';
        for (int i = index; i >= 0; i--) {
            cout << arr3[i];
        }
    }
}

int main() {
    string num1, num2;
    cin >> num1 >> num2;
    High_precision2(num1, num2);
    return 0;
}