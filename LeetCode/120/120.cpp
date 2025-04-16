#include<stdlib.h>
#include<vector>

using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp;
        dp.resize(n);
        for (int i = 0; i < n; i++) {
            dp[i].resize(i + 1);
        }

        if (n == 1)return triangle[0][0];
        if (n == 2)return triangle[0][0] + min(triangle[1][0], triangle[1][1]);


        for (int i = 0; i < n; i++) {
            dp[n - 1][i] = triangle[n - 1][i];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
        return dp[0][0];
    }
};