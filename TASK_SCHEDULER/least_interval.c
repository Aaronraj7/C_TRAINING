//to return the minimum number of CPU intervals required to complete all tasks
//n is the min interval btw two tasks of same label
#include "task_scheduler.h"
int least_interval(char* tasks, int tasksSize, int n){
    int freq[26]={0};
    int max_f=0, max_count=0;

    for(int i=0;i<tasksSize;i++){
        freq[tasks[i]-'A']++; //limiting the array index to 0-26, since only alphabet labels are given. (ex. 65-65=0,66-65=1...26)
        if(freq[tasks[i]-'A']>max_f)    max_f=freq[tasks[i]-'A'];
    }

    for(int i=0;i<26;i++){
        if(freq[i]==max_f)    max_count++;
    }

    int least_intervals=(max_f-1)*(n+1)+max_count;
    return (least_intervals>tasksSize)?least_intervals:tasksSize; 
}
// (max_f-1*)*(n+1) gives the number of complete blocks. A _ _|A _ _|A if A has most freq and n=2
// adding max_count adds the remaining repeating labels