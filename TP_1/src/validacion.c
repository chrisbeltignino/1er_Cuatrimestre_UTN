#include <stdio.h>
#include <stdlib.h>
#include "validacion.h"
#include "operaciones.h"

float pedirNumero(char mensaje[], char mensajeError[])
{
    float numero;
    printf("%s", mensaje);
    scanf("%f", &numero);
    while(numero < 1)
	{
		printf("%s", mensajeError);
		fflush(stdin);
		scanf("%f", &numero);
	}
    return numero;
}

void CalcularTodo(float x, float y, float z, float* precioTarjDebA, float* precioTarjCredA, float* precioBitA, float* precioUnitA, float* precioTarjDebL, float* precioTarjCredL, float* precioBitL, float* precioUnitL, float* difPrecio)
{
	if (x == 0 || y == 0 || z == 0)
	{
		printf("No se ha introducido ningun valor para realizar alguna de las operaciones\n");
		system("pause");
	}
	else
	{
		*precioTarjDebA = CalcularPrecioTarjetaDebito(y);
		*precioTarjCredA = CalcularPrecioTarjetaCredito(y);
		*precioBitA = CalcularPrecioBitcoin(y);
		*precioUnitA = CalcularPrecioUnitario(x, y);

		*precioTarjDebL = CalcularPrecioTarjetaDebito(z);
		*precioTarjCredL = CalcularPrecioTarjetaCredito(z);
		*precioBitL = CalcularPrecioBitcoin(z);
		*precioUnitL = CalcularPrecioUnitario(x, z);

		*difPrecio = CalcularDiferenciaPrecio(y, z);

		printf("Se a calculado todo los costos\n");
	}
}

void MostrarCostos(float x, float y, float z, float precioTarjDebA, float precioTarjCredA, float precioBitA, float precioUnitA, float precioTarjDebL, float precioTarjCredL, float precioBitL, float precioUnitL, float difPrecio)
{
	if(precioTarjDebA == 0 || precioTarjCredA == 0 || precioBitA == 0 || precioUnitA == 0 || precioTarjDebL == 0 || precioTarjCredL == 0 || precioBitL == 0 || precioUnitL == 0 || difPrecio == 0){
        printf("Porfavor, ingrese datos para poder mostrar. \n");
    } else {
    	printf("\nKM ingresado es: %.2f", x);

    	printf("\nAerolíneas: %.2f", y);
		printf("\na) Precio con tarjeta de débito: %.2f", precioTarjDebA);
		printf("\nb) Precio con tarjeta de crédito: %.2f", precioTarjCredA);
		printf("\nc) Precio pagando con bitcoin : %.11f", precioBitA);
		printf("\nd) Precio unitario: %.2f", precioUnitA);

		printf("\nLatam: %.2f", z);
		printf("\na) Precio con tarjeta de débito: %.2f", precioTarjDebL);
		printf("\nb) Precio con tarjeta de crédito: %.2f", precioTarjCredL);
		printf("\nc) Precio pagando con bitcoin : %.11f", precioBitL);
		printf("\nd) Precio unitario: %.2f\n", precioUnitL);

		printf("\nd) Diferencia de precio: %.2f\n", difPrecio);
    }
}
