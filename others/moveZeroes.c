//move zeroes to the end
#include<stdio.h>

void movezeroes(int* arr, int n){
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0)   arr[j++]=arr[i];
    }
    while(j<n){
        arr[j++]=0;
    }
}

int main(){
    int arr[]={0,2,1,0,4,0,6,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    movezeroes(arr,n);
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    printf("\n");
}
