/*
 * Productos.h
 *
 *  Created on: 19 abr. 2022
 *      Author: Nani
 */

#ifndef PRODUCTOS_H_
#define PRODUCTOS_H_
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
#define TAM 10
#define TP 4
//Estado
#define VACIO 0
#define OCUPADO 1

typedef struct
{
	int idTipo;
	char descripcionTipo[20];
}stipoProducto;

typedef struct
{
	int idProducto;
	char descripcion[30];
	int nacionalidad; // EEUU - CHINA - OTRO
	int tipo; //IPHONE - MAC - IPAD - ACCESORIOS
	float precio;
	int estado;
	int idTipo;

}sProducto;

void iniciarArray(sProducto listaProductos[], int tam);

sProducto CargarUnProducto(stipoProducto listaTipos[], int tam);

void hardcodearProductos(sProducto listaProductos[], int tam);

void MostrarUnProducto(sProducto unProducto, stipoProducto listaTipos[], int tp);

int BuscarLibre(sProducto listaProductos[], int tam);

int CargarUnProductoEnLista(sProducto listaProductos[], int tam, stipoProducto listaTipos[], int sizelista);

int EliminarUnProducto(sProducto listaProductos[], int tam);

int ModificarUnProducto(sProducto listaProductos[], int tam, stipoProducto listaTipos[], int sizeTipos);

void MostrarListadoProductos(sProducto listaProductos[], int tam, stipoProducto listaTipos[], int tp);

void MostrarListadoPorPrecio(sProducto listaProductos[], int tam, stipoProducto listaTipos[], int sizeTipos);

void MostrarListadoPorDescripcion(sProducto listaProductos[], int tam, stipoProducto listaTipos[], int sizeTipos);

void MostrarProductosMasCaros(sProducto listaProductos[], int tam, stipoProducto listaTipos[], int sizeTipo);

float BuscarPrecioMaximo(sProducto listaProductos[], int tam);

void MostrarPromedioYTipo(sProducto listaProductos[], int tam,stipoProducto listaTipos[], int sizeTipo);

float CalcularPromedio(float acumulador,int contador);

int BuscarPorPrecio(sProducto listaProductos[], int tam, float precio, stipoProducto listaTipos[], int sizeTipo);

int BuscarIndiceTipo(int idTipo, stipoProducto listaTipos[], int tam);

float BuscarPrecioMinimoPorTipo (sProducto listaProductos[], int tam, int idTipo);

int BuscarMenorPorTipo (sProducto listaProductos[], int tam, stipoProducto listaTipos[], int sizeTipo, int idTipo );
#endif /* PRODUCTOS_H_ */

