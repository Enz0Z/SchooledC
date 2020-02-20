//
//  Exercise8.c
//  SistElectrEmbebidos
//
//  Created by Enzo Giova on 03/04/2019.
//  Copyright © 2019 Enzo Giova. All rights reserved.
//

#include "header.h"

void exer8(void) {
    
    bool listening = false;
    float insertedNumber = 0;
    float minValue = 1000;
    
    int countListened = 0;
    int countBetween = 0;
    float averageBetween = 0;
    
    
    printf("Al terminar el programa, debe insertar un -100.\n");
    
    while (1) {
        printf("Ingrese un valor\n");
        scanf("%f", &insertedNumber);
        if (insertedNumber != -100) {
            if (listening == true) {
                countListened++;
            }
            if (listening == false && insertedNumber == 8) {
                listening = true;
            }
            if (insertedNumber < minValue) {
                minValue = insertedNumber;
            }
            if (insertedNumber >= 9 && insertedNumber <= 18) {
                countBetween++;
                averageBetween += insertedNumber;
            }
        } else {
            break;
        }
    }
    
    if (listening == true) {
        printf("Cantidad de numeros posteriores: %d\n", countListened);
    }
    printf("Minimo Valor: %3.3f\n", minValue);
    printf("Promedio entre Valores entre 9C y 18C: %3.3f\n", averageBetween/countBetween);
}
