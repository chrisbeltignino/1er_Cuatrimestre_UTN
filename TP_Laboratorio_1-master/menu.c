#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
void menu()
{
    /** \brief variable de control, utilizada para la repeticion del while.
     */
    int continuar = 's';
    /** \brief variable de control, utilizada para la seleccion de opciones en el menu.
    */
    int opcion;
    /** \brief variable del tipo flotante, utilizada para almacenar el retorno del a funcion "suma".
    */
    float sumar;
    /** \brief variable del tipo flotante, utilizada para almacenar el retorno de la funcion "resta".
    */
    float restar;
    /** \brief variable del tipo flotante, utilizada para almacenar el retorno de la funcion "division".
    */
    float dividir;
    /** \brief variable del tipo flotante, utilizada para almacenar el retorno de la funcion "multiplicacion".
    */
    float multiplicar;
    /** \brief variable del tipo flotante, utilizada para almacenar el retorno de la funcion "resolverFactorial", del primer numero.
    */
    float factorizarNumero1;
    /** \brief variable del tipo flotante, utilizada para almacenar el retorno de la funcion "resolverFactorial", del segundo numero.
    */
    float factorizarNumero2;
    /** \brief variable de control del tipo flotante, utilizada para la verificacion de introduccion del primer numero.
    */
    float numero1=0;
    /** \brief variable de control del tipo flotante, utilizada para la verificacion de introduccion del segundo numero.
    */
    float numero2=0;
    /** \brief variable de control del tipo entero, utilizada para la alteracion del menu, una vez introducidos los dos numeros.
    */
    int flag=0;



        while(continuar=='s'){

        printf("Indique que operacion desea realizar:\n");

        if(flag==1)
        {
            printf("1)Ingrese el 1er operando (A=%.2f)",numero1);
            printf("\n2)Ingrese el 2do operando (B=y)");
            printf("\n3)Calcular todas las operaciones");
            printf("\n4)Informar resultados ");
            printf("\n5)Salir.\n");
        }
        if(flag==2)
        {
            printf("1)Ingrese el 1er operando (A=%.2f)",numero1);
            printf("\n2)Ingrese el 2do operando (B=%.2f)",numero2);
            printf("\n3)Calcular todas las operaciones");
            printf("\n4)Informar resultados ");
            printf("\n5)Salir.\n");
        }
        if(flag<1)
        {
        printf("1)Ingrese el 1er operando (A=x)");
        printf("\n2)Ingrese el 2do operando (B=y)");
        printf("\n3)Calcular todas las operaciones");
        printf("\n4)Informar resultados ");
        printf("\n5)Salir.\n");
        }
        scanf("%d",&opcion);
        system("cls");
        if(opcion==3&&numero1==0&&numero2==0){
            printf("No se ha introducido ningun valor para realizar alguna de las operaciones\n");
            system("pause");
            system("cls");
        }
        else{
        switch(opcion){
        case 1:
            numero1=pedirNumero("ingrese el primer numero: ");
            flag=1;
            system("cls");

            break;
        case 2:
            numero2=pedirNumero("ingrese el segundo numero: ");
            flag=2;
            system("cls");
            break;
        case 3:
            printf("Se realizaran las siguientes operaciones");
            printf("\na)Calcular la suma (%.2f+%.2f)",numero1,numero2);
            printf("\nb)Calcular la resta(%.2f-%.2f)",numero1,numero2);
            printf("\nc)Calcular la Division (%.2f/%.2f)",numero1,numero2);
            printf("\nd)Calcular la multiplicacion(%.2f*%.2f)",numero1,numero2);
            printf("\ne)Calcular el factorial (%.2f!)\n",numero1);

            sumar=suma(numero1,numero2);
            restar=resta(numero1,numero2);
            dividir=division(numero1,numero2);
            multiplicar=multiplicacion(numero1,numero2);
            factorizarNumero1=resolverFactorial(numero1);
            factorizarNumero2=resolverFactorial(numero2);
            system("pause");
            system("cls");
            break;
        case 4:

            printf("El resultado de %.2f + %.2f es: %.2f\n",numero1,numero2,sumar);
            printf("El resultado de %.2f - %.2f es: %.2f\n",numero1,numero2,restar);
            if(numero2==0)
            {
                printf("Error,no se puede dividir por 0");
            }

            else{
            printf("El resultado de %.2f / %.2f es: %.2f\n",numero1,numero2,dividir);
            }
            printf("El resultado de %.2f * %.2f es: %.2f\n",numero1,numero2,multiplicar);
            if(numero1>=0 && numero2<0)
            {
                printf("El factorial de %.2f es: %.2f y ",numero1,factorizarNumero1);
                printf("no se puede factorizar un numero negativo (%.2f).\n",numero2);
            }
            else if(numero2>=0&&numero1<0)
            {
                printf("no se puede factorizar un numero negativo. (%.2f)  y",numero1);
                printf("El factorial de %.2f es: %.2f\n",numero2,factorizarNumero2);
            }
            else if(numero1<0 && numero2<0)
            {
                printf("no se puede factorizar un numero negativo. (%.2f) y (%.2f) \n",numero1,numero2);
            }
            else
            {
                printf("El factorial de %.2f es: %.2f y ",numero1,factorizarNumero1);
                printf("El factorial de %.2f es: %.2f\n",numero2,factorizarNumero2);
            }
            system("pause");
            system("cls");
            flag=0;
            break;
        case 5:
            printf("saliendo...\n");
            system("pause");
            continuar='n';
            break;
        default:
            printf("ingrese una opción valida.");
            system("pause");

}
        }
}

}
