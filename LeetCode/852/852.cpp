#include<stdlib.h>
#include<vector>
using namespace std;

class Solution {
public:    int peakIndexInMountainArray(vector<int>& arr) {           //要求复杂度为log(n),且数组为部分有序，适合使用二分法
	int left = 0; int right = arr.size() - 1;
	int mid = (left + right) / 2;
	while (left < right) {
		mid = (left + right) / 2;
	if (arr[mid - 1]<arr[mid] && arr[mid]>arr[mid + 1]) return mid;   //mid恰好落在峰上(可能是第一次就恰好)，此时应立刻中断循环返回，防止指针过度变动
	else { 
		if (arr[mid] < arr[mid + 1]) { left = mid; }   //位于上坡     //不使用+1,防止跳过山峰
		else if (arr[mid] > arr[mid + 1]) { right = mid; } //位于下坡
	}
	}
	return mid; 
}
};