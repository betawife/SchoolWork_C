#include<stdlib.h>
#include<vector>

using namespace std;

class Solution {
public:    
	int addDigits(int num) {
	vector<int> v;
	if (num / 10 == 0) return num;   //递归结束条件

	while (num != 0) {               //收集num各个位
		v.push_back(num % 10);
		num /= 10; 
	}
	int nnum = 0;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) 
	{nnum += *it;  }                //求和

	return addDigits(nnum);         //递归调用
    } 
};