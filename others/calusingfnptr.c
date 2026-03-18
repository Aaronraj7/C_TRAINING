//use function ptr to simulate a calculator
#include<stdio.h>

double add(double a, double b){printf("ADDITION: ");return(a+b);}
double sub(double a, double b){printf("SUBTRACTION: ");return(a-b);}
double mul(double a, double b){printf("MULTIPLICATION: ");return(a*b);}
double div(double a, double b){printf("DIVISION: ");return(a==0 || b==0)?(-1):(a/b);}

int main(){
    double (*fnptr[4])(double,double)={add,sub,mul,div},a,b;
    int choice;
    while(1){
        printf("Select operation to perform(1-add,2-sub,3-mul,4-div): ");
        scanf("%d",&choice);
    
        if(choice>=1 && choice<=4){
            printf("Enter operands:- \n");
            scanf("%lf %lf",&a,&b);
            double res=fnptr[choice-1](a,b);
            res!=-1?printf("%lf\n",res):printf("InVaLiD!Math error\n");
            return 1;
        }
        else    printf("InVaLiD choice, Try again....\n");
    }
    return 0;   
}
