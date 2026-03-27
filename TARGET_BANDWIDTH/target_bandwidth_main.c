#include<stdio.h>
#include"target_bandwidth.h"

int main(){
    int target=5;
    int maxdoubles=2;
    int moves=min_moves(target, maxdoubles);
    printf("Min moves - %d\n",moves);
    return 0;
}