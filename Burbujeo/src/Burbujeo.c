#include <stdio.h>
#include <stdlib.h>
#define TAM 100

void mostrarNumeros(int* lista, int tam);
int ordenarNumerosDesc(int* lista, int tam);
int ordenarNumerosDescPerformante(int* lista, int tam);
void inicializar(int* lista, int tam);

int main(void) {
	setbuf(stdout, NULL);

	int numeros[TAM]; //array de numeros
	int contador; //variable donde guardo el retorno de ordenar

	inicializar(numeros, TAM);
	printf("Array desordenado\n");
	mostrarNumeros(numeros, TAM); //muestro array desordenado
	printf("Array ordenado\n");
	contador = ordenarNumerosDescPerformante(numeros, TAM); //ordeno los numeros
	mostrarNumeros(numeros, TAM); //muestro array ordenado
	printf("Contador: %d", contador); //muestro la cantidad de iteraciones que hicieron falta para ordenar

	return EXIT_SUCCESS;
}

/**
 * @fn void mostrarNumeros(int*, int)
 * @brief Imprime en pantalla todos los elementos de un array
 *
 * @param lista El array del cual imprimiremos sus elementos
 * @param tam El tamaño del array
 */
void mostrarNumeros(int* lista, int tam)
{
	int i;
	for(i=0; i<tam; i++)
	{
		printf("Indice: %d - Valor: %d\n", i, lista[i]);
	}
}

/**
 * @fn int ordenarNumeros(int*, int)
 * @brief Ordena descendentemente todos los elementos de un array
 *
 * @param lista El array del cual imprimiremos sus elementos
 * @param tam El tamaño del array
 * @return Retorna la cantidad de iteraciones necesarias para ordenar el array
 */
int ordenarNumerosDesc(int* lista, int tam)
{
	int i;
	int j;
	int contador = 0;
	int aux;

	if(lista != NULL && tam > -1)
	{
		for(i=0; i<tam-1; i++)
		{
			for(j=i+1; j<tam; j++)
			{
				contador++;
				if(lista[i] < lista[j])
				{
					aux = lista[i];
					lista[i] = lista[j];
					lista[j] = aux;
				}
			}
		}
	}

	return contador;
}

int ordenarNumerosDescPerformante(int* lista, int tam)
{
	int i;
	int flagSwap;
	int contador = 0;
	int aux;
	int nuevoLimite;

	if(lista != NULL && tam > -1)
	{
		nuevoLimite = tam - 1;
		do{
			flagSwap = 0;
			for(i=0; i<nuevoLimite; i++)
			{
				contador++;
				if(lista[i] < lista[i+1])
				{
					aux = lista[i];
					lista[i] = lista[i+1];
					lista[i+1] = aux;
					flagSwap = 1;
				}
			}
			nuevoLimite--;
		}while(flagSwap);
	}

	return contador;
}

void inicializar(int* lista, int tam)
{
	int i;
	for(i=0; i<tam; i++)
	{
		lista[i] = 1;
	}
}

