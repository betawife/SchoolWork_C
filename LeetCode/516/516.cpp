#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));   //二维数组dp[i][j]，用于记录s从i到j的最大回文子序列的长度， 初始化0

    for (int i = n - 1; i >= 0; --i) {
        dp[i][i] = 1;  //当i=j时，dp=1
        for (int j = i + 1; j < n; ++j) {  // i>j 时，子序列不成立，为默认值0
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;   //假设s中存在s[i]==s[j]；此时i,j可以添加到子序列s(i+1,j-1)两端,序列长度加2
            }
            else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);  //若s[i]!=s[j]; 此时子序列s(i,j)内缩一位：s(i+1,j) || s(i,j+1) ,dp[i][j]=max(内缩子序列dp)
            }
        }
    }

    return dp[0][n - 1];
}