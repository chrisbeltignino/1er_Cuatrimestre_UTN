/*
Una empresa importadora que comercializa lista Apple, decide registrar de sus lista los siguientes datos:
idProducto (numerico)
descripcion (alfanumérico)
nacionalidad (numérico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
tipo (numérico, por el momento utilizaremos un define: IPHONE -MAC - IPAD - ACCESORIOS)
precio (numérico decimal)
Realizar un programa que permita interactuar con un menú de usuarios con las siguientes opciones:
1.ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio disponible en el array.
2.BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista, dejando espacio disponible para un nuevo producto.
3.MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá modificar el precio o el tipo.
4.LISTADO lista.
5.LISTADO ordenado por precio.
6.LISTADO ordenado por descripción.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include "Producto.h"

int main(void) {
	setbuf(stdout, NULL);

	eProducto lista[TAM];
	int opcion;
	int cantidadPerros = 3;
	int ultimoId = 1002;

	producto_inicializarArray(lista, TAM);
	producto_hardCodear(lista, TAM);

	do
	{
		pedirEntero(&opcion, "-------------------------------------\n"
							 "1. ALTA producto\n"
							 "2. BAJA producto\n"
							 "3. MODIFICACION producto\n"
							 "4. LISTADO lista\n"
							 "5. LISTADO ordenado por precio\n"
							 "6. LISTADO ordenado por descripcion\n"
							 "7. SALIR\n"
							 "-------------------------------------\n"
							 "Ingrese una opcion: ",
							 "-------------------------------------\n"
							 "1. ALTA producto\n"
							 "2. BAJA producto\n"
							 "3. MODIFICACION producto\n"
							 "4. LISTADO lista\n"
							 "5. LISTADO ordenado por precio\n"
							 "6. LISTADO ordenado por descripcion\n"
							 "7. SALIR\n"
							 "-------------------------------------\n"
							 "Opcion invalida, reingrese: ", 1, 7);

		switch(opcion)
		{
			case 1:
				if(!producto_agregarProducto(lista, TAM, ultimoId))
				{
					cantidadPerros++;
					ultimoId++;
				}
				system("pause");
				break;
			case 2:
				producto_mostrarTodos(lista, TAM);
				if(!producto_borrarUno(lista, TAM))
				{
					cantidadPerros--;
				}
				system("pause");
				break;
			case 3:
				producto_mostrarTodos(lista, TAM);
				producto_subMenuModificarUno(lista, TAM);
				system("pause");
				break;
			case 4:
				if(cantidadPerros > 0)
				{
					producto_mostrarTodos(lista, TAM);
				}
				else
				{
					printf("\nNo hay lista cargados en el sistema.\n\n");
				}
				system("pause");
				break;
			case 5:
				if(cantidadPerros > 0)
				{
					producto_ordenarlistaPorPrecioAsc(lista, TAM);
				}
				else
				{
					printf("\nNo hay lista cargados en el sistema.\n\n");
				}
				system("pause");
				break;
			case 6:
				if(cantidadPerros > 0)
				{
					producto_ordenarlistaPorDescripcionAsc(lista, TAM);
				}
				else
				{
					printf("\nNo hay lista cargados en el sistema.\n\n");
				}
				system("pause");
				break;
			case 7:
				printf("\nSaliendo...\nPrograma terminado.\n");
				break;
		}
	}while(opcion != 7);

	return EXIT_SUCCESS;
}
