//next greatest element in a circular arr
#include<stdio.h>

void NGE_circularray(int *arr,int n,int *res){
    int stack[100];
    int top=-1;
    for(int i=0;i<n;i++){
        res[i]=-1;
    }
    for(int i=0;i<2*n-1;i++){
        int index=i%n;
        while(top>=0 && arr[stack[top]]<arr[index]){
            res[stack[top--]]=arr[index];
        }
        if(i<n){
            stack[++top]=index;
        }
    }
}

int main(){
    int arr[]={1,2,3,4,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int res[n];
    NGE_circularray(arr,n,res);
    gotoxy(13,26);
    for(int i=0;i<n;i++){
        printf("%d ",res[i]);
    }
    return 0;
}
