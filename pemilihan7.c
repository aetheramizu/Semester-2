#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char *romawi[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int nilai[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    char hasil[100] = ""; 

    printf("Masukkan bilangan bulat positif: ");
    scanf("%d", &n);

    if (n > 0) {
        for (int i = 12; i >= 0; i--) {
            while (n >= nilai[i]) {
                n -= nilai[i]; 
                strcat(hasil, romawi[i]); 
            }
        }

        printf("Angka Romawi adalah: %s\n", hasil);
    } else {
        printf("Harap masukkan bilangan bulat positif.\n");
    }

    return 0;
}