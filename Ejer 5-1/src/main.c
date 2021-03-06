#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define T 5 //Definir un valor que luego va a ser un remplazado en el codigo
            //(constante)Elemento de la programacion que va a valer el mismo valor, toda la vida del programa.

int main()
{
	setbuf(stdout, NULL);
    int vectorDeNumeros[T]= {};
    int op = 0;
    int opcion;

    do
    {
    	opcion = mostrarOpciones(op);
        switch(opcion)
        {
        case 1:
            cargarVector(vectorDeNumeros,T);
            break;
        case 2:
            mostrarVector(vectorDeNumeros,T);
            break;
        case 3:
            mostrarNegativos(vectorDeNumeros,T);
            break;
        case 4:
            mostrarPromedio(vectorDeNumeros,T);
            break;
        case 5:
            mostrarMaximo(vectorDeNumeros,T);
            break;
        case 6:
            mostrarMinimo(vectorDeNumeros,T);
            break;
        }
        system("pause");
    }
    while(opcion!=7);
    return 0;
}
