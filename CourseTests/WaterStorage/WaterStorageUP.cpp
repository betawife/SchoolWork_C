#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if (n < 3) return 0;

    vector<int> maxL(n), maxR(n);              //�����е�maxL,maxRԤ�ȴ��������У�����ʱ�临�Ӷ�
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
        sumWater += max(0, min(maxL[i], maxR[i]) - height[i]);  // ���þ��Ƿ�ֹ��ֵ���֣�ֻ����ֵ
    }

    return sumWater;
}

int main() {
    vector<int> height = { 2, 1, 3, 0, 1, 4, 2, 5, 0, 3 };
    int SumWater = trap(height);
    cout << "��ά��״ͼ����ˮ��Ϊ " << SumWater << endl;
    return 0;
}
