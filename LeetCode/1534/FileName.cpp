#include<stdlib.h>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:    
	int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
		int count=0;
		for(int i=0;i<arr.size()-2;i++){
			for(int j=i+1;j<arr.size()-1;j++){
				if(abs(arr[i]-arr[j])<=a){             //先判断一个条件，不满足则跳到下一次循环，节省时间   //break是终止循环，别用错
					for(int k=j+1;k<arr.size();k++){
						if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) 
						{count++;  }
					}
				}else continue;
			}
		}
		return count;
	}
};