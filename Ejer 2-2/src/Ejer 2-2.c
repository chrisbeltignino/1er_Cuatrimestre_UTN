/*
 ============================================================================
 Name        : Ejer.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Ingresar 10 números enteros, distintos de cero. Mostrar:
				Cantidad de pares e impares.
				El menor número ingresado.
				De los pares el mayor número ingresado.
				Suma de los positivos.
				Producto de los negativos.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);

	int i;
	int numIngre;
	int contador = 0;
	int contPar;
	int contPositivo;
	int contNeg;
	int acumPar;
	int acumPositivo;
	int acumNeg;
	int cantImpar;
	int cantParImpar;
	int numMenor;
	int mayorPar;
	int sumPositivo;
	int productoNeg = 0;
	int contGrupo1;
	int contGrupo2;

	for(i=0; i<10; i++)
	{
		if(numIngre%2 == 0)
		{
			contPar++;
		}

		if(numIngre > mayorPar || i == 0)
		{
			numIngre = mayorPar;
		}

		if(numIngre < 0)
		{
			contPositivo++;
			acumPositivo+=numIngre;
			if(numIngre < 11)
			{
				contGrupo1++;
			}
			else{
				if(numIngre < 21)
				{
					contGrupo2++;
				}
			}
		}
		else{
			contNeg++;
			if(numIngre < numMenor || contNeg == 1)
			{
				numMenor = numIngre;
			}
		}
	}
	/*
	 * int main()
{
    int contador=0;
    int numeroIngresado;
    int cantidadPares=0;
    int cantidadImpares=0;
    int menorIngresado;
    int mayorPares;
    int sumaPositivos=0;
    int productoNegativos=1;
    short int i;
    float promedio;

    for(i=0; i<10; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numeroIngresado);

        if(numeroIngresado%2 == 0)
        {
            cantidadPares = cantidadPares + 1;
            if(numeroIngresado > mayorPares || i==0)
            {
                mayorPares = numeroIngresado;
            }
        }
        else
        {
            cantidadImpares = cantidadImpares + 1;
        }

        if(numeroIngresado < menorIngresado || i==0)
        {
            menorIngresado = numeroIngresado;
        }

        if(numeroIngresado > 0)
        {
            sumaPositivos = sumaPositivos + numeroIngresado;
        }
        else
        {
            productoNegativos = productoNegativos * numeroIngresado;
        }

    }

    printf("La cantidad de pares es de %d, la cantidad de impares es de %d, El mayor de los pares es %d, la suma de positivos da como resultado %d, el producto de los negativos es %d", cantidadPares, cantidadImpares, mayorPares, sumaPositivos, productoNegativos);

    return 0;
}
	 */

}
