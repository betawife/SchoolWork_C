#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));   //��ά����dp[i][j]�����ڼ�¼s��i��j�������������еĳ��ȣ� ��ʼ��0

    for (int i = n - 1; i >= 0; --i) {
        dp[i][i] = 1;  //��i=jʱ��dp=1
        for (int j = i + 1; j < n; ++j) {  // i>j ʱ�������в�������ΪĬ��ֵ0
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;   //����s�д���s[i]==s[j]����ʱi,j������ӵ�������s(i+1,j-1)����,���г��ȼ�2
            }
            else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);  //��s[i]!=s[j]; ��ʱ������s(i,j)����һλ��s(i+1,j) || s(i,j+1) ,dp[i][j]=max(����������dp)
            }
        }
    }

    return dp[0][n - 1];
}