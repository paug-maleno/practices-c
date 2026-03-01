#include <stdio.h>

typedef struct{
    char name[20];
    float time;
} driver;

int main () {
    int n;
    scanf("%d", &n);
    driver a[n];
    for(int i=0; i<n; i++){
        scanf("%s %f", a[i].name, &a[i].time);
    }
    // for changing we need a aux var
    
    // bubble sort
    for(int i =0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(a[j].time > a[j+1].time){
                driver temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    for(int i=0; i <n; i++){
        printf("%d. %s, %.2f\n",i+1, a[i].name, a[i].time);
    }
    return 0;
}