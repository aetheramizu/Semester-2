#include <stdio.h>

int main() {
    int N, i, jumlah;

    printf("Masukkan jumlah bilangan ganjil yang ingin dihitung (N): ");
    scanf("%d", &N);

    jumlah = 0;

    for (i = 0; i < N; i++) {
        jumlah += (2 * i + 1);
    }

    printf("Jumlah %d bilangan ganjil pertama adalah: %d\n", N, jumlah);

    return 0;
}