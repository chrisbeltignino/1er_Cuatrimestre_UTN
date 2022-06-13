/*
 ============================================================================
 Name        : Promedio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    int num3;
    int num4;
    int num5;

    float promedio;

    setbuf(stdout, NULL);
    printf("Ingrese primer numero: ");
    scanf("%d", &num1);
    printf("Ingrese segundo numero: ");
    scanf("%d", &num2);
	printf("Ingrese tercer numero: ");
	scanf("%d", &num3);
	printf("Ingrese cuarto numero: ");
	scanf("%d", &num4);
	printf("Ingrese quinto numero: ");
	scanf("%d", &num5);

    promedio = (num1 + num2 + num3 + num4 + num5) / 5;

    printf("El promedio de los 5 numeros es %.2f\n", promedio);

    return 0;
}
