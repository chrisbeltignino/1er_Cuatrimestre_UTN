/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

Realizar una función que  reciba como parámetro el importe de una compra y una
cadena que determina el tipo de cliente. La función retornará el  importe con un
descuento aplicado, en el caso de que el cliente sea VIP, un 30% descuento, en el
caso de que sea Premium, un 20. Cualquier otro caso un 10. Probar calcular los 3 descuentos en el main.

3. Crear una función que reciba como parámetro una cadena. Dicha función  deberá
ordenar alfabéticamente la cadena y luego reemplazar los espacios por un asterisco.
Por ej: "el arbol" -> "*abellor". Hardcodear otro ejemplo.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 20

void recibeCadena(char cadena[]);
float hacerDescuento(float precioIngresado, char* tipo);

int main()
{
    setbuf(stdout, NULL);
    char cadena[TAM];
    char tipo;
    float precio;
    float precioTotal;

    printf("Escriba la oracion: \n");
    fflush(stdin);
    scanf("%[^\n]", cadena);
    recibeCadena(cadena);
    puts(cadena);

    printf("Ingrese el precio: \n");
    fflush(stdin);
    scanf("%f", &precio);
    printf("Ingrese el tipo de cliente (VIP = v, PREMIUM = p, OTRO = o):");
    fflush(stdin);
    scanf("%c", &tipo);

    precioTotal = hacerDescuento(precio, &tipo);
    printf("El precio con descuento es: %.2f\n"
    	   "Y el Tipo de cliente es: %c", precioTotal, tipo);

    return 0;
}

void recibeCadena(char cadena[])
{
    char asterisco = '*';
    char espacios = ' ';
    int i;

    for(i=0; cadena[i] != '\0'; i++)
    {
        if(cadena[i] == espacios)
        {
            cadena[i] = asterisco;
            //break;
        }
    }
}

float hacerDescuento(float precioIngresado, char* tipo)
{
    char vip = 'v';
    char premium = 'p';
    char otro = 'o';
    float precioDescuento;
    float descuento;

    if(strcmp(tipo, &vip)==1)
    {
        descuento = precioIngresado*0.30;
    }else
    {
		if(strcmp(tipo, &premium)==1)
		{
			descuento = precioIngresado*0.20;
		}else
		{
			if(strcmp(tipo, &otro)==1)
			{
				descuento = precioIngresado*0.10;
			}
		}
    }
    precioDescuento = precioIngresado - descuento;
    return precioDescuento;
}
