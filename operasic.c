#include <stdio.h>
#include <string.h>

int binarySearch(char arr[][20], int size, char target[]) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(arr[mid], target);

        if (cmp == 0)
            return mid;
        else if (cmp < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // Tidak ditemukan
}

int main() {
    char names[][20] = {
        "Ahmad", "Alif", "Bella", "Budi", "Chandra", "Citra", "Diana",
        "Dewi", "Eli", "Eko", "Fajar", "Farhan", "Gani", "Gita", "Hani",
        "Hendra", "Indra", "Ika", "Jasmine", "Joko", "Kirana", "Kevin",
        "Lara", "Laras", "Lina", "Marcel", "Maya", "Nadia", "Nina",
        "Oki", "Omar", "Putri", "Qiana", "Rina", "Rudi", "Sari", "Sinta",
        "Tari", "Tina", "Uli", "Umar", "Vina", "Vira", "Wanda", "Wira",
        "Xena", "Yani", "Yudi", "Zaki"
    };
    int size = sizeof(names) / sizeof(names[0]);

    int t;
    scanf("%d", &t);
    getchar(); // Untuk menangani newline setelah input angka

    for (int i = 0; i < t; i++) {
        char target[20];
        fgets(target, sizeof(target), stdin);

        // Hapus newline '\n' dari fgets
        target[strcspn(target, "\n")] = 0;

        int index = binarySearch(names, size, target);

        if (index != -1)
            printf("%d\n", index);
        else
            printf("tidak ditemukan\n");
    }

    return 0;
}
