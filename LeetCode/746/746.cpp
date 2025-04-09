#include<stdlib.h>
#include<vector>

using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);      //����dp,dp[i]������¼��iλ���ﶥ�˵����ٻ���
        dp[n - 1] = cost[n - 1];     //�������(��������)
        dp[n - 2] = cost[n - 2];
        for (int i = n - 3; i >= 0; i--) {      //ѭ������ͽ�
            dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);   //��ǰ��ͻ���=�ý׻���+ min��dp��һ�ף�dp�����ף�
        }
        return min(dp[0], dp[1]);   //0ʼ��1ʼѡ���С��
    } 
};