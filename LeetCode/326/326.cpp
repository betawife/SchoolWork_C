#include<stdlib.h>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {  //使用递归，3的n次幂特点：能一直被3整除
        if (n == 0)return false;  //上一次返回false，未被3整除
        if (n == 1)return true;   //上一次返回true，被3整除
        if (n % 3 != 0)return false;   //不是3倍数,返回false(0)
        return isPowerOfThree(n / 3);
    }
};