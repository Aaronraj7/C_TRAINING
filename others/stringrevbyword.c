//reverse words in a string
#include<stdio.h>
#include<string.h>

void stringrevbyword(char* str){
    char res[10][10];
    int i=0,j=0;
    while(str[i]!='\0'){
        int k=0;
        while(str[i]!=' ' && str[i]!='\0'){
            res[j][k++]=str[i++];
        }
        j++;
        if(str[i]==' ') i++;
    }
    for(i=j-1;i>=0;i--)
        printf("%s ",res[i]);
    printf("\n");
}

int main(){
    char str[]="hello, hi bye";
    stringrevbyword(str);
    return 0;
}
