#include<stdlib.h>
#include<vector>

using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) { return nums[0]; }                   //特殊情况
        if (n == 2) { return max(nums[0], nums[1]); }
        if (n >= 3) {
            vector<int> mm(n);  //数组mm,mm[i]存放：打劫到该户时最大金额
            mm[0] = nums[0];
            mm[1] = max(nums[0], nums[1]);
            for (int i = 2; i < n; i++) { mm[i] = max(mm[i - 1], mm[i - 2] + nums[i]); }   //到该位时最大金额= max(mm上一位，mm上上一位+该户金额)
            return mm[n - 1];
        }
        return 0;
    }
};