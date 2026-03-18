//twin prime
#include<stdio.h>
int isprime(int n){
    for(int i=2;i<n/2;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n,c=0;
    printf("Enter n: \n");scanf("%d",&n);
    
    for(int i=3;i<=n-2;i++){
        if(isprime(i) && isprime(i+2)){
            printf("(%d %d) \n",i,i+2);
            c++;
        }
    }
    printf("count-%d\n",c);
    return 0;
}
