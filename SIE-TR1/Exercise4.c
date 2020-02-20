#include "header.h"

void exer4(void) {
    
    int insertedNumber = 0;
    int numbersPositive = 0;
    int numbersNegative = 0;
    int numbersCero = 0;
    
    for (int i = 1; i < 11; i++) {
        
        printf("Ingrese un numero positivo o negativo %d \n", i);
        scanf("%d", &insertedNumber);
        
        if (insertedNumber > 0) {
            numbersPositive++;
        } else if (insertedNumber < 0) {
            numbersNegative++;
        } else if (insertedNumber == 0) {
            numbersCero++;
        }
    }
    
    printf("Cant. de Numeros Negativos: %d\n", numbersNegative);
    printf("Cant. de Numeros Positivos: %d\n", numbersPositive);
    printf("Cant. de Numeros Cero: %d\n", numbersCero);
}
