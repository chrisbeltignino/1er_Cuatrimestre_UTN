/******************************************************************************

Christian Tignino

Ejercicio 1-1: Ingresar dos n�meros enteros, sumarlos y mostrar el resultado.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroUno;
    int numeroDos;
    int resultado;

    printf("Ingrese un numero 1: ");
    scanf("%d", &numeroUno);
    fflush(stdin);

    printf("Ingrese un numero 2: ");
    scanf("%d", &numeroDos);

    resultado = numeroUno + numeroDos;

    printf("El resultado es: %d", resultado);
}


