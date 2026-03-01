#include <stdio.h>
#include <string.h>

typedef enum {
    alien,
    not_alien,
} result;

int is_vowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int main() {
    char word[20];
    scanf("%s", word);
    int len = strlen(word);
    result result = alien;

    if (len <= 1) {
        result = not_alien;
    } else {
        for (int i = 0; i < len; i++) {
            if (is_vowel(word[i])) {
                result = not_alien;
                break;
            }
        }
    }

    printf("%s\n", result == alien ? "true" : "false");
    return 0;
}