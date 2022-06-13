/*
 ============================================================================
 Name        : Ejer1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
De una compra debes ingresar una cantidad indeterminada de cortes de carne vacuna,
validando los siguientes datos:

Nombre del corte, precio, peso en kilogramos, tipo(con hueso o sin hueso)
a)informar el peso total de la compra.
b)el nombre del corte más caro de los sin hueso.
c)el nombre del corte más liviano de los con hueso.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	char nombre;
	float precio;
	float precioMax;
	float peso;
	float pesoMin;
	float acumPeso = 0;
	char tipo;
	char nomCaroSinHueso = 0;
	char nomLivConHueso = 0;
	int flag = 0;
	int flagSinHueso = 0;
	int flagHueso = 0;

	setbuf(stdout, NULL);

	printf("Ingrese el peso: ");
	scanf("%f", peso);

	acumPeso = acumPeso + peso;

}
