/*
 ============================================================================
 Name        : Modificar.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void modificar(int numero);

int main(void)
{
	int numero = 10;

	printf("Valor dentro de Main: %d - %d", numero, &numero);

	modificar(numero);

	printf("\nValor dentro de Main modificado: %d - %d", numero, &numero);

	return EXIT_SUCCESS;
}

void modificar(int numero)
{
	numero = 7;
	printf("\nValor dentro de Modificar: %d - %d", numero, &numero);
}

