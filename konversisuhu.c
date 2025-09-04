#include <stdio.h>

float konversiKeFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

void tampilkanKelvin(float celsius) {
    float kelvin = celsius + 273.15;
    printf("Suhu dalam Kelvin: %.2f K\n", kelvin);
}

int main() {
    float celsius;

    printf("Masukkan suhu dalam Celcius: ");
    scanf("%f", &celsius);

    float fahrenheit = konversiKeFahrenheit(celsius);+
    printf("Suhu dalam Fahrenheit: %.2f °F\n", fahrenheit);

    tampilkanKelvin(celsius);

    return 0;
}