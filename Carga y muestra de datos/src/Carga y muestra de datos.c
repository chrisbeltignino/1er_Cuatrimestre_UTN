#include <stdio.h>
#include <string.h>

#define TAM 2
#define TAMNOMBRE 31

int pedirEntero(char* mensaje, char* mensajeError, int min, int max);
void pedirString(char* cadena, char* mensaje, char* mensajeError, int max);
void pedirPersonas(char nombres[][TAMNOMBRE], int* edades, int tam, int tamMaxNombre);
void mostrarPersonas(int* edades, char nombres[][TAMNOMBRE], int tam);
void ordenarPersonas(char nombres[][TAMNOMBRE], int* edades, int tam);

int main(void) {
	setbuf(stdout, NULL);

	int edades[TAM];
	char nombres[TAM][TAMNOMBRE];

	pedirPersonas(nombres, edades, TAM, TAMNOMBRE);
	mostrarPersonas(edades, nombres, TAM);
	ordenarPersonas(nombres, edades, TAM);
	mostrarPersonas(edades, nombres, TAM);

	return 0;
}

//por nombre ascendente
void ordenarPersonas(char nombres[][TAMNOMBRE], int* edades, int tam)
{
	int i;
	int j;
	int edadAux;
	char nombreAux[TAMNOMBRE];

	for(i = 0;i < tam-1; i++)
	{
		for(j = i+1;j < tam; j++)
		{
			if(strcmp(nombres[i], nombres[j])==-1)
			{
				strcpy(nombreAux, nombres[i]);
				strcpy(nombres[i], nombres[j]);
				strcpy(nombres[j], nombreAux);

				edadAux = edades[i];
				edades[i] = edades[j];
				edades[j] = edadAux;
			}
		}
	}
}

void pedirString(char* cadena, char* mensaje, char* mensajeError, int max)
{
	char cadenaSinValidar[200];
	int tam;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", cadenaSinValidar);
	tam = strlen(cadenaSinValidar);

	while(tam > max)
	{
		printf("%s", mensajeError);
		fflush(stdin);
		scanf("%[^\n]", cadenaSinValidar);
		tam = strlen(cadenaSinValidar);
	}

	strcpy(cadena, cadenaSinValidar);
}

void mostrarPersonas(int* edades, char nombres[][TAMNOMBRE], int tam)
{
	int i;
	for(i = 0; i < tam; i++)
	{
		printf("Su nombre es %s, su edad es %d\n", nombres[i], edades[i]);
	}
}

void pedirPersonas(char nombres[][TAMNOMBRE], int* edades, int tam, int tamMaxNombre)
{
	int i;
	for(i = 0; i < tam; i++)
	{
		edades[i] = pedirEntero("Ingrese su edad: ", "Ingrese edad valida (18-60): ", 18, 60);
		pedirString(nombres[i], "Ingrese su nombre: ", "Ingrese nombre valido (hasta 30 caracteres)", tamMaxNombre);
	}
}

int pedirEntero(char* mensaje, char* mensajeError, int min, int max)
{
	int numeroIngresado;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &numeroIngresado);

	while(numeroIngresado < min || numeroIngresado > max)
	{
		printf("%s", mensajeError);
		fflush(stdin);
		scanf("%d", &numeroIngresado);
	}

	return numeroIngresado;
}

