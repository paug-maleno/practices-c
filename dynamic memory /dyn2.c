#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    int *arr = malloc(3 *sizeof(int));
    for(int i = 0 ; i <3; i++){
        printf("enter 3 numbers: ");
        scanf("%d", &num);
        arr[i] = num;
    }
    arr = realloc(arr, 6*sizeof(int));
    for(int i = 3; i < 6; i++){
        printf("enter 3 more numbers: ");
        scanf("%d", &num);
        arr[i] = num;
    }
    printf("all numbers are: ");
    // hacemos un for para recorrer toda la matriz
    for(int i = 0; i <= 6; i++){
        printf("%d ", arr[i]);
    }
    free(arr);

    return 0;

}