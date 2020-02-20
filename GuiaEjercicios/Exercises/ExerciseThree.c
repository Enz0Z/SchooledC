#include "header.h"

#define arraysize 9999

void exerciseThree() {
    int array[arraysize];
    int arrayused = 0;
    int numberTotal = 0;
    for (int i = 1; i < arraysize; i++) {
        printf("Ingrese un numero %d \n", i);
        scanf("%d", &array[i-1]);
        arrayused++;
        if (array[i-1] == 0) {
            break;
        }
    }
    for (int i = 1; i < arrayused; i++) {
        numberTotal = numberTotal+array[i-1];
    }
    printf("Promedio Total: %d\n", numberTotal/arrayused);
}
