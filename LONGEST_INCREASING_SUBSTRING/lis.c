#include "lis.h"

int lis(int *nums, int numsSize){
    if(!numsSize)   return 0;

    int dp[numsSize], max_length=1;

    for(int i=0;i<numsSize;i++){dp[i]=1;}
    
    for(int i=0;i<numsSize;i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                if(dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                }
            }
        }
        if(dp[i]>max_length)    max_length=dp[i];
    }

    return max_length;
}