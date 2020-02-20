//
//  Exercise9.c
//  SistElectrEmbebidos
//
//  Created by Enzo Giova on 03/04/2019.
//  Copyright © 2019 Enzo Giova. All rights reserved.
//

#include "header.h"

void exer9(void) {
    
    float m1, c1, m2, c2;
    float x1, y1, x2, y2;
    float dx, dy;
    float intersection_X, intersection_Y;

    // Linea 1
    printf("Linea 1 - X1: ");
    scanf("%f", &x1);
    
    printf("Linea 1 - Y1: ");
    scanf("%f", &y1);
    
    printf("Linea 1 - X2: ");
    scanf("%f", &x2);
    
    printf("Linea 1 - Y2: ");
    scanf("%f", &y2);
    
    dx = x2 - x1;
    dy = y2 - y1;
    m1 = dy / dx;
    c1 = y1 - m1 * x1;
    
    printf("\n");
    
    // Linea 2
    printf("Linea 2 - X1: ");
    scanf("%f", &x1);
    
    printf("Linea 2 - Y1: ");
    scanf("%f", &y1);
    
    printf("Linea 2 - X2: ");
    scanf("%f", &x2);
    
    printf("Linea 2 - Y2: ");
    scanf("%f", &y2);
    
    dx = x2 - x1;
    dy = y2 - y1;
    m2 = dy / dx;
    c2 = y1 - m2 * x1;
    
    printf("\n");
    
    printf("Ecuación de la Linea 1: Y = %.2fX %c %.2f\n", m1, (c1 < 0) ? ' ' : '+',  c1);
    printf("Ecuación de la Linea 2: Y = %.2fX %c %.2f\n", m2, (c2 < 0) ? ' ' : '+',  c2);
    
    if ((m1 - m2) == 0) {
        printf("No hay intersección entre las lineas.\n");
    } else {
        intersection_X = (c2 - c1) / (m1 - m2);
        intersection_Y = m1 * intersection_X + c1;
        printf("Punto de intersección: %.2f, %.2f\n", intersection_X, intersection_Y);
    }
}
