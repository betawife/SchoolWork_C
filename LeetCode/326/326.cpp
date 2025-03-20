#include<stdlib.h>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {  //使用递归，3的n次幂特点：1.是3倍数；2.不断/3，最后一定是3/3=1；
        if (n == 0)return false;  //上一次n未够3
        if (n == 1)return true;   //最后一次是3/3=1
        if (n % 3 != 0)return false;   //不是3倍数
        return isPowerOfThree(n / 3);
    }
};