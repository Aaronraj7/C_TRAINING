//unique element in an array
#include<stdio.h>

int unique_element(int* arr, int n){
    int unique=0;
    for(int i=0;i<n;i++){
        unique^=arr[i];
    }
    return unique;
}

int main(){
    int n;
    printf("Enter size of arr: \n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    int res=unique_element(arr,n);
    if(res)   printf("%d\n",res);
    else    printf("No unique element\n");
    return 0;
}
