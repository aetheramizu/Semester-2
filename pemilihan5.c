#include <stdio.h>

int main() {
    char digit;
    int nilai;

    printf("Masukkan karakter: ");
    scanf(" %c", &digit);

    if (digit >= '0' && digit <= '9') {
        nilai = digit - '0';
    } else {
        nilai = -99;
    }

    printf("Nilai integer: %d\n", nilai);

    return 0;
}