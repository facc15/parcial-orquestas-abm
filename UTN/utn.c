#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
//#include "ArrayEmployees.h"

int getInt(int *pResultado,
          char *pMensaje,
          char *pMensajeError,
          int minimo,
          int maximo,
          int reintentos)
{
    int retorno = -1;//DEVUELVE -1 SI ES ERROR
    int buffer;

    if(pResultado != NULL &&
       pMensaje != NULL &&
       pMensajeError != NULL &&
       minimo < maximo &&
       reintentos >=0)
    {
        do
        {
            printf("%s",pMensaje);
            fflush(stdin);

            if(scanf("%d",&buffer)==1)
            {
                if(buffer >= minimo && buffer <= maximo)
                {
                    retorno = 0;//DEVUELVE 0
                    *pResultado = buffer;
                    break;
                }
            }
            printf("%s",pMensajeError);
            reintentos--;

        }while(reintentos >= 0);

    }
    return retorno;//VA A RETORNAR 0 SI ESTA TODOOK
}


float getFloat(float *pResultado,
          char *pMensaje,
          char *pMensajeError,
          float minimo,
          float maximo,
          int reintentos)
{
    int retorno = -1;//DEVUELVE -1 SI ES ERROR
    float buffer;

    if(pResultado != NULL &&
       pMensaje != NULL &&
       pMensajeError != NULL &&
       minimo < maximo &&
       reintentos >=0)
    {
        do
        {
            printf("%s",pMensaje);
            fflush(stdin);

            if(scanf("%f",&buffer)==1)
            {
                if(buffer >= minimo && buffer <= maximo)
                {
                    retorno = EXIT_SUCCESS;//DEVUELVE 0
                    *pResultado = buffer;
                    break;
                }
            }
            printf("%s",pMensajeError);
            reintentos--;

        }while(reintentos >= 0);

    }
    return retorno;//VA A RETORNAR 0 SI ESTA TODOOK
}

char getChar(char *pResultado,
          char *pMensaje,
          char *pMensajeError,
          char minimo,
          char maximo,
          int reintentos)
{
    int retorno = -1;//DEVUELVE -1 SI ES ERROR
    char buffer;

    if(pResultado != NULL &&
       pMensaje != NULL &&
       pMensajeError != NULL &&
       minimo < maximo &&
       reintentos >=0)
    {
        do
        {
            printf("%s",pMensaje);
            fflush(stdin);

            if(scanf("%c",&buffer)==1)
            {
                if(buffer >= minimo && buffer <= maximo)
                {
                    retorno = EXIT_SUCCESS;//DEVUELVE 0
                    *pResultado = buffer;
                    break;
                }
            }

            printf("%s",pMensajeError);
            reintentos--;

        }while(reintentos >= 0);

    }
    return retorno;//VA A RETORNAR 0 SI ESTA TODOOK
}

int getString(char *pResultado,
          char *pMensaje,
          char *pMensajeError,
          int minimo,
          int maximo,
          int reintentos)
{
    int retorno = -1;
    char buffer[500];

    if(pResultado != NULL &&
       pMensaje != NULL &&
       pMensajeError != NULL &&
       minimo < maximo &&
       reintentos >=0)
       {
           do
           {
               printf("%s",pMensaje);
               fflush(stdin);
               fgets(buffer,sizeof(buffer),stdin);
               //retorna cadena si es realizada con �xito.
               buffer[strlen(buffer)-1] = '\0';
               if(strlen(buffer)>=minimo && strlen(buffer)<=maximo)
               {
                   strncpy(pResultado,buffer,maximo+1);
                   retorno = 0;
                   break;
               }

               printf("%s",pMensajeError);
               reintentos--;

           }while(reintentos >=0);
       }
    return retorno;
}


/** \brief Verifica si el valor recibido es num�rico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es num�rico y 0 si no lo es
 */
int esNumerico(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9');
        return 0;
        i++;
    }
    return 1;
}


/** \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 */
int esSoloLetras(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        //va a retornar 0 cuando:
        //si NO es un espacio y que no sea algo que este entra la a y z
        //y algo que no este entre la A y la Z
        if((str[i] != ' ')
           &&(str[i] < 'a' || str[i] > 'z')
           &&(str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}


/** \brief Verifica si el valor recibido tiene letras y n�meros
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y numeros . 0 si no lo es
 *
 */
int esAlfanumerico(char str[])
{

    int i = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ')
           &&(str[i] < 'a' || str[i] > 'z')
           &&(str[i] < 'A' || str[i] > 'Z')
           &&(str[i] < '0' || str[i] > '9'))
           return 0;
        i++;
    }
    return 1;
}


/** \brief Verifica si es valor recibido contiene solo numeros, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo n�meros, espacios y UN gui�n
 */
int esTelefono(char str[])
{
    int i = 0;
    int contadorDeGuiones = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ')
           &&(str[i] != '-')
           &&(str[i] < '0' || str[i] > '9'))
           return 0;
        if(str[i] == '-')
            contadorDeGuiones ++;
        i++;
    }
    return 1;
}




