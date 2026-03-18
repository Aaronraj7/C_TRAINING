//sum of middle elements of 2 list
#include<stdio.h>

int summerged(int* arr1, int* arr2, int n1, int n2){
    int i=0,j=0,n=n1+n2;
    int res[n];
    int k=0;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            res[k]=arr1[i];
            i++;
        }
        else{
            res[k]=arr2[j];
            j++;
        }
        k++;

    }
    while(i<n1) res[k++]=arr1[i++];
    while(j<n2) res[k++]=arr2[j++];
    printf("%d %d\n",res[((n)/2)-1],res[(n/2)]);
    for(int i=0;i<n;i++)    printf("%d ",res[i]);
    return (n)%2==0?((res[((n/2)-1)]+res[(n)/2])):(res[(n)/2]);
}

int main(){
    int arr1[]={1,2};
    int arr2[]={4,5,6};
    int res[6];
    int sum=summerged(arr1,arr2,sizeof(arr1)/sizeof(arr1[0]),sizeof(arr2)/sizeof(arr2[0]));
    printf("\n%d\n",sum);
}
