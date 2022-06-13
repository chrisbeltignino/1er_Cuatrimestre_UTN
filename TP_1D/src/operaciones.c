#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float pedirNumero(char mensaje[])
{
    float numero;
    printf("%s",mensaje);
    scanf("%f",&numero);

    return numero;
}

float suma(float numero1,float numero2)
{
    float resultado;
    resultado=numero1 + numero2;
    return resultado;
}

float resta(float numero1,float numero2)
{
    float resultado;
    resultado=numero1 - numero2;
    return resultado;
}

float division (float numero1,float numero2)
{
    float resultado;
    resultado= (float)numero1 / numero2;
    return resultado;
}

float multiplicacion(float numero1,float numero2)
{
    float resultado;
    resultado=numero1 * numero2;
    return resultado;

}
/*
int resolverFactorial(int numero)
{
    int factorial=1;
    int i;

    for(i=numero;i>1;i--)
    {
        factorial=factorial * i;
    }
    return factorial;
}
*/
int resolverFactorial(int numero)
{
    int factorial;

    if(numero == 0)
    {
    	factorial = 1;
    }
    else
    {
    	factorial = numero * resolverFactorial(numero - 1);
    }

    return factorial;
}



