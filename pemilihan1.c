#include <stdio.h>

int main() {
    int N;
    printf("Masukkan bilangan bulat positif: ");
    scanf("%d", &N);

    if (N % 4 == 0) {
        printf("Kelipatan 4\n");
    } else {
        printf("Bukan Kelipatan 4\n");
    }

    return 0; 
}