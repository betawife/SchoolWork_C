#include<stdlib.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        for (int i = 0; i < 32; i++) {   //int ��ȡֵ��Χ��-2^32 ~2^32֮�䣬����������n���ʴ�����0~31
            if (1 << i == n) {      //1����iλ��=1*2^i
                return true;
            }
            if (1 << i > n) return false;//����n
        }
        return false;
    }
};