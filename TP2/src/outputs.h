#include <stdio.h>

/** \brief Función para encapsular el menu de opciones.
*/
void menu ();
/** \brief Función para "limpar" consola con "\n".
*/
void limpiarConsola(void);
/** \brief Función para separar el menu de la consola con "----".
*/
void mostrarSeparador(void);
/** \brief Función para encapsular el submenu de opciones.
 *
 * \param opcion que el usuario ingrese.
*/
void mostrarMenu(int* opcion);
/** \brief Función para mostrar todos los pasajeros.
 *
 * \param list Passenger*
 * \param len int
 * \param list Type*
 * \param list Status*
 * \param flag int*
 *
*/
void mostrarPasajeros(Passenger* list, int len, Type* typeP, Status* status, int* flag);
/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger* list, int len, int order);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersByCode(Passenger* list, int len, int order);
/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \param list Type*
* \param list Status*
* \return int
*/
int printPassenger(Passenger* list, int len ,Type* typeP, Status* status);
/** \brief Función para devolver la posicion del indice de la estructura Type.
 *
 * \param list Passenger
 * \param len int
 * \param list Type*
 * \return int posicion del indicie
*/
int descripcionTypePassengerr(Passenger list,Type* typeP, int tam);
/** \brief Función para devolver la posicion del indice de la estructura Status.
 *
 * \param list Passenger
 * \param len int
 * \param list Status*
 * \return int posicion del indicie
*/
int descripcionStatusFlight(Passenger list,Status* status, int tam);
/** \brief Función para calcaular el promedio de los pasajeros, el total de
 * 		   precios de todos los pasajeros y los pasajeros con promedio mayor al precio de pasaje .
 *
 * \param list Passenger*
 * \param length Passenger int
 * \param list Type*
 * \param length Type int
 * \param list Status*
 * \param length Status int
 *
*/
void mostrarPromedio(Passenger* list,int len, Type* typeP, int lenT, Status* status, int lenS);
/** \brief Función para mostrar todos los pasajeros los pasajeros ACTIVOS.
 *
 * \param list Passenger*
 * \param len int
 *
*/
void mostrarListaPasajerosActivos(Passenger* list,int len);
/** \brief Función para mostrar todos los pasajeros con los ID de Type y Status.
 *
 * \param list Passenger*
 * \param len int
 *
*/
void mostrarListaPasajeros(Passenger* list,int len);
/** \brief Función para mostrar un pasajero.
 *
 * \param list Passenger*
 *
*/
void mostrarUnPasajero(Passenger list);
/** \brief Función para mostrar un pasajero con la ID de la estructura Type.
 *
 * \param list Passenger
 * \param list Type
 *
*/
void mostrarUnPasajeroConTipo(Passenger list, Type typeP);
/** \brief Función para mostrar todos los pasajeros con la ID de Type y Status.
 *
 * \param list Passenger
 * \param list Type
 * \param list Status
 *
*/
void mostrarUnPasajeroConTodo(Passenger list, Type typeP, Status status);
/** \brief Función para mostrar todos los pasajeros con la descripcion de Type y Status.
 *
 * \param list Passenger
 * \param list Type*
 * \param list Status*
 *
*/
void mostrarUnPasajeroConDescripcion(Passenger list, Type* typeP, Status* status);
/** \brief Función para mostrar la lista de Tipo de Pasajeros.
 *
 * \param list Type
 * \param len int
 *
*/
void mostrarTipoPasajero(Type typeP[], int len);
/** \brief Función para mostrar la lista de Estado de vuelo.
 *
 * \param list Status
 * \param len int
 *
*/
void mostrarEstadoDeVuelo(Status status[], int len);
