#include<stdlib.h>
#include<vector>

using namespace std;

class Solution {
public:    
	int addDigits(int num) {
	vector<int> v;
	if (num / 10 == 0) return num;   //�ݹ��������

	while (num != 0) {               //�ռ�num����λ
		v.push_back(num % 10);
		num /= 10; 
	}
	int nnum = 0;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) 
	{nnum += *it;  }                //���

	return addDigits(nnum);         //�ݹ����
    } 
};