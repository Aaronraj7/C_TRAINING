#include "target_bandwidth.h" 
int min_moves(int target, int max_doubles){
    int moves=0;
    while(target>1 && max_doubles>0){
        if(target%2!=0)
            target-=1;
        else{    
            target/=2;
            max_doubles--;
        }
        moves++;    
    }
    if(target>1){
        moves=(target-1);
    }
    return moves;
}