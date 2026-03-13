#include "count_vow.h"
#include<stdio.h>

int main(){
    char str[]="aeiouAEIOUBCDEF";
    int n=sizeof(str)/sizeof(str[0]);
    printf("Total count : %d\n",n-1);
    printf("Vowel count : %d\n",count_vowels(str));
    return 0;
}