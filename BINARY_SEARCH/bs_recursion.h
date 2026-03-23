#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

int binarySearch(int left, int right, int *arr, int target){
    
    if(left<=right){
        
        int mid = left+(right-left)/2;

        if(arr[mid]==target)    return mid;
        
        else if(arr[mid]<target)    return binarySearch(mid+1,right,arr,target);

        else    return binarySearch(left, mid-1, arr, target);
    }
    return -1;
}


#endif