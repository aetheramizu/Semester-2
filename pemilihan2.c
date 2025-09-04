#include <stdio.h>

int main() {
    float TotalBelanja, Diskon, TotalSetelahDiskon;

    printf("Masukkan Total belanja: ");
    scanf("%f", &TotalBelanja);

    if (TotalBelanja > 100000) {
        Diskon = TotalBelanja * 0.1; 
        printf("Diskon harga: Rp%.2f\n", Diskon);
    } else {
        Diskon = 0; 
    }

    TotalSetelahDiskon = TotalBelanja - Diskon;

    printf("Total belanja setelah Diskon: Rp%.2f\n", TotalSetelahDiskon);

    return 0;
}