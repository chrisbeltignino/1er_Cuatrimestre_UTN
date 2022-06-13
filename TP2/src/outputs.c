#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassanger.h"
#include "outputs.h"
#include "inputs.h"

void limpiarConsola(void)
{
	printf("\n\n\n\n");
}

void mostrarSeparador(void)
{
	printf("--------------\n");
}

void mostrarMenu(int* opcion)
{
	pedirEntero(opcion, "-------------------------------------\n"
								 "1. ALTA Pasajero\n"
								 "2. MODIFICAR Pasajero\n"
								 "3. BAJA Pasajero\n"
								 "4. LISTADO Pasajero\n"
	    						 "5. ALTA FORZADA Pasajero\n"
								 "6. SALIR\n"
								 "-------------------------------------\n"
								 "Ingrese una opcion: ",
								 "-------------------------------------\n"
								 "1. ALTA Pasajero\n"
								 "2. MODIFICAR Pasajero\n"
								 "3. BAJA Pasajero\n"
								 "4. LISTADO Pasajero\n"
								 "5. ALTA FORZADA Pasajero\n"
								 "6. SALIR\n"
								 "-------------------------------------\n"
								 "Opcion invalida, reingrese: ", 1, 6);
}

void mostrarPasajeros(Passenger* list, int len, Type* typeP, Status* status, int* flag)
{
	int opcionListado;
	int orden;
	int respuestaMostrar;
	int respuestaMostrarAlfabeticamente;
	if(*flag==1)
	{
		do
		{
			pedirEntero(&opcionListado, "-------------------------------------\n"
										 "1. Listado de los pasajeros ordenados alfabéticamente.\n"
										 "2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n"
										 "3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n"
										 "4. SALIR\n"
										 "-------------------------------------\n"
										 "Ingrese una opcion: ",
										 "-------------------------------------\n"
										 "1. Listado de los pasajeros ordenados alfabéticamente.\n"
										 "2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n"
										 "3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n"
										 "4. SALIR\n"
										 "-------------------------------------\n"
										 "Opcion invalida, reingrese: ", 1, 4);
			switch(opcionListado)
			{
				case 1:
					respuestaMostrar = printPassenger(list, MAX, typeP, status);
					do
					{
						pedirEntero(&orden, "-------------------------------------\n"
											 "1. Listado de los pasajeros ordenados alfabéticamente ASCENDENTE.\n"
											 "2. Listado de los pasajeros ordenados alfabéticamente DESCENDENTE.\n"
											 "3. SALIR\n"
											 "-------------------------------------\n"
											 "Ingrese una opcion: ",
											 "-------------------------------------\n"
											 "1. Listado de los pasajeros ordenados alfabéticamente ASCENDENTE.\n"
											 "2. Listado de los pasajeros ordenados alfabéticamente DESCENDENTE.\n"
											 "3. SALIR\n"
											 "-------------------------------------\n"
											 "Opcion invalida, reingrese: ", 1, 3);
						switch(orden)
						{
							case 1:
								respuestaMostrarAlfabeticamente = sortPassengers(list, MAX, 0);
								if(respuestaMostrarAlfabeticamente == 0)
								{
									printPassenger(list, MAX, typeP, status);
									system("pause");
								}
							break;
							case 2:
								respuestaMostrarAlfabeticamente = sortPassengers(list, MAX, 1);
								if(respuestaMostrarAlfabeticamente == 0)
								{
									printPassenger(list, MAX, typeP, status);
									system("pause");
								}
							break;
						}
					}while(orden!=3);

					if(respuestaMostrar == -1)
					{
						printf("No se pueden mostrar los pasajeros\n");
						system("pause");
					}

				break;
				case 2:
					mostrarPromedio(list, MAX, typeP, TY, status, TS);
					system("pause");

				break;
				case 3:
					respuestaMostrar = printPassenger(list, MAX, typeP, status);
					do
					{
						pedirEntero(&orden, "-------------------------------------\n"
											 "1. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’ ASCENDENTE.\n"
											 "2. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’ DESCENDENTE.\n"
											 "3. SALIR\n"
											 "-------------------------------------\n"
											 "Ingrese una opcion: ",
											 "-------------------------------------\n"
											 "1. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’ ASCENDENTE.\n"
											 "2. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’ DESCENDENTE.\n"
											 "3. SALIR\n"
											 "-------------------------------------\n"
											 "Opcion invalida, reingrese: ", 1, 3);
						switch(orden)
						{
						case 1:
							respuestaMostrarAlfabeticamente = sortPassengersByCode(list, MAX, 0);
							if(respuestaMostrarAlfabeticamente == 0)
							{
								mostrarListaPasajerosActivos(list, MAX);
								system("pause");
							}
						break;
						case 2:
							respuestaMostrarAlfabeticamente = sortPassengersByCode(list, MAX, 1);
							if(respuestaMostrarAlfabeticamente == 0)
							{
								mostrarListaPasajerosActivos(list, MAX);
								system("pause");
							}
						break;
						}
					}while(orden!=3);

					if(respuestaMostrar == -1)
					{
						printf("No se pueden mostrar los pasajeros\n");
						system("pause");
					}
				break;
			}
		}while(opcionListado!=4);
	}else
	{
		printf("Error, debe tener cargado minimo 1 pasajero para ingresar a esta opcion.\n");
		system("pause");
	}
}


int printPassenger(Passenger* list, int len ,Type* typeP, Status* status)
{
	int i;
	printf("\nMostrando lista de pasajeros...\n\n"
		   " ______________________________________________________________________________________________________________________________\n"
		   "|%-5s|%-15s|%-15s|%-13s|%-21s|%-20s|%-20s|%-10s|\n"
		   "|=====|===============|===============|=============|=====================|====================|====================|==========|",
		      "ID",    "Nombre",      "Apellido",     "Precio",    "Tipo de pasajero",   "Estado de Vuelo",   "Codigo de vuelo",  "ESTADO");
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			mostrarUnPasajeroConDescripcion(list[i], typeP, status);
		}
	}
	printf("\n|_____|_______________|_______________|_____________|_____________________|____________________|____________________|__________|\n");
	return 0;
}

void mostrarListaPasajerosActivos(Passenger* list,int len)
{
	int i;
	printf("\nMostrando lista de pasajeros ACTIVOS...\n\n"
		   " ___________________________________________________________________________________________________________________\n"
		   "|%-5s|%-15s|%-15s|%-13s|%-21s|%-20s|%-20s|\n"
		   "|=====|===============|===============|=============|=====================|====================|====================|",
		      "ID",    "Nombre",      "Apellido",     "Precio",    "Tipo de pasajero",   "Estado de Vuelo",   "Codigo de vuelo");
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].idStatusFlight == 1)
		{
			mostrarUnPasajero(list[i]);
		}
	}
	printf("\n|_____|_______________|_______________|_____________|_____________________|____________________|____________________|\n");
}

void mostrarListaPasajeros(Passenger* list,int len)
{
	int i;
	printf("\nMostrando lista de pasajeros...\n\n"
		   " ___________________________________________________________________________________________________________________\n"
		   "|%-5s|%-15s|%-15s|%-13s|%-21s|%-20s|%-20s|\n"
		   "|=====|===============|===============|=============|=====================|====================|====================|",
		     "ID",     "Nombre",      "Apellido",     "Precio",    "Tipo de pasajero",   "Estado de Vuelo",   "Codigo de vuelo");
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			mostrarUnPasajero(list[i]);
		}
	}
	printf("\n|_____|_______________|_______________|_____________|_____________________|____________________|____________________|\n");
}

void mostrarUnPasajero(Passenger list)
{
	printf("\n|%-5d|",list.id);
	printf("%-15s|",list.name);
	printf("%-15s|",list.lastName);
	printf("%-13.2f|",list.price);
	printf("%-21d|",list.idType);
	printf("%-20d|",list.idStatusFlight);
	printf("%-20s|",list.flycode);
}

void mostrarUnPasajeroConTipo(Passenger list, Type typeP)
{
	printf("\n|%-5d|",list.id);
	printf("%-15s|",list.name);
	printf("%-15s|",list.lastName);
	printf("%-13.2f|",list.price);
	printf("%-21d|",typeP.idType);
	printf("%-20d|",list.idStatusFlight);
	printf("%-20s|",list.flycode);
}

void mostrarUnPasajeroConTodo(Passenger list, Type typeP, Status status)
{
	printf("\n|%-5d|",list.id);
	printf("%-15s|",list.name);
	printf("%-15s|",list.lastName);
	printf("%-13.2f|",list.price);
	printf("%-21d|",typeP.idType);
	printf("%-20d|",status.idStatusFlight);
	printf("%-20s|",list.flycode);
}

void mostrarUnPasajeroConDescripcion(Passenger list, Type* typeP, Status* status)
{
    int tipoPasajero;
    int estadoVuelo;

    if(list.isEmpty == OCUPADO)
	{
    	estadoVuelo = descripcionStatusFlight(list, status, TS);
		tipoPasajero = descripcionTypePassengerr(list, typeP, TY);
		printf("\n|%-5d|",list.id);
		printf("%-15s|",list.name);
		printf("%-15s|",list.lastName);
		printf("%-13.2f|",list.price);
		printf("%-21s|",typeP[tipoPasajero].typePassenger);
		printf("%-20s|",status[estadoVuelo].statusFlight);
		printf("%-20s|",list.flycode);
	}
}

void mostrarTipoPasajero(Type typeP[], int len)
{
    int i;

	printf(" ___________________________\n"
		   "|%-5s|%-21s|\n"
		   "|=====|=====================|\n",
		     "ID",   "Tipo de pasajero");

    for(i=0;i<len;i++)
    {
        printf("|%-5d|%-21s|\n", typeP[i].idType, typeP[i].typePassenger);
    }
    printf("|_____|_____________________|\n");
}

void mostrarEstadoDeVuelo(Status status[], int len)
{
    int i;
	printf(" __________________________\n"
		   "|%-5s|%-20s|\n"
		   "|=====|====================|\n",
		      "ID",  "Estado de Vuelo");

    for(i=0;i<len;i++)
    {
        printf("|%-5d|%-20s|\n", status[i].idStatusFlight, status[i].statusFlight);
    }
    printf("|_____|____________________|\n");
}

int descripcionStatusFlight(Passenger list,Status* status, int tam)
{
    int index;

    for(int i=0;i<tam;i++)
    {
        if(list.idStatusFlight==status[i].idStatusFlight)
        {
            index=i;
            break;
        }
    }
    return index;
}

int descripcionTypePassengerr(Passenger list,Type* typeP, int tam)
{
    int index;

    for(int i=0;i<tam;i++)
    {
        if(list.idType==typeP[i].idType)
        {
            index=i;
            break;
        }
    }
    return index;
}

int sortPassengers(Passenger* list, int len, int order)
{
	int i;
	int j;
	Passenger aux;
	if(list != NULL && len > 0 && (order == 0 || order == 1))
	{
		for(i=0; i<len-1; i++)
		{
			for(j=i+1; j<len; j++)
			{
				if(list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO)
				{
					if(strcmp(list[i].lastName, list[j].lastName) < 0 && (list[i].idType < list[j].idType) && order == 1)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}else if(strcmp(list[i].lastName, list[j].lastName) > 0 && (list[i].idType > list[j].idType) && order == 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
				}
			}
		}
	}
	return 0;
}

int sortPassengersByCode(Passenger* list, int len, int order)
{
	int i;
	int j;
	Passenger aux;
	if(list != NULL && len > 0 && (order == 0 || order == 1))
	{
		for(i=0; i<len-1; i++)
		{
			for(j=i+1; j<len; j++)
			{
				if(list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO)
				{
					if(strcmp(list[i].flycode, list[j].flycode) < 0 && order == 1)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}else if(strcmp(list[i].flycode, list[j].flycode) > 0 && order == 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
				}
			}
		}
	}
	return 0;
}

void mostrarPromedio(Passenger* list,int len, Type* typeP, int lenT, Status* status, int lenS)
{
	float precioTotal = 0;
	float promedio;
	float contadorPasajeros = 0;
	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
		 precioTotal = list[i].price + precioTotal;
		 contadorPasajeros++;
		}
	}
	promedio = precioTotal/contadorPasajeros;
	printf("\nPrecio total de los pasajes: %.2f\nPrecio promedio de los pasajes: %.2f\n",precioTotal,promedio);

	printf("\nPasajeros con promedio mayor al precio de pasaje...\n"
		   " ___________________________________________________________________________________________________________________\n"
		   "|%-5s|%-15s|%-15s|%-13s|%-21s|%-20s|%-20s|\n"
		   "|=====|===============|===============|=============|=====================|====================|====================|",
		      "ID",   "Nombre",       "Apellido",    "Precio",     "Tipo de pasajero",   "Estado de Vuelo",   "Codigo de vuelo");
	for(int i = 0; i < len; i++)
	{
		for(int j = 0;j<lenT;j++)
		{
			for(int z = 0;z<lenS;z++)
			{
				if(list[i].isEmpty == OCUPADO && list[i].price > promedio && list[i].idType ==  typeP[j].idType && list[i].idStatusFlight == status[z].idStatusFlight)
				{
					mostrarUnPasajeroConTodo(list[i], typeP[j], status[z]);
				}
			}
		}
	}
	printf("\n|_____|_______________|_______________|_____________|_____________________|____________________|____________________|\n");
}

