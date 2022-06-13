#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int cargarNumeros(int* array, int tam)
{
	int retorno = -1;
	int i;

	for(i=0; i<tam; i++)
	{
		printf("%d - Ingrese un numero: ", i+1);
		fflush(stdin);
		scanf("%d", &array[i]);
		retorno = 0;
	}

	return retorno;
}

int recorrerNumeros(int* array, int tam)
{
	int retorno = -1;
	int i;
	for(i=0; i<tam; i++)
	{
		printf("Indice: %d - Valor: %d\n", i, array[i]);
	}
	retorno = 0;
	return retorno;
}

int inicializarElementos(int* array, int tam)
{
	int retorno = -1;
	int i;
	for(i=0; i<tam; i++)
	{
		array[i] = -1;
	}
	retorno = 0;
	return retorno;
}

int sumarNumeros(int* array, int tam, int* suma)
{
	int retorno = -1;
	int i;
	int acumulador = 0;
	for(i=0; i<tam; i++)
	{
		acumulador = acumulador + array[i];
		//acumulador += numeros[i];
	}
	*suma = acumulador;
	retorno = 0;
	return retorno;
}

int sacarMaximo(int* array, int tam, int* maximo)
{
	int retorno = -1;
	int i;
	int max;
	for(i=0; i<tam; i++)
	{
		if(i == 0 || array[i] > max)
		{
			max = array[i];
			retorno = 0;
		}
	}
	*maximo = max;
	return retorno;
}

int obtenerIndex(int* array, int tam, int numero, int* index)
{
	int retorno = -1;
	int i;
	int indiceEncontrado = -1;
	for(i=0; i<tam; i++)
	{
		if(array[i] == numero)
		{
			indiceEncontrado = i;
			retorno = 0;
			break;
		}
	}
	*index = indiceEncontrado;
	return retorno;
}
