#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, l;
    scanf("%d %d", &n, &l);

    int *hasil = (int *)malloc((n + 1) * sizeof(int));
    int size = 1;
    hasil[0] = l;

    for (int i = 0; i < n; i++) {
        int potong;
        scanf("%d", &potong);

        int l = hasil[potong - 1];

        hasil[potong - 1] = l / 2;

        for (int j = size; j > potong; j--) {
            hasil[j] = hasil[j - 1];
        }

        hasil[potong] = l - l / 2;
        size++;
    }

    for (int i = 0; i < size; i++) {
        printf("%d ", hasil[i]);
    }
    printf("\n");

    free(hasil);

    return 0;
}