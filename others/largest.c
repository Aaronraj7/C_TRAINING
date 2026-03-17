//largest element in the arr
#include<stdio.h>
int largest(int *ptr,int n){
    int l=*ptr;
    for(int i=0;i<n;i++){
        if(*(ptr+i)>l){
            l=*(ptr+i);
        }
    }
    return l;
}
void main(){
    int n,*ptr;
    printf("Enter size of array: \n");
    scanf("%d",&n);
    int arr[n];
    ptr=arr;
    printf("Enter values: ");
    for(int i=0;i<n;i++){
        scanf("%d",(ptr+i));  
    }
    printf("the largest is : %d\n",largest(arr,n));
}
