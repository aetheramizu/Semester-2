#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, X;
    scanf("%d %d", &N, &X);

    int data[1005];
    for (int i = 0; i < N; i++) {
        scanf("%d", &data[i]);
    }

    int hasil = data[0];
    int selisih_min = abs(data[0] - X);

    for (int i = 1; i < N; i++) {
        int selisih = abs(data[i] - X);

        if (selisih < selisih_min) {
            selisih_min = selisih;
            hasil = data[i];
        } 
        else if (selisih == selisih_min && data[i] < hasil) {
            hasil = data[i];
        }
    }

    printf("%d\n", hasil);
    return 0;
}
