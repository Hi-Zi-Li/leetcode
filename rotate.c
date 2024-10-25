#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void rotate(int *nums, int numsSize, int k) {
    k = k % numsSize;
    int* ans = (int*) malloc(numsSize*4); 
    memcpy(ans, nums+numsSize-k, k * 4);
    memcpy(ans+k, nums, (numsSize-k)*4);    
    memcpy(nums, ans, numsSize * 4);
}

int main() {
    int nums[10] = {0,1,2,3,4,5,6,7,8,9};
    rotate(nums, 10, 1);
    for (int i = 0; i < 10; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}