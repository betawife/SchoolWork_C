#include<stdlib.h>
#include<vector>

using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m, 0)); //二维数组dp,用来存储该位到(n-1,m-1)的所有路径数
                                                   //观察特殊位置，如最右下角的四个格子dp[n-2][m-2]=dp[n-1][m-2]+dp[n-2][m-1]，得规律：非边缘dp[i][j]=dp[i+1][j]+dp[i][j+1]
        // 处理边界dp,路径数都是1
        for (int i = 0; i < n; i++) {
            dp[i][m - 1] = 1;
        }
        for (int j = 0; j < m; j++) {
            dp[n - 1][j] = 1;
        }

        // 递减遍历赋值dp(矩阵会越来越小，防止撞到边界/数组越界)  ！！！
        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }

        return dp[0][0];
    }
};

class Solution02 {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m, 1));          //初始赋值都为1，不用再为边界赋值

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];       //逆向思维，从(该位)终点到左上角起点
            }
        }

        return dp[n - 1][m - 1];
    }
};