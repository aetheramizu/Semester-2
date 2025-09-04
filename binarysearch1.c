#include <stdio.h>
#include <string.h>

#define SIZE 50

int binarySearch(char names[][20], int size, char target[]) {
    int kiri = 0;
    int kanan = size - 1;

    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        int cmp = strcmp(names[tengah], target);

        if (cmp == 0) {
            return tengah;
        } else if (cmp < 0) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }

    return -1; 
}

int main() {
    
    char names[SIZE][20] = {
        "Ahmad", "Alif", "Bella", "Budi", "Chandra", "Citra", "Diana", "Dewi",
        "Eli", "Eko", "Fajar", "Farhan", "Gani", "Gita", "Hani", "Hendra",
        "Indra", "Ika", "Jasmine", "Joko", "Kirana", "Kevin", "Lara", "Laras",
        "Lina", "Marcel", "Maya", "Nadia", "Nina", "Oki", "Omar", "Putri",
        "Qiana", "Rina", "Rudi", "Sari", "Sinta", "Tari", "Tina", "Uli",
        "Umar", "Vina", "Vira", "Wanda", "Wira", "Xena", "Yani", "Yudi", "Zaki"
    };

    int n;
    char cari[20];

    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", cari);

        int hasil = binarySearch(names, SIZE, cari);
        if (hasil != -1) {
            printf("%d\n", hasil);
        } else {
            printf("tidak ditemukan\n");
        }
    }

    return 0;
}
