#include <stdio.h>
    
typedef enum{
    THURSDAY = 0,
    FRIDAY,
    SATURDAY,
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY, 
} day;

int main(){
    char* days[] ={"thursday", "friday", "saturday", "sunday", "monday", "tuesday", "wednesday"};
    int x;
    scanf("%d", &x);

    day result = (day)((x-8)%7);
    printf("%s\n", days[result]);
    return 0;
}

