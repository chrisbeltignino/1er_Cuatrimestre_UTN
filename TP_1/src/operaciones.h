/** \brief Funcion de costo con tarjeta de debito
 *
 * \param El precio ingresado
 * \return El resultado del descuento con Tarjeta de Debito
 */
float CalcularPrecioTarjetaDebito(float num);

/** \brief Funcion de costo con tarjeta de credito
 *
 * \param El precio ingresado
 * \return El resultado del descuento con Tarjeta de Credito
 */
float CalcularPrecioTarjetaCredito(float num);

/** \brief Funcion de conversor de peso a BITCOIN
 *
 * \param El precio ingresado
 * \return El resultado en BITCOIN
 */
float CalcularPrecioBitcoin(float num);

/** \brief Funcion de costo por KM
 *
 * \param El precio ingresado y Kilometros
 * \return El resultado del costo por KM
 */
float CalcularPrecioUnitario(float km,float num);

/** \brief Funcion de diferencia de precio
 *
 * \param Precio Aerolineas y Latam, Kilometros
 * \return El resultado es la diferencia de precio de ambos
 */
float CalcularDiferenciaPrecio(float y, float z);

/** \brief Funcion para carga forzada de datos
 */
void CargaForzada(void);

