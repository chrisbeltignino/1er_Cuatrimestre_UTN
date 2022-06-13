#define MAXD 4
#define MAXE 5
#define MAXM 6
#define MAX 300
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
	int idDiagnostico;
	char nombreDiagnostico[50];
}eDiagnostico;

typedef struct
{
	int idEspecialidad;
	char especialidad[50];
}eEspecialidad;

typedef struct
{
	int idMecanico;
	char nombreMecanico[50];
	int idEspecialidad;
}eMecanico;

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int idConsulta;
	char nombreCliente[50];
	eFecha fecha;
	int idMecanico;
	int idDiagnostico;
	float cotizacion;
	int isEmpty;
}eConsulta;

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list eConsulta[]
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int iniciarConsulta(eConsulta list[],int len);
/** \brief Indica la posicion del array del primer LIBRE
*
* \param list eConsulta[]
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int indicoLibre(eConsulta list[], int len);
/** \brief busca la consulta por ID y devuelve el inidice de la posicion del array.
*
* \param list eConsulta* puntero al array consulta
* \param len int
* \return Return inquiry index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*/
int buscarConsultaID(eConsulta* list, int len);
/** \brief busca el mecanico por ID y devuelve el inidice de la posicion del array.
*
* \param list eMecanico* puntero al array mecanico
* \param len int
* \return Return mechanical index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*/
int buscarMecanicoID(eMecanico* list, int len);
/** \brief busca la Especialidad por ID y devuelve el inidice de la posicion del array.
*
* \param list eEspecialidad* puntero al array especialidad
* \param len int
* \return Return specialty index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*/
int buscarEspecialidad(eEspecialidad* list, int len);
/** \brief busca una consulta con mecanico asignado por ID y devuelve el inidice de la posicion del array.
*
* \param list eEspecialidad* puntero al array especialidad
* \param len int
* \return Return inquiry index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*/
int buscarConsultaConMecanicoID(eConsulta* list, int len);
/** \brief Valida la ALTA y cambia el flag a 1 una vez dada la primera alta
*
* \param list eConsulta* puntero al array consulta
* \param len int Array length
* \param diagnostico eDiagnostico* puntero al array diagnostico
* \param mecanico eMecanico* puntero al array mecanico
* \param fecha eFecha* puntero al array fecha
* \param flag int*
*/
void altaConsulta(eConsulta* list, int len, eDiagnostico* diagnostico, eMecanico* mecanico, eFecha* fecha, int* flag);
/** \brief agrega en la listade consulta los valores que llega
 * por parametros en la primera posicion LIBRE.
 *
* \param list eConsulta* puntero al array consulta
* \param len int
* \param id int
* \param nombreCliente[] char
* \param cotizacion float
* \param dia int
* \param mes int
* \param anio int
* \param list eFecha* puntero al array fecha
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
		  free space] - (0) if Ok
*/
int agregarConsulta(eConsulta* list, int len, int id, char nombreCliente[], float cotizacion, int dia, int mes, int anio, eFecha* fecha);
/** \brief Llena todas las variables auxiliares con los datos que el usuario ingrese
 * y lleva como parametro a la funcion "agregarConsulta()"
*
* \param list eConsulta* puntero al array consulta
* \param len int Array length
* \param fecha eFecha* puntero al arrary fecha
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int cargarConsulta(eConsulta* list, int len, eFecha* fecha);
/** \brief Valida la MODIFICACION una vez que el flag es 1
*
* \param list eConsulta* puntero al array consulta
* \param len int Array length
* \param diagnostico eDiagnostico* puntero al array consulta
* \param mecanico eMecanico* puntero al array mecanico
* \param fecha eFecha* puntero al array fecha
* \param especialidad eEspecialidad* puntero al array especialidad
* \param flag int*
*/
void modificarConsultas(eConsulta* list, int len, eMecanico* mecanico, eDiagnostico* diagnostico, eFecha* fecha, eEspecialidad* especialidad, int* flag);
/** \brief Llena todas las variables auxiliares con los datos que el usuario ingrese y modifica los campos de la
 * posicion de la ID ingresada para cambiar
*
* \param list eConsulta* puntero al array consulta
* \param len int Array length
* \param diagnostico eDiagnostico* puntero al array consulta
* \param mecanico eMecanico* puntero al array mecanico
* \param fecha eFecha* puntero al array fecha
* \param especialidad eEspecialidad* puntero al array especialidad
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int modificoConsulta(eConsulta* list, int len, eMecanico* mecanico, eFecha* fecha, eDiagnostico* diagnostico, eEspecialidad* especialidad);
/** \brief Valida la BAJA una vez que el flag es 1
*
* \param list eConsulta* puntero al array consulta
* \param len int Array length
* \param diagnostico eDiagnostico* puntero al array consulta
* \param mecanico eMecanico* puntero al array mecanico
* \param fecha eFecha* puntero al array fecha
* \param especialidad eEspecialidad* puntero al array especialidad
* \param flag int*
*/
void bajaConsulta(eConsulta* list, int len, eMecanico* mecanico, eDiagnostico* diagnostico, eFecha* fecha, int* flag);
/** \brief hace la baja de la consulta por busqueda de ID, poniendo isEmpty en LIBRE
*
* \param list eConsulta* puntero al array consulta
* \param len int Array length
* \param diagnostico eDiagnostico* puntero al array consulta
* \param mecanico eMecanico* puntero al array mecanico
* \param fecha eFecha* puntero al array fecha
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int removerConsulta(eConsulta* list, int len, eFecha* fecha, eDiagnostico* diagnostico, eMecanico* mecanico);
/** \brief Valida el DIAGNOSTICO una vez que el flag es 1
*
* \param list eConsulta* puntero al array consulta
* \param len int Array length
* \param diagnostico eDiagnostico* puntero al array consulta
* \param mecanico eMecanico* puntero al array mecanico
* \param fecha eFecha* puntero al array fecha
* \param especialidad eEspecialidad* puntero al array especialidad
* \param flag int*
*/
void diagnosticarConsultas(eConsulta* list, int len, eMecanico* mecanico, eDiagnostico* diagnostico, eFecha* fecha, eEspecialidad* especialidad, int* flag);
/** \brief diagnostica las consultas por ID y con diagnostico = 0, e ingresando por ID de mecanico y asignando al idMecanico del array eConsulta
*
* \param list eConsulta* puntero al array consulta
* \param len int Array length
* \param diagnostico eDiagnostico* puntero al array consulta
* \param mecanico eMecanico* puntero al array mecanico
* \param fecha eFecha* puntero al array fecha
* \param especialidad eEspecialidad* puntero al array especialidad
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int diagnosticoConsulta(eConsulta* list, int len, eFecha* fecha, eMecanico* mecanico, eDiagnostico* diagnostico, eEspecialidad* especialidad);
/** \brief Harcodea las consultas con todos los datos ingresados en cada variable auxiliar y cambia el flag a 1
*
* \param list eConsulta* puntero al array consulta
* \param len int Array length
* \param flag int*
*
*/
void cargaForzada(eConsulta* list, int len, int* flag);
/** \brief Harcodea todos los campos con los datos ingresados en cada variable y cambia el flag a 1
*
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \param flag int*
*
*/
void HardcodearMecanicos(eMecanico* mecanico, int tam);

