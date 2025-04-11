#include<stdlib.h>
#include<vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>score(n, vector<int>(m, 0)); //数组score,用来存储该位到终点的最小路权：该位到终点的最小路权=该位权+min(下一步(右或下)到终点的最小路权)

        if (n == 1 && m == 1) { return grid[0][0]; }
        if (n == 1 && m == 2) { return grid[0][0] + grid[0][1]; }
        if (n == 2 && m == 1) { return grid[0][0] + grid[1][0]; }

        score[n - 1][m - 1] = grid[n - 1][m - 1];                   //处理边界,处理时也要按照score公式!!
        for (int i = m - 2; i >= 0; i--) { //下边界
            score[n - 1][i] = grid[n - 1][i] + score[n - 1][i + 1];
        }
        for (int i = n - 2; i >= 0; i--) { //右边界
            score[i][m - 1] = grid[i][m - 1] + score[i + 1][m - 1];
        }

        for (int i = n - 2; i >= 0; i--) { //其余部分
            for (int j = m - 2; j >= 0; j--) {
                score[i][j] =grid[i][j] + min(score[i + 1][j],score[i][j + 1]);
            }
        }
        return score[0][0];
    }
};