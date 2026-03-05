
#define MAX(a,b) (a>b)?a:b

int largestrectangle(int *heights, int heightSize){
    
    int stack[heightSize+1];
    int top=-1,max=0;
    
    for(int i=0;i<=heightSize;i++){
        int currentheight=(i==heightSize)?0:heights[i];
        while(top!=-1 && currentheight<heights[stack[top]]){
            int h=heights[stack[top--]];
            int rightlimit=i;
            int leftlimit=(top==-1)?-1:stack[top];
            int width=rightlimit-leftlimit-1;
            max=MAX(max,h*width);
        }
        stack[++top]=i;
    }
    return max;
}