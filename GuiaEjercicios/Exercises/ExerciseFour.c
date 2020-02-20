#include "header.h"

#define arraysize 10

void exerciseFour() {
    int array[arraysize];
    int numbersPositive = 0;
    int numbersNegative = 0;
    int numbersCero = 0;
    for (int i = 1; i < 11; i++) {
        printf("Ingrese un numero positivo o negativo %d \n", i);
        scanf("%d", &array[i-1]);
        //printf("Numero insertado: %d \n", array_1[i-1]);
    }
    for (int i = 1; i < 11; i++) {
        if (array[i-1] > 0) {
            numbersPositive++;
        } else if (array[i-1] < 0) {
            numbersNegative++;
        } else if (array[i-1] == 0) {
            numbersCero++;
        }
    }
    printf("Numeros Negativos: %d\n", numbersNegative);
    printf("Numeros Positivos: %d\n", numbersPositive);
    printf("Numeros Igual a Cero: %d\n", numbersCero);
}
