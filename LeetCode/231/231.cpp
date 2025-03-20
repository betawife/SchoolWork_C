#include<stdlib.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        for (int i = 0; i < 32; i++) {   //int 型取值范围在-2^32 ~2^32之间，这里是整数n，故次幂在0~31
            if (1 << i == n) {      //1左移i位即=1*2^i
                return true;
            }
            if (1 << i > n) return false;//超出n
        }
        return false;
    }
};