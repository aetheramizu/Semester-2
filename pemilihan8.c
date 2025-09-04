#include <stdio.h>

int main() {
    int n;

    printf("Masukkan nilai pixel: ");
    scanf("%d", &n);

    if (n < 0) {
        n = 0; 
    } 
    else if (n > 255) {
        n = 255; 
    }

    printf("Nilai pixel setelah clipping adalah: %d\n", n);
    
    return 0;
}