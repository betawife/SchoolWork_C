#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if (n < 3) return 0;

    vector<int> maxL(n), maxR(n);              //将各列的maxL,maxR预先存入数组中，减少时间复杂度
    maxL[0] = height[0];
    for (int i = 1; i < n; i++) {
        maxL[i] = max(maxL[i - 1], height[i]);
    }

    maxR[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        maxR[i] = max(maxR[i + 1], height[i]);
    }

    int sumWater = 0;
    for (int i = 1; i < n - 1; i++) {
        sumWater += max(0, min(maxL[i], maxR[i]) - height[i]);  // 作用就是防止负值出现，只加正值
    }

    return sumWater;
}

int main() {
    vector<int> height = { 2, 1, 3, 0, 1, 4, 2, 5, 0, 3 };
    int SumWater = trap(height);
    cout << "二维柱状图总蓄水量为 " << SumWater << endl;
    return 0;
}
