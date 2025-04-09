#include<stdlib.h>
#include<vector>

using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) { return nums[0]; }                   //�������
        if (n == 2) { return max(nums[0], nums[1]); }
        if (n >= 3) {
            vector<int> mm(n);  //����mm,mm[i]��ţ���ٵ��û�ʱ�����
            mm[0] = nums[0];
            mm[1] = max(nums[0], nums[1]);
            for (int i = 2; i < n; i++) { mm[i] = max(mm[i - 1], mm[i - 2] + nums[i]); }   //����λʱ�����= max(mm��һλ��mm����һλ+�û����)
            return mm[n - 1];
        }
        return 0;
    }
};