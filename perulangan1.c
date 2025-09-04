#include <stdio.h>

int main() {
    char C;

    printf("Masukkan karakter (titik untuk berhenti): ");
    scanf(" %c", &C); 

    while (C != '.') {
        printf("Karakter yang dibaca: %c\n", C);
        printf("Masukkan karakter (titik untuk berhenti): ");
        scanf(" %c", &C); 
    }

    return 0;
}