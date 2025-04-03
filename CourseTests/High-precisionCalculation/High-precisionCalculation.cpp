#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>

using namespace std;
void High_precision(string num1,string num2) {
	int n = num1.length(), m = num2.length();
	vector<int> arr1(n), arr2(m), arr3(max(n,m)+1,0);      //结果数组要预先存零并指定大小，方便进位

	for (int i = 0, j = 0; i < n && j < m; i++, j++) {     //为保证右位对齐，将字符数逆序写入数组
		arr1[i] = (num1[n - i - 1] - '0');
		arr2[j] = (num2[m - j - 1] - '0');
	}

	int len = arr1.size();
	if (arr1.size() < arr2.size())len = arr2.size();

	for (int i = 0; i < len; i++) {
		arr3[i] =arr3[i]+ arr1[i] + arr2[i];  //预先进位数+现位和
		arr3[i + 1] = arr3[i] / 10;   //进位
		arr3[i] = arr3[i] % 10;       //留位
	}

	if (arr3[len] != 0)len++;     //判断结果数组是否比加数多了一位
	for (int i = len - 1; i >= 0; i--) { //逆序输出
		cout << arr3[i];
	}
}

int main() {
	string num1, num2;
	cin >> num1; cin >> num2;
	High_precision(num1, num2);
}