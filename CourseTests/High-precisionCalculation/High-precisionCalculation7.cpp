#include<stdlib.h>
#include<vector>
#include<string.h>
#include<string>
#include<iostream>

using namespace std;
void copys(vector<int> c1, int c2[], int offset) {    //偏移拷贝
	for (int i = 1; i <= c1[0]; i++) {
		c2[i + offset] = c1[i];
	}
	c2[0] = c1[0] + offset;//同时将有效位更新
}

bool compare(vector<int> c1, int c2[]) {               //判断截数与temp大小
	if (c1.size() > c2[0])return true;
	else if (c1.size() < c2[0])return false;
	else {
		for (int i = 1; i <= c1.size(); i++) {
			if (c1[i] > c2[i])return true;
			if (c1[i] < c2[i])return false;
		}
	}
	return true;
}

void sub(vector<int> c1, int c2[]) {                   //相减
	for (int i = c1[0]; i >= 1; i--) {
		if (c1[i] < c2[i]) {
			c1[i] += 10;
			c1[i - 1] -= 1;
		}
		c1[i] -= c2[i];
	}
}
void high_precisionCalculation7(string num1, string num2) {   //除法也可以看作是被除数多次减除数
	int n = num1.length();
	int m = num2.length();
	vector<int>arr1(n + 1); vector<int>arr2(m + 1);
	vector<int>arr3(n + m, 0);
	arr1[0] = n; arr2[0] = m;  //arr的首位存放有效位数

	for (int i = 1; i <= arr1[0]; i++) {
		arr1[i] = num1[i - 1] - '0';
	}
	for (int i = 1; i <= arr2[0]; i++) {
		arr2[i] = num2[i - 1] - '0';
	}

	arr3[0] = arr1[0] - arr2[0] + 1;
	int temp[500] = { 0 };
	for (int i = 1; i <= arr3[0]; i++) {
		memset(temp, 0, sizeof(temp));//临时数组置零
		copys(arr2, temp, i - 1); //右偏移除数并拷贝至temp
		arr1[0] = temp[0];  //通过有效位来截取除数的一部分作为截数

		while (compare(arr1, temp) == true) {
			sub(arr1, temp);//截数不断减去temp
			arr3[i]++;   //结果数组该位就是减法的次数
		}
	}
	int index = 0;
	for (int i = 1; i <= arr3[0]; i++) {
		if (arr3[i] != 0) {
			index = i;
		}
	}
	for (int i = index; i <= arr3[0]; i++) {
		cout << arr3[i];
	}
}

int main() {
	string num1, num2;
	cin >> num1;
	cin >> num2;
	high_precisionCalculation7(num1, num2);
	return 0;
}