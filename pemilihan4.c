#include <stdio.h>

int main() {
    int a, b, c;
    printf("Masukkan panjang tiga sisi segitiga: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a * a + b * b == c * c) {
        printf("Segitiga siku-siku\n");
    } else if (a * a + b * b < c * c) {
        printf("Segitiga lancip\n");
    } else {
        printf("Segitiga tumpul\n");
    }

    return 0;
}