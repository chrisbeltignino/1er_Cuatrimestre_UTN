/*
 ============================================================================
 Name        : 3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int pedirNumeroEntero(char* mensaje, char* mensajeError, int minimo, int maximo);

int main(void) {
	setbuf(stdout, NULL);

	int dni;
	int edad;

	dni = pedirNumeroEntero("Ingrese su DNI (10000000-42000000): ", "Error, reingrese su DNI (10000000-47000000): ", 10000000, 47000000);
	edad = pedirNumeroEntero("Ingrese su edad (1-120): ", "Error, reingrese su edad (1-120): ", 1, 120);

	printf("DNI: %d - Edad: %d", dni, edad);

	return EXIT_SUCCESS;
}

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


