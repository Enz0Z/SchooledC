#include "header.h"

void exer2(void) {
    
    int arrayNumbers[20];
    int totalCount = 0;
    
    for (int i = 1; i < 21; i++) {
        printf("Ingrese un numero %d \n", i);
        scanf("%d", &arrayNumbers[i - 1]);
        //printf("DEBUG: Numero insertado: %d \n", arrayNumbers[i - 1]);
    }
    
    for (int i = 1; i < 21; i++) {
        totalCount = totalCount + arrayNumbers[i - 1];
    }
    
    printf("Promedio Total: %d\n", totalCount/20);
}
