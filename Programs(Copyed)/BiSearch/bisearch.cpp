#include<stdlib.h>
#include<iostream>
using namespace std;
void Sorted(int arr[],int n) {
	for (int i = 0; i <n-1; i++) {          //外循环控制内循环每趟比较次数
		for (int j = 0; j <n-1- i; j++) {
			if (arr[j] > arr[j+1]) {      //内循环，依次比较所有前后两者，最后会将最大者置尾
				int temp = arr[j];                           //注意：sizeof(arr)在这里指的是形参arr指针的大小，因此会报错“用一个指针的sizeof值.....”
				arr[j] = arr[j+1];                           //所以我们在函数中使用数组长度，一般通过形参传入，在函数外sizeof(arr)才是真数组大小
				arr[j+1] = temp;
			}
		}
	}
}

int bisearch(int arr[], int key = 0,int n=0) {
	int right = n- 1;
	int left = 0;
	int mid = (left + right) / 2;

	while (left < right) {
		mid= (left + right) / 2;
		if (arr[mid] == key) {
			return mid;
		}
		if (arr[mid] > key) {
			right = mid - 1;
		}
		else left = mid + 1;
		
	}
	if (left > right) return -1;
}

int main() {
	int arr[] = { 2,13,14,3,6,7,10,9,11,1,19};
	int n = sizeof(arr) / sizeof(arr[0]);
	Sorted(arr,n);
	for (int k = 0; k < n; k++) cout << arr[k]<<" ";
	cout << endl;
	if (bisearch(arr, 6,n) != -1) {
		cout << "找到关键字，在数组中第" << bisearch(arr, 6,n) + 1 << "位置" << endl;
	}
	else cout << "未找到！" << endl;

	system("pause");
	return 0;
}