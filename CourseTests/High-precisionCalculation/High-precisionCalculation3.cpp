#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>

using namespace std;
void High_precision3(string num1, int num2) {                    //�߾����� �� �;��������߾��ȵ�ÿλ�����Ե;��ȣ������ν�λ
	int n = num1.length(); int num2f = num2; int m = 0;
	while (num2f != 0) {
		num2f /= 10;
		m++;
	}
	vector<int> arr1(n, 0), arr3(n + 10, 0);            //arr3Ԥ���㹻�ռ�

	for (int i = 0; i < n; i++) {     //�������
		arr1[i] = num1[n - 1 - i] - '0';
	}
	// ִ�г˷�����
	for (int i = 0; i < n; i++) {
		arr3[i] += arr1[i] * num2;  // Ԥ�Ƚ�λ+�߾�*�;�
		if (arr3[i] >= 10) {        // �����λ
			arr3[i + 1] += arr3[i] / 10;
			arr3[i] %= 10;
		}
	}

	// ����ʣ��Ľ�λ(��Ϊ��һ��ѭ��ֻ���е�n-1,arr3[n]û�н�λ��λ����)
	int carry_pos = n;
	while (arr3[carry_pos] >= 10) {
		arr3[carry_pos + 1] += arr3[carry_pos] / 10;
		arr3[carry_pos] %= 10;
		carry_pos++;
	}


	int index = n + 9;
	while (arr3[index] == 0)index--;

	for (int i = index; i >= 0; i--) {
		cout << arr3[i];
	}
}

int main() {
	string num1; int num2;
	cin >> num1; cin >> num2;
	High_precision3(num1, num2);
}