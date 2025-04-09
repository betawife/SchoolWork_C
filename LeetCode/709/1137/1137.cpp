#include<stdlib.h>

using namespace std;
int tribonacci(int n) { 
	if (n == 0)return 0;
	if (n == 1 || n == 2)return 1;
	
	int ppre = 0, pre = 1, cur = 1;
	for (int i = 3; i <= n; i++) { 
		int next = ppre + pre + cur;
		ppre = pre;
		pre = cur;
		cur = next;
	}        
	return cur; 
}