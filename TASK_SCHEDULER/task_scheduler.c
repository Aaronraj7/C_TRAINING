#include<stdio.h>
#include "task_scheduler.h"
int main(){
    int n=3;
    char tasks[]="AAABBB";
    int tasksSize=sizeof(tasks)/sizeof(tasks[0])-1;
    printf("%d\n",least_interval(tasks, tasksSize, n));
    return 0;
}