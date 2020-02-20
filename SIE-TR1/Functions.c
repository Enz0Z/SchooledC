//
//  ExerciseA.c
//  SistElectrEmbebidos
//
//  Created by Enzo Giova on 16/05/2019.
//  Copyright © 2019 Enzo Giova. All rights reserved.
//

#include "header.h"

struct amigo {
    char *nombre;
    int edad;
};

int buscar_maximo(int vector[], int tamanio);
int buscar_minimo(int vector[], int tamanio);
int promedio(int vector[], int tamanio);

void matriz_suma(int matrizA[3][3], int matrizB[3][3]);
void matriz_escala(int matrizA[3][3], int escala);
void mostrarBits(int data);

int *bitSet(int *byte, int bit);
void bitClear(int *byte, int bit);

int mostrarDBrecord(struct amigo *a);
void ordenarAscendente(int vector[], int tamanio);
void ordenarDescendente(int vector[], int tamanio);
void buscarLineal(int vector[], int tamanio, int datoA);
void buscarBinary(int vector[], int tamanio, int datoA);
int buscarMostrarJugador(char nombre[], struct amigo a[5]);

void functions(void) {
    //clock_t start, end;
    
    /*int a[3][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}
    };
    
    int b[3][3] = {
        {10, 11, 12}, {13, 14, 15}, {16, 17, 18}
    };*/
    //int vector[] = {1, 50, 400, 12, 15, 23, 72, 37, 1000};
    int number = 15;
    *bitSet(&number, 6);
    //mostrarBits(returned);
    bitClear(&number, 1);
    //struct amigo newAmigo;
    //newAmigo.edad = 16;
    //int i = mostrarDBrecord(&newAmigo);
    //printf("Edad de un amigo ingresado es %d\n", i);
    
    /*int vector[1000000];
    for (int i = 0; i < 1000000; i++) {
        int newValue = rand();
        vector[i] = newValue;
        //printf("%d ", newValue);
    }
    //ordenarDescendente(vector, 9);
    
    start = clock();
    buscarBinary(vector, 999999, 23874972);
    end = clock();
    printf("Total time taken by CPU: %f\n", (double) (end - start) / CLOCKS_PER_SEC);
     */
    /*struct amigo amigos[5];
    
    struct amigo amigo1;
    amigo1.nombre = "Pepit";
    amigo1.edad = 16;
    amigos[0] = amigo1;
    
    struct amigo amigo2;
    amigo2.nombre = "Carlos";
    amigo2.edad = 18;
    amigos[1] = amigo2;
    
    struct amigo amigo3;
    amigo3.nombre = "Bonadio";
    amigo3.edad = 54;
    amigos[2] = amigo3;
    
    struct amigo amigo4;
    amigo4.nombre = "Juan";
    amigo4.edad = 24;
    amigos[3] = amigo4;
    
    struct amigo amigo5;
    amigo5.nombre = "Enzo";
    amigo5.edad = 19;
    amigos[4] = amigo5;
    
    int returned = buscarMostrarJugador("Bonaadio", amigos);
    if (returned == 0) {
        printf("No hemos encontrado a ese amigo en la lista.\n");
    } else {
        printf("Hemos encontrado a ese amigo en la lista y tiene %d años de edad.\n", returned);
    }*/
}

int buscar_maximo(int vector[], int tamanio) {
    int maxNumber = 0;
    for (int i = 0; i < tamanio; i++) {
        if (vector[i] > maxNumber) {
            maxNumber = vector[i];
        }
    }
    return maxNumber;
}

int buscar_minimo(int vector[], int tamanio) {
    int minNumber = vector[0];
    for (int i = 0; i < tamanio; i++) {
        if (vector[i] < minNumber) {
            minNumber = vector[i];
        }
    }
    return minNumber;
}

int promedio(int vector[], int tamanio) {
    int result = 0;
    for (int i = 0; i < tamanio; i++) {
        result = result + vector[i];
    }
    return result/tamanio;
}

void matriz_suma(int matrizA[3][3], int matrizB[3][3]) {
    int matrizC[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
            printf("matrizC[%d][%d] = %d\n", i, j, matrizC[i][j]);
        }
        printf("\n");
    }
}

void matriz_escala(int matrizA[3][3], int escala) {
    int matrizC[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrizC[i][j] = matrizA[i][j] * escala;
            printf("matrizC[%d][%d] = %d\n", i, j, matrizC[i][j]);
        }
        printf("\n");
    }
}

void mostrarBits(int data) {
    printf("%d in bits is ", data);
    for (int i = 31; i >= 0; i--) {
        int k = data >> i;
        if (k & 1) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

//set: x |= (1 << bit);

//clear: x &= ~(1 << bit);

//toggle: x ^= (1 << bit);

int *bitSet(int *byte, int bit) {
    mostrarBits(*byte);
    *byte |= (1 << bit);
    mostrarBits(*byte);
    return byte;
}

void bitClear(int *byte, int bit) {
    mostrarBits(*byte);
    *byte &= ~(1 << bit);
    mostrarBits(*byte);
}

int mostrarDBrecord(struct amigo *a) {
    return a -> edad;
}

void ordenarAscendente(int vector[], int tamanio) {
    int temp = 0;
    for (int i = 0; i < tamanio; i++) {
        if (i == 0) printf("Ingresado: ");
        printf("%d ", vector[i]);
        if (i == tamanio - 1) printf("\n");
    }
    for (int i = 0; i < tamanio; i++) {
        for (int j = 0; j < tamanio - 1; j++) {
            if (vector[j] > vector[j + 1]) {
                temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < tamanio; i++) {
        if (i == 0) printf("Ascendente: ");
        printf("%d ", vector[i]);
        if (i == tamanio - 1) printf("\n");
    }
    
}

void ordenarDescendente(int vector[], int tamanio) {
    int temp = 0;
    for (int i = 0; i < tamanio; i++) {
        if (i == 0) printf("Ingresado: ");
        printf("%d ", vector[i]);
        if (i == tamanio - 1) printf("\n");
    }
    for (int i = 0; i < tamanio; i++) {
        for (int j = 0; j < tamanio - 1; j++) {
            if (vector[j] < vector[j + 1]) {
                temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < tamanio; i++) {
        if (i == 0) printf("Descendente: ");
        printf("%d ", vector[i]);
        if (i == tamanio - 1) printf("\n");
    }
}

void buscarLineal(int vector[], int tamanio, int datoA) {
    for (int i = 0; i < tamanio; i++) {
        if (vector[i] == datoA) {
            printf("Dato encontrado: %d\n", datoA);
            return;
        }
    }
    printf("Dato no encontrado en el vector.\n");
}

void buscarBinary(int vector[], int tamanio, int datoA) {
    for (int i = 0; i < tamanio; i++) {
        if (vector[i] == datoA || vector[tamanio - i] == datoA) {
            printf("Dato encontrado: %d\n", datoA);
            return;
        }
    }
    printf("Dato no encontrado en el vector.\n");
}

int buscarMostrarJugador(char *nombre, struct amigo a[5]) {
    for (int i = 0; i < 5; i++) {
        if (a[i].nombre == nombre) {
            return a[i].edad;
        }
    }
    return 0;
}
