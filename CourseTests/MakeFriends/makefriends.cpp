#include<stdlib.h>
#include<iostream>

using namespace std;

int solve() {
	int count = 0;
	for (int i = 0; i < 50; i++)        //主握手人
	{
		for (int j = i + 1; j < 50; j++) {   //被握手人，会不断减少
			if (i<=42)count++;    //最后七人，和前面的握过了，同时也不能和后面人握，所以不再计数
		}
	}
	return count;
}

int main() {
	cout << solve() << endl;
	return 0;
}