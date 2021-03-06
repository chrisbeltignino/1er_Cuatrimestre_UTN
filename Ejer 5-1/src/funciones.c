#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int mostrarOpciones(int opcion)
{
	printf( "1 Cargar numeros\n");
	printf( "2 Mostar todo\n");
	printf( "3 Mostrar negativos\n");
	printf( "4 Mostrar promedio positivos\n");
	printf( "5 Mostrar Maximo\n");
	printf( "6 Mostrar Minimo\n");
	printf( "7 Salir\n");
	printf("Elija una opcion: ");
	fflush(stdin);
	scanf("%d",&opcion);
	return opcion;
}

int pedirNumero(char mensaje[], char mensajeError[], int min, int max)
{
    int numero;
    printf("%s", mensaje);
	scanf("%d", &numero);
	while(numero < min || numero > max)
	{
		printf("%s", mensajeError);
		fflush(stdin);
		scanf("%d", &numero);
	}
    return numero;
}

void cargarVector(int vector[],int tam)
{
    int i;
    printf("\tCARGA DE DATOS\n");
    for(i=0; i<tam; i++)
    {
    	vector[i] = pedirNumero("Ingrese un numero (-1000 a 1000): ", "ERROR. Ingrese un numero nuevamente: ",-1000,1000);
    }
}

void mostrarVector(int vector[],int tam)
{
    int i;
    printf("\tMUESTRO EL VECTOR\n");
	for(i=0; i<tam; i++)
	{
		printf("%d\n", vector[i]);
	}
}

void mostrarNegativos(int vector[],int tam)
{
	int i;
	printf("\n\n\tMUESTRO SOLO LOS NEGATIVOS\n");
	for(i=0; i<tam; i++)
	{
		if(vector[i]<0)
		{
			printf("%d\n", vector[i]);
		}
	}
}

void mostrarPromedio(int vector[],int tam)
{
    int i;
    float promedioPositivos;
    int sumaDePositivos=0;
    int contadorDePositivos=0;
    for(i=0; i<tam; i++)
    {
    	if(vector[i]>0)
    	{
    		sumaDePositivos += vector[i];
    		contadorDePositivos++;
    	}
    }
	promedioPositivos = (float)sumaDePositivos/contadorDePositivos;
	printf("Suma: %d -- Cantidad %d\n\n", sumaDePositivos, contadorDePositivos);
	printf("\n\nPROMEDIO DE POSITIVOS: %.2f\n\n", promedioPositivos);
}

void mostrarMaximo(int vector[],int tam)
{
	int i;
	int maximo;

	maximo=calcularMaximo(vector,tam);
	printf("EL MAXIMO: %d\n", maximo);
	for(i=0; i<tam; i++)
	{
		if(vector[i]==maximo)
		{
			printf("%d-",i);
		}
	}
}

void mostrarMinimo(int vector[],int tam)
{
    int i;
    int minimo;
    minimo=calcularMinimo(vector,tam);
    printf("EL MINIMO: %d\n",minimo);
    for(i=0; i<tam; i++)
    {
    	if(vector[i]==minimo)
    	{
    		printf("%d-",i);
        }
    }
}

int calcularMaximo(int vector[],int tam)
{
    int i;
    int flag=0;
    int maximo;
    for(i=0; i<tam; i++)
	{
		if(flag==0||vector[i]>maximo)
		{
			maximo=vector[i];
		}
		flag=1;
	}
    return maximo;
}

int calcularMinimo(int vector[],int tam)
{
    int minimo;
    int i;
    int flag=0;
	for(i=0; i<tam; i++)
	{
		if(flag==0||vector[i]<minimo)
		{
			minimo=vector[i];
		}
		flag=1;
	}
	return minimo;
}

void ordenarVector(int vector[],int tam) /** le burbuja metodo (ordenamiento)*/
{
    int aux;   /** para el swap  c = a || a = b || b = c (las diagonales!!) */
    int i;
    int j;
    for(i=0;i<tam-1;i++)  /** mecanica para mover elementos dentro del vector*/
    {
        for(j=i+1;i<tam;j++)
        {
            if(vector[i]>vector[j]) /** criterio de ordenamiento*/
            {
                aux=vector[i];
                vector[i]=vector[j];
                vector[j]=aux;
            }
        }
    }
}
