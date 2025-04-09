#include<stdlib.h>
#include<vector>

using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);      //数组dp,dp[i]用来记录第i位到达顶端的最少花费
        dp[n - 1] = cost[n - 1];     //特殊情况(基底条件)
        dp[n - 2] = cost[n - 2];
        for (int i = n - 3; i >= 0; i--) {      //循环到最低阶
            dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);   //当前最低花费=该阶花费+ min（dp高一阶，dp高两阶）
        }
        return min(dp[0], dp[1]);   //0始或1始选择更小者
    } 
};