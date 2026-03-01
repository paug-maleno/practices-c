#include <stdio.h>

typedef struct{
    char name[20];
    float grade;
} student;

int main () {
    int n;
    scanf("%d", &n);
    student a[n];
    for(int i=0; i<n; i++){
        scanf("%s %f", a[i].name, &a[i].grade);
    }
    for(int i =0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(a[j+1].grade > a[j].grade){
                student temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
    }
    for(int i=0; i<n; i++){
        printf("%s %.2f\n", a[i].name, a[i].grade);
    }
    return 0;
}    