#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    int num;
    scanf("%d\n", &n);
    int *arr = malloc(n *sizeof(int));
    for(int i = 0; i<n; i++){
        printf("enter a number: ");
        scanf("%d", &num);
        arr[i] = num;
        printf("number is %d\n", arr[i]);
    }
    free(arr);
    return 0;
}


