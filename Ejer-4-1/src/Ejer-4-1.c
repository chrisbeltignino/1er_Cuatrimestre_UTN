/*
 ============================================================================
 Name        : Ejer-4-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int pedirEntero(void);

int main(void)
{
	setbuf(stdout, NULL);

	int x;
	int numero;
	int factorial = 1;

	numero = pedirEntero();

	for (x = numero; x > 1; x--)
	{
		factorial *= x;
		printf("%d x ", x);
	}

	printf("1 = %d\n\n", factorial);
	system("pause");

    return 0;
}

int pedirEntero(void)
{
    int numeroIngresado;

    printf("Ingrese un numero entero: ");
    scanf("%d",&numeroIngresado);

    while(numeroIngresado < 1)
    {
        printf("ERROR, intentelo nuevamente: ");
        scanf("%d",&numeroIngresado);
    }

    return numeroIngresado;
}
