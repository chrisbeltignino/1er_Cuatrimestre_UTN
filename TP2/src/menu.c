#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassanger.h"
#include "outputs.h"
#include "inputs.h"

void menu()
{
	setbuf(stdout, NULL);
    int opcion;
    int flag = 0;

    Passenger list[MAX];
    Type typeP[TY] = {{1,"Turistica"},{2,"Economica"},{3,"Business"},{4,"Primera clase"}};
    Status status[TS] = {{1,"Activo"},{2,"Inactivo"},{3,"Demora"}};

    initPassengers(list, MAX);
    do
    {
    	mostrarMenu(&opcion);
        switch(opcion)
        {
            case 1:
            	altaPasajeros(list, MAX, typeP, status, &flag);
                break;
            case 2:
            	modificarPasajeros(list, MAX, typeP, status, &flag);
            break;
            case 3:
            	bajaPasajeros(list, MAX, typeP, status, &flag);
            break;
            case 4:
            	mostrarPasajeros(list, MAX, typeP, status, &flag);
            break;
            case 5:
            	cargaForzada(list, MAX, &flag);
            break;
            case 6:
            	limpiarConsola();
            	printf("Saliendo...\n");
            break;

            default:
            	limpiarConsola();
                printf("Ingrese una opcion valida\n");
        }
    }while(opcion!=6);
}

