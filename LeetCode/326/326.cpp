#include<stdlib.h>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {  //3^n特点：能一直被3整除至1
        if (n == 0)return false;  //用于最后一次判断 ，传参  n/3=0
        if (n == 1)return true;   //用于最后一次判断 ，传参  n/3=1
        if (n % 3 != 0)return false;   //判断每次传入的n是否可以被整除
        return isPowerOfThree(n / 3);  //递归调用，传值n/3
    }
};