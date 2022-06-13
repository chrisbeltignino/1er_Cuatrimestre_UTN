/*
 ===========================================================================================================
 Name        : Ejer 1-2.c
 Author      : Christian Tignino
 Description : Ingresar 3 números y mostrar cuál de los tres es el mayor.
               Ejemplo: Si ingresamos 5, 9 y 3 el programa mostrará: “El mayor de los números es el segundo”
 ===========================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	setbuf(stdout, NULL);

    int n1;
    int n2;
    int n3;

    printf("Introduzca el primer numero (entero): ");
    fflush(stdin);
    scanf("%d", &n1);
    printf("Introduzca el segundo numero (entero): ");
    fflush(stdin);
    scanf("%d", &n2);
    printf("Introduzca el tercer numero (entero): ");
    fflush(stdin);
    scanf("%d", &n3);

    if (n1 >= n2 && n1 >= n3)
    {
        printf( "\n %d es el mayor.", n1 );
    }
    else{
        if (n2 > n3){
            printf( "\n %d es el mayor.", n2 );
        }
        else{
            printf( "\n %d es el mayor.", n3 );
        }
    }
    return 0;
}
