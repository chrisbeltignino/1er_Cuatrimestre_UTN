/*
 ========================================================================================================================
 Name        : Ejer 1-3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : ingresar 3 números y mostrar el número del medio, sólo si existe. En caso de que no exista también informarlo.
 ========================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	setbuf(stdout, NULL);

	int n1;
	int n2;
	int n3;

	printf("Introduzca el primer numero (entero): ");
	fflush(stdin);
	scanf("%d", &n1);
	printf("Introduzca el segundo numero (entero): ");
	fflush(stdin);
	scanf("%d", &n2);
	printf("Introduzca el tercer numero (entero): ");
	fflush(stdin);
	scanf("%d", &n3);

	if (n1 != n2 && n1 != n3 && n2 != n3)
	{
		if ((n1 > n2 && n1 < n3) || (n1 < n2 && n1 > n3))
		{
			printf("El numero medio es: %d", n1);
		}
		else{
			if ((n2 > n1 && n2 < n3) || (n2 < n1 && n2 > n3))
			{
				printf("El numero medio es: %d", n2);
			}
			else{
				if ((n3 > n1 && n3 < n2) || (n3 < n1 && n3 > n2))
				{
					printf("El numero medio es: %d", n3);
				}
			}
		}
	}
	else{
		printf("No se encuentra numero intermedio");
	}
	return 0;
}
