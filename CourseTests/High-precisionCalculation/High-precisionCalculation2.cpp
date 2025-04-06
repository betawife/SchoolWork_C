#include <iostream>
#include <string>
#include <vector>

using namespace std;

void High_precision2(string num1, string num2) {
    // ȥ��ǰ����
    num1.erase(0, min(num1.find_first_not_of('0'), num1.size() - 1));
    num2.erase(0, min(num2.find_first_not_of('0'), num2.size() - 1));

    // �����ַ���Ϊ��/�����
    if (num1.empty()) num1 = "0";
    if (num2.empty()) num2 = "0";

    int n = num1.length(), m = num2.length();
    char flag = '+';

    // �жϴ�С�������Ƿ񽻻�
    if (n < m || (n == m && num1 < num2)) {
        flag = '-';
        swap(num1, num2);
        swap(n, m);
    }

    vector<int> arr1(n, 0), arr2(n, 0), arr3(n, 0);  // �������鲹��ȳ�����ֹ����ʱ��һ��Խ��

    // ����洢����
    for (int i = 0; i < n; i++) {
        arr1[i] = num1[n - 1 - i] - '0';
    }
    for (int i = 0; i < m; i++) {
        arr2[i] = num2[m - 1 - i] - '0';
    }

    // �߾��ȼ���
    for (int i = 0; i < n; i++) {
        if (arr1[i] < arr2[i]) {
            arr1[i] += 10;
            arr1[i + 1]--;          //��λ
        }
        arr3[i] = arr1[i] - arr2[i];
    }

    // ���������Чλ�������λ���λ�ҵ�һ�����㣩
    int index = n - 1;
    while (index >= 0 && arr3[index] == 0) {
        index--;
    }

    // ������
    if (index < 0) {  // ˵������� 0
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