#include<stdlib.h>
#include<vector>

using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> path(n, vector<int>(m, 0));  //path初始化为0，为了之后边界的初始化

        // 如果起点或终点是障碍物，直接返回0
        if (obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1) {
            return 0;
        }

        // 初始化终点
        path[n - 1][m - 1] = 1;

        // 初始化最后一列（从下往上） ，当前没有障碍物+之后没有
        for (int i = n - 2; i >= 0; i--) {
            if (obstacleGrid[i][m - 1] == 0 && path[i + 1][m - 1] == 1) {
                path[i][m - 1] = 1;
            }
        }

        // 初始化最后一行（从右往左）
        for (int j = m - 2; j >= 0; j--) {
            if (obstacleGrid[n - 1][j] == 0 && path[n - 1][j + 1] == 1) {
                path[n - 1][j] = 1;
            }
        }

        // 动态规划填充其余部分（从右下到左上）
        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                if (obstacleGrid[i][j] == 0) {
                    path[i][j] = path[i + 1][j] + path[i][j + 1];
                }
                else {
                    path[i][j] = 0; //当前位有路障，路径数直接归零
                }
            }
        }

        return path[0][0];
    }
};