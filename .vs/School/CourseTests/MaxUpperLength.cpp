#include<stdlib.h>
using namespace std;

int max(int i, int j)
{
    return i>j?i:j;
}

int main() {
    
    int nums[5]={1,5,2,4,3};
    int L[5] = {1, 1, 1, 1, 1};
    
    for(int i=4;i>=0;i--){
        
        for(int j=i+1;j<=4;j++){
            if(nums[j]>nums[i]){
                L[i]=max(L[i],L[j]+1);
            }
        }
    }

    int maxLength = 0;
    for(int i=0; i<5; i++) {
        maxLength = max(maxLength, L[i]);
    }

    return maxLength;
}