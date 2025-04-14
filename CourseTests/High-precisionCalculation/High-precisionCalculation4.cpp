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
			//第i+1次外循环，结果数组每位要右偏移i位，再存储 上一次的结果数组的对应位+相乘
			arr3[j + i] = arr3[j+i] + arr1[i] * arr2[j];     //该次结果该位 先偏移 = 上一次结果对应位+相乘
			if (arr3[j + i] >= 10) {	//及时处理进位
				arr3[j + i + 1] += arr3[j + i] / 10;
				arr3[j + i] %= 10;
			}
		}
	}

	// 处理剩余的进位(因为上一个循环只进行到n-1,arr3[n]之后没有进位留位操作)    ！！！
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