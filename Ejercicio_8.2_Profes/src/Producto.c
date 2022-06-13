#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Producto.h"
#include "Inputs.h"

void producto_inicializarArray(eProducto producto[], int tam)
{
	int i;
	for(i=0; i<tam; i++)
	{
		producto[i].estado = VACIO;
	}
}

void producto_mostrarUno(eProducto producto)
{
	printf("%-5d %-20s %-20d %-20d %-20.2f\n", producto.idProducto, producto.descripcion, producto.nacionalidad, producto.tipo, producto.precio);
}

void producto_mostrarTodos(eProducto lista[], int tam)
{
	int i;
	printf("\nMostrando lista de lista...\n\n"
		   "%-5s %-20s %-20s %-20s %-20s\n", "ID", "Descripcion", "Nacionalidad", "Tipo", "Precio");
	for(i=0; i<tam; i++)
	{
		if(lista[i].estado == OCUPADO)
		{
			producto_mostrarUno(lista[i]);
		}
	}
	printf("\n");
}

int producto_agregarProducto(eProducto lista[], int tam, int ultimoId)
{
	int retorno = -1;
	int index = producto_buscarEspacioLibre(lista, tam);

	if(index != -1) //Si hay lugar en el array
	{
		printf("\nDando de alta un producto...\n\n");
		if(!producto_cargarUno(lista, index, ultimoId))
		{
			printf("\nSe cargo el producto!\n\n");
			retorno = 0;
		}
		else
		{
			printf("\nSe cancelo el alta del producto.\n\n");
		}
	}
	else
	{
		printf("\nError. No hay espacio disponible.\n\n");
	}

	return retorno;
}

int producto_cargarUno(eProducto lista[], int i, int ultimoId)
{
	int retorno = -1;

	lista[i].idProducto = ultimoId + 1;
	//pedirEntero(&lista[i].idProducto, "Ingrese el id (entre 1000-1100): ", "Ingrese un id valido (entre 1000-1100): ", 1000, 1100);
	pedirCadena(lista[i].descripcion, "Ingrese la descripcion: ", "Descripcion invalida, hasta 50 caracteres, reingrese: ", 51);
	pedirEntero(&lista[i].nacionalidad, "Ingrese la nacionalidad (EEUU = 0, CHINA = 1, OTRO = 2): ", "Ingrese una nacionalidad valida  (EEUU = 0, CHINA = 1, OTRO = 2): ", 0, 2);
	pedirEntero(&lista[i].tipo, "Ingrese el tipo (IPHONE = 0, MAC = 1, IPAD = 2, ACCESORIOS = 3): ", "Ingrese un tipo valido (IPHONE = 0, MAC = 1, IPAD = 2, ACCESORIOS = 3): ", 0, 3);
	pedirFlotante(&lista[i].precio, "Ingrese el precio (entre 1000 y 300000): ", "Ingrese un precio valido (entre 1000 y 300000): ", 1000, 300000);

	printf("\nProducto a agregar:\n\n%-5s %-20s %-20s %-20s %-20s\n", "ID", "Descripcion", "Nacionalidad", "Tipo", "Precio");
	producto_mostrarUno(lista[i]);

	if(!producto_verificarConfirmacion("\nIngrese 's' para confirmar el alta del producto: "))
	{
		lista[i].estado = OCUPADO;
		retorno = 0;
	}

	return retorno;
}

int producto_borrarUno(eProducto lista[], int tam)
{
	int retorno = -1;
	int index;
	int idIngresado;

	pedirEntero(&idIngresado, "Ingrese el ID del producto a borrar (1000-1100): ", "Reingrese el ID del producto a borrar (1000-1100): ", 1000, 1100);
	index = producto_buscarPorId(lista, tam, idIngresado);

	if(index != -1) //Existe el producto?
	{
		printf("\nProducto a eliminar:\n\n%-5s %-20s %-20s %-20s %-20s\n", "ID", "Descripcion", "Nacionalidad", "Tipo", "Precio");
		producto_mostrarUno(lista[index]);

		if(!producto_verificarConfirmacion("\nIngrese 's' para confirmar la baja del producto: "))
		{
			lista[index].estado = VACIO;
			printf("\nProducto %s dado de baja correctamente!\n\n", lista[index].descripcion);
			retorno = 0;
		}
		else
		{
			printf("\nSe cancelo la baja del producto.\n\n");
		}
	}
	else
	{
		printf("\nError. Producto no encontrado...\n\n");
	}

	return retorno;
}

int producto_subMenuModificarUno(eProducto lista[], int tam)
{
	int retorno = -1;
	int index;
	int idIngresado;
	int opcion;
	eProducto auxProducto;

	pedirEntero(&idIngresado, "Ingrese el ID del producto a modificar (1000-1100): ", "Reingrese el ID del producto a modificar (1000-1100): ", 1000, 1100);
	index = producto_buscarPorId(lista, tam, idIngresado);

	if(index != -1) //Existe el producto?
	{
		printf("\nProducto a modificar:\n\n%-5s %-20s %-20s %-20s %-20s\n", "ID", "Descripcion", "Nacionalidad", "Tipo", "Precio");
		producto_mostrarUno(lista[index]);
		printf("\n");

		do
		{
			auxProducto = lista[index];
			pedirEntero(&opcion, "-------------------------------------\n"
								 "1. MODIFICAR precio\n"
								 "2. MODIFICAR tipo\n"
								 "3. ATRAS\n"
								 "-------------------------------------\n"
								 "Ingrese una opcion: ",
								 "-------------------------------------\n"
								 "1. MODIFICAR precio\n"
								 "2. MODIFICAR tipo\n"
								 "3. ATRAS\n"
								 "-------------------------------------\n"
								 "Opcion invalida, reingrese: ", 1, 3);

			switch(opcion)
			{
				case 1:
					printf("\nProducto a modificar:\n\n%-5s %-20s %-20s %-20s %-20s\n", "ID", "Descripcion", "Nacionalidad", "Tipo", "Precio");
					producto_mostrarUno(lista[index]);
					pedirFlotante(&auxProducto.precio, "\nIngrese el nuevo precio (entre 1000 y 300000): ", "Ingrese un precio valido (entre 1000 y 300000): ", 1000, 300000);

					printf("\nProducto luego de la modificación:\n\n%-5s %-20s %-20s %-20s %-20s\n", "ID", "Descripcion", "Nacionalidad", "Tipo", "Precio");
					producto_mostrarUno(auxProducto);

					if(!producto_verificarConfirmacion("\nIngrese 's' para confirmar la modificacion del producto: "))
					{
						lista[index].precio = auxProducto.precio;
						printf("\nProducto %s modificado correctamente!\n\n", lista[index].descripcion);
						retorno = 0;
					}
					else
					{
						printf("\nSe cancelo la modificacion del producto.\n\n");
					}

					system("pause");
					break;
				case 2:
					printf("\nProducto a modificar:\n\n%-5s %-20s %-20s %-20s %-20s\n", "ID", "Descripcion", "Nacionalidad", "Tipo", "Precio");
					producto_mostrarUno(lista[index]);
					pedirEntero(&auxProducto.tipo, "\nIngrese el nuevo tipo (IPHONE = 0, MAC = 1, IPAD = 2, ACCESORIOS = 3): ", "Ingrese un tipo valido (IPHONE = 0, MAC = 1, IPAD = 2, ACCESORIOS = 3): ", 0, 3);

					printf("\nProducto luego de la modificación:\n\n%-5s %-20s %-20s %-20s %-20s\n", "ID", "Descripcion", "Nacionalidad", "Tipo", "Precio");
					producto_mostrarUno(auxProducto);

					if(!producto_verificarConfirmacion("\nIngrese 's' para confirmar la modificacion del producto: "))
					{
						lista[index].tipo = auxProducto.tipo;
						printf("\nProducto %s modificado correctamente!\n\n", lista[index].descripcion);
						retorno = 0;
					}
					else
					{
						printf("\nSe cancelo la modificacion del producto.\n\n");
					}

					system("pause");
					break;
				case 3:
					printf("\n");
					break;
			}
		}while(opcion != 3);
	}
	else
	{
		printf("\nError. Producto no encontrado...\n\n");
	}

	return retorno;
}

int producto_buscarPorId(eProducto lista[], int tam, int id)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(lista[i].estado == OCUPADO && lista[i].idProducto == id)
		{
			index = i;
			break;
		}
	}

	return index;
}

int producto_buscarEspacioLibre(eProducto lista[], int tam)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(lista[i].estado == VACIO)
		{
			index = i;
			break;
		}
	}

	return index;
}

void producto_hardCodear(eProducto lista[], int tam)
{
	int i;
	int ids[] = {1000, 1001, 1002};
	char descripciones[][51] = {"IPhone 12", "IPhone 13", "IPad Pro"};
	int nacionalidades[] = {EEUU, EEUU, CHINA};
	int tipos[] = {IPHONE, IPHONE, IPAD};
	float precios[] = {250000, 300000, 275000};

	for(i=0; i<tam-2; i++)
	{
		lista[i].idProducto = ids[i];
		strcpy(lista[i].descripcion, descripciones[i]);
		lista[i].nacionalidad = nacionalidades[i];
		lista[i].tipo = tipos[i];
		lista[i].precio = precios[i];
		lista[i].estado = OCUPADO;
	}
}

void producto_ordenarlistaPorPrecioAsc(eProducto lista[], int tam)
{
	int i;
	int j;
	eProducto auxProducto;

	for(i=0; i<tam-1; i++)
	{
		for(j=i+1; j<tam; j++)
		{
			if(lista[i].estado == OCUPADO && lista[j].estado == OCUPADO && lista[i].precio > lista[j].precio)
			{
				auxProducto = lista[i]; //copiamos la estructura ENTERA
				lista[i] = lista[j]; //copiamos la estructura ENTERA
				lista[j] = auxProducto; //copiamos la estructura ENTERA
			}
		}
	}

	printf("\nLista de lista ordenada exitosamente!\n\n");
}

void producto_ordenarlistaPorDescripcionAsc(eProducto lista[], int tam)
{
	int i;
	int j;
	eProducto auxProducto;

	for(i=0; i<tam-1; i++)
	{
		for(j=i+1; j<tam; j++)
		{
			if(lista[i].estado == OCUPADO && lista[j].estado == OCUPADO && strcmp(lista[i].descripcion, lista[j].descripcion) == 1)
			{
				auxProducto = lista[i]; //copiamos la estructura ENTERA
				lista[i] = lista[j]; //copiamos la estructura ENTERA
				lista[j] = auxProducto; //copiamos la estructura ENTERA
			}
		}
	}
	printf("\nLista de lista ordenada exitosamente!\n\n");
}

int producto_verificarConfirmacion(char* mensaje)
{
	int retorno = -1;
	char respuesta;

	pedirCaracter(&respuesta, mensaje);
	if(respuesta == 's' || respuesta == 'S')
	{
		retorno = 0;
	}

	return retorno;
}
