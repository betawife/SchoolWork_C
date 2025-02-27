#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int test01(vector<int>& height) {
	int sumWater = 0;
	int n = height.size();    //���ڶ�vectorʹ������
	
	if (n < 3)return 0;
	
	for (int i = 1; i < n - 1;i++) {
		int maxL, maxR = 0;
		for (int j = 0; j < i;j++) {
			maxL = max(maxL, height[j]);
		}
		for (int j = i+1; j <=n-1; j++) {
			maxR = max(maxR, height[j]);
		}
		int water = min(maxL, maxR) - height[i];     //water�Ķ������ѭ�����Է���һ���ض���
		
		if(water>0)                  //water���ܼ������ֵ��ֻͳ����ֵ
		{sumWater += water;}
	}
	return sumWater;
}

int main() {
	vector<int> height = { 2, 1, 3, 0, 1, 4, 2, 5, 0, 3 };
	int SumWater = test01(height);
	cout << "��ά��״ͼ����ˮ��Ϊ" << SumWater << endl;
	return 0;
}