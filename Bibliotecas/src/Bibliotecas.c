/*
 ============================================================================
 Name        : Bibliotecas.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void)
{
	setbuf(stdout, NULL);
	int numero = pedirNumeroEntero("Ingrese un numero: ", "Reingrese numero: ", MINIMO, 10);

	printf("Valor dentro de Main: %d - %p", numero, &numero);

	modificar(&numero);

	printf("\nValor dentro de Main modificado: %d - %p", numero, &numero);

	return EXIT_SUCCESS;
}
