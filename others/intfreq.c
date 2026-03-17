//frequency of an int in an arr
#include<stdio.h>

void intfreq(int *arr, int n){
int freq[100]={0};
int count[100]={0};
for(int i=0;i<n;i++)	freq[arr[i]]++;
for(int i=0;i<n;i++){
	if(count[arr[i]]<1){
	printf("%d occurs - %d times \n",arr[i],freq[arr[i]]);
	count[arr[i]]++;
	}
}
}

int main(){
int n;
printf("Enter n: \n");
scanf("%d",&n);
int arr[n];
printf("Enter arr elements: \n");
for(int i=0;i<n;i++)	scanf("%d",&arr[i]);
intfreq(arr,n);
return 0;
}
