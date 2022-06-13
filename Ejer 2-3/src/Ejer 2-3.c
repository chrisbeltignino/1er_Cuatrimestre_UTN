/*
 ============================================================================
Ejercicio 2-3:
Debemos alquilar el servicio de transporte para llegar a Mar del Plata con un grupo de personas, de cada persona debemos obtener los siguientes datos:
número de cliente, estado civil ('s' para soltero", 'c' para casado o 'v' viudo),
edad( solo mayores de edad, más de 17), temperatura corporal (validar por favor)
y genero('f' para femenino, 'm' para masculino, 'o' para no binario).

NOTA: El precio por pasajero es de $600.

Se debe informar (solo si corresponde):
a) La cantidad de personas con estado "viudo" de más de 60 años.
b) el número de cliente y edad de la mujer soltera más joven.
c) cuánto sale el viaje total sin descuento.
d) si hay más del 50% de los pasajeros que tiene más de 60 años , el precio final tiene un descuento del 25%, que solo mostramos si corresponde.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int id;
	char estadoCivil;
	int edad;
	float temperatura;
	char genero;
	char respuesta;
	int contadorMay = 0;
	int idMujer = 0;
	int edadMujer = 0;
	int contadorMayViu = 0;
	int contador = 0;
	int precioTotal = 0;
	int flag = 0;
	float porcentajeMayores;
	float descuento;
	float totalConDescuento;

	do{
		printf("Ingrese Numero de Cliente: ");
		scanf("%d", &id);

		//estado civil ('s' para soltero", 'c' para casado o 'v' viudo),
		printf("Ingrese su Estado Civil(S o C o V): ");
		fflush(stdin);
		scanf("%c", &estadoCivil);
		while(estadoCivil != 's' && estadoCivil != 'c' && estadoCivil != 'v')
		{
			printf("Ingrese bien su Estado Civil(S o C o V): ");
			fflush(stdin);
			scanf("%c", &estadoCivil);
		}

		//edad( solo mayores de edad, más de 17)
		printf("Ingrese su Edad(mayor a 17): ");
		scanf("%d", &edad);
		while(edad < 17)
		{
			printf("Ingrese bien su Edad(mayor a 17): ");
			scanf("%d", &edad);
		}

		//temperatura corporal (validar por favor)
		printf("Ingrese su Temperatura: ");
		scanf("%f", &temperatura);
		while(temperatura < 36.1 || temperatura > 37)
		{
			printf("Ingrese bien su Temperatura: ");
			scanf("%f", &temperatura);
		}

		//genero('f' para femenino, 'm' para masculino, 'o' para no binario)
		printf("Ingrese el Genero(H o M u O): ");
		fflush(stdin);
		scanf("%c", &genero);
		while(genero != 'h' && genero != 'm' && genero != 'o')
		{
			printf("Ingrese bien su Genero(H o M u O): ");
			fflush(stdin);
			scanf("%c", &genero);
		}

		//a) La cantidad de personas con estado "viudo" de más de 60 años.
		if(estadoCivil == 'v' && edad > 59)
		{
			contadorMay++;

			if(estadoCivil == 'v')
			{
				contadorMayViu++;
			}
		}

		//b) el número de cliente y edad de la mujer soltera más joven.
		if(genero == 'm' && estadoCivil == 's')
		{
			if(flag == 0)
			{
				edadMujer = edad;
				idMujer = id;
				flag = 1;
			}
			else{
				if(edadMujer > edad)
				{
					edadMujer = edad;
					idMujer = id;
				}
			}
		}
		//c) cuánto sale el viaje total sin descuento.
		precioTotal = precioTotal + 600;
		contador++;
		printf("Desea continuar?");
		fflush(stdin);
		scanf("%c", &respuesta);
	}while(respuesta == 's');

	porcentajeMayores = contadorMay * 100 / contador;

	if(contadorMay > contador / 2)
	{
		precioTotal = precioTotal - (precioTotal / 100 * 25);
	}

	printf("La cantidad de personas con estado viudo de mas de 60 años es de %d. \n"
			"El numero de cliente de la mujer mas joven es %d y su edad es %d años. \n"
			"El viaje en total cuesta %d.\n", contadorMayViu, idMujer, edadMujer, precioTotal);

	//d) si hay más del 50% de los pasajeros que tiene más de 60 años , el precio final tiene un descuento del 25%, que solo mostramos si corresponde.
	if(porcentajeMayores > 50)
	{
		descuento = 0.75;
		totalConDescuento = precioTotal * descuento;
		printf("Como hay mas del 50 de pasajeros mayores de 60 se aplica un descuento de 25 quedando: %.2f \n", totalConDescuento);
	}

	return EXIT_SUCCESS;
}
