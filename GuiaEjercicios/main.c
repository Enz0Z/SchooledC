#include "header.h"

int main() {
    int variable = 0;
    printf("Numero del Ejercicio:\n");
    scanf("%d", &variable);
    if (variable == 1) {
        exerciseOne();
        restartProgram();
    } else if (variable == 2) {
        exerciseTwo();
        restartProgram();
    } else if (variable == 3) {
        exerciseThree();
        restartProgram();
    } else if (variable == 4) {
        exerciseFour();
        restartProgram();
    } else {
        createBlanks(1);
        printf("No me enseniaron a hacer eso todavia. ");
        restartProgram();
    }
    return 0;
}

void restartProgram() {
    createBlanks(5);
    //system("cls");
    main();
}
