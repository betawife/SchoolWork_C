#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>

using namespace std;
void High_precision(string num1, string num2) {
	int n = num1.length(), m = num2.length();
	int maxl = max(n, m);
	vector<int> arr1(maxl, 0), arr2(maxl, 0), arr3(maxl + 1, 0);      //�����鲹��ȳ�,��ֹ����ʱ��һ������Խ��

	for (int i = 0; i < n; i++) {     //Ϊ��֤��λ���룬���ַ�������д������
		arr1[i] = (num1[n - 1 - i] - '0');
	}
	for (int j = 0; j < m; j++) {
		arr2[j] = (num2[m - 1 - j] - '0');
	}

	for (int i = 0; i < maxl; i++) {
		arr3[i] = arr3[i] + arr1[i] + arr2[i];  //Ԥ�Ƚ�λ��+��λ��
		arr3[i + 1] = arr3[i] / 10;   //��λ(0��1)
		arr3[i] = arr3[i] % 10;       //��λ
	}

	if (arr3[maxl] != 0) maxl++;     //�жϽ�������Ƿ�ȼ�������һλ(����������Ƿ�Ϊ0)
	for (int i = maxl - 1; i >= 0; i--) { //�������
		cout << arr3[i];
	}
}

int main() {
	string num1, num2;
	cin >> num1; cin >> num2;
	High_precision(num1, num2);
}