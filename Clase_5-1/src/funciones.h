#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#define TAM 5

int inicializarElementos(int* array, int tam);
int cargarNumeros(int* array, int tam);
int sumarNumeros(int* array, int tam, int* suma);
int recorrerNumeros(int* array, int tam);
int sacarMaximo(int* array, int tam, int* maximo);
int obtenerIndex(int* array, int tam, int numeroBuscado, int* index);

#endif /* FUNCIONES_H_ */
