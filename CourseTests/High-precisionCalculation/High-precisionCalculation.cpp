#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>

using namespace std;
void High_precision(string num1, string num2) {
	int n = num1.length(), m = num2.length();
	int maxl = max(n, m);
	vector<int> arr1(maxl, 0), arr2(maxl, 0), arr3(maxl + 1, 0);      //两数组补零等长,防止计算时有一者索引越界

	for (int i = 0; i < n; i++) {     //为保证右位对齐，将字符数逆序写入数组
		arr1[i] = (num1[n - 1 - i] - '0');
	}
	for (int j = 0; j < m; j++) {
		arr2[j] = (num2[m - 1 - j] - '0');
	}

	for (int i = 0; i < maxl; i++) {
		arr3[i] = arr3[i] + arr1[i] + arr2[i];  //预先进位数+现位和
		arr3[i + 1] = arr3[i] / 10;   //进位(0或1)
		arr3[i] = arr3[i] % 10;       //留位
	}

	if (arr3[maxl] != 0) maxl++;     //判断结果数组是否比加数多了一位(最大索引处是否为0)
	for (int i = maxl - 1; i >= 0; i--) { //逆序输出
		cout << arr3[i];
	}
}

int main() {
	string num1, num2;
	cin >> num1; cin >> num2;
	High_precision(num1, num2);
}