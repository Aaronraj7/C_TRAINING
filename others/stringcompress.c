//compress string of repeating char
#include<stdio.h>
#include<string.h>
int main(){
  int n;
  printf("Enter the string(within 100 char) : \n");
  char str[100];
  scanf("%s",str);
  n=strlen(str);
  int count[256]={0};
  int t[256]={0};
  for(int i=0;i<n;i++){
    count[str[i]]++;
    t[str[i]]++;
  }
  for(int i=0;i<n;i++){
    if(t[str[i]]>0){
      printf("%c",str[i]);
      if(count[str[i]]>1){
        printf("%d",count[str[i]]);
      }
      t[str[i]]=0;
    }
  }
  printf("\n");
  return 0;
}
