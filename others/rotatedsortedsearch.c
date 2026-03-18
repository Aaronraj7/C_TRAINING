//search element in rotated sorted arr
#include<stdio.h>

int search_ele(int *arr, int n, int target){
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            printf("Found\n");
            return mid;
        }
        if(arr[low]<=arr[mid]){
            if(target>=arr[low] && target<arr[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(target>arr[mid] && target<=arr[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return -1;
}

int main(){
    int arr[]={4,5,6,1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=1;
    int res=search_ele(arr,n,target);
    if(res==-1){
        printf("Element not present\n");
        return -1;
    }
    printf("Element found at %d\n",res);
    return 0;
}
