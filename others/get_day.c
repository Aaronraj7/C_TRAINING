//get a random day in a year
#include<stdio.h>

int isleapyear(int year){
	return (year%4==0 && year%100!=0)||(year%400==0);
}

void get_day(int date, int month, int year, int firstday){

char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int oddDays[12]={3,0,3,2,3,2,3,3,2,3,2,3};
if(isleapyear(year))	oddDays[1]=1;
int  totaloddDays=0;
for(int i=0;i<month-1;i++){
totaloddDays+=oddDays[i];
}
totaloddDays+=(date-1);
int targetindex=(firstday+totaloddDays)%7;
printf("The date %02d/%02d/%d is a %s.\n",date,month,year,days[targetindex]);
}

int main(){ 
    int date = 1;
    int month = 1;
    int year = 2026;
    int first_day_of_year = 4; 

    get_day(date, month, year, first_day_of_year);

    return 0;
}
