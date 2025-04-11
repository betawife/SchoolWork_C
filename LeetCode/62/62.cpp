#include<stdlib.h>
#include<vector>

using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m, 0)); //��ά����dp,�����洢��λ��(n-1,m-1)������·����
                                                   //�۲�����λ�ã��������½ǵ��ĸ�����dp[n-2][m-2]=dp[n-1][m-2]+dp[n-2][m-1]���ù��ɣ��Ǳ�Եdp[i][j]=dp[i+1][j]+dp[i][j+1]
        // ����߽�dp,·��������1
        for (int i = 0; i < n; i++) {
            dp[i][m - 1] = 1;
        }
        for (int j = 0; j < m; j++) {
            dp[n - 1][j] = 1;
        }

        // �ݼ�������ֵdp(�����Խ��ԽС����ֹײ���߽�/����Խ��)  ������
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
        vector<vector<int>> dp(n, vector<int>(m, 1));          //��ʼ��ֵ��Ϊ1��������Ϊ�߽縳ֵ

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];       //����˼ά����(��λ)�յ㵽���Ͻ����
            }
        }

        return dp[n - 1][m - 1];
    }
};