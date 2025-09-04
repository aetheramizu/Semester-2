#include <stdio.h>

int main() {
    int saldo = 100000;
    int kode_transaksi;
    int jumlah;

    while (1) {
        printf("Saldo saat ini: Rp%d\n", saldo);
        printf("Masukkan kode transaksi (0 untuk setor, 1 untuk ambil): ");
        scanf("%d", &kode_transaksi);

        if (kode_transaksi == 0) {
            printf("Masukkan jumlah uang yang disetor: ");
            scanf("%d", &jumlah);
            saldo += jumlah; 
            printf("Setoran berhasil. Saldo baru: Rp%d\n", saldo);
        }

        else if (kode_transaksi == 1) {
            printf("Masukkan jumlah uang yang diambil: ");
            scanf("%d", &jumlah);

            if (jumlah > saldo - 10000) {
                printf("Transaksi gagal. Jumlah yang diambil melebihi saldo yang tersedia.\n");
            } else {
                saldo -= jumlah;
                printf("Penarikan berhasil. Saldo baru: Rp%d\n", saldo);
            }
        } else {
            printf("Kode transaksi tidak valid. Silakan coba lagi.\n");
        }

        if (saldo <= 10000) {
            printf("Saldo sudah mencapai Rp10.000. Transaksi dihentikan.\n");
            break;
        }
    }

    return 0;
}