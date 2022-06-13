/*
 ============================================================================
 Name        : Ejer.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(){

    setbuf(stdout, NULL);
    short int i;
    char letraIngresada;
    int contadorP = 0;

    for (i = 0; i < 5; i++){
        printf("Ingrese un un caracter: ");
        fflush(stdin);
        scanf("%c", &letraIngresada);

        if(letraIngresada == 'p'){
            contadorP++;
        }
    }
    printf("Se ingresaron %d letras P", contadorP);
    return 0;
}
