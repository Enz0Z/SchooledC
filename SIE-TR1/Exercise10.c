//
//  Exercise10.c
//  SistElectrEmbebidos
//
//  Created by Enzo Giova on 22/05/2019.
//  Copyright © 2019 Enzo Giova. All rights reserved.
//

#include "header.h"

void exer10(void) {
    
    float valor_a = 4;
    float valor_b = 2;
    float valor_c = 9;
    float discriminante = 0;
    float x1 = 0;
    float x2 = 0;
    float xr = 0;
    float xi = 0;
        
    /* Ingreso de datos */
    
    printf("Ingrese un valor para A.\n");
    scanf("%f", &valor_a);
    printf("Ingrese un valor para B.\n");
    scanf("%f", &valor_b);
    printf("Ingrese un valor para C.\n");
    scanf("%f", &valor_c);
    printf("\n");
    
    /* Calculo de discriminante */
    
    discriminante = ((valor_b * valor_b) - (4 * valor_a * valor_c));
    printf("Valor Discriminante: %2.1f\n",discriminante);
    
    /* Condicionales */
    
    if (discriminante > 0.0) {
        x1 = (- valor_b + sqrt(discriminante)) / (2 * valor_a);
        x2 = (- valor_b - sqrt(discriminante)) / (2 * valor_a);
        printf("Las dos raices son reales y distintas.\n");
        printf("X1: %2.1f\n",x1);
        printf("X2: %2.1f\n",x2);
    } else if (discriminante == 0.0) {
        x1 = x2 = (- valor_b / 2 * valor_a);
        printf("Las dos raices son  reales e iguales.\n");
        printf("Raices: %2.1f\n",x1);
    } else if (discriminante < 0.0) {
        xr = (- valor_b / 2 * valor_a);
        xi = (sqrt(-discriminante) / 2 * valor_a);
        printf("Las dos raices son complejas conjugadas.\n");
        printf("Valor Real: %2.1f\n",xr);
        printf("Valor Imaginario: %2.1f\n",xi);
    }
    printf("\n");
}
