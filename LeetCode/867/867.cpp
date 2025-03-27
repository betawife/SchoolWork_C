#include<stdlib.h>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> tp(col, vector<int>(row));   //新数组列作行，行作列

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                tp[j][i] = matrix[i][j];      //装填每一个元素，记得是行列互换
            }
        }
        return tp;
    }
};