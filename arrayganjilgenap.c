#include <stdio.h>

int main() {
    int N;

    printf("Masukkan ukuran array : ");
    scanf("%d", &N);

    int array[N]; 
    int genap = 0; 
    int ganjil = 0; 

    printf("Masukkan %d bilangan bulat:\n", N);
    for (int i = 0; i < N; i++) {
        printf("Elemen %d: ", i + 1);
        scanf("%d", &array[i]);

        if (array[i] % 2 == 0) {
            genap++; 
        } else {
            ganjil++; 
        }
    }
    
    printf("Jumlah elemen genap: %d\n", genap);
    printf("Jumlah elemen ganjil: %d\n", ganjil);

    return 0;
}