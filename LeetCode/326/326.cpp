#include<stdlib.h>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {  //3^n�ص㣺��һֱ��3������1
        if (n == 0)return false;  //�������һ���ж� ������  n/3=0
        if (n == 1)return true;   //�������һ���ж� ������  n/3=1
        if (n % 3 != 0)return false;   //�ж�ÿ�δ����n�Ƿ���Ա�����
        return isPowerOfThree(n / 3);  //�ݹ���ã���ֵn/3
    }
};