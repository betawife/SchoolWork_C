#include<stdlib.h>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {  //ʹ�õݹ飬3��n�����ص㣺��һֱ��3����
        if (n == 0)return false;  //��һ�η���false��δ��3����
        if (n == 1)return true;   //��һ�η���true����3����
        if (n % 3 != 0)return false;   //����3����,����false(0)
        return isPowerOfThree(n / 3);
    }
};