/*
 ============================================================================
 Name        : 10-3.c
 Author      : Nani Renato
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Productos.h"

int main(void)
{
	setbuf(stdout, NULL);
	sProducto listaProductos[TAM];
	iniciarArray(listaProductos, TAM);
	stipoProducto listaTipos[TP] = {{1000, "IPHONE"}, {1001, "IPAD"}, {1002, "MAC"},{1003, "ACCESORIOS"}};
	hardcodearProductos(listaProductos, TAM);

	int opcion;
	int index;
	int confirmacionProductoEliminado;
	int confirmacionProductoModificado;
	do
	{
		printf("1. ALTA Producto \n");
		printf("2. BAJA Producto \n");
		printf("3. MODIFICACIÓN Producto \n");
		printf("4. LISTADO Productos \n");
		printf("5. LISTADO ordenado por precio \n");
		printf("6. LISTADO ordenado por descripción \n");
		printf("7. LISTADO precio maximo\n");
		printf("8. MOSTRAR precio promedio por tipo\n");
		printf("9. SALIR\n");
		printf("Elija una opcion: ");
		scanf("%d", &opcion);
		switch(opcion)
		{
			case 1:
				index = CargarUnProductoEnLista(listaProductos, TAM, listaTipos, TP);
				switch(index)
				{
					case -1:
						printf("No hay espacio disponible\n");
					break;
					default:
						printf("\nLa carga se realizó con éxito en la posición %d\n", index);
					break;
				}
				break;
			case 2:
				confirmacionProductoEliminado = EliminarUnProducto(listaProductos, TAM);
				if(confirmacionProductoEliminado==1)
				{
					printf("Se ha eliminado correctamente el producto.\n");
				}
				else
				{
					printf("El producto no ha sido eliminado.\n");
				}

				break;

			case 3:
				confirmacionProductoModificado = ModificarUnProducto(listaProductos, TAM, listaTipos, TP);

				if(confirmacionProductoModificado==1)
				{
					printf("Se ha modificado correctamente el producto.\n");
				}
				else
				{
					printf("El producto no ha sido modificado.\n");
				}
				break;
			case 4:
				MostrarListadoProductos(listaProductos, TAM, listaTipos, TP);
				break;
			case 5:
				MostrarListadoPorPrecio(listaProductos, TAM, listaTipos, TP);
				break;
			case 6:
				MostrarListadoPorDescripcion(listaProductos,TAM, listaTipos, TP);
				break;
			case 7:
				MostrarProductosMasCaros(listaProductos, TAM, listaTipos);
				break;
			case 8:
				MostrarPromedioYTipo(listaProductos,TAM, listaTipos, TP);
				break;
			case 9:
			    if(BuscarPorPrecio(listaProductos, TAM, 700, listaTipos, TP) == -1)
			    {
			        printf("No hay ningun producto que valga eso!!");
			    }

			    break;
			case 10:
			    if (BuscarMenorPorTipo (listaProductos, TAM, listaTipos, TP, 1000) == -1){
			        printf("No hay ningun IPHONE\n");
			    }
			    break;
			case 11:

				printf("Hasta pronto...");
				break;


			default:

				printf("Introduzca una opcion valida");
				break;

			}

		}while(opcion!=11);


	return 0;
}
