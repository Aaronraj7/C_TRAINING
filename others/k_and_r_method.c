//practice implementation of Kernighan and Ritchie(K & R) method
int calsum(a,b);
int main(){
    int a,b,sum; 
    a=1,b=3;
    sum = calsum(a,b);
    return sum;
}

calsum(a,b)
int a,b;
{
    return a+b;
}
//echo $? to see the exit status of last command)(in this case the return of main)