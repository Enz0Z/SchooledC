#include "header.h"

void exer1(void) {
    
    int numberOne;
    int numberTwo;
    int numberThree;
    
    printf("Ingrese el primer numero\n");
    scanf("%d", &numberOne);
    
    printf("Ingrese el segundo numero\n");
    scanf("%d", &numberTwo);
    
    printf("Ingrese el tercer numero\n");
    scanf("%d", &numberThree);
    
    int numberTotal = (numberOne + numberTwo + numberThree)/3;
    printf("Promedio Total: %d\n", numberTotal);
}
