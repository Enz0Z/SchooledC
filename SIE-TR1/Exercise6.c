#include "header.h"

void exer6(void) {
    
    float insertedNumber = -1;
    float maxNumber = 0;
    float minNumber = 0;
    
    while (1) {
        //printf("%f", minNumber);
        printf("Ingrese un numero.\n");
        scanf("%f", &insertedNumber);
        if (insertedNumber == 0) {
            break;
        } else {
                    if (maxNumber == 0 && minNumber == 0) {
                        maxNumber = insertedNumber;
                        minNumber = insertedNumber;
                    } else {
                                if (insertedNumber > maxNumber)
                                {
                                    maxNumber = insertedNumber;
                                
                                } else if (insertedNumber < minNumber) {
                            
                                                minNumber = insertedNumber;
                                            }
                            }
                }
    }
    
    printf("Máximo Valor: %3.3f \n", maxNumber);
    printf("Minimo Valor: %3.3f \n", minNumber);
}
