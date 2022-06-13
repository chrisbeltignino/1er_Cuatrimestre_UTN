#include <stdio.h>

#define TY 4
#define TS 3
#define MAX 300
#define LIBRE 0
#define OCUPADO 1

//#define TAMNAME 51
//#define TAMLASTNAME 51
//#define TAMFLYCODE 10
//#define TAMDESC 10

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int idType;
	int idStatusFlight;
	int isEmpty;
} Passenger;

typedef struct
{
    int idType;
    char typePassenger[20];
} Type;

typedef struct
{
    int idStatusFlight;
    char statusFlight[20];
} Status;

/** \brief Indica la posicion del array del primer LIBRE
*
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int indicoPasajero(Passenger list[], int len);
/** \brief Valida la ALTA y cambia el flag a 1 una vez dada la primera alta
*
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \param list Type* Pointer to array of types
* \param list Status* Pointer to array of status
* \param flag int*
*
*/
void altaPasajeros(Passenger* list, int len, Type* typeP, Status* status, int* flag);
/** \brief Llena todas las variables auxiliares con los datos que el usuario ingrese y lleva como parametro a la funcion "addPassenger[]"
*
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \param list Type* Pointer to array of types
* \param list Status* Pointer to array of status
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int cargarPasajero(Passenger* list, int len, Type* typeP, Status* status);
/** \brief Valida la BAJA una vez que el flag es 1
*
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \param list Type* Pointer to array of types
* \param list Status* Pointer to array of status
* \param flag int*
*
*/
void bajaPasajeros(Passenger* list, int len, Type* typeP, Status* status, int* flag);
/** \brief Valida la MODIFICACION una vez que el flag es 1
*
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \param list Type* Pointer to array of types
* \param list Status* Pointer to array of status
* \param flag int*
*
*/
void modificarPasajeros(Passenger* list, int len, Type* typeP, Status* status, int* flag);
/** \brief Llena todas las variables auxiliares con los datos que el usuario ingrese y modifica los campos de la
 * posicion de la ID ingresada para cambiar
*
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \param list Type* Pointer to array of types
* \param list Status* Pointer to array of status
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int modificoPasajero(Passenger* list, int len, Type* typeP, Status* status);
/** \brief Harcodea todos los campos con los datos ingresados en cada variable y cambia el flag a 1
*
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \param flag int*
*
*/
void cargaForzada(Passenger* list, int len, int* flag);

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger list[],int len);

/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
		  free space] - (0) if Ok
*/
int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int idtype, int idStatusFlight, char flycode[], Type typeP[], Status status[]);

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int len);

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, Type* typeP, Status* status);
