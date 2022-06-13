/******************************************************************************

Christian Tignino

Ejercicio 1 - Pedir al usuario el ingreso de dos personas con su nombre y edad.
Luego, mostrar en pantalla los datos conseguidos
(Nombre x edad x y nombre z edad z se ingresaron al sistema)

*******************************************************************************/
#include <stdio.h>

/**
 * @fn int main()
 * @brief
 *
 * @return
 */

int main()
{
    char nombreUno[21];
    char nombreDos[21];
    char edadUno[3];
    char edadDos[3];

    printf("Ingrese su Nombre: ");
    scanf("%s", nombreUno);
    fflush(stdin);

    printf("Ingrese su Edad: ");
    scanf("%s", edadUno);
    fflush(stdin);

    printf("Ingrese su Nombre: ");
    scanf("%s", nombreDos);
    fflush(stdin);

    printf("Ingrese un Edad: ");
    scanf("%s", edadDos);


    printf("Nombre %s edad %s y nombre %s edad %s se ingresaron al sistema", nombreUno, edadUno, nombreDos, edadDos);
}
