#include<stdlib.h>
#include<iostream>
using namespace std;
void Sorted(int arr[]) {
	for (int i = 0; i <= sizeof(arr); i++) {          //外循环控制内循环每趟比较次数
		for (int j = 0; j <= sizeof(arr)- i; j++) {                        //内外为何不是sizeof（arr）-1 和sizeof（arr）-1 -i
			if (arr[j] > arr[j+1]) {      //内循环，依次比较所有前后两者，最后会将最大者置尾
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int bisearch(int arr[], int key = 0) {
	int right = sizeof(arr)- 1;
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
	int arr[] = { 2,13,14,3,6,7,10,9,11,1 };
	Sorted(arr);
	for (int k = 0; k < 10; k++) cout << arr[k]<<" ";
	cout << endl;
	if (bisearch(arr, 6) != -1) {
		cout << "找到关键字，在数组中第" << bisearch(arr, 6) + 1 << "位置" << endl;
	}
	else cout << "未找到！" << endl;

	system("pause");
	return 0;
}