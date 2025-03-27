#include<stdlib.h>
#include<vector>
using namespace std;

class Solution { 
public:    vector<int> shuffle(vector<int>& nums, int n) { 
	vector<int> v1, v2;
	v1.resize(n); v2.resize(n);
	for (int i = 0; i < n; i++) { 
		v1[i] = nums[i];
		v2[i] = nums[n + i]; 
	}
	for (int i = 0, j = 0; i < n, j < 2 * n; i++, j += 2) {
		nums[j] = v1[i];
		nums[j + 1] = v2[i]; 
	}
	return nums; 
} 
};