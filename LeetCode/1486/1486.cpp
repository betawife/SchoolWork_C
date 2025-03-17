#include<stdlib.h>
#include<vector>
using namespace std;

class Solution {
public:    int xorOperation(int n, int start) {
	vector<int> nums;
	nums.resize(n);
	for (int i = 0; i < n; i++) {
		nums[i] = start + 2 * i; 
	}
	int i = 1; int r = nums[0];
	while (i != n) {
		r ^= nums[i];
		i++; 
	}
	return r; 
} 
};