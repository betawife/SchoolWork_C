#include<stdlib.h>
#include<iostream>

using namespace std;
class Solution {
public:
	int fib(int n) {            //复杂度O(n) 
	if (n == 0)return 0;		//F(0),F(1)
	if (n == 1)return 1;
	int pre = 0, cur = 1;       //起始索引在开始两项
	for (int i = 2; i <= n; i++) {
		int next = pre + cur;  //斐波那契数
		pre = cur;      //前进(当前项赋给前一项，下一项赋给当前项)
		cur = next;
	}
	return cur;
	}

	int fib2(int n) {          //复杂度O(2^n) ,使用了斐波那契数列的原概念: F(n)=F(n-1)+F(n-2);F(0)=0,F(1)=1;
		if (n == 0)return 0;
		if (n == 1)return 1;
		return fib2(n - 1) + fib(n - 2);
	}
};