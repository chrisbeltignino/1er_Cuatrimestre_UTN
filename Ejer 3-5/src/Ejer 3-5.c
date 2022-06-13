/*
 ============================================================================
 Name        : Ejer.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

int Sumar1(int num1, int num2);
int Sumar2(void);
void Sumar3(int num1, int num2);
void Sumar4(void);


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int num1;
	int num2;
	int result1;
	int result2;

	printf("Ingrese primer numero: ");
	scanf("%d", &num1);
	printf("Ingrese segundo numero: ");
	scanf("%d", &num2);

	result1 = Sumar1(num1, num2);
	printf("El resultado 1 es: %d\n", result1);

	result2 = Sumar2(num1, num2);
	printf("El resultado 2 es: %d\n", result2);

	Sumar3(num1, num2);

	Sumar4();
}

int Sumar1(int num1, int num2){
	int resultado;
	resultado = num1 + num2;
	return resultado;
}

int Sumar2(void){
	int num1;
	int num2;
	int resultado;

	printf("Ingrese primer numero: ");
	scanf("%d", &num1);
	printf("Ingrese segundo numero: ");
	scanf("%d", &num2);

	resultado = num1 + num2;
	return resultado;
}

void Sumar3(int num1, int num2){
	int resultado;
	resultado = num1 + num2;
	printf("El resultado 3 es: %d\n", resultado);
}

void Sumar4(void){
	int num1;
	int num2;
	int resultado;

	printf("Ingrese primer numero: ");
	scanf("%d", &num1);
	printf("Ingrese segundo numero: ");
	scanf("%d", &num2);

	resultado = num1 + num2;
	printf("El resultado 4 es: %d\n", resultado);
}

