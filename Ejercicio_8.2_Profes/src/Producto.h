#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

//Nacionalidad
#define EEUU 0
#define CHINA 1
#define OTRO 2
//Tipo
#define IPHONE 0
#define MAC 1
#define IPAD 2
#define ACCESORIOS 3
//Tamaño del array
#define TAM 5
//Estado
#define VACIO 0
#define OCUPADO 1

typedef struct
{
	int idProducto;
	char descripcion[51];
	int nacionalidad;
	int tipo;
	float precio;
	int estado;
}eProducto;

void producto_inicializarArray(eProducto lista[], int tam);
void producto_mostrarUno(eProducto producto);
void producto_mostrarTodos(eProducto lista[], int tam);
int producto_agregarProducto(eProducto lista[], int tam, int ultimoId);
int producto_cargarUno(eProducto lista[], int i, int ultimoId);
int producto_borrarUno(eProducto lista[], int tam);
int producto_subMenuModificarUno(eProducto lista[], int tam);
int producto_buscarPorId(eProducto lista[], int tam, int id);
int producto_buscarEspacioLibre(eProducto lista[], int tam);
void producto_hardCodear(eProducto lista[], int tam);
void producto_ordenarlistaPorPrecioAsc(eProducto lista[], int tam);
void producto_ordenarlistaPorDescripcionAsc(eProducto lista[], int tam);
int producto_verificarConfirmacion(char* mensaje);

#endif /* PRODUCTO_H_ */
