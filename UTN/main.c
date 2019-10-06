#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "funciones.h"

#define tamOrq 5
#define tamMus 5
#define tamInst 20

int main()
{
    eOrquesta orquesta[tamOrq];
    //eOrquesta tipo[tamOrq]={};
    eMusico musico[tamMus];
    eInstrumento instrumento[tamInst];
    char salir='s';


    inicializarOrquesta(orquesta,tamOrq);
    inicializarMusico(musico,tamMus);
    inicializarInstrumento(instrumento,tamInst);

    do
    {
        system("cls");
        switch(menu())
        {
        case 1:
            system("cls");
            altaOrquesta(orquesta,tamOrq);
            system("pause");
            break;
        case 2:
            system("cls");
            bajaOrquesta(orquesta,tamOrq,musico,tamMus);

            system("pause");

            break;
        case 3:
            system("cls");
            imprimirOrquesta(orquesta,tamOrq);
            system("pause");
            break;
        case 4:
            system("cls");
            altaMusico(musico,tamMus,instrumento,tamInst,orquesta,tamOrq);
            system("pause");
            break;
        case 5:
            system("cls");
            modificaMusico(musico,tamMus,orquesta,tamOrq);
            break;
        case 6:
            system("cls");
            bajaMusico(musico,tamMus);
            system("pause");
            break;
        case 7:
            system("cls");
            imprimirMusicos(musico,tamMus,instrumento,tamInst);
            system("pause");

            break;
        case 8:
            system("cls");
            altaInstrumento(instrumento,tamInst);
            system("pause");
            break;
        case 9:
            system("cls");
            imprimirInstrumento(instrumento,tamInst);
            system("pause");

        default:
            {
                printf("Error, opcion invalida\n");
            }
        }

        system("cls");
    }while(salir=='s');




    return 0;
}
