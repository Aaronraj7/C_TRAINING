//sort an arr using ptr
#include "stdio.h"
void sortptr(int *arr,int n){
    for(int i=0;i<n;i++){
        for(int j = 0; j < n-i-1; j++) {
            if (*(arr + i) > *(arr + j)) {  
                int temp = *(arr + i);           
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        printf("%d ",*(arr+i));    
    }
}

void main(){
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter values: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sortptr(arr,n);
    printf("\n");
}
