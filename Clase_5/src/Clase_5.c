/*
 ============================================================================
 Name        : Clase05.c
 Author      : alancio
 Version     :
 Copyright   : anda a saber no
 Description : arrays bro
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main(void) {
	setbuf(stdout, NULL);

	//tipo nombre[tamaño];
	int numeros[TAM];
	int i;
	int acumulador = 0;
	int maximo;
	//char seguir = 's';
	//int posicion;

	//Carga secuencial
	for(i=0; i<TAM; i++)
	{
		printf("%d - Ingrese un numero: ", i+1);
		fflush(stdin);
		scanf("%d", &numeros[i]);
	}

	//Sumar elementos de un array
	for(i=0; i<TAM; i++)
	{
		acumulador = acumulador + numeros[i];
		//acumulador += numeros[i];
	}

	printf("%d\n", acumulador);

	for(i=0; i<TAM; i++)
	{
		//Pro
		if(i == 0 || numeros[i] > maximo)
		{
			maximo = numeros[i];
		}

		//Ingreso jeje
		/*if(i == 0)
		{
			maximo = numeros[i];
		}
		else
		{
			if(numeros[i] > maximo)
			{
				maximo = numeros[i];
			}
		}*/
	}

	printf("El maximo es %d", maximo);

	//Inicializar elementos de array
	/*for(i=0; i<TAM; i++)
	{
		numeros[i] = -1;
	}*/

	//Carga aleatoria
	/*do{
		printf("Ingrese la posicion (1-5): ");
		fflush(stdin);
		scanf("%d", &posicion);
		printf("Ingrese un numero positivo: ");
		fflush(stdin);
		scanf("%d", &numeros[posicion-1]);
		printf("Quiere continuar? (s para continuar) ");
		fflush(stdin);
		scanf("%c", &seguir);
	}while(seguir == 's');*/

	printf("\n");

	//Recorrer array
	for(i=0; i<TAM; i++)
	{
		if(numeros[i] != -1)
		{
			printf("Indice: %d - Valor: %d\n", i, numeros[i]);
		}
	}

	return EXIT_SUCCESS;
}

