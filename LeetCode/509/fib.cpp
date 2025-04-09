#include<stdlib.h>
#include<iostream>

using namespace std;
class Solution {
public:
	int fib(int n) {            //���Ӷ�O(n) 
	if (n == 0)return 0;		//F(0),F(1)
	if (n == 1)return 1;
	int pre = 0, cur = 1;       //��ʼ�����ڿ�ʼ����
	for (int i = 2; i <= n; i++) {
		int next = pre + cur;  //쳲�������
		pre = cur;      //ǰ��(��ǰ���ǰһ���һ�����ǰ��)
		cur = next;
	}
	return cur;
	}

	int fib2(int n) {          //���Ӷ�O(2^n) ,ʹ����쳲��������е�ԭ����: F(n)=F(n-1)+F(n-2);F(0)=0,F(1)=1;
		if (n == 0)return 0;
		if (n == 1)return 1;
		return fib2(n - 1) + fib(n - 2);
	}
};