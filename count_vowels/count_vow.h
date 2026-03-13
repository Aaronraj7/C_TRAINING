#ifndef COUNT_VOWELS_H
#define COUNT_VOWELS_H

int count_vowels(char *s){
    int count=0;
    for(int i=0;*(s+i)!='\0';i++){
        char ch=*(s+i);    
        ch= ch | (int)' '; //ASCI value of space is 32
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
            count++;
        }
    }    
    return count;
}

#endif
// A - 65, a= 65+32 = 97
// the difference between lowercase and uppercase alphabets is the 6th bit from the right, hence setting it gives always a lowercase for any uppercase or lowercase alphabet.
// 32 16 8 4 2 1 