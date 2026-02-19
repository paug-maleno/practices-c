#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("how many words do you want to save? ");
    scanf("%d", &n);
    char **arr = malloc(n * sizeof(char*));  // char** es una array de strings
    for(int i = 0; i <n; i++){
        arr[i] = malloc(50 * sizeof(char));  // cada string cabe 50 caracteres
        printf("enter a string: ");
        scanf("%s", arr[i]);
    }
    for(int i = 0; i <n; i++){
        printf("%s", arr[i]);
    }
    printf("\n");

for (int i = 0; i < n; i++) free(arr[i]);
free(arr);
}