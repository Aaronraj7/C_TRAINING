//string len without spaces
#include<stdio.h>
#include<string.h>
int main(){
    char s[10];
    int i=0;
    printf("Enter a string with spaces(limit-10): \n");
    scanf("%[^\n]",s);
    int count=0;
    while(s[i]!='\n' && s[i]!='\0'){
        if(s[i]!=' ') count++; 
        i++;
    }
    printf("length-%d \n",count);
    return 0;
}
