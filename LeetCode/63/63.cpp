#include<stdlib.h>
#include<vector>

using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> path(n, vector<int>(m, 0));  //path��ʼ��Ϊ0��Ϊ��֮��߽�ĳ�ʼ��

        // ��������յ����ϰ��ֱ�ӷ���0
        if (obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1) {
            return 0;
        }

        // ��ʼ���յ�
        path[n - 1][m - 1] = 1;

        // ��ʼ�����һ�У��������ϣ� ����ǰû���ϰ���+֮��û��
        for (int i = n - 2; i >= 0; i--) {
            if (obstacleGrid[i][m - 1] == 0 && path[i + 1][m - 1] == 1) {
                path[i][m - 1] = 1;
            }
        }

        // ��ʼ�����һ�У���������
        for (int j = m - 2; j >= 0; j--) {
            if (obstacleGrid[n - 1][j] == 0 && path[n - 1][j + 1] == 1) {
                path[n - 1][j] = 1;
            }
        }

        // ��̬�滮������ಿ�֣������µ����ϣ�
        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                if (obstacleGrid[i][j] == 0) {
                    path[i][j] = path[i + 1][j] + path[i][j + 1];
                }
                else {
                    path[i][j] = 0; //��ǰλ��·�ϣ�·����ֱ�ӹ���
                }
            }
        }

        return path[0][0];
    }
};