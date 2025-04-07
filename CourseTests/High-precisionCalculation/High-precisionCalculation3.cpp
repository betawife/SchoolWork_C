#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>

using namespace std;
void High_precision3(string num1, int num2) {                    //高精度数 乘 低精度数：高精度的每位都乘以低精度，再依次进位
	int n = num1.length(); int num2f = num2; int m = 0;
	while (num2f != 0) {
		num2f /= 10;
		m++;
	}
	vector<int> arr1(n, 0), arr3(n + 10, 0);            //arr3预留足够空间

	for (int i = 0; i < n; i++) {     //逆序存入
		arr1[i] = num1[n - 1 - i] - '0';
	}
	// 执行乘法运算
	for (int i = 0; i < n; i++) {
		arr3[i] += arr1[i] * num2;  // 预先进位+高精*低精
		if (arr3[i] >= 10) {        // 处理进位
			arr3[i + 1] += arr3[i] / 10;
			arr3[i] %= 10;
		}
	}

	// 处理剩余的进位(因为上一个循环只进行到n-1,arr3[n]没有进位留位操作)
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