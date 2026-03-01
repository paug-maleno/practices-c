#include <stdio.h>

int counting_paths(int x, int y, int n) {
    if (x==n && y==n) return 1;
    if (x>n || y>n) return 0;
    return counting_paths(x+1, y, n) + counting_paths(x, y+1, n);
}

int main(){
    int n;
    scanf("%d", &n);
    printf("the possible paths are %d\n", counting_paths(1,1,n));
    return 0;
}