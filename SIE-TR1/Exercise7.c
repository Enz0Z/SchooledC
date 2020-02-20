//
//  ExerciseSeven.c
//  SistElectrEmbebidos
//
//  Created by Enzo Giova on 03/04/2019.
//  Copyright © 2019 Enzo Giova. All rights reserved.
//

#include "header.h"

void exer7(void) {
    
    int countMeasures = 0;
    float insertedNumber = 0;
    float maxValue = 0;
    
    int countBetween = 0;
    float averageBetween = 0;
    
    while (1) {
        printf("Ingrese un valor\n");
        scanf("%f", &insertedNumber);
        if (insertedNumber != -100) {
            countMeasures++;
            if (insertedNumber > maxValue) {
                maxValue = insertedNumber;
            }
            if (insertedNumber >= 10 && insertedNumber <= 30) {
                countBetween++;
                averageBetween += insertedNumber;
            }
        } else {
            break;
        }
    }
    
    printf("Cantidad de Mediciones: %d\n", countMeasures);
    printf("Máximo Valor: %3.3f\n", maxValue);
    printf("Promedio entre Valores entre 10C y 30C: %3.3f\n", averageBetween/countBetween);
}
