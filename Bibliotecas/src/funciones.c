/*
 * funciones.c
 *
 *  Created on: 3 sep. 2021
 *      Author: 54115
 */

#include "funciones.h"

int pedirNumeroEntero(char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int numeroIngresado;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &numeroIngresado);

	while(numeroIngresado < minimo || numeroIngresado > maximo)
	{
		printf("%s", mensajeError);
		fflush(stdin);
		scanf("%d", &numeroIngresado);
	}
//	do{
//		printf("%s", mensaje);
//		fflush(stdin);
//		scanf("%d", &numeroIngresado);
//	}while(numeroIngresado < minimo || numeroIngresado > maximo);

	return numeroIngresado;
}

void modificar(int* numero)
{
	*numero = 7;
	printf("\nValor dentro de Modificar: %d - %p", *numero, &numero);
}

