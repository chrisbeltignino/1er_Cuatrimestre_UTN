#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

#define BITCOIN 4606954.55

float CalcularPrecioTarjetaDebito(float num)
{
	float descuento;
	float precioConAumento;

	descuento = num * 0.10;
	precioConAumento = num - descuento;

	return precioConAumento;
}

float CalcularPrecioTarjetaCredito(float num)
{
	float precioConAumentoL;
	float aumento;

	aumento = num * 0.25;
	precioConAumentoL = num + aumento;

	return precioConAumentoL;
}

float CalcularPrecioBitcoin(float num)
{
	float precioConBitcoin;

	precioConBitcoin = num / BITCOIN;

	return precioConBitcoin;
}

float CalcularPrecioUnitario(float km, float num)
{
	float precioUnitario;

	precioUnitario = num / km;

	return precioUnitario;
}

float CalcularDiferenciaPrecio(float y, float z)
{
    float resultado;

    if (z > y){
        resultado = z - y;
    } else {
    	resultado = y - z;
    }

    return resultado;
}

void CargaForzada(void)
{
	float x = 7090;
	float y = 162965;
	float z = 159339;
	float precioTarjDebA;
	float precioTarjCredA;
	float precioBitA;
	float precioUnitA;
	float precioTarjDebL;
	float precioTarjCredL;
	float precioBitL;
	float precioUnitL;
	float difPrecio;

	printf("Carga forzada...\n");

	precioTarjDebA = CalcularPrecioTarjetaDebito(y);
	precioTarjCredA = CalcularPrecioTarjetaCredito(y);
	precioBitA = CalcularPrecioBitcoin(y);
	precioUnitA = CalcularPrecioUnitario(x, y);

	precioTarjDebL = CalcularPrecioTarjetaDebito(z);
	precioTarjCredL = CalcularPrecioTarjetaCredito(z);
	precioBitL = CalcularPrecioBitcoin(z);
	precioUnitL = CalcularPrecioUnitario(x, z);

	difPrecio = CalcularDiferenciaPrecio(y, z);

	printf("KM ingresado: %.2f", x);

	printf("\nAerolíneas: %.2f", y);
	printf("\na) Precio con tarjeta de débito: %.2f", precioTarjDebA);
	printf("\nb) Precio con tarjeta de crédito: %.2f", precioTarjCredA);
	printf("\nc) Precio pagando con bitcoin : %.11f", precioBitA);
	printf("\nd) Precio unitario: %.2f\n", precioUnitA);

	printf("\nLatam: %.2f", z);
	printf("\na) Precio con tarjeta de débito: %.2f", precioTarjDebL);
	printf("\nb) Precio con tarjeta de crédito: %.2f", precioTarjCredL);
	printf("\nc) Precio pagando con bitcoin : %.11f", precioBitL);
	printf("\nd) Precio unitario: %.2f\n", precioUnitL);

	printf("\nd) Diferencia de precio: %.2f\n", difPrecio);
}
