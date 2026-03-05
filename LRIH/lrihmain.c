#include<stdio.h>
#include "lrih.h"

int main(){
    int heightSize;
    printf("Enter number of bars: \n");
    scanf("%d",&heightSize);
    int heights[heightSize];
    printf("Enter heights of bars: \n");
    for(int i=0;i<heightSize;i++){
        scanf("%d",&heights[i]);
    }
    printf("Largest area: %d\n",largestrectangle(heights,heightSize));
    return 0;
}
