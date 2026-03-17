//remove duplicate chars
#include<stdio.h>
#include<string.h>
void removeduplicate(char s[], int n){
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        if(s[i]==s[j]){
          while(j<n-1){
            s[j]=s[j+1];
            j++;
          }
        }
      }
    }
  }
  printf("Updated string is: %s",s);
}
int main(){
  int n;
  char s[100];
  printf("Enter string: ");
  scanf("%d",s);
  n=strlen(s);
  removeduplicate(s,n);
  return 0;
}
