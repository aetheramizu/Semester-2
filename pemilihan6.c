#include <stdio.h>

int pembulatan(int nilai_belanja) {

    if (nilai_belanja % 100 >= 75) {
        nilai_belanja = nilai_belanja - (nilai_belanja % 100) + 100;
    } else if (nilai_belanja % 100 >= 50) {
        nilai_belanja = nilai_belanja - (nilai_belanja % 100) + 50;
    } else if (nilai_belanja % 100 >= 25) {
        nilai_belanja = nilai_belanja - (nilai_belanja % 100) + 25;
    } else {
        nilai_belanja = nilai_belanja - (nilai_belanja % 100);
    }
    
    return nilai_belanja;
}

int main() {
    int nilai_belanja;
    
    printf("Masukkan nilai belanja: ");
    scanf("%d", &nilai_belanja);
    
    int nilai_belanja_bulat = pembulatan(nilai_belanja);

    printf("Nilai belanja setelah dibulatkan: Rp%d\n", nilai_belanja_bulat);
    
    return 0;
}