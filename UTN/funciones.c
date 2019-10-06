#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "funciones.h"


void inicializarOrquesta(eOrquesta vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

int menu()
{
    int option;




    printf("***TEATRO***\n\n\n\n");
    printf("1.Agregar orquesta\n");
    printf("2.Eliminar orquesta\n");
    printf("3.Imprimir orquesta\n");
    printf("4.Agregar musico\n");
    printf("5.Modificar musico\n");
    printf("6.Eliminar musico\n");
    printf("7.Imprimir musico\n");
    printf("8.Agregar instrumento\n");
    printf("9.Imprimir instrumentos\n");
    getInt(&option,"Ingrese opcion\n","Reingrese opcion\n",1,9,3);

    return option;

}


int buscarLibreOrquesta(eOrquesta vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarPorIdOrquesta(eOrquesta vec[],int leg, int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].id == leg && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaOrquesta(eOrquesta vec[], int tam)
{
	eOrquesta auxL;
	int retorno = -1;
	printf("ALTA\n");
	if (buscarLibreOrquesta(vec, tam) == -1)
    {
		printf("ERROR,No hay mas lugar  para ingresar \n ");
	}
	else
    {
		if (getString(auxL.nombre, "Ingrese nombre\n", "Error\n", 0, 50, 3)!= -1)
        {
			if (getString(auxL.lugar, "Ingrese lugar\n", "Error\n", 0,50, 3) == 0)
            {
               if(getInt(&auxL.tipo,"Ingrese tipo: \n1.Sinfonica\n2.Filarmonica\n3.Camara\n","Reingrese tipo\n",1,3,3)==0)
                {
                    if (altaOrquestaPorId(vec,tam,auxL)== 0)
                    {
                        printf("Alta exitosa\n");
                        retorno = 0;
                    }
                }

            }
        }
        if (retorno != 0)
        {
            printf("Error al cargar los datos\n");
        }
    }
    return retorno;
}

int altaOrquestaPorId(eOrquesta vec[], int tam, eOrquesta auxL)
{
	int retorno = -1;
	int index;
	if(vec!=NULL && tam>0){
		index = buscarLibreOrquesta(vec,tam);
		if(index>=0){
			vec[index] = auxL;
			vec[index].isEmpty = 0;
			vec[index].id = generarOrquestaId();
			retorno = 0;
		}
	}
	return retorno;
}


static int generarOrquestaId(void)
{
	static int id = 100;
	id++;
	return id;
}

int imprimirOrquesta(eOrquesta vec[],int tam)
{

   int flag=0;
    printf("ID     NOMBRE    LUGAR     TIPO\n");
    printf("--     ------    -----     ----\n\n");
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarUnaOrquesta(vec[i]);
            flag=1;
        }

    }
    if (flag==0)
    {
        printf("\nNo hay que mostrar\n");
    }
    return flag;
}


void mostrarUnaOrquesta(eOrquesta vec)
{
    printf("%d  %8s   %8s    ",
           vec.id,
           vec.nombre,
           vec.lugar);

    switch(vec.tipo)
    {
        case 1:
            printf("Orquesta Sinfonica\n");
            break;
        case 2:
            printf("Orquesta Filarmonica\n");
            break;
        case 3:
            printf("Orquesta Camara\n");
            break;
        default:
            {
                printf("Opcion invalida");
            }
    }
}

int bajaOrquesta(eOrquesta vec[], int tam,eMusico mus[],int tamU)
{
    int leg;
    int index;
    char respuesta;

    int validacion = -1;

    system("cls");

    imprimirOrquesta(vec,tam);

     getInt(&leg,"Ingrese el id a dar de baja: \n","Reingrese id",1,200,3);

     index = buscarPorIdOrquesta(vec,leg,tam);

    if(index == -1)
    {
        printf("\nNo existe orquesta con ese ID.\n\n");
    }
    else
    {

        mostrarUnaOrquesta(vec[index]);

        printf("\nConfirma baja? <s/n>: ");
        fflush(stdin);
        scanf("%c",&respuesta);

        if(respuesta == 's')
        {
            vec[index].isEmpty = 1;
            bajaMusicoPorOrquesta(mus,tamU,leg);
            validacion = 0;
            printf("\n\n-Baja exitosa-\n\n");
        }
        else if(respuesta == 'n')
        {
            printf("\nSe ha cancelado la operacion.\n\n");
        }
        else
        {
            printf("\nIngrese opcion valida.\n\n");
        }
    }
    return validacion;
}

int bajaMusicoPorOrquesta(eMusico vec[], int tamU, int id)
{
    int retorno=-1;

    for(int i=0;i<tamU;i++)
    {
        if(vec[i].idOrquesta==id)
        {
            vec[i].isEmpty=1;
            retorno =0;
        }
    }

    return retorno;
}

int bajaMusicoPorOrquestaId(eMusico vec[], int tamU, int id)
{
    int retorno=-1;
    int i;
    for(i=0; i<tamU; i++)
    {
        if (vec[i].idOrquesta==id)
        {
            retorno=0;
            id=i;
            break;

        }
    }

    return retorno;
}




void inicializarMusico(eMusico vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

int buscarLibreMusico(eMusico vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaMusico(eMusico vec[], int tam,eInstrumento inst[],int tamI,eOrquesta orq[],int tamO)
{
	eMusico auxM;
	int retorno = -1;
	int validacion;
	int validacion2;
	printf("ALTA\n");
	if (buscarLibreMusico(vec, tam) == -1)
    {
		printf("ERROR,No hay mas lugar  para ingresar \n ");
	}
	else
    {
		if (getString(auxM.nombre, "Ingrese nombre\n", "Error\n", 0, 50, 3)!= -1)
        {
			if (getString(auxM.apellido, "Ingrese apellido\n", "Reingrese apellido\n", 0,50, 3) == 0)
            {
				if (getInt(&auxM.edad,"Ingrese edad\n", "Reingrese edad\n", 1,50, 3) != -1)
                {
                    validacion=imprimirOrquesta(orq,tamO);
                    if(validacion==1)
                    {
                         if  (getInt(&auxM.idOrquesta,"Ingrese orquesta en la que toca\n","Reingrese\n\n",100,1000,3)==0)
                        {
                            validacion2=imprimirInstrumento(inst,tamI);
                            if(validacion2==1)
                            {
                                if(getInt(&auxM.idInstrumento,"Ingrese instrumento que toca\n","Reingrese\n\n",100,1000,3)==0)
                                {

                                    if (altaMusicoPorId(vec,tam,auxM)== 0)
                                    {
                                    printf("Alta exitosa\n");
                                    retorno = 0;

                                    }

                                }

                            }



                        }

                    }

                }
            }
        }
        if (retorno != 0)
        {
            printf("Error al cargar los datos\n");
        }
    }
    return retorno;
}

int altaMusicoPorId(eMusico vec[], int tam, eMusico auxL)
{
	int retorno = -1;
	int index;
	if(vec!=NULL && tam>0){
		index = buscarLibreMusico(vec,tam);
		if(index>=0){
			vec[index] = auxL;
			vec[index].isEmpty = 0;
			vec[index].id = generarMusicoId();
			retorno = 0;
		}
	}
	return retorno;
}


static int generarMusicoId(void)
{
	static int id = 100;
	id++;
	return id;
}


void imprimirMusicos(eMusico vec[],int tam,eInstrumento inst[],int tamI)
{

   int flag=0;
    printf("ID     NOMBRE      APELLIDO     EDAD      INSTRUMENTO       TIPO\n");
    printf("--     ------      -----        ----      -----------       ----\n\n");
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            imprimirUnMusico(vec[i],inst,tamI);
            flag=1;
        }

    }
    if (flag==0)
    {
        printf("\nNo hay musicos que mostrar\n");
    }
}

void mostrarMusicos(eMusico vec[], int tam)
{

   int flag=0;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarUnMusico(vec[i]);
            flag=1;
        }

    }
    if (flag==0)
    {
        printf("\nNo hay musicos que mostrar\n");
    }
}

void mostrarUnMusico(eMusico vec)
{

    printf("%d  %10s   %10s  \n",
           vec.id,
           vec.nombre,
           vec.apellido);
}

void imprimirUnMusico(eMusico vec,eInstrumento inst[],int tamI)
{
    char aux[20];
    int auxT=0;

    cargarDescInstrumento(vec.idInstrumento,inst,tamI,aux,&auxT);
    printf("%d  %8s   %8s          %d     %s       ",
           vec.id,
           vec.nombre,
           vec.apellido,
           vec.edad,aux);
    switch(auxT)
    {
        case 1:
            printf("Cuerdas\n");
            break;
        case 2:
            printf("Vientos-madera\n");
            break;
        case 3:
            printf("Vientos-metal\n");
            break;
        case 4:
            printf("Percusion\n");
            break;
    }

}



void inicializarInstrumento(eInstrumento vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

int buscarPorIdMusico(eMusico vec[],int leg, int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].id == leg && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int altaInstrumento(eInstrumento vec[], int tam)
{
	eInstrumento auxL;
	int retorno = -1;
	printf("ALTA\n");
	if (buscarLibreInstrumento(vec, tam) == -1)
    {
		printf("ERROR,No hay mas lugar  para ingresar \n ");
	}
	else
    {
		if (getString(auxL.nombre, "Ingrese nombre del instrumento\n", "Error\n", 0, 50, 3)!= -1)
        {

			if (getInt(&auxL.tipo, "Ingrese tipo:\n1.Cuerdas\n2.Vientos-madera\n3.Vientos-metal\n4.Percusion\n",
              "Reingrese\n1.Cuerdas\n2.Vientos-madera\n3.Vientos-metal\n4.Percusion\n", 1,4, 3) == 0)
            {
                if (altaInstrumentoPorId(vec,tam,auxL)== 0)
                {
                    printf("\nAlta exitosa!!!!!!!!!\n");
                    retorno = 0;
                }
            }

        }
    }
        if (retorno != 0)
        {
            printf("Error al cargar los datos\n");
        }
    return retorno;
}


int buscarLibreInstrumento(eInstrumento vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaInstrumentoPorId(eInstrumento vec[], int tam, eInstrumento auxL)
{
	int retorno = -1;
	int index;
	if(vec!=NULL && tam>0){
		index = buscarLibreInstrumento(vec,tam);
		if(index>=0){
			vec[index] = auxL;
			vec[index].isEmpty = 0;
			vec[index].id = generarInstrumentoId();
			retorno = 0;
		}
	}
	return retorno;
}

int generarInstrumentoId(void)
{
	static int id = 100;
	id++;
	return id;
}


int buscarPorIdInstrumento(eInstrumento vec[],int leg, int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].id == leg && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int imprimirInstrumento(eInstrumento vec[],int tam)
{

   int flag=0;
    printf("ID     NOMBRE    TIPO\n");
    printf("--     ------    -----\n\n");
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarUnInstrumento(vec[i]);
            flag=1;
        }

    }
    if (flag==0)
    {
        printf("\nNo hay instrumentos que mostrar\n");
    }
    return flag;
}

void mostrarUnInstrumento(eInstrumento vec)
{
    printf("%d  %8s   ",
           vec.id,
           vec.nombre);

    switch(vec.tipo)
    {
        case 1:
            printf("Cuerdas\n");
            break;
        case 2:
            printf("Vientos-madera\n");
            break;
        case 3:
            printf("Vientos-metal\n");
            break;
        case 4:
            printf("Percusion\n");
            break;
    }
}

int cargarDescInstrumento(int id, eInstrumento vec[], int tam, char desc[],int *auxT)
{
    int todoOk = 0;

    for(int i=0; i < tam; i++)
    {
        if( id == vec[i].id)
        {
            strcpy(desc, vec[i].nombre);
            *auxT=vec[i].tipo;
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}


int modificaMusico(eMusico vec[], int tam,eOrquesta orq[], int tamO)
{
    int index;
    int id;
    int validacion = -1;
    int option;

    printf("MODIFICACION DE MUSICOS\n\n");;
    mostrarMusicos(vec,tam);
    getInt(&id,"Ingrese ID a modificar: \n","Reingrese ID valido: \n",100,1000,3);

    index=buscarPorIdMusico(vec,id,tam);

    if(index!=-1)
    {

        if(getInt(&option,"1.Desea modificar edad?\n2.Desea modificar orquesta?\n","Reingrese\n\n1.Desea modificar edad?\n2.Desea modificar orquesta?\n",1,2,3)==0)
        {
            switch(option)
            {
            case 1:
                printf("Modifica edad\n");
                if(getInt(&vec[index].edad,"Ingrese nueva edad: \n","Reingrese nueva edad: \n",1,40,3)==0)
                {
                printf("MODIFICACION EXITOSA!!!\n");
                system("pause");
                validacion=0;
                }
                break;
            case 2:
                printf("Modifica orquesta\n");
                imprimirOrquesta(orq,tamO);
                if(getInt(&vec[index].idOrquesta,"Ingrese nueva orquesta donde pertenece: \n","Reingrese nueva orquesta donde pertenece: \n",100,1000,3)==0)
                {
                printf("MODIFICACION EXITOSA!!!\n");
                system("pause");
                validacion=0;
                }

                break;
            }


        }

    }
    else
    {
        validacion = -1;
    }


    return validacion;
}

int bajaMusico(eMusico vec[], int tam)
{
    int todoOk = 0;
    int legajo;
    int indice;
    char confirma;
    system("cls");
    printf("***** Baja Musico *****\n\n");

    mostrarMusicos(vec,tam);
    getInt(&legajo,"Ingrese legajo a dar de baja\n","Reingrese legajo a dar de baja\n",100,1000,3);

    indice = buscarPorIdMusico(vec,legajo,tam);

    if( indice == -1)
    {
        printf("No existe el musico con ese legajo\n\n");

    }
    else
    {
        mostrarUnMusico(vec[indice]);
        printf("\nConfirma baja?");
        fflush(stdin);
        scanf("%c", &confirma);

        if( confirma == 's')
        {
            vec[indice].isEmpty = 1;
            todoOk = 1;
            printf("Baja exitosa!!!\n\n");
        }
        else
        {
            printf("Se ha cancelado la operacion\n\n");
        }
    }

    return todoOk;
}




/*

int cargarDescTipo(int id, eOrquesta vec[], int tam, char tipo[])
{
    int todoOk = 0;

    for(int i=0; i < tam; i++)
    {
        if( id == vec[i].id)
        {
            strcpy(tipo, vec[i].tipo);
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}








*/





/*
void mostrarListado(eX vec[], int tam)
{

   int flag=0;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarUno(vec[i]);
            flag=1;
        }

    }
    if (flag==0)
    {
        printf("\nNo hay que mostrar\n");
    }
}

eX cargar(void)
{
    eX vec;

    //getInt();
    //getChar();
    //getString();
    //getFloat();



    vec.isEmpty = 0;

    return vec;
}

int cargarListado(eX vec[], int tam)
{

    int indice;
    int respuesta = 0;

    indice = buscarLibre(vec, tam);

    if(indice!=-1)
    {
        //hay lugar
        vec[indice] = cargar();
        respuesta = 1;
    }

    return respuesta;
}







void sorting(eX vec[], int tam)
{
    int i;
    int j;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(vec[i].name,vec[j].name)>0)
            {
                bubbleSorting(vec, i, j);
            }
            else
            {
                if(strcmp(vec[i].name,vec[j].name)==0)
                {
                    if(vec[i].promedio>vec[j].promedio)
                    {
                        bubbleSorting(vec, i, j);
                    }
                }
            }
        }
    }
}

void bubbleSorting(eX vec[],int i,int  j)
{
    eX auxX;

    auxX=vec[i];
    vec[i]=vec[j];
    vec[j]=auxX;
}


int eliminar(eX vec[], int tam)
{
    int leg;
    int i;
    int flag = 0 ;
    char respuesta;

    int validacion = -1;

    mostrarListado(vec,tam);

     //getInt("Ingrese el legajo: ");

     //index = buscarPorId(vec,tam, legajo);

    for(i=0; i<tam; i++)
    {
        if(vec[i].id==leg && vec[i].isEmpty==0)
        {
            mostrarUno(vec[i]);
            printf("Esta seguro que desea eliminar ? :");
            respuesta = getche();
            if(respuesta=='s')
            {
                vec[i].isEmpty = 1;
                validacion = 1;
            }
            else
            {
                validacion = 0;
            }
            break;
        }

        case 0:
        printf("Accion cancelada por el usuario\n");
         case 1:
        printf("Eliminado\n");

        case -1:
        printf("Dato no encontrado\n");


    }
    return validacion;
}

int modificar(eX vec[], int tam, int legajo)
{
    int index;
    int validacion = -1;
    char respuesta;
    eX aux;

    //getInt("Ingrese el legajo: ");

    //index = buscarPorId(vec,tam, legajo);
    if(index!=-1)
    {
        aux = vec[index];
        mostrarUno(aux);


        printf("Esta seguro que desea modificar este alumno? :");
        respuesta = getche();
        if(respuesta=='s')
        {
            vec[index] = aux;
            validacion = 1;
        }
        else
        {
            validacion = 0;
        }

    }
    return validacion;
}


*/




