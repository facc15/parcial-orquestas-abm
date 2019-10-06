/** \brief Solicita un número al usuario y lo valida
 * \param pResultado Se carga el numero ingresado
 * \param pMensaje Es el mensaje a ser mostrado
 * \param pMensajeError  Es el mensaje a ser mostrado en caso de error
 * \param minimo Limite minimo a validar
 * \param maximo Limite maximo a validar
 * \return Si obtuvo el numero [0] si no [-1]
 */
int getInt(int *pResultado,
          char *pMensaje,
          char *pMensajeError,
          int minimo,
          int maximo,
          int reintentos);


/** \brief Solicita un número (flotante) al usuario y lo valida
 * \param pResultado Se carga el numero ingresado
 * \param pMensaje Es el mensaje a ser mostrado
 * \param pMensajeError  Es el mensaje a ser mostrado en caso de error
 * \param minimo Limite minimo a validar
 * \param maximo Limite maximo a validar
 * \return Si obtuvo el numero [0] si no [-1]
 */
float getFloat(float *pResultado,
          char *pMensaje,
          char *pMensajeError,
          float minimo,
          float maximo,
          int reintentos);


/** \brief Solicita un caracter al usuario y lo valida
 * \param pResultado Se carga el caracter ingresado
 * \param pMensaje Es el mensaje a ser mostrado
 * \param pMensajeError  Es el mensaje a ser mostrado en caso de error
 * \param minimo Limite minimo a validar
 * \param maximo Limite maximo a validar
 * \return Si obtuvo el caracter [0] si no [-1]
 */
char getChar(char *pResultado,
          char *pMensaje,
          char *pMensajeError,
          char minimo,
          char maximo,
          int reintentos);


/** \brief Solicita una cadena de caracteres al usuario y lo valida
 * \param pResultado Se carga el string ingresado
 * \param pMensaje Es el mensaje a ser mostrado
 * \param pMensajeError  Es el mensaje a ser mostrado en caso de error
 * \param minimo longitud minimo a validar
 * \param maximo longitud maximo a validar
 * \return Si obtuvo la cadena [0] si no [-1]
 */
int getString(char *pResultado,
          char *pMensaje,
          char *pMensajeError,
          int minimo,
          int maximo,
          int reintentos);


int esNumerico(char str[]);
int esTelefono(char str[]);
int esAlfanumerico(char str[]);
int esSoloLetras(char str[]);


