#include <stdio.h>

int main() {
    char golongan;
    int jamKerja;
    float upahPerJam, gaji;
    
    printf("Masukkan golongan karyawan (A, B, C, atau D): ");
    scanf(" %c", &golongan);
    
    switch (golongan) {
        case 'A': 
            upahPerJam = 15000;
            break;
        case 'B': 
            upahPerJam = 12000;
            break;
        case 'C': 
            upahPerJam = 10000;
            break;
        case 'D': 
            upahPerJam = 8000;
            break;
        default:
            printf("Golongan tidak valid!\n");
    }

    printf("Masukkan jumlah jam kerja: ");
    scanf("%d", &jamKerja);

    if (jamKerja <= 40) {
        gaji = jamKerja * upahPerJam;
    } else {
        int jamLembur = jamKerja - 40;
        gaji = (40 * upahPerJam) + (jamLembur * 1.5 * upahPerJam);
    }
    
    printf("Gaji karyawan: Rp%.f\n", gaji);
    
    return 0;
}
