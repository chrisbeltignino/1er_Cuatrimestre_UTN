#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void) {
	setbuf(stdout, NULL);

	int numeros[TAM];
	int suma;
	int maximo;
	int indice;
	recorrerNumeros(numeros, TAM);
	inicializarElementos(numeros, TAM);
	recorrerNumeros(numeros, TAM);
	cargarNumeros(numeros, TAM);
	recorrerNumeros(numeros, TAM);
	sumarNumeros(numeros, TAM, &suma);
	printf("La suma es %d\n", suma);
	sacarMaximo(numeros, TAM, &maximo);
	printf("El maximo es %d\n", maximo);
	if(obtenerIndex(numeros, TAM, 5, &indice) == 0)
	{
		printf("El indice del numero buscado es %d\n", indice);
	}
	else
	{
		printf("Ese numero no se encuentra en el array\n");
	}

	return EXIT_SUCCESS;
}
