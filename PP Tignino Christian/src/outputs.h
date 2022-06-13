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
/** \brief Valida el LISTADO una vez que el flag es 1
 *
 * \param list eConsulta* puntero al array consulta
 * \param len int
 * \param fecha eFecha* puntero al array fecha
 * \param diagnostico eDiagnostico* puntero al array diagnostico
 * \param mecanico eMecanico* puntero al array mecanico
 * \param especialidad eEspecialidad* puntero al array especialidad
 * \param flag int*
 *
*/
void mostrarListados(eConsulta* list, int len, eMecanico* mecanico, eDiagnostico* diagnostico, eFecha* fecha, eEspecialidad* especialidad, int* flag);
/** \brief Función para mostrar todas las consultas con las cadenas de careacteres en lugar de los ID de diagnostico y mecanico.
 *
 * \param list eConsulta* puntero al array consulta
 * \param len int
 * \param fecha eFecha* puntero al array fecha
 * \param diagnostico eDiagnostico* puntero al array diagnostico
 * \param mecanico eMecanico* puntero al array mecanico
 *
*/
int mostrarListaConsulta(eConsulta* list, int len, eFecha* fecha, eDiagnostico* diagnostico, eMecanico* mecanico);
/** \brief Función para mostrar una consultas con las cadenas de careacteres en lugar de los ID de diagnostico y mecanico.
 *
 * \param list eConsulta* puntero al array consulta
 * \param fecha eFecha* puntero al array fecha
 * \param diagnostico eDiagnostico* puntero al array diagnostico
 * \param mecanico eMecanico* puntero al array mecanico
 *
*/
void mostrarConsultaConTodo(eConsulta list, eFecha* fecha, eDiagnostico* diagnostico, eMecanico* mecanico);
/** \brief Función para devolver la posicion del indice de la estructura eDiagnostico.
 *
 * \param list eConsulta
 * \param tam int
 * \param diagnostico eDiagnostico* puntero al array diagnostico
 * \return int posicion del indice
*/
int descripcionDiagnostico(eConsulta list, eDiagnostico* diagnostico, int tam);
/** \brief Función para devolver la posicion del indice de la estructura eMecanico.
 *
 * \param list eConsulta
 * \param tam int
 * \param mecanico eMecanico* puntero al array mecanico
 * \return int posicion del indice
*/
int descripcionMecanico(eConsulta list, eMecanico* mecanico, int tam);
/** \brief Función para mostrar una consulta.
 *
 * \param list eConsulta
 *
*/
void mostrarUnaConsulta(eConsulta list);
/** \brief Función para mostrar todos los mecanicos.
 *
 * \param mecanico eMecanico* puntero al array mecanico
 * \param len int
 *
*/
void mostrarMecanicos(eMecanico* mecanico, eEspecialidad* especialidad, int len);
/** \brief Función para mostrar una mecanico.
 *
 * \param mecanico eMecanico
 *
*/
void mostrarUnMecanico(eMecanico mecanico, eEspecialidad* especialidad);

void mostrarUnMecanicoConCotizacion(eMecanico mecanico, eEspecialidad* especialidad, float cotizacion);
/** \brief Función para devolver la posicion del indice de la estructura eEspecialidad.
 *
 * \param list eMecanico
 * \param tam int
 * \param especialidad eEspecialidad* puntero al array especialidad
 * \return int posicion del indice
*/
int descripcionEspecialidad(eMecanico mecanico, eEspecialidad* especialidad, int tam);
/** \brief Función para mostrar un mecanico sin consultas asignadas.
 *
 * \param list eConsulta* puntero al array consulta
 * \param mecanico eMecanico* puntero al array mecanico
 * \param len int
 *
*/
void mostrarMecanicosSinConsultas(eConsulta* list, eMecanico* mecanico, eEspecialidad* especialidad, int len);
/** \brief Listado de consultas ordenados por fecha, desde el más antiguo hasta el más reciente.
 *
 * \param list eConsulta* puntero al array consulta
 * \param mecanico eMecanico* puntero al array mecanico
 * \param len int
 *
*/
void mostrarConsultasPorFecha(eConsulta* list, int len);
/** \brief Listado de consultas con la suma de cotizacion por fecha y diagnostico "Cambio de Aceite".
 *
 * \param list eConsulta* puntero al array consulta
 * \param len int
 *
*/
void mostrarCotizacionPorFecha(eConsulta* list, int len);
/** \brief Listado de consultas con promedio de cotizacion de cada uno de los mecánicos.
 *
 * \param list eConsulta* puntero al array consulta
 * \param len int
 * \param mecanico eMecanico* puntero al array mecanico
 * \param lenM int
 *
*/
void mostrarCotizacionPorMecanico(eConsulta* list, int len, eMecanico* mecanico, eEspecialidad* especialidad, int lenM);
/** \brief Listado de mecanicos que se hayan asignado consultas.
 *
 * \param list eConsulta* puntero al array consulta
 * \param len int
 * \param mecanico eMecanico* puntero al array mecanico
 * \param lenM int
 *
*/
void mostrarMecanicosConConsultas(eConsulta* list, int len, eMecanico* mecanico, int lenM);
/** \brief Listado de mecanicos ordenados por especialidad del	 alfabéticamente.
 *
 * \param list eConsulta* puntero al array consulta
 * \param len int
 * \param mecanico eMecanico* puntero al array mecanico
 * \param lenM int
 * \param fecha eFecha* puntero al array fecha
 * \param diagnostico eDiagnostico* puntero al array diagnostico
 * \param especialidad eEspecialidad* puntero al array especialidad
 *
*/
void ordenarEspecialidadAlfabeticamente(eConsulta* list, int len, eMecanico* mecanico, int lenM, eFecha* fecha, eDiagnostico* diagnostico, eEspecialidad* especialidad);
/** \brief Listado de consultas entre el mes de Marzo y Mayo del 2022 para una especialidad determinada.
 *
 * \param list eConsulta* puntero al array consulta
 * \param len int
 * \param mecanico eMecanico* puntero al array mecanico
 * \param lenM int
 * \param fecha eFecha* puntero al array fecha
 * \param diagnostico eDiagnostico* puntero al array diagnostico
 * \param especialidad eEspecialidad* puntero al array especialidad
 *
*/
void mostrarListadoConsultaPorMes(eConsulta* list, int len, eMecanico* mecanico, int lenM, eFecha* fecha, eDiagnostico* diagnostico, eEspecialidad* especialidad);
/** \brief Saca el porcentaje de consultas diagnosticados que atiende cada mecánico en función del total de diagnósticos..
 *
 * \param list eConsulta* puntero al array consulta
 * \param len int
 * \param mecanico eMecanico* puntero al array mecanico
 * \param lenM int
 * \param diagnostico eDiagnostico* puntero al array diagnostico
 *
*/
void porcentajeConsultas(eConsulta* list, int len, eMecanico* mecanico, int lenM, eDiagnostico* diagnostico);
/** \brief Listado de consultas con el porcentaje.
 *
 * \param mecanico eMecanico
 * \param len int
 * \param porcentaje float
 *
*/
void mostrarMecanicoPorcentaje(eMecanico mecanico, int len, float porcentaje);
/** \brief Listado de diagnosticos.
 *
 * \param diagnostico eDiagnostico* puntero al array diagnostico
 * \param len int
 *
*/
void mostrarDiagnosticos(eDiagnostico* diagnostico, int len);
/** \brief Listado de consultas con mecanico asignado.
 *
 * \param list eConsulta* puntero al array consulta
 * \param len int
 * \param fecha eFecha* puntero al array fecha
 * \param diagnostico eDiagnostico* puntero al array diagnostico
 * \param mecanico eMecanico* puntero al array mecanico
 *
*/
void mostrarListaConsultaConMecanico(eConsulta* list, int len, eFecha* fecha, eDiagnostico* diagnostico, eMecanico* mecanico);
/** \brief funcion para asignar la cadena de caracter de "nombreMecanico" a la consulta llamada en "mostrarListaConsultaConMecanico".
 *
 * \param list eConsulta
 * \param fecha eFecha* puntero al array fecha
 * \param diagnostico eDiagnostico* puntero al array diagnostico
 * \param mecanico eMecanico* puntero al array mecanico
 *
*/
void mostrarConsultaConMecanico(eConsulta list, eFecha* fecha, eMecanico* mecanico);
/** \brief Listado de consultas sin diagnosticos asignados.
 *
 * \param list eConsulta* puntero al array consulta
 * \param len int
 * \param fecha eFecha* puntero al array fecha
 * \param diagnostico eDiagnostico* puntero al array diagnostico
 *
*/
void mostrarListaConsultaSinDiagnostico(eConsulta* list, int len, eFecha* fecha, eDiagnostico* diagnostico);

void topTresEspecialidades(eMecanico* mecanico, int lenM, eEspecialidad* especialidad, int lenE);

void mostrarUnaConsultaCSinDiagnostico(eConsulta list, eFecha* fecha);
/** \brief funcion para asignar la cadena de caracter de "nombreDiagnostico" a la consulta llamada en "mostrarListaConsultaSinDiagnostico".
 *
 * \param list eConsulta
 * \param fecha eFecha* puntero al array fecha
 * \param diagnostico eDiagnostico* puntero al array diagnostico
 *
*/
void mostrarConsultaCSinDiagnostico(eConsulta list, eFecha* fecha, eDiagnostico* diagnostico);
/** \brief Listado de consultas con diagnosticos asignados.
 *
 * \param list eConsulta* puntero al array consulta
 * \param len int
 * \param fecha eFecha* puntero al array fecha
 * \param diagnostico eDiagnostico* puntero al array diagnostico
 *
*/
void mostrarListaConsultaConDiagnostico(eConsulta* list, int len, eFecha* fecha, eDiagnostico* diagnostico);
/** \brief funcion para asignar la cadena de caracter de "nombreDiagnostico" a la consulta llamada en "mostrarListaConsultaSinDiagnostico".
 *
 * \param list eConsulta
 * \param fecha eFecha* puntero al array fecha
 * \param diagnostico eDiagnostico* puntero al array diagnostico
 *
*/
void mostrarConsultaConDiagnostico(eConsulta list, eFecha* fecha, eDiagnostico* diagnostico);
