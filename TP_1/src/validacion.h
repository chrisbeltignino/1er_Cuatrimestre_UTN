/** \brief funcion para pedir numero.
 *
 * \param char mensaje[] se escribe el mensaje
 * \return El numero ingresado
 */
float pedirNumero(char mensaje[], char mensajeError[]);

/** \brief Funcion para calcular todos los costos.
 *
 * \param KM, Precio Aerolineas, Precio Latam, Precio tarjeta debito Aerolineas, Precio tarjeta credito Aerolineas,
 * 		  Precio Bitcoin Aerolineas, Precio Unitario Aerolineas, Precio tarjeta debito Latam, Precio tarjeta credito Latam,
 * 		  Precio Bitcoin Latam, Precio Unitario Latam, Diferencia de precios de Aerolineas y Latam.
 */
void CalcularTodo(float x, float y, float z, float* precioTarjDebA, float* precioTarjCredA, float* precioBitA, float* precioUnitA, float* precioTarjDebL, float* precioTarjCredL, float* precioBitL, float* precioUnitL, float* difPrecio);

/** \brief Funcion para mostrar todos los costos.
 *
 * \param KM, Precio Aerolineas, Precio Latam, Precio tarjeta debito Aerolineas, Precio tarjeta credito Aerolineas,
 * 		  Precio Bitcoin Aerolineas, Precio Unitario Aerolineas, Precio tarjeta debito Latam, Precio tarjeta credito Latam,
 * 		  Precio Bitcoin Latam, Precio Unitario Latam, Diferencia de precios de Aerolineas y Latam.
 */
void MostrarCostos(float x, float y, float z, float precioTarjDebA, float precioTarjCredA, float precioBitA, float precioUnitA, float precioTarjDebL, float precioTarjCredL, float precioBitL, float precioUnitL, float difPrecio);
