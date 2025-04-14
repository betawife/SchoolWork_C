#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>

using namespace std;
int high_precisionCalculation6(string num1,int num2) {
	int len = num1.length();
	vector<int> arr1(len, 0);

	for (int i = 0; i< len; i++) { //顺序插入，高位在前
		arr1[i] = num1[i] - '0';
	}
		
	for (int i = 0; i < len-1; i++) {
		if (arr1[i] / num2 > 0) {
			cout << arr1[i] / num2;
			arr1[i + 1] += (arr1[i] % num2) * 10;   //余数*10加到下一位
		}
		else {
			cout << 0;
			arr1[i + 1] += arr1[i] * 10;
		}
	}
	return arr1[len - 1];   //num1最后一位加完上一位余数后，没有处理，返回由低精度除法处理
}

void high_precisionCalculation5(int num1, int num2, int n) {   //低精度除法
	if (num1 == 0)
	{
		cout << "Division by zero error";
	}
	else {
		cout << num1 / num2;
		cout << ".";

		for (int i = 0; i < n; i++) {
			int temp = num1 % num2; //取余添0再除num2
			temp *= 10;
			cout << temp / num2;
			num1 = temp % num2;    //重新赋值被除数
		}
	}
}

int main() {
	string num1; int num2 = 0; int n = 0;
	cin >> num1;
	cin >> num2;
	cin >> n;
	high_precisionCalculation5( high_precisionCalculation6(num1, num2), num2, n);

	return 0;
}