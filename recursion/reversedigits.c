#include <stdio.h>

int reverse_digits(int n, int res) {
    if (n==0) return res;
    return reverse_digits(n/10, res * 10 + n%10);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("the reversed number is %d\n ", reverse_digits(n, 0));
}
