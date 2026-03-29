#include<stdio.h>
#include "lis.h"

int main(){
    int nums[]={2,3,6,1,4,8,7,9,9};
    int numsSize=sizeof(nums)/sizeof(nums[0]);

    int l=lis(nums, numsSize);
    printf("length of longest substring - %d\n",l);

    return 0;
}