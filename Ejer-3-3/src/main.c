/*
 ============================================================================
 Name        : Ejer. 3-3: Crear una función que pida el ingreso de un entero
                          y lo retorne.
 Author      : Chistian Tignino
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int pedirNumero(void);

int main(void)
{
	setbuf(stdout, NULL);

    int numero;
	printf("\nNumero ingresado: %d", pedirNumero(numero));

	return EXIT_SUCCESS;
}

int pedirNumero(void)
{
    printf("Ingrese un numero: ");
	fflush(stdin);
	scanf("%d", &numero);
	return numero;
}



