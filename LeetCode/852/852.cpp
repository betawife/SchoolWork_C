#include<stdlib.h>
#include<vector>
using namespace std;

class Solution {
public:    int peakIndexInMountainArray(vector<int>& arr) {           //Ҫ���Ӷ�Ϊlog(n),������Ϊ���������ʺ�ʹ�ö��ַ�
	int left = 0; int right = arr.size() - 1;
	int mid = (left + right) / 2;
	while (left < right) {
		mid = (left + right) / 2;
	if (arr[mid - 1]<arr[mid] && arr[mid]>arr[mid + 1]) return mid;   //midǡ�����ڷ���(�����ǵ�һ�ξ�ǡ��)����ʱӦ�����ж�ѭ�����أ���ָֹ����ȱ䶯
	else { 
		if (arr[mid] < arr[mid + 1]) { left = mid; }   //λ������     //��ʹ��+1,��ֹ����ɽ��
		else if (arr[mid] > arr[mid + 1]) { right = mid; } //λ������
	}
	}
	return mid; 
}
};