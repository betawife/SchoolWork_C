#include<stdlib.h>
#include<vector>

using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0)); //�������ÿ��λ����Ϊ�������½�ʱ�����߳�
        int MAXborder = 0;

        // ��ʼ����һ�����һ�У�ͬʱ�������߳�
        for (int i = 0; i < n; i++) {
            dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
            MAXborder = max(MAXborder, dp[i][0]);
        }
        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j] == '1' ? 1 : 0;
            MAXborder = max(MAXborder, dp[0][j]);
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1; //�����ϣ�����С�߳�   1 1 1
                    MAXborder = max(MAXborder, dp[i][j]);                                  //                       1 1 1
                }                                                                          //                       1 1 .
                else {
                    dp[i][j] = 0;
                }
            }
        }

        return MAXborder * MAXborder;
    }
};