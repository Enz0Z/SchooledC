#include "header.h"

#define arraysize 20

void exerciseTwo() {
    int array[arraysize];
    int tuHermana = 0;
    for (int i = 1; i < 21; i++) {
        printf("Ingrese un numero %d \n", i);
        scanf("%d", &array[i-1]);
        //printf("Numero insertado: %d \n", array_1[i-1]);
    }
    for (int i = 1; i < 21; i++) {
        tuHermana = tuHermana+array[i-1];
    }
    printf("Promedio Total: %d\n", tuHermana/20);
}
