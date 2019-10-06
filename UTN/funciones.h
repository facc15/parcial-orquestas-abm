#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"

typedef struct
{
    int id;
    int tipo;
    char nombre[50];
    char lugar[50];

    int isEmpty;
}eOrquesta;

typedef struct
{
    char nombre[50];
    char apellido[50];
    int edad;
    int id;
    int idOrquesta;
    int idInstrumento;
    int isEmpty;
}eMusico;

typedef struct
{
    int id;
    char nombre[50];
    int tipo;
    int isEmpty;
}eInstrumento;

int menu();
void inicializarOrquesta(eOrquesta vec[], int tam);
int altaOrquesta(eOrquesta vec[], int tam);
int buscarLibreOrquesta(eOrquesta vec[], int tam);
int buscarPorIdOrquesta(eOrquesta vec[],int leg, int tam);
int altaOrquestaPorId(eOrquesta vec[], int tam, eOrquesta auxL);
static int generarOrquestaId(void);
int imprimirOrquesta(eOrquesta vec[],int tam);
void mostrarUnaOrquesta(eOrquesta vec);
int bajaOrquesta(eOrquesta vec[], int tam,eMusico mus[],int tamU);




void inicializarMusico(eMusico vec[], int tam);
int altaMusico(eMusico vec[], int tam,eInstrumento inst[],int tamI,eOrquesta orq[],int tamO);
int buscarLibreMusico(eMusico vec[], int tam);
int buscarPorIdMusico(eMusico vec[],int leg, int tam);
int altaMusicoPorId(eMusico vec[], int tam, eMusico auxL);
static int generarMusicoId(void);
void imprimirMusicos(eMusico vec[],int tam,eInstrumento inst[],int tamI);
void imprimirUnMusico(eMusico vec,eInstrumento inst[],int tamI);
void mostrarMusicos(eMusico vec[],int tam);
void mostrarUnMusico(eMusico vec);
int modificaMusico(eMusico vec[], int tam,eOrquesta orq[], int tamO);
int bajaMusico(eMusico vec[], int tam);
int bajaMusicoPorOrquestaId(eMusico vec[], int tamU, int id);
int bajaMusicoPorOrquesta(eMusico vec[], int tamU, int id);



int altaInstrumento(eInstrumento vec[], int tam);
void inicializarInstrumento(eInstrumento vec[], int tam);
int buscarLibreInstrumento(eInstrumento vec[], int tam);
int buscarPorIdInstrumento(eInstrumento vec[],int leg, int tam);
int altaInstrumentoPorId(eInstrumento vec[], int tam, eInstrumento auxL);
static int generarInstrumentoId(void);
int imprimirInstrumento(eInstrumento vec[],int tam);
void mostrarUnInstrumento(eInstrumento vec);
int cargarDescInstrumento(int id, eInstrumento vec[], int tam, char desc[],int *auxT);



