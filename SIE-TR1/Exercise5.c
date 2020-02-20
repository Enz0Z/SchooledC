//
//  ExerciseFive.c
//  SistElectrEmbebidos
//
//  Created by Enzo Giova on 22/03/2019.
//  Copyright © 2019 Enzo Giova. All rights reserved.
//

#include "header.h"

void exer5(void) {
    
    float temp = 0;
    float average = 0;
    int numbers = 0;
    
    for (int i = 1; i < 11; i++) {
        printf("Ingrese un numero valor de temperatura %d \n", i);
        scanf("%f", &temp);
        if (temp >= 5 && temp <= 15) {
            average += temp;
            numbers++;
        }
    }
    printf("Promedio: %3.3f\n", average/numbers);
}
