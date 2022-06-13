#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayConsulta.h"
#include "inputs.h"
#include "outputs.h"

int iniciarConsulta(eConsulta list[], int len)
{
	int i;
	int index = -1;

	if(len == MAX)
	{
		for(i=0; i<len; i++)
		{
			list[i].isEmpty = LIBRE;
			list[i].idDiagnostico = 0;
			list[i].idMecanico = 0;
			index = 0;
		}
	}
	return index;
}

int indicoLibre(eConsulta list[], int len)
{
	int i;
	int index=-1;
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == LIBRE && list[i].idDiagnostico == 0 && list[i].idMecanico == 0)
		{
			index = i;
			break;
		}
	}
	return index;
}

int buscarConsultaID(eConsulta* list, int len)
{
	int i;
	int numero;
	int loEncontre=-1; //fuera de indice

	utn_getInt(&numero, "Ingrese el id a buscar: ", "ERROR, no se encontro la ID\n", 0, MAX, 3);
	for(i=0; i<len; i++)
	{
		if(numero == list[i].idConsulta && list[i].isEmpty == OCUPADO)
		{
			loEncontre=i;
		}
	}
	return loEncontre;
}

int buscarMecanicoID(eMecanico* list, int len)
{
	int i;
	int numero;
	int loEncontre=-1; //fuera de indice

	utn_getInt(&numero, "Ingrese el id a buscar: ", "ERROR, no se encontro la ID\n", 0, MAXM, 3);
	for(i=0; i<len; i++)
	{
		if(numero == list[i].idMecanico)
		{
			loEncontre=i;
		}
	}
	return loEncontre;
}

int buscarEspecialidad(eEspecialidad* list, int len)
{
	int i;
	int numero;
	int loEncontre=-1; //fuera de indice

	utn_getInt(&numero, "Ingrese el id a buscar: ", "ERROR, no se encontro la ID\n", 0, MAXE, 3);
	for(i=0; i<len; i++)
	{
		if(numero == list[i].idEspecialidad)
		{
			loEncontre=i;
		}
	}
	return loEncontre;
}

int buscarConsultaConMecanicoID(eConsulta* list, int len)
{
	int i;
	int numero;
	int loEncontre=-1; //fuera de indice

	utn_getInt(&numero, "Ingrese el id a buscar: ", "ERROR, no se encontro la ID\n", 0, MAX, 3);
	for(i=0; i<len; i++)
	{
		if(numero == list[i].idConsulta && list[i].idMecanico >= 1 && list[i].isEmpty == OCUPADO)
		{
			loEncontre=i;
		}
	}
	return loEncontre;
}

int buscarConsultaSinMecanicoID(eConsulta* list, int len)
{
	int i;
	int numero;
	int loEncontre=-1; //fuera de indice

	utn_getInt(&numero, "Ingrese el id a buscar: ", "ERROR, no se encontro la ID\n", 0, MAX, 3);
	for(i=0; i<len; i++)
	{
		if(numero == list[i].idConsulta && list[i].idMecanico == 0 && list[i].isEmpty == OCUPADO)
		{
			loEncontre=i;
		}
	}
	return loEncontre;
}

void altaConsulta(eConsulta* list, int len, eDiagnostico* diagnostico, eMecanico* mecanico, eFecha* fecha, int* flag)
{
	int respuestaCargar;
	respuestaCargar = cargarConsulta(list, MAX, fecha);

	if(respuestaCargar==-1)
	{
		printf("No se pudo cargar la consulta\n");
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

int agregarConsulta(eConsulta* list, int len, int id, char nombreCliente[], float cotizacion, int dia, int mes, int anio, eFecha* fecha)
{
	int retorno;
	int indice;

	if(list!= NULL && len > 0)
	{
		indice = indicoLibre(list,len);
		if(indice != -1)
		{
			list[indice].idConsulta = id;
			SizeString(nombreCliente);
			strcpy(list[indice].nombreCliente, nombreCliente);
			list[indice].cotizacion = cotizacion;
			list[indice].fecha.dia = dia;
			list[indice].fecha.mes = mes;
			list[indice].fecha.anio = anio;

			printf("\nLa Consulta a AGREGAR es...\n\n"
				   " _______________________________________________________\n"
				   "|%-5s|%-15s|%-19s|%-13s|\n"
				   "|=====|===============|===================|=============|",
				     "ID",     "Nombre",    "Fecha de Consulta",   "Precio");
			mostrarUnaConsultaCSinDiagnostico(list[indice], fecha);
			printf("\n|_____|_______________|___________________|_____________|\n");

			if(!verificarConfirmacion("\nIngrese 's' para confirmar el alta de la Consulta: "))
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

int cargarConsulta(eConsulta* list, int len, eFecha* fecha)
{
	int id;
	char nombre[50];
	float cotizacion;
	int dia;
	int mes;
	int anio;
	int retorno;

	if(list!= NULL && len > 0)
	{
		retorno = indicoLibre(list,len);
		if (retorno != -1)
		{
			id = retorno + 1;
			utn_getString(nombre, "Ingrese nombre: ", "ERROR. Ingrese nombre nuevamente, hasta 51 caracteres, reingrese: ", 50, 3);
			utn_getFloat(&cotizacion, "Ingrese precio: ", "ERROR. Ingrese precio nuevamente : ", 1, 1000000000, 3);
			ingresarFecha(&dia, &mes, &anio);
			fflush(stdin);
			retorno = agregarConsulta(list,len,id,nombre,cotizacion,dia,mes,anio, fecha);
		}
	}
	return retorno;
}

void modificarConsultas(eConsulta* list, int len, eMecanico* mecanico, eDiagnostico* diagnostico, eFecha* fecha, eEspecialidad* especialidad, int* flag)
{
	int respuestaModificar;
	if(*flag==1)
	{
		respuestaModificar = modificoConsulta(list, MAX, mecanico, fecha, diagnostico, especialidad);
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
		printf("Error, debe tener cargado minimo 1 CONSULTA para ingresar a esta opcion.\n");
		system("pause");
	}
}

int modificoConsulta(eConsulta* list, int len, eMecanico* mecanico, eFecha* fecha, eDiagnostico* diagnostico, eEspecialidad* especialidad)
{
	int retorno; //0 si no se pudo borrar, 1 si se pudo borrar
	int index;
	char nombre[50];
	int dia;
	int mes;
	int anio;
	int idMecanico;
	int opcion;
	eConsulta aux;

	if (list != NULL && len > 0)
	{
		mostrarListaConsultaConMecanico(list, len, fecha, diagnostico, mecanico);
		index = buscarConsultaConMecanicoID(list, len);
		aux = list[index];
		if(index!=-1)
		{
			retorno=0;
			printf("\nLa Consulta a MODIFICAR es...\n\n"
				   " _________________________________________________________\n"
				   "|%-5s|%-15s|%-15s|%-13s|\n"
				   "|=====|===============|=====================|=============|",
					 "ID",     "Nombre",    "Fecha de Consulta",   "Mecanico");
			mostrarConsultaConMecanico(list[index], fecha, mecanico);
			printf("\n|_____|_______________|____________________|_____________|\n");

			pedirEntero(&opcion, "-------------------------------------\n"
								 "1. Nombre Cliente\n"
								 "2. Fecha de Consulta\n"
								 "3. Mecanico\n"
								 "4. No quiero modificar nada\n"
								 "-------------------------------------\n"
								 "Ingrese que desea modificar: ",
								 "-------------------------------------\n"
								 "1. Nombre Cliente\n"
								 "2. Fecha de Consulta\n"
								 "3. Mecanico\n"
								 "4. No quiero modificar nada\n"
								 "-------------------------------------\n"
								 "Opcion invalida, reingrese: ", 1, 4);
			switch(opcion)
			{
				case 1:
					limpiarConsola();
					utn_getString(nombre, "Ingrese un nuevo nombre: ", "ERROR. Ingrese nombre nuevamente, hasta 51 caracteres, reingrese: ", 51, 3);
					SizeString(nombre);
					strcpy(aux.nombreCliente, nombre);
					break;
				case 2:
					limpiarConsola();
					ingresarFecha(&dia, &mes, &anio);
					aux.fecha.dia = dia;
					aux.fecha.mes = mes;
					aux.fecha.anio = anio;
					break;
				case 3:
					limpiarConsola();
					mostrarMecanicos(mecanico, especialidad, MAXM);
					utn_getInt(&idMecanico, "Ingrese el Mecanico: ", "ERROR. Ingrese el Mecanico nuevamente: ", 0, MAXM, 3);
					idMecanico = buscarMecanicoID(mecanico, MAXM);
					aux.idMecanico = idMecanico;
					break;
				case 4:
					printf("Saliendo");
					break;
				default:
					printf("Opcion no valida");
			}

			if(retorno==0)
			{
				printf("\nLa Consulta a AGREGAR es...\n\n"
					   " _________________________________________________________\n"
					   "|%-5s|%-15s|%-15s|%-13s|\n"
					   "|=====|===============|=====================|=============|",
						 "ID",     "Nombre",    "Fecha de Consulta",   "Mecanico");
				mostrarConsultaConMecanico(aux, fecha, mecanico);
				printf("\n|_____|_______________|____________________|_____________|\n");

				if(!verificarConfirmacion("\nIngrese 's' para confirmar la modificacion de la Consulta: "))
				{
					list[index]=aux;
				}else
				{
					printf("\nNo se realizo la modificacion");
					retorno = 1;
				}
			}
		}else
		{
			printf("\nNo se encontro la Consulta");
			retorno = -1;
		}
	}else
	{
		retorno=-1;
	}

	return retorno;
}

void bajaConsulta(eConsulta* list, int len, eMecanico* mecanico, eDiagnostico* diagnostico, eFecha* fecha, int* flag)
{
	int respuestaBorrar;
	if(*flag == 1)
	{
		respuestaBorrar = removerConsulta(list, MAX, fecha, diagnostico, mecanico);
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

int removerConsulta(eConsulta* list, int len, eFecha* fecha, eDiagnostico* diagnostico, eMecanico* mecanico)
{
	int retorno=-1; //0 si no se pudo borrar, 1 si se pudo borrar
	int index;

	mostrarListaConsulta(list, len ,fecha, diagnostico, mecanico);
	index = buscarConsultaID(list,len);

	if(index!=-1)
	{
		printf("\nLa Consulta a MODIFICAR es...\n\n"
			   " ______________________________________________________________________________________________\n"
			   "|%-5s|%-15s|%-15s|%-13s|%-13s|%-13s|\n"
			   "|=====|===============|=====================|================|================|================|",
				 "ID",     "Nombre",    "Fecha de Consulta",   "Diagnostico",    "Mecanico",        "Precio");
		mostrarConsultaConTodo(list[index], fecha, diagnostico, mecanico);
		printf("\n|_____|_______________|____________________|________________|________________|________________|\n");
		if(!verificarConfirmacion("\nIngrese 's' para confirmar la BAJA de la Consulta: "))
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

void diagnosticarConsultas(eConsulta* list, int len, eMecanico* mecanico, eDiagnostico* diagnostico, eFecha* fecha, eEspecialidad* especialidad, int* flag)
{
	int respuestaDiagnosticar;
	if(*flag==1)
	{
		respuestaDiagnosticar = diagnosticoConsulta(list, MAX, fecha, mecanico, diagnostico, especialidad);
		if(respuestaDiagnosticar == -1)
		{
			printf("No se pudo realizar el diagnostico\n");
			system("pause");
		}
		else if(respuestaDiagnosticar == 1)
		{
			printf("Se cancelo el diagnostico\n");
			system("pause");
		}
		else
		{
			printf("Diagnostico realizado correctamente\n");
			system("pause");
		}
	}
	else
	{
		printf("Error, debe tener cargado minimo 1 CONSULTA para ingresar a esta opcion.\n");
		system("pause");
	}
}

int diagnosticoConsulta(eConsulta* list, int len, eFecha* fecha, eMecanico* mecanico, eDiagnostico* diagnostico, eEspecialidad* especialidad)
{
	int retorno; //0 si no se pudo borrar, 1 si se pudo borrar
	int index;
	int indexC;
	float precio;
	int idDiagnostico;
	int opcion;
	eConsulta aux;

	if (list != NULL && len > 0)
	{
		mostrarMecanicos(mecanico, especialidad, MAXM);
		index = buscarMecanicoID(mecanico, MAXM);
		if(index!=-1)
		{
			mostrarListaConsultaSinDiagnostico(list, len, fecha, diagnostico);
			indexC = buscarConsultaSinMecanicoID(list, len);
			aux = list[indexC];
			if(indexC!=-1)
			{
				retorno=0;
				printf("\nLa Consulta a DIAGNOSTICAR es...\n\n"
					   " ___________________________________________________________________________\n"
					   "|%-5s|%-15s|%-15s|%-15s|%-15s|\n"
					   "|=====|===============|=====================|===============|===============|",
						 "ID",     "Nombre",    "Fecha de Consulta",  "Diagnostico",    "Precio");
				mostrarConsultaCSinDiagnostico(list[indexC], fecha, diagnostico);
				printf("\n|_____|_______________|____________________|_______________|_______________|\n");
				pedirEntero(&opcion, "-------------------------------------\n"
									 "1. Elegir DIAGNOSTICO\n"
									 "2. No quiero Diagnosticar NADA\n"
									 "-------------------------------------\n"
									 "Ingrese que desea Diagnosticar: ",
									 "-------------------------------------\n"
									 "1. Elegir DIAGNOSTICO\n"
									 "2. No quiero Diagnosticar NADA\n"
									 "-------------------------------------\n"
									 "Opcion invalida, reingrese: ", 1, 2);
				switch(opcion)
				{
					case 1:
						limpiarConsola();
						mostrarDiagnosticos(diagnostico, MAXD);
						utn_getInt(&idDiagnostico, "Ingrese el Diagnostico: ", "ERROR. Ingrese el Mecanico nuevamente: ", 1, MAXD, 3);
						aux.idDiagnostico = idDiagnostico;
						utn_getFloat(&precio, "Ingrese un nuevo precio: ", "ERROR. Ingrese precio nuevamente : ", 1, 1000000000, 3);
						aux.cotizacion = aux.cotizacion +  precio;
						break;
					case 2:
						printf("Saliendo");
						break;
					default:
						printf("Opcion no valida");
				}

				if(retorno==0)
				{
					printf("\nLa Consulta a DIAGNOSTICAR es...\n\n"
						   " ___________________________________________________________________________\n"
						   "|%-5s|%-15s|%-15s|%-15s|%-15s|\n"
						   "|=====|===============|=====================|===============|===============|",
							 "ID",     "Nombre",    "Fecha de Consulta",  "Diagnostico",    "Precio");
					mostrarConsultaConDiagnostico(aux, fecha, diagnostico);
					printf("\n|_____|_______________|____________________|_______________|_______________|\n");

					if(!verificarConfirmacion("\nIngrese 's' para confirmar el DIAGNOSTICO de la Consulta: "))
					{
						aux.idMecanico = index;
						list[indexC]=aux;
					}else
					{
						printf("\nNo se realizo el DIAGNOSTICO");
						retorno = 1;
					}
				}
			}else
			{
				printf("\nNo se encontro la Consulta");
				retorno = -1;
			}
		}else
		{
			printf("\nNo se encontro el Mecanico");
			retorno = -1;
		}
	}else
	{
		retorno=-1;
	}

	return retorno;
}

void cargaForzada(eConsulta* list, int len, int* flag)
{
    int id[] = {1,2,3,4};
    char name[][51] = {"Christian","Matias","Juliana","Leo"};
    eFecha fechas[] = {{2,4,2022},{2,4,2022},{1,2,2023},{20,9,2022}};
    float price[] = {50000,25000,60000,30000};
    int idDiagnostico[] = {1,1,3,1};
    int idMecanico[] = {5,1,1,3};
    int isEmpty[]={1,1,1,1};

    for(int i=0;i<4;i++)
    {
    	list[i].idConsulta = id[i];
        strcpy(list[i].nombreCliente, name[i]);
        list[i].fecha = fechas[i];
        list[i].cotizacion = price[i];
        list[i].idDiagnostico = idDiagnostico[i];
        list[i].idMecanico = idMecanico[i];
        list[i].isEmpty = isEmpty[i];
    }
    *flag = 1;
    printf("Carga Forzada EXITOSA\n");
    system("pause");

}

void HardcodearMecanicos(eMecanico* mecanico, int tam)
{
	eMecanico listaMecanicos[]  =  {{0, "SIN Mecanico",  0},
									{1, "Pepe Argento",  1},
									{2, "Dario Peron",   2},
									{3, "Franco Allende",3},
									{4, "Ricky Ford",    2},
									{5, "Susana Gimena", 4}};

	for(int i=0; i<tam; i++)
	{
		mecanico[i] = listaMecanicos[i];
	}
}
