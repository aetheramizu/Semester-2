#include <stdio.h>
#include <string.h>

struct Mahasiswa {
    char nim[20];
    char nama[50];
    float ipk;
};

int main() {
    int jumlah, i;
    char cariNIM[20];
    int ditemukan = 0;

    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &jumlah);

    struct Mahasiswa mhs[jumlah];

    for (i = 0; i < jumlah; i++) {
        printf("\nMahasiswa ke-%d:\n", i + 1);
        printf("NIM  : ");
        scanf("%s", mhs[i].nim);
        printf("Nama : ");
        scanf(" %[^\n]", mhs[i].nama);
        printf("IPK  : ");
        scanf("%f", &mhs[i].ipk);
    }

    printf("\nMasukkan NIM mahasiswa yang ingin diganti IPK-nya: ");
    scanf("%s", cariNIM);

    for (i = 0; i < jumlah; i++) {
        if (strcmp(mhs[i].nim, cariNIM) == 0) {
            printf("Mahasiswa ditemukan: %s - %s - IPK: %.2f\n", mhs[i].nim, mhs[i].nama, mhs[i].ipk);
            printf("Masukkan IPK baru: ");
            scanf("%f", &mhs[i].ipk);
            printf("IPK berhasil diupdate!\n");
            ditemukan = 1;
            break;
        }
    }

    if (!ditemukan) {
        printf("Mahasiswa dengan NIM %s tidak ditemukan.\n", cariNIM);
    }

    printf("\nData Mahasiswa Setelah Update:\n");
    for (i = 0; i < jumlah; i++) {
        printf("%s - %s - IPK: %.2f\n", mhs[i].nim, mhs[i].nama, mhs[i].ipk);
    }

    return 0;
}
