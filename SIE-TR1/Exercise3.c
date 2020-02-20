#include "header.h"

void exer3(void) {
    
    //int arrayNumbers[100]; int numbers = 0; y sumar todo directamente. Para no usar Vectores
    float numbers = 0;
    float insertedNumber = -1;
    int numberTotal = 0;
    
    while (1) {
        printf("Ingrese un numero\n");
        scanf("%f", &insertedNumber);
        if (insertedNumber != 0) {
            numbers += insertedNumber;
            // numbers = numbers + insertedNumbers;
            numberTotal++;
        } else {
            break;
        }
    }
    
    printf("Promedio Total: %f\n", numbers/numberTotal);
}
