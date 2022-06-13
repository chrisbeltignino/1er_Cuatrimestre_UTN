#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
#include "validacion.h"
#include "menu.h"

void menu()
{
	setbuf(stdout, NULL);
		/** \brief variable de control, utilizada para la repeticion del while.
		*/
	    int opcion;

	    /** \brief variable del tipo flotante, utilizada para almacenar los Kilometros.
	    */
	    float x = 0;

	    /** \brief variable del tipo flotante, utilizada para almacenar el precio de Aerolineas.
	    */
	    float y = 0;

	    /** \brief variable del tipo flotante, utilizada para almacenar el precio de Latam.
	    */
	    float z = 0;

	    /** \brief variable del tipo flotante, utilizada para almacenar el retorno de la funcion "CalcularPrecioTarjetaDebito".
	    */
	    float precioTarjDebA = 0;

	    /** \brief variable del tipo flotante, utilizada para almacenar el retorno de la funcion "CalcularPrecioTarjetaDebito".
	    */
	    float precioTarjCredA = 0;

	    /** \brief variable del tipo flotante, utilizada para almacenar el retorno de la funcion "CalcularPrecioBitcoin".
	    */
	    float precioBitA = 0;

	    /** \brief variable del tipo flotante, utilizada para almacenar el retorno de la funcion "CalcularPrecioUnitarioAerolineas".
	    */
	    float precioUnitA = 0;

	    /** \brief variable del tipo flotante, utilizada para almacenar el retorno de la funcion "CalcularPrecioTarjetaDebitoLatam".
	   	*/
	    float precioTarjDebL = 0;

		/** \brief variable del tipo flotante, utilizada para almacenar el retorno de la funcion "CalcularPrecioTarjetaCreditoLatam".
		*/
		float precioTarjCredL = 0;

		/** \brief variable del tipo flotante, utilizada para almacenar el retorno de la funcion "CalcularPrecioBitcoinLatam".
		*/
		float precioBitL = 0;

		/** \brief variable del tipo flotante, utilizada para almacenar el retorno de la funcion "CalcularPrecioUnitarioLatam".
		*/
		float precioUnitL = 0;

		/** \brief variable del tipo flotante, utilizada para almacenar el retorno de la funcion "CalcularDiferenciaPrecio".
		*/
		float difPrecio = 0;

	printf("Bienvenido!!\n");

	do
	{
		mostrarSeparador();
		mostrarMenu(x, y, z);
		mostrarSeparador();
		fflush(stdin);
		scanf("%d", &opcion);

		switch(opcion)
		{
		case 1:
			IngresoKilometros(&x);
			break;
		case 2:
			IngresoPrecios(&y, &z);
			break;
		case 3:
			CalcularTodo(x, y, z, &precioTarjDebA, &precioTarjCredA, &precioBitA, &precioUnitA, &precioTarjDebL, &precioTarjCredL, &precioBitL, &precioUnitL, &difPrecio);
			system("pause");
			limpiarConsola();
			break;
		case 4:
			MostrarCostos(x, y, z, precioTarjDebA, precioTarjCredA, precioBitA, precioUnitA, precioTarjDebL, precioTarjCredL, precioBitL, precioUnitL, difPrecio);
			system("pause");
			limpiarConsola();
			break;
		case 5:
			CargaForzada();
			system("pause");
			limpiarConsola();
			break;
		case 6:
			printf("Saliendo...\n");
			break;
		default:
			printf("Ingrese una opción valida.");
			system("pause");
		}
		if (opcion != 6)
		{
			system("pause");
			limpiarConsola();
		}
	}while(opcion != 6);
}

void IngresoKilometros(float* x)
{
	*x = pedirNumero("Ingrese KM: ", "Error, ingrese nuevamente los kilometros");
	limpiarConsola();
}

void IngresoPrecios(float* y, float* z)
{
	printf("Ingresar Precio de Vuelos:\n");
	*y = pedirNumero("- Precio vuelo Aerolíneas: ", "Error, ingrese nuevamente el precio");
	*z = pedirNumero("- Precio vuelo Latam: ", "Error, ingrese nuevamente el precio");
	limpiarConsola();
}

void mostrarMenu(float x, float y, float z)
{
	printf("1)Ingresar KM: (km = %.2f)", x);
	printf("\n2)Ingresar Precio de Vuelos: (Aerolíneas = %.2f, Latam = %.2f)", y, z);
	printf("\n3)Calcular todos los costos.");
	printf("\n4)Informar Resultados.");
	printf("\n5)Carga forzada de datos.");
	printf("\n6)Salir.\n");
}

void limpiarConsola(void)
{
	printf("\n\n\n\n\n\n");
}

void mostrarSeparador(void)
{
	printf("------------------------------------------------------------------------\n");
}
