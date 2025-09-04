#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int upperBound(int arr[], int n, int x) {
    int kiri = 0, kanan = n;
    while (kiri < kanan) {
        int mid = (kiri + kanan) / 2;
        if (arr[mid] <= x) {
            kiri = mid + 1;
        } else {
            kanan = mid;
        }
    }
    return kiri;
}

int lowerBound(int arr[], int n, int y) {
    int kiri = 0, kanan = n;
    while (kiri < kanan) {
        int mid = (kiri + kanan) / 2;
        if (arr[mid] <= y) {
            kiri = mid + 1;
        } else {
            kanan = mid;
        }
    }
    return kiri;
}

int main() {
    int N, Q;
    scanf("%d", &N);

    int berat[100005];
    for (int i = 0; i < N; i++) {
        scanf("%d", &berat[i]);
    }

    scanf("%d", &Q);

    qsort(berat, N, sizeof(int), compare);

    for (int i = 0; i < Q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        int kiri = upperBound(berat, N, x); // > x
        int kanan = lowerBound(berat, N, y); // ≤ y

        int hasil = kanan - kiri;
        printf("%d\n", hasil);
    }

    return 0;
}
