//
//  LastExercise.c
//  SistElectrEmbebidos
//
//  Created by Enzo Giova on 05/06/2019.
//  Copyright © 2019 Enzo Giova. All rights reserved.
//

#include "header.h"

typedef struct Sensores {
    char name[32];
    int priority;
} Sensor;

int kbEntered;
int sensorsCount = 0;
Sensor sensores[100];

void showMenu(void);
void conectar(void);
void eliminar(void);
void modificar(void);
void visualidar(void);
int getPositionByName(char name[32]);

void lastExer(void) {
    showMenu();
}

void showMenu(void) {
    printf("\n1_Conectar (Alta) Sensor\n");
    printf("2_Eliminar (Baja) Sensor\n");
    printf("3_Modificar Sensor\n");
    printf("4_Visualizar Sensores\n");
    printf("5_Salir\n\n");
    printf("Ingrese una opción: ");
    scanf("%d", &kbEntered);
    switch (kbEntered) {
        case 1:
            conectar();
            break;
        case 2:
            eliminar();
            break;
        case 3:
            modificar();
            break;
        case 4:
            visualidar();
            break;
        case 5:
            printf("Cerrando el programa!\n");
            return;
        default:
            showMenu();
    }
}

void conectar(void) {
    Sensor newSensor;
    printf("Conectar un nuevo sensor:\n");
    scanf("%s", newSensor.name);
    scanf("%d", &newSensor.priority);
    while (newSensor.priority > 10 || newSensor.priority < 1) {
        printf("El numero debe ser entre 1 a 10.\n");
        scanf("%d", &newSensor.priority);
    }
    printf("Agregado el %s con prioridad %d.\n", newSensor.name, newSensor.priority);
    sensores[sensorsCount] = newSensor;
    sensorsCount++;
    showMenu();
}

void eliminar(void) {
    printf("Para eliminar, debe elegir uno mediante el nombre:\n");
    Sensor newSensores[100];
    char selected[32];
    while (true) {
        scanf("%s", selected);
        int position = getPositionByName(selected);
        if (position == -1) {
            printf("%s no se ha encontrado.\n", selected);
        } else {
            int newCount = 0;
            for (int i = 0; i < sensorsCount; i++) {
                Sensor newSensor = sensores[i];
                if (position != i) {
                    Sensor sensorAdd;
                    *sensorAdd.name = *newSensor.name;
                    sensorAdd.priority = newSensor.priority;
                    newSensores[newCount] = sensorAdd;
                    newCount++;
                }
            }
            sensorsCount = newCount;
            break;
        }
    }
    showMenu();
}

void modificar(void) {
    printf("Modificar un sensor, debe ingresar el nombre del sensor:\n");
    char selected[32];
    bool founded = false;
    int where = 0;
    while (!founded) {
        scanf("%s", selected);
        int position = getPositionByName(selected);
        if (position == -1) {
            printf("%s no se ha encontrado.\n", selected);
        } else {
            founded = true;
            where = position;
        }
    }
    
    Sensor newSensor;
    printf("Nuevo nombre: ");
    scanf("%s", newSensor.name);
    printf("Nueva prioridad: ");
    scanf("%d", &newSensor.priority);
    while (newSensor.priority > 10 || newSensor.priority < 1) {
        printf("El numero debe ser entre 1 a 10.\n");
        scanf("%d", &newSensor.priority);
    }
    printf("Modificado el %s con prioridad %d.\n", newSensor.name, newSensor.priority);
    sensores[where] = newSensor;
    showMenu();
}

void visualidar(void) {
    clock_t start_time = clock();
    int times = 0;
    while (true) {
        if (clock() > start_time + 1000000) {
            if (times > 10) break;
            printf("\nNombreSensor    Medicion    Unidad    Prioridad\n");
            for (int i = 0; i < sensorsCount; i++) {
                Sensor newSensor = sensores[i];
                printf("%s    %d    A    %d\n", newSensor.name, rand() % (0 - 5 + 1) + 5, newSensor.priority);
            }
            start_time = clock();
            times++;
        }
    }
    showMenu();
}


int getPositionByName(char searchedname[32]) {
    for (int i = 0; i < sensorsCount; i++) {
        Sensor newSensor = sensores[i];
        if (strcmp(newSensor.name, searchedname) == 0) {
            return i;
        }
    }
    return -1;
}
