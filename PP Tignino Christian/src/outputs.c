#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayConsulta.h"
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
						"1. ALTA Consulta\n"
						"2. MODIFICAR Consulta\n"
						"3. BAJA Consulta\n"
						"4. DIAGNOSTICO Consulta\n"
						"5. CARGA FORAZADA\n"
						"6. LISTADO Consulta\n"
						"7. SALIR\n"
						"-------------------------------------\n"
						"Ingrese una opcion: ",
						"-------------------------------------\n"
						"1. ALTA Consulta\n"
						"2. MODIFICAR Consulta\n"
						"3. BAJA Consulta\n"
						"4. DIAGNOSTICO Consulta\n"
						"5. CARGA FORAZADA\n"
						"6. LISTADO Consulta\n"
						"7. SALIR\n"
						"-------------------------------------\n"
						"Opcion invalida, reingrese: ", 1, 7);
}

void mostrarListados(eConsulta* list, int len, eMecanico* mecanico, eDiagnostico* diagnostico, eFecha* fecha, eEspecialidad* especialidad, int* flag)
{
	int opcionListado;

	if(*flag==1)
	{
		do
		{
			pedirEntero(&opcionListado, "----------------LISTADO-----------------\n"
										"1. Todos los mecánicos.\n"
										"2. Todos los servicios.\n"
										"3. Todos los mecánicos a los cuales no se les haya asignado ningún servicio.\n"
										"4. Listado de servicios ordenados por fecha, desde el más antiguo hasta el más reciente.\n"
										"5. Para una fecha determinada se necesita saber cuál fue la suma de cotizaciones en concepto de cambio de aceite.\n"
										"6. Cotización promedio de cada uno de los mecánicos.\n"
										"7. Determinar cuál/cuáles son los mecánicos que diagnosticaron más servicios.\n"
										"8. Listado de servicios ordenados por especialidad del mecánico alfabéticamente\n"
										"9. Listado de todos los servicios entre el mes de Marzo y Mayo del 2022 para una especialidad determinada.\n"
										"10. Porcentaje de servicio diagnosticados que atiende cada mecánico en función del total de diagnósticos.\n"
										"11. Top 3 de especialidades más estudiadas por los mecánicos.\n"
										"12. SALIR\n"
										"-------------------------------------\n"
										"Ingrese una opcion: ",
										"-------------------------------------\n"
										"1. Todos los mecánicos.\n"
										"2. Todos los servicios.\n"
										"3. Todos los mecánicos a los cuales no se les haya asignado ningún servicio.\n"
										"4. Listado de servicios ordenados por fecha, desde el más antiguo hasta el más reciente.\n"
										"5. Para una fecha determinada se necesita saber cuál fue la suma de cotizaciones en concepto de cambio de aceite.\n"
										"6. Cotización promedio de cada uno de los mecánicos.\n"
										"7. Determinar cuál/cuáles son los mecánicos que diagnosticaron más servicios.\n"
										"8. Listado de servicios ordenados por especialidad del mecánico alfabéticamente\n"
										"9. Listado de todos los servicios entre el mes de Marzo y Mayo del 2022 para una especialidad determinada.\n"
										"10. Porcentaje de servicio diagnosticados que atiende cada mecánico en función del total de diagnósticos.\n"
										"11. Top 3 de especialidades más estudiadas por los mecánicos.\n"
										"12. SALIR\n"
										"-------------------------------------\n"
										"Opcion invalida, reingrese: ", 1, 12);
			switch(opcionListado)
			{
				case 1:
					mostrarMecanicos(mecanico, especialidad, MAXM);
					system("pause");
				break;
				case 2:
					mostrarListaConsulta(list, MAX, fecha, diagnostico, mecanico);
					system("pause");
				break;
				case 3:
					mostrarMecanicosSinConsultas(list, mecanico, especialidad, MAXM);
					system("pause");
				break;
				case 4:
					mostrarConsultasPorFecha(list, MAX);
					mostrarListaConsulta(list, MAX, fecha, diagnostico, mecanico);
					system("pause");
				break;
				case 5:
					mostrarCotizacionPorFecha(list, MAX);
					system("pause");
				break;
				case 6:
					mostrarCotizacionPorMecanico(list, MAX, mecanico, especialidad, MAXM);
					system("pause");
				break;
				case 7:
					mostrarMecanicosConConsultas(list, MAX, mecanico, MAXM);
					system("pause");
				break;
				case 8:
					ordenarEspecialidadAlfabeticamente(list, MAX, mecanico, MAXM, fecha, diagnostico, especialidad);
					system("pause");
				break;
				case 9:
					mostrarListadoConsultaPorMes(list, MAX, mecanico, MAXM, fecha, diagnostico, especialidad);
					system("pause");
				break;
				case 10:
					porcentajeConsultas(list, MAX, mecanico, MAXM, diagnostico);
					system("pause");
				break;
				case 11:
					topTresEspecialidades(mecanico, MAXM, especialidad, MAXE);
					system("pause");
				break;
				case 12:
					printf("Saliendo del LISTADO\n");
				break;

			}
		}while(opcionListado!=12);
	}else
	{
		printf("Error, debe tener cargado minimo 1 pasajero para ingresar a esta opcion.\n");
		system("pause");
	}
}

int mostrarListaConsulta(eConsulta* list, int len, eFecha* fecha, eDiagnostico* diagnostico, eMecanico* mecanico)
{
	int i;
	printf("\nMostrando lista de Consultas...\n\n"
		   " _________________________________________________________________________________________________\n"
		   "|%-5s|%-15s|%-10s|%-21s|%-21s|%-15s|\n"
		   "|=====|===============|==========|=====================|=====================|====================|",
		      "ID",    "Nombre",    "Fecha",     "Diagnostico",        "Mecanico",            "Precio");
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			mostrarConsultaConTodo(list[i], fecha, diagnostico, mecanico);
		}
	}
	printf("\n|_____|_______________|_______________|________________|_____________________|____________________|\n");
	return 0;
}

void mostrarConsultaConTodo(eConsulta list, eFecha* fecha, eDiagnostico* diagnostico, eMecanico* mecanico)
{
    int idDiagnostico;
    int idMecanico;

    if(list.isEmpty == OCUPADO)
	{
    	idDiagnostico = descripcionDiagnostico(list, diagnostico, MAXD);
    	idMecanico = descripcionMecanico(list, mecanico, MAXM);
		printf("\n|%-5d|",list.idConsulta);
		printf("%-15s|",list.nombreCliente);
		printf("%d/%d/%-5d|",list.fecha.dia, list.fecha.mes, list.fecha.anio);
		printf("%-21s|",diagnostico[idDiagnostico].nombreDiagnostico);
		printf("%-20s|",mecanico[idMecanico].nombreMecanico);
		printf("%-13.2f|",list.cotizacion);
	}
}

int descripcionDiagnostico(eConsulta list, eDiagnostico* diagnostico, int tam)
{
    int index;

    for(int i=0;i<tam;i++)
    {
        if(list.idDiagnostico == diagnostico[i].idDiagnostico)
        {
            index=i;
            break;
        }
    }
    return index;
}

int descripcionMecanico(eConsulta list, eMecanico* mecanico, int tam)
{
    int index;

    for(int i=0;i<tam;i++)
    {
        if(list.idMecanico == mecanico[i].idMecanico)
        {
            index=i;
            break;
        }
    }
    return index;
}

void mostrarUnaConsulta(eConsulta list)
{
	printf("\n|%-5d|",list.idConsulta);
	printf("%-15s|",list.nombreCliente);
	printf("%d/%d/%-15d|",list.fecha.dia, list.fecha.mes, list.fecha.anio);
	printf("%-21d|",list.idDiagnostico);
	printf("%-20d|",list.idMecanico);
	printf("%-13.2f|",list.cotizacion);
}

void mostrarMecanicos(eMecanico* mecanico, eEspecialidad* especialidad, int len)
{
    int i;

    printf(" __________________________________________________________\n"
		   "|%-5s|%-21s|%-30s|\n"
		   "|=====|=====================|==============================|\n",
			 "ID",      "Mecanico",               "Especialidad");

    for(i=1;i<len;i++)
    {
    	mostrarUnMecanico(mecanico[i], especialidad);
    }
	printf("|_____|_____________________|______________________________|\n");
}

void mostrarUnMecanico(eMecanico mecanico, eEspecialidad* especialidad)
{
	int idEspecialidad;

	idEspecialidad = descripcionEspecialidad(mecanico, especialidad, MAXE);
	printf("|%-5d|%-21s|%-30s|\n", mecanico.idMecanico, mecanico.nombreMecanico, especialidad[idEspecialidad].especialidad);
}

void mostrarUnMecanicoConCotizacion(eMecanico mecanico, eEspecialidad* especialidad, float cotizacion)
{
	int idEspecialidad;

	idEspecialidad = descripcionEspecialidad(mecanico, especialidad, MAXE);
	printf("|%-5d|%-21s|%-30s|%-18.2f|\n", mecanico.idMecanico, mecanico.nombreMecanico, especialidad[idEspecialidad].especialidad, cotizacion);
}


int descripcionEspecialidad(eMecanico mecanico, eEspecialidad* especialidad, int tam)
{
    int index;

    for(int i=0;i<tam;i++)
    {
        if(mecanico.idEspecialidad == especialidad[i].idEspecialidad)
        {
            index=i;
            break;
        }
    }
    return index;
}

void mostrarMecanicosSinConsultas(eConsulta* list, eMecanico* mecanico, eEspecialidad* especialidad, int len)
{
	int bandera;
    int i;
    int j;

    printf(" __________________________________________________________\n"
		   "|%-5s|%-21s|%-30s|\n"
		   "|=====|=====================|==============================|\n",
			 "ID",      "Mecanico",               "Especialidad");
	for(j=0;j<len;j++)
	{
		bandera = 0;
		for(i=0;i<len;i++)
		{
			if(list[i].idMecanico == mecanico[j].idMecanico)
			{
				bandera = 1;
			}
		}
		if(bandera == 0)
		{
			mostrarUnMecanico(mecanico[j], especialidad);
		}
	}
	printf("|_____|_____________________|______________________________|\n");;

}

void mostrarConsultasPorFecha(eConsulta* list, int len)
{
	eConsulta aux;
	printf("\nMostrando lista de Consultas...\n\n"
			   " _________________________________________________________________________________________________\n"
			   "|%-5s|%-15s|%-10s|%-21s|%-21s|%-15s|\n"
			   "|=====|===============|==========|=====================|=====================|====================|",
			      "ID",    "Nombre",    "Fecha",     "Diagnostico",        "Mecanico",            "Precio");
	for(int i = 0; i<len-1; i++)
	{
		for(int j = i+1; j<len; j++)
		{
			if(list[i].fecha.anio > list[j].fecha.anio)
			{
				aux = list[i];
				list[i] = list[j];
				list[j] = aux;
			}else
			{
				if(list[i].fecha.anio == list[j].fecha.anio)
				{
					if(list[i].fecha.mes > list[j].fecha.mes)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}else
					{
						if(list[i].fecha.mes == list[j].fecha.mes)
						{
							if(list[i].fecha.dia > list[j].fecha.dia)
							{
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							}
						}
					}
				}
			}
		}
	}
	printf("\n|_____|_______________|_______________|________________|_____________________|____________________|\n");
}

void mostrarCotizacionPorFecha(eConsulta* list, int len)
{
	int i;
	int dia;
	int mes;
	int bandera = -1;
	float cotizacion = 0;
	pedirEntero(&mes, "Ingresar el mes: ", "ERROR, reingrese el mes: ", 1, 12);
	pedirEntero(&dia, "Ingresar dia que desea saber la cotizacion general: ", "ERROR, reingrese el dia", 1, 31);

	for(i=0;i<len;i++)
	{
		if(mes == list[i].fecha.mes && dia == list[i].fecha.dia && list[i].idDiagnostico == 1)
		{
			cotizacion = cotizacion + list[i].cotizacion;
			bandera = 0;
		}
	}
	if(bandera==-1)
	{
		printf("No existen servicios con Cambio de Aceite para esa fecha. \n");
	}
	if(cotizacion!=0)
	{
		printf("La cotizacion general de ese dia es %.2f: \n", cotizacion);
	}
}

void mostrarCotizacionPorMecanico(eConsulta* list, int len, eMecanico* mecanico, eEspecialidad* especialidad, int lenM)
{
	int i;
	int j;
	int cont = 0;
	float precio = 0;
	float promedio = 0;

	printf(" _____________________________________________________________________________\n"
		   "|%-5s|%-21s|%-30s|%-18s|\n"
		   "|=====|=====================|==============================|==================|\n",
			 "ID",      "Mecanico",               "Especialidad",          "Cotizacion");
	for(i=0;i<lenM;i++)
	{
		precio = 0;
		cont = 0;
		for(j=0;j<len;j++)
		{
			if(mecanico[i].idMecanico == list[j].idMecanico)
			{
				cont++;
				precio = precio + list[j].cotizacion;
			}
		}
		if(mecanico[i].idMecanico > 0 && precio > 0)
		{
			promedio = precio/cont;
			mostrarUnMecanicoConCotizacion(mecanico[i], especialidad, promedio);
		}else
			if(mecanico[i].idMecanico > 0 && precio == 0)
			{
				promedio = 0;
				mostrarUnMecanicoConCotizacion(mecanico[i], especialidad, promedio);
			}
	}
	printf("|_____|_____________________|______________________________|__________________|\n");
}

void mostrarMecanicosConConsultas(eConsulta* list, int len, eMecanico* mecanico, int lenM)
{
	int i;
	int j;
	int cont;
	int cantConsultas;
	int bandera=1;

	for(i=0;i<lenM;i++)
	{
		cont = 0;
		for(j=0;j<len;j++)
		{
			if(mecanico[i].idMecanico == list[j].idMecanico && mecanico[i].idMecanico > 0)
			{
				cont++;
			}
		}
		if(cont > cantConsultas || bandera == 1)
		{
			cantConsultas = cont;
			bandera = 0;
		}
	}

	printf("----------Cantidad de Consulta por Mecanico---------\n");
	printf(" _____________________________________________________________________________\n"
		   "|%-5s|%-21s|%-30s|%-18s|\n"
		   "|=====|=====================|==============================|==================|\n",
			 "ID",      "Mecanico",               "Especialidad",        "Cant. Consultas");
	for(i=0;i<lenM;i++)
	{
		cont = 0;
		for(j=0;j<len;j++)
		{
			if(mecanico[i].idMecanico == list[j].idMecanico && mecanico[i].idMecanico > 0)
			{
				cont++;
			}
		}
		if(cont == cantConsultas)
		{
			printf("|%-5d|%-21s|%-30d|%-18d|\n", mecanico[i].idMecanico, mecanico[i].nombreMecanico, mecanico[i].idEspecialidad, cantConsultas);
		}
	}
	printf("|_____|_____________________|______________________________|__________________|\n");
}

void ordenarEspecialidadAlfabeticamente(eConsulta* list, int len, eMecanico* mecanico, int lenM, eFecha* fecha, eDiagnostico* diagnostico, eEspecialidad* especialidad)
{
	int i;
	int j;
	eConsulta aux;
	int idDiagnostico;
	int idMecanico;
	int idEspecialidad;

	for(i=0; i<lenM-1; i++)
	{
		for(j=i+1; j<lenM; j++)
		{
			if(strcmp(especialidad[i].especialidad, especialidad[j].especialidad) > 0)
			{
				aux = list[i];
				list[i] = list[j];
				list[j] = aux;
			}
		}
	}
	printf("\nMostrando lista de Consultas...\n\n"
		   " ________________________________________________________________________________________________________________________________\n"
		   "|%-5s|%-15s|%-10s|%-21s|%-21s|%-20s|%-15s|\n"
		   "|=====|===============|==========|=====================|=====================|==============================|====================|",
			  "ID",    "Nombre",    "Fecha",     "Diagnostico",        "Mecanico",                "Especialidad",               "Precio");
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<lenM;j++)
		{
			if(list[i].isEmpty == OCUPADO && mecanico[j].idMecanico == list[i].idMecanico)
			{
				idDiagnostico = descripcionDiagnostico(list[i], diagnostico, MAXD);
				idMecanico = descripcionMecanico(list[i], mecanico, MAXM);
				idEspecialidad = descripcionEspecialidad(mecanico[i], especialidad, MAXE);
				printf("\n|%-5d|",list[i].idConsulta);
				printf("%-15s|",list[i].nombreCliente);
				printf("%d/%d/%-5d|",list[i].fecha.dia, list[i].fecha.mes, list[i].fecha.anio);
				printf("%-21s|",diagnostico[idDiagnostico].nombreDiagnostico);
				printf("%-20s|",mecanico[idMecanico].nombreMecanico);
				printf("%-20s|",especialidad[idEspecialidad].especialidad);
				printf("%-13.2f|",list[i].cotizacion);
			}
		}
	}
	printf("\n|_____|_______________|_______________|________________|_____________________|______________________________|____________________|\n");
}

void mostrarListadoConsultaPorMes(eConsulta* list, int len, eMecanico* mecanico, int lenM, eFecha* fecha, eDiagnostico* diagnostico, eEspecialidad* especialidad)
{
	int idDiagnostico;
	int idMecanico;
	int idEspecialidad;

	//MostrarEspecialidades(especialidadLista, sizeEspe);
	printf("Busque la especialidad entre Marzo y Mayo\n");
	idEspecialidad = buscarEspecialidad(especialidad, MAXE);

	if(idEspecialidad!=-1)
	{
		for(int i=0;i<len;i++)
		{
			for(int j=0;j<lenM;j++)
			{
				if((list[i].fecha.mes >= 3 && list[i].fecha.mes <= 5) && (mecanico[j].idMecanico == list[i].idMecanico) && (mecanico[j].idEspecialidad == idEspecialidad))
				{
					idDiagnostico = descripcionDiagnostico(list[i], diagnostico, MAXD);
					idMecanico = descripcionMecanico(list[i], mecanico, MAXM);
					printf("\n|%-5d|",list[i].idConsulta);
					printf("%-15s|",list[i].nombreCliente);
					printf("%d/%d/%-5d|",list[i].fecha.dia, list[i].fecha.mes, list[i].fecha.anio);
					printf("%-21s|",diagnostico[idDiagnostico].nombreDiagnostico);
					printf("%-20s|",mecanico[idMecanico].nombreMecanico);
					printf("%-20s|",especialidad[idEspecialidad].especialidad);
					printf("%-13.2f|",list[i].cotizacion);
				}
			}
		}
	}else
	{
		printf("No existe ningún servicio asignado a un mecanico con esa especialidad");
	}
}

void porcentajeConsultas(eConsulta* list, int len, eMecanico* mecanico, int lenM, eDiagnostico* diagnostico)
{
	float contDiagnostico;
	float contMecanico;
	float porcentaje;

	for(int i=1;i<len;i++)
	{
		if(list[i].idDiagnostico > 0)
		{
			contDiagnostico++;
		}
	}

	printf("PORCENTAJE DE DIAGNOSTICOS POR MECANICO: \n");
	printf(" _________________________________________\n"
		   "|%-5s|%-21s|%-14s|\n"
		   "|=====|=====================|=============|\n",
			 "ID",      "Mecanico",       "Porcentaje");
	for(int i=1; i<lenM; i++)
	{
		contMecanico = 0;
		for(int j=0; j<len; j++)
		{
			if(list[j].isEmpty == OCUPADO && mecanico[i].idMecanico == list[j].idMecanico)
			{
				contMecanico++;
			}
		}
		if(contMecanico > 0)
		{
			porcentaje = (contMecanico/contDiagnostico)*100;
		}else
		{
			porcentaje = 0;
		}

		mostrarMecanicoPorcentaje(mecanico[i], len, porcentaje);
	}
	printf("|_____|_____________________|______________|\n");
}

void topTresEspecialidades(eMecanico* mecanico, int lenM, eEspecialidad* especialidad, int lenE)
{
	int i;
	int j;
	int cont;
	int cantEspecialidad;
	int bandera=1;

	for(i=0;i<lenE;i++)
	{
		cont = 0;
		for(j=1;j<lenM;j++)
		{
			if(mecanico[i].idEspecialidad == especialidad[j].idEspecialidad)
			{
				cont++;
			}
		}
		if(cont > cantEspecialidad || bandera == 1)
		{
			cantEspecialidad = cont;
			bandera = 0;
		}
	}

	printf("----------------------TOP 3---------------------------\n");
	printf(" _____________________________________________________\n"
		   "|%-5s|%-21s|%-30s|\n"
		   "|=====|=========================|=====================|\n",
			 "ID",      "Especialidad",      "Cant. de Estudiados");
	for(i=0;i<lenE;i++)
	{
		cont = 0;
		for(j=1;j<lenM;j++)
		{
			if(mecanico[i].idEspecialidad == especialidad[j].idEspecialidad)
			{
				cont++;
			}
		}
		if(cont == cantEspecialidad)
		{
			printf("|%-5d|%-21s|%-18d|\n", especialidad[i].idEspecialidad, especialidad[i].especialidad, cantEspecialidad);
		}
	}
	printf("|_____|____________________________|____________________|\n");
}

void mostrarMecanicoPorcentaje(eMecanico mecanico, int len, float porcentaje)
{
	printf("|%-5d|%-21s|%c %-14.2f|\n", mecanico.idMecanico, mecanico.nombreMecanico, '%', porcentaje);
}

void mostrarDiagnosticos(eDiagnostico* diagnostico, int len)
{
    int i;
	printf(" __________________________\n"
		   "|%-5s|%-20s|\n"
		   "|=====|====================|\n",
		      "ID",   "Diagnostico");

    for(i=0;i<len;i++)
    {
        printf("|%-5d|%-20s|\n", diagnostico[i].idDiagnostico, diagnostico[i].nombreDiagnostico);
    }
    printf("|_____|____________________|\n");
}

void mostrarListaConsultaConMecanico(eConsulta* list, int len, eFecha* fecha, eDiagnostico* diagnostico, eMecanico* mecanico)
{
	int i;
	printf("\nMostrando lista de Consultas...\n\n"
		   " _________________________________________________________________________________________________\n"
		   "|%-5s|%-15s|%-15s|%-13s|%-21s|%-20s|\n"
		   "|=====|===============|===============|================|=====================|====================|",
			  "ID",    "Nombre",      "Fecha",      "Diagnostico",        "Mecanico",            "Precio");
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].idMecanico >= 1)
		{
			mostrarConsultaConTodo(list[i], fecha, diagnostico, mecanico);
		}
	}
	printf("\n|_____|_______________|_______________|________________|_____________________|____________________|\n");
}


void mostrarConsultaConMecanico(eConsulta list, eFecha* fecha, eMecanico* mecanico)
{
	int idMecanico;

	if(list.isEmpty == OCUPADO)
	{
		idMecanico = descripcionMecanico(list, mecanico, MAXM);
		printf("\n|%-5d|",list.idConsulta);
		printf("%-15s|",list.nombreCliente);
		printf("%d/%d/%-15d|",list.fecha.dia, list.fecha.mes, list.fecha.anio);
		printf("%-20s|",mecanico[idMecanico].nombreMecanico);
		printf("%-13.2f|",list.cotizacion);
	}
}

void mostrarListaConsultaSinDiagnostico(eConsulta* list, int len, eFecha* fecha, eDiagnostico* diagnostico)
{
	int i;
	printf("\nMostrando lista de Consultas...\n\n"
		   " _________________________________________________________________________________________________\n"
		   "|%-5s|%-15s|%-15s|%-13s|%-21s|%-20s|\n"
		   "|=====|===============|===============|================|=====================|====================|",
			  "ID",    "Nombre",      "Fecha",      "Diagnostico",        "Mecanico",            "Precio");
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].idDiagnostico <=0)
		{
			mostrarConsultaCSinDiagnostico(list[i], fecha, diagnostico);
		}
	}
	printf("\n|_____|_______________|_______________|________________|_____________________|____________________|\n");
}

void mostrarUnaConsultaCSinDiagnostico(eConsulta list, eFecha* fecha)
{
	printf("\n|%-5d|",list.idConsulta);
	printf("%-15s|",list.nombreCliente);
	printf("%d/%d/%-15d|",list.fecha.dia, list.fecha.mes, list.fecha.anio);
	printf("%-13.2f|",list.cotizacion);
}

void mostrarConsultaCSinDiagnostico(eConsulta list, eFecha* fecha, eDiagnostico* diagnostico)
{
	int idDiagnostico;

	if(list.isEmpty == OCUPADO)
	{
		idDiagnostico = descripcionDiagnostico(list, diagnostico, MAXD);
		printf("\n|%-5d|",list.idConsulta);
		printf("%-15s|",list.nombreCliente);
		printf("%d/%d/%-15d|",list.fecha.dia, list.fecha.mes, list.fecha.anio);
		printf("%-21s|",diagnostico[idDiagnostico].nombreDiagnostico);
		printf("%-13.2f|",list.cotizacion);
	}
}

void mostrarListaConsultaConDiagnostico(eConsulta* list, int len, eFecha* fecha, eDiagnostico* diagnostico)
{
	int i;
	printf("\nMostrando lista de Consultas...\n\n"
		   " _________________________________________________________________________________________________\n"
		   "|%-5s|%-15s|%-15s|%-13s|%-21s|%-20s|\n"
		   "|=====|===============|===============|================|=====================|====================|",
			  "ID",    "Nombre",      "Fecha",      "Diagnostico",        "Mecanico",            "Precio");
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].idDiagnostico >=1)
		{
			mostrarConsultaConDiagnostico(list[i], fecha, diagnostico);
		}
	}
	printf("\n|_____|_______________|_______________|________________|_____________________|____________________|\n");
}


void mostrarConsultaConDiagnostico(eConsulta list, eFecha* fecha, eDiagnostico* diagnostico)
{
	int idDiagnostico;

	if(list.isEmpty == OCUPADO)
	{
		idDiagnostico = descripcionDiagnostico(list, diagnostico, MAXD);
		printf("\n|%-5d|",list.idConsulta);
		printf("%-15s|",list.nombreCliente);
		printf("%d/%d/%-15d|",list.fecha.dia, list.fecha.mes, list.fecha.anio);
		printf("%-21s|",diagnostico[idDiagnostico].nombreDiagnostico);
		printf("%-13.2f|",list.cotizacion);
	}
}
