#include<stdlib.h>
#include<vector>
#include<string.h>
#include<string>
#include<iostream>

using namespace std;
void copys(vector<int> c1, int c2[], int offset) {    //ƫ�ƿ���
	for (int i = 1; i <= c1[0]; i++) {
		c2[i + offset] = c1[i];
	}
	c2[0] = c1[0] + offset;//ͬʱ����Чλ����
}

bool compare(vector<int> c1, int c2[]) {               //�жϽ�����temp��С
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

void sub(vector<int> c1, int c2[]) {                   //���
	for (int i = c1[0]; i >= 1; i--) {
		if (c1[i] < c2[i]) {
			c1[i] += 10;
			c1[i - 1] -= 1;
		}
		c1[i] -= c2[i];
	}
}
void high_precisionCalculation7(string num1, string num2) {   //����Ҳ���Կ����Ǳ�������μ�����
	int n = num1.length();
	int m = num2.length();
	vector<int>arr1(n + 1); vector<int>arr2(m + 1);
	vector<int>arr3(n + m, 0);
	arr1[0] = n; arr2[0] = m;  //arr����λ�����Чλ��

	for (int i = 1; i <= arr1[0]; i++) {
		arr1[i] = num1[i - 1] - '0';
	}
	for (int i = 1; i <= arr2[0]; i++) {
		arr2[i] = num2[i - 1] - '0';
	}

	arr3[0] = arr1[0] - arr2[0] + 1;
	int temp[500] = { 0 };
	for (int i = 1; i <= arr3[0]; i++) {
		memset(temp, 0, sizeof(temp));//��ʱ��������
		copys(arr2, temp, i - 1); //��ƫ�Ƴ�����������temp
		arr1[0] = temp[0];  //ͨ����Чλ����ȡ������һ������Ϊ����

		while (compare(arr1, temp) == true) {
			sub(arr1, temp);//�������ϼ�ȥtemp
			arr3[i]++;   //��������λ���Ǽ����Ĵ���
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