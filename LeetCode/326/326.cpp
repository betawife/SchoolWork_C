#include<stdlib.h>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {  //ʹ�õݹ飬3��n�����ص㣺1.��3������2.����/3�����һ����3/3=1��
        if (n == 0)return false;  //��һ��nδ��3
        if (n == 1)return true;   //���һ����3/3=1
        if (n % 3 != 0)return false;   //����3����
        return isPowerOfThree(n / 3);
    }
};