#include<stdlib.h>
#include<iostream>

using namespace std;
void high_precisionCalculation5(int num1,int num2,int n) {
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
	int num1, num2 = 0; int n = 0;
	cin >> num1;
	cin >> num2;
	cin>>n;
	high_precisionCalculation5(num1, num2, n);

	return 0;
}