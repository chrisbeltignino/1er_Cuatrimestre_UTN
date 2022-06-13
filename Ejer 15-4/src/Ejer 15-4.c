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

typedef struct
{
	 int legajo;
	 char nombre[20];
	 int edad;
}eEstudiante;

int cargarEstudiante(eEstudiante* unEstudiante);
void mostrarEstudiantes(eEstudiante* estudiantes, int tam);

int main(void)
{
	setbuf(stdout, NULL);
	eEstudiante estudiantes[3];
	int respuestaCargar;

	respuestaCargar = cargarEstudiante(estudiantes);
	if(respuestaCargar!=-1)
	{
		printf("Se cargo el estudiante\n");
	} else
	{
		printf("No se cargo el estudiante\n");
	}

	mostrarEstudiantes(estudiantes, 3);
	system("pause");

	return EXIT_SUCCESS;
}

int cargarEstudiante(eEstudiante* unEstudiante)
{
	int retorno = -1;

	if(unEstudiante!=NULL)
	{
		printf("Ingrese legajo: ");
		scanf("%d", &unEstudiante->legajo);

		printf("Ingrese el nombre: ");
		fflush(stdin);
		gets(unEstudiante->nombre);

		printf("Ingrese la edad: ");
		scanf("%d", &unEstudiante->edad);
		retorno = 0;
	}
	return retorno;
}

void mostrarEstudiantes(eEstudiante* estudiantes, int tam)
{
	for(int i=0;i<tam;i++)
	{
		if(estudiantes!=NULL)
		{
			printf("|%d     |%s     |%d\n", (estudiantes+i)->legajo, (estudiantes+i)->nombre, (estudiantes+i)->edad);
		}
	}
}
