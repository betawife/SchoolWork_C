#include<stdlib.h>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

void High_precisionCalculation4(string num1,string num2) {
	int n = num1.length();
	int m = num2.length();
	vector<int> arr1(n), arr2(m), arr3(n+m);

	for (int i = 0; i < n; i++) {
		arr1[i] = num1[n - 1 - i] - '0';
	}
	for (int i = 0; i < m; i++) {
		arr2[i] = num2[m - 1 - i] - '0';
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//�������ÿλҪ��ƫ��iλ��������һ�εĽ�������λ���(��һ��ƫ����Ϊ��ȷ����λ��ȷ���ڶ���ƫ����Ϊ�˴�λ)
			arr3[j + i] = arr3[j+i] + arr1[i] * arr2[j];     //�ôν��= ��һ�ν��+���
			if (arr3[j + i] >= 10) {
				arr3[j + i + 1] += arr3[j + i] / 10;
				arr3[j + i] %= 10;
			}
		}
	}

	// ����ʣ��Ľ�λ(��Ϊ��һ��ѭ��ֻ���е�n-1,arr3[n]֮��û�н�λ��λ����)
	for (int i = n; i < n + m; i++) {
		if (arr3[i] >= 10) {
			arr3[i + 1] += arr3[i] / 10;
			arr3[i] %= 10;
		}
	}

	int index = 0;
	for (int i = arr3.size()-1; i >= 0; i--) {
		if (arr3[i] != 0) { index = i; break; }
	}

	for (int i = index; i >= 0; i--) {
		cout << arr3[i];
	}
}

int main() {
	string num1; string num2;
	cin >> num1; cin >> num2;
	High_precisionCalculation4(num1, num2);
}