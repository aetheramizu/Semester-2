#include <stdio.h>

int faktorialganjilgenap(int n) {
    if (n == 0 || n == 1) {
        return 1; 
    }

    if (n % 2 == 0) {
        return (n / 2) * faktorialganjilgenap(n - 1);
    } else {
        return n * faktorialganjilgenap(n - 1);
    }
}

int main() {
    int n;

    printf("Masukkan bilangan bulat : ");
    scanf("%d", &n);

    int hasil = faktorialganjilgenap(n);
    printf("Faktorial ganjil-genap dari %d adalah: %d\n", n, hasil);

    return 0;
}