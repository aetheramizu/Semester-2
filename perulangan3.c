#include <stdio.h>

int main() {
    int N, i, jumlah;

    printf("Masukkan bilangan bulat positif N: ");
    scanf("%d", &N);

    jumlah = 0;

    for (i = 1; i <= N; i++) {
        if (i % 2 != 0) {
            jumlah += i; 
        }
    } 

    printf("Jumlah bilangan ganjil dari 1 sampai %d adalah: %d\n", N, jumlah);
    return 0;
}