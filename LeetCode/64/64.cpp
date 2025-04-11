#include<stdlib.h>
#include<vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>score(n, vector<int>(m, 0)); //����score,�����洢��λ���յ����С·Ȩ����λ���յ����С·Ȩ=��λȨ+min(��һ��(�һ���)���յ����С·Ȩ)

        if (n == 1 && m == 1) { return grid[0][0]; }
        if (n == 1 && m == 2) { return grid[0][0] + grid[0][1]; }
        if (n == 2 && m == 1) { return grid[0][0] + grid[1][0]; }

        score[n - 1][m - 1] = grid[n - 1][m - 1];                   //����߽�,����ʱҲҪ����score��ʽ!!
        for (int i = m - 2; i >= 0; i--) { //�±߽�
            score[n - 1][i] = grid[n - 1][i] + score[n - 1][i + 1];
        }
        for (int i = n - 2; i >= 0; i--) { //�ұ߽�
            score[i][m - 1] = grid[i][m - 1] + score[i + 1][m - 1];
        }

        for (int i = n - 2; i >= 0; i--) { //���ಿ��
            for (int j = m - 2; j >= 0; j--) {
                score[i][j] =grid[i][j] + min(score[i + 1][j],score[i][j + 1]);
            }
        }
        return score[0][0];
    }
};