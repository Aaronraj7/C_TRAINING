#include"bs_recursion.h"
#include<stdio.h>

int main(){
    int arr[] = {1,2,3,6,8,12,25,87,100};
    int target = 87;
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int index = binarySearch(0 ,arr_size-1, arr, target);
    if(index!=-1)   printf("Target element at index - %d\n",index);
    else    printf("No such element");
    return 0;
}