#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassanger.h"
#include "outputs.h"
#include "inputs.h"

int indicoPasajero(Passenger list[], int len)
{
	int i;
	int index=-1;
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == LIBRE)
		{
			index = i;
			break;
		}
	}
	return index;
}

int initPassengers(Passenger list[], int len)
{
	int i;
	int index = -1;

	if(len == MAX)
	{
		for(i=0; i<len; i++)
		{
			list[i].isEmpty = LIBRE;
			index = 0;
		}
	}
	return index;
}

void altaPasajeros(Passenger* list, int len, Type* typeP, Status* status, int* flag)
{
	int respuestaCargar;
	respuestaCargar = cargarPasajero(list, MAX, typeP, status);

	if(respuestaCargar==-1)
	{
		printf("No se pudo cargar el pasajero\n");
		system("pause");
	}
	else
	{
		printf("Carga realizada con exito\n");
		*flag=1;
		system("pause");
	}
	system("pause");
	limpiarConsola();
}

int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int idtype, int idStatusFlight, char flycode[], Type typeP[], Status status[])
{
	int retorno;
	int indice;

	if(list!= NULL && len > 0)
	{
		indice = indicoPasajero(list,len);
		if(indice != -1)
		{
			list[indice].id = id;
			SizeString(name);
			strcpy(list[indice].name, name);
			SizeString(lastName);
			strcpy(list[indice].lastName, lastName);
			list[indice].price = price;
			list[indice].idType = idtype;
			list[indice].idStatusFlight = idStatusFlight;
			strcpy(list[indice].flycode, flycode);

			printf("\nEl pasajero a AGREGAR es...\n\n"
				   " ___________________________________________________________________________________________________________________\n"
				   "|%-5s|%-15s|%-15s|%-13s|%-21s|%-20s|%-20s|\n"
				   "|=====|===============|===============|=============|=====================|====================|====================|",
				     "ID",     "Nombre",      "Apellido",     "Precio",   "Tipo de pasajero",    "Estado de Vuelo",   "Codigo de vuelo");
			mostrarUnPasajero(list[indice]);
			printf("\n|_____|_______________|_______________|_____________|_____________________|____________________|____________________|\n");

			if(!verificarConfirmacion("\nIngrese 's' para confirmar el alta del producto: "))
			{
				list[indice].isEmpty = OCUPADO;
				retorno = 0;
			}else
			{
				retorno = -1;
			}
		}
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

int cargarPasajero(Passenger* list, int len, Type* typeP, Status* status)
{
	int id;
	char nombre[51];
	char apellido[51];
	float precio;
	char codigodeVuelo[10];
	int idTipo;
	int idEstadoVuelo;
	int retorno;

	if(list!= NULL && len > 0)
	{
		retorno = indicoPasajero(list,len);
		if (retorno != -1)
		{
			id = retorno + 1;
			utn_getString(nombre, "Ingrese nombre: ", "ERROR. Ingrese nombre nuevamente, hasta 51 caracteres, reingrese: ", 51, 3);
			utn_getString(apellido, "Ingrese apellido: ", "ERROR. Ingrese apellido nuevamente, hasta 51 caracteres, reingrese: ", 51, 3);
			utn_getFloat(&precio, "Ingrese precio: ", "ERROR. Ingrese precio nuevamente : ", 1, 1000000000, 3);
			mostrarTipoPasajero(typeP, TY);
			utn_getInt(&idTipo, "Ingrese el tipo (Turistica = 1, Economica = 2, Business = 3, Primera clase = 4): ", "ERROR. Ingrese el tipo nuevamente (Turistica = 1, Economica = 2, Business = 3, Primera clase = 4): ", 0, 4, 3);
			mostrarEstadoDeVuelo(status, TS);
			utn_getInt(&idEstadoVuelo, "Ingrese el estado de vuelo (Activo = 1, Inactivo = 2, Demorado = 3): ", "ERROR. Ingrese el estado de vuelo (Activo = 1, Inactivo = 2, Demorado = 3): ", 0, 3, 3);
			pedirCadena(codigodeVuelo, "Ingrese codigo de vuelo: ", "ERROR. Ingrese codigo de vuelo nuevamente: ", 10);
			retorno = addPassenger(list,len,id,nombre,apellido,precio,idTipo,idEstadoVuelo,codigodeVuelo,typeP,status);
		}
	}
	return retorno;
}

void modificarPasajeros(Passenger* list, int len, Type* typeP, Status* status, int* flag)
{
	int respuestaModificar;
	if(*flag==1)
	{
		respuestaModificar = modificoPasajero(list, MAX, typeP, status);
		if(respuestaModificar == -1)
		{
			printf("No se pudo realizar la modificacion\n");
			system("pause");
		}
		else if(respuestaModificar == 1)
		{
			printf("Se cancelo la modificacion\n");
			system("pause");
		}
		else
		{
			printf("Modificacion realizada correctamente\n");
			system("pause");
		}
	}
	else
	{
		printf("Error, debe tener cargado minimo 1 pasajero para ingresar a esta opcion.\n");
		system("pause");
	}
}

int modificoPasajero(Passenger* list, int len, Type* typeP, Status* status)
{
	int retorno; //0 si no se pudo borrar, 1 si se pudo borrar
	int index;
	char nombre[51];
	char apellido[51];
	float precio;
	int idTipo;
	int idEstadoVuelo;
	int opcion;
	Passenger aux;

	if (list != NULL && len > 0)
	{
		printPassenger(list, len ,typeP, status);
		index = findPassengerById(list, len);
		aux = list[index];
		if(index!=-1)
		{
			retorno=0;
			printf("\nEl pasajero a MODOFICAR es...\n"
				   " ___________________________________________________________________________________________________________________\n"
				   "|%-5s|%-15s|%-15s|%-13s|%-21s|%-20s|%-20s|\n"
				   "|=====|===============|===============|=============|=====================|====================|====================|",
				   	 "ID",     "Nombre",      "Apellido",    "Precio",     "Tipo de pasajero",   "Estado de Vuelo",   "Codigo de vuelo");
			mostrarUnPasajeroConDescripcion(list[index], typeP, status);
			printf("\n|_____|_______________|_______________|_____________|_____________________|____________________|____________________|\n");

			pedirEntero(&opcion, "-------------------------------------\n"
								 "1. Nombre Pasajero\n"
								 "2. Apellido Pasajero\n"
								 "3. Precio Pasajero\n"
								 "4. Tipo de Pasajero Pasajero\n"
								 "5. Codigo de vuelo Pasajero\n"
								 "6. No quiero modificar nada\n"
								 "-------------------------------------\n"
								 "Ingrese que desea modificar: ",
								 "-------------------------------------\n"
								 "1. Nombre Pasajero\n"
								 "2. Apellido Pasajero\n"
								 "3. Precio Pasajero\n"
								 "4. Tipo de Pasajero Pasajero\n"
								 "5. Codigo de vuelo Pasajero\n"
								 "6. No quiero modificar nada\n"
								 "-------------------------------------\n"
								 "Opcion invalida, reingrese: ", 1, 6);
			switch(opcion)
			{
			case 1:
				limpiarConsola();
				utn_getString(nombre, "Ingrese un nuevo nombre: ", "ERROR. Ingrese nombre nuevamente, hasta 51 caracteres, reingrese: ", 51, 3);
				SizeString(nombre);
				strcpy(aux.name, nombre);
				break;
			case 2:
				limpiarConsola();
				utn_getString(apellido, "Ingrese un nuevo apellido: ", "ERROR. Ingrese nombre nuevamente, hasta 51 caracteres, reingrese: ", 51, 3);
				SizeString(apellido);
				strcpy(aux.lastName, apellido);
				break;
			case 3:
				limpiarConsola();
				utn_getFloat(&precio, "Ingrese un nuevo precio: ", "ERROR. Ingrese precio nuevamente : ", 1, 1000000000, 3);
				aux.price = precio;
				break;
			case 4:
				limpiarConsola();
				mostrarTipoPasajero(typeP, TY);
				utn_getInt(&idTipo, "Ingrese el tipo (Turistica = 1, Economica = 2, Business = 3, Primera clase = 4): ", "ERROR. Ingrese el tipo nuevamente (Turistica = 1, Economica = 2, Business = 3, Primera clase = 4): ", 0, 4, 3);
				aux.idType = idTipo;
				break;
			case 5:
				limpiarConsola();
				mostrarEstadoDeVuelo(status, TS);
				utn_getInt(&idEstadoVuelo, "Ingrese el estado de vuelo (Activo = 1, Inactivo = 2, Demorado = 3): ", "ERROR. Ingrese el estado de vuelo (Activo = 1, Inactivo = 2, Demorado = 3): ", 0, 3, 3);
				aux.idStatusFlight = idEstadoVuelo;
			break;
			case 6:
				printf("Saliendo");
			break;
			default:
				printf("Opcion no valida");
			}

			if(retorno==0)
			{
				printf("\nEl pasajero a modificar va a quedar de la siguiente manera:...\n"
					   " ___________________________________________________________________________________________________________________\n"
					   "|%-5s|%-15s|%-15s|%-13s|%-21s|%-20s|%-20s|\n"
					   "|=====|===============|===============|=============|=====================|====================|====================|",
					      "ID",   "Nombre",       "Apellido",     "Precio",    "Tipo de pasajero",   "Estado de Vuelo",   "Codigo de vuelo");
				mostrarUnPasajeroConDescripcion(aux, typeP, status);
				printf("\n|_____|_______________|_______________|_____________|_____________________|____________________|____________________|\n");

				if(!verificarConfirmacion("\nIngrese 's' para confirmar la modificacion del pasajero: "))
				{
					list[index]=aux;
				}
				else
				{
					printf("\nNo se realizo la modificacion");
					retorno = 1;
				}
			}
		}
		else
		{
			retorno = -1;
		}
	}
	else
	{
		retorno=-1;
	}

	return retorno;
}

int findPassengerById(Passenger* list, int len)
{
	int i;
	int numero;
	int loEncontre=-1; //fuera de indice

	utn_getInt(&numero, "Ingrese el id a buscar: ", "ERROR, no se encontro la ID\n", 0, MAX, 3);
	for(i=0; i<len; i++)
	{
		if(numero == list[i].id && list[i].isEmpty == OCUPADO)
		{
			loEncontre=i;
		}
	}
	return loEncontre;
}

void bajaPasajeros(Passenger* list, int len, Type* typeP, Status* status, int* flag)
{
	int respuestaBorrar;
	if(*flag == 1)
	{
		respuestaBorrar = removePassenger(list, MAX, typeP, status);
		if(respuestaBorrar == -1)
		{
			printf("No se pudo Borrar al pasajero\n");
			system("pause");
		}
		else
		{
			printf("Pasajero borrado con exito\n");
			system("pause");
		}
	}
	else
	{
		printf("Error, debe tener cargado minimo 1 pasajero para ingresar a esta opcion.\n");
		system("pause");
	}
	system("pause");
	limpiarConsola();
}

int removePassenger(Passenger* list, int len, Type* typeP, Status* status)
{
	int retorno=-1; //0 si no se pudo borrar, 1 si se pudo borrar
	int index;

	printPassenger(list, len ,typeP, status);
	index = findPassengerById(list,len);

	if(index!=-1)
	{
		printf("\nEl pasajero que quiere ELIMINAR es: \n"
			   " ___________________________________________________________________________________________________________________\n"
			   "|%-5s|%-15s|%-15s|%-13s|%-21s|%-20s|%-20s|\n"
			   "|=====|===============|===============|=============|=====================|====================|====================|",
			     "ID",     "Nombre",      "Apellido",    "Precio",     "Tipo de pasajero",   "Estado de Vuelo",   "Codigo de vuelo");
		mostrarUnPasajeroConDescripcion(list[index], typeP, status);
		printf("\n|_____|_______________|_______________|_____________|_____________________|____________________|____________________|\n");
		if(!verificarConfirmacion("\nIngrese 's' para confirmar la baja del pasajero: "))
		{
			retorno = 0;
			list[index].isEmpty = LIBRE;
		}
		else
		{
			printf("\nNo se realizo la baja");
			retorno = -1;
		}
	}
	return retorno;
}

void cargaForzada(Passenger* list, int len, int* flag)
{
    int id[] = {1,2,3,4};
    char name[][51]={"Christian","Matias","Juliana","Leo"};
    char lastName[][51]= {"Tignino","Peron","Hernandez","Elizalde"};
    float price[]={50000,25000,60000,30000};
    char flycode[][10]={"23c23r","dwq3e23","awd223r","thtr345"};
    int typePassenger[]={1,4,1,2};
    int statusFlight[]={1,3,2,1};
    int isEmpty[]={1,1,1,1};

    for(int i=0;i<4;i++)
    {
    	list[i].id = id[i];
        strcpy(list[i].name, name[i]);
        strcpy(list[i].lastName, lastName[i]);
        list[i].price = price[i];
        strcpy(list[i].flycode, flycode[i]);
        list[i].idType = typePassenger[i];
        list[i].idStatusFlight = statusFlight[i];
        list[i].isEmpty = isEmpty[i];
    }
    *flag = 1;
    printf("Carga Forzada EXITOSA\n");
    system("pause");

}

