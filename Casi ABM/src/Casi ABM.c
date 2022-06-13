#include <stdio.h>
#include <string.h>

#define TAM 3
#define TAMNOMBRE 21

typedef struct
{
	int edad;
	char nombre[TAMNOMBRE];
} sPerrito;

//POR FAVOR CAMBIENLO A UNA BIBLIOTECA
int pedirEntero(char* mensaje, char* mensajeError, int min, int max);
void pedirString(char* cadena, char* mensaje, char* mensajeError, int max);


//POR FAVOR CAMBIENLO A UNA BIBLIOTECA
void cargarPerrito(sPerrito* perrito);
void mostrarPerrito(sPerrito* perrito);
void cargarPerritos(sPerrito* perritos, int tam);
void mostrarPerritos(sPerrito* perritos, int tam);
void ordenarPerritosPorNombreAsc(sPerrito* perritos, int tam);

int main(void) {
	setbuf(stdout, NULL);

	sPerrito perritos[TAM];

	cargarPerritos(perritos, TAM); //LOS ARRAYS SE PASAN SIN AMPERSAND &
	mostrarPerritos(perritos, TAM);

	ordenarPerritosPorNombreAsc(perritos, TAM);
	printf("---------PERRITOS ORDENADOS ASCENDENTE---------\n");
	mostrarPerritos(perritos, TAM);

	/*
	sPerrito perrito;
	sPerrito otroPerrito;

	//cargarPerrito(&perrito);
	//otroPerrito.edad = perrito.edad;
	//strcpy(otroPerrito.nombre, perrito.nombre);



	//otroPerrito = perrito; MAL

	//cargarPerrito(&perrito);
	//mostrarPerrito(&perrito);
	*/
	return 0;
}

//POR FAVOR CAMBIENLO A UNA BIBLIOTECA
void ordenarPerritosPorNombreAsc(sPerrito* perritos, int tam)
{
	int i;
	int j;
	sPerrito auxPerrito;

	for(i=0; i<tam-1; i++)
	{
		for(j=i+1; j<tam; j++)
		{
			if(strcmp(perritos[i].nombre, perritos[j].nombre)==1)
			{
				auxPerrito = perritos[i]; //copiamos la estructura ENTERA
				perritos[i] = perritos[j]; //copiamos la estructura ENTERA
				perritos[j] = auxPerrito; //copiamos la estructura ENTERA
			}
		}
	}
}

void mostrarPerritos(sPerrito* perritos, int tam)
{
	int i;
	for(i=0; i<tam; i++)
	{
		mostrarPerrito(&perritos[i]);
	}
}

void cargarPerritos(sPerrito* perritos, int tam)
{
	int i;
	for(i=0; i<tam; i++)
	{
		cargarPerrito(&perritos[i]);
	}
}

void mostrarPerrito(sPerrito* perrito)
{
	printf("La edad es %d, el nombre es %s\n", (*perrito).edad, (*perrito).nombre);
}

void cargarPerrito(sPerrito* perrito)
{
	(*perrito).edad = pedirEntero("Ingrese la edad del perrito: ", "Ingrese una edad valida (entre 0 y 21)", 0, 21);
	pedirString((*perrito).nombre, "Ingrese el nombre del perrito: ", "Nombre invalido, hasta 21 caracteres, reingrese: ", TAMNOMBRE);
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

