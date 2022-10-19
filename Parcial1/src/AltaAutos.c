#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "AltaAutos.h"
#include "Baja.h"
#include "Modificar.h"
#include "Mostrar.h"


int inicializarAutos(eAuto vec[], int tam)
{
	int todoOk = 0;
	if(vec != NULL && tam > 0)
	{
		for(int i = 0 ; i < tam ; i++)
		{
			vec[i].isEmpty = 1;
		}
		todoOk = 1;
	}
	return todoOk;
}
int inicializarTrabajos(eTrabajo vec[], int tam)
{
	int todoOk = 0;
	if(vec != NULL && tam > 0)
	{
		for(int i = 0 ; i < tam ; i++)
		{
			vec[i].isEmpty = 1;
		}
		todoOk = 1;
	}
	return todoOk;
}

int buscarLibreAutos(int* pIndice, eAuto vec[], int tam)
{
    int todoOk = 0;
    int indice = 1;

    if(pIndice != NULL && vec != NULL && tam > 0)
    {
        for(int i = 0 ; i < tam ; i++)
        {
            if( vec[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
        *pIndice = indice;
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibreTrabajos(int* pIndice, eTrabajo vec[], int tam)
{
    int todoOk = 0;
    int indice = -1;

    if(pIndice != NULL && vec != NULL && tam > 0)
    {
        for(int i = 0 ; i < tam ; i++)
        {
            if( vec[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
        *pIndice = indice;
        todoOk = 1;
    }
    return todoOk;
}

int buscarAuto(int* pIndice, int id, eAuto vec[], int tam)
{
    int todoOk = 0;
    int indice = -1;

    if(pIndice != NULL && vec != NULL && tam > 0)
    {
        for(int i = 0 ; i < tam ; i++)
        {
            if( !vec[i].isEmpty && vec[i].id == id )
            {
                indice = i;
                break;
            }
        }
        *pIndice = indice;
        todoOk = 1;
    }
    return todoOk;
}

int altaAutos(int* pIdAuto, eAuto vecAuto[], eMarca vecMarcas[], eColor vecColores[], int tamAutos, int tamMarcas, int tamColores)
{
	char seguir;
    int todoOk = 0;
    int indice;
    eAuto axuAuto;

    if(pIdAuto != NULL && vecAuto != NULL && vecMarcas != NULL && vecColores != NULL && tamAutos > 0 && tamAutos > 0 && tamMarcas > 0 && tamColores >0)
    {
    	do
    	{
    		printf("**** Alta Auto   ****\n\n");
    		buscarLibreAutos(&indice, vecAuto, tamAutos);
			if(indice == -1)
			{
				printf("No hay lugar en el sistema.\n");
			}
			else
			{
				cargarAuto(&axuAuto, vecMarcas,vecColores,tamAutos,tamMarcas,tamColores);
				axuAuto.id = *pIdAuto;
				*pIdAuto = *pIdAuto + 1;
				vecAuto[indice] = axuAuto;
				todoOk = 1;
			}
			printf("Le gustaria ingresar otro Auto:");
			fflush(stdin);
			scanf("%c", &seguir);
			//validarCaracterSeguir(&seguir);

    	}while(seguir != 'n');


    }
    return todoOk;
}

int altaTrabajos(int* pIdTrabajo, eAuto vecAvion[], eMarca vecMarcas[], eColor vecColores[], int tamAutos, int tamMarcas, int tamColores, eTrabajo vecTrabajos[], int tamTrabajos)
{
	char seguir;
    int todoOk = 0;
    int indice;
    eTrabajo auxTrabajo;

    if(pIdTrabajo != NULL && vecAvion != NULL && vecMarcas != NULL && vecColores != NULL && tamAutos > 0 && tamAutos > 0 && tamMarcas > 0 && tamColores >0)
    {
    	do
    	{
    		printf("**** Alta Trabajos ****\n\n");
			buscarLibreTrabajos(&indice, vecTrabajos, tamColores);
			if(indice == 1)
			{
				printf("No hay lugar en el sistema.\n");
			}
			else
			{
				cargarTrabajo(vecAvion, vecMarcas,vecColores,tamAutos,tamMarcas,tamColores, &auxTrabajo, tamTrabajos);
				auxTrabajo.id = *pIdTrabajo;
				*pIdTrabajo = *pIdTrabajo + 1;
				vecTrabajos[indice] = auxTrabajo;
				todoOk = 1;
			}
			printf("Le gustaria ingresar otro trabajo:");
			fflush(stdin);
			scanf("%c", &seguir);
			//validarCaracterSeguir(&seguir);

    	}while(seguir != 'n');


    }
    return todoOk;
}

int cargarAuto(eAuto * pAuto, eMarca vecMarcas[], eColor vecColores[], int tamAutos, int tamMarcas, int tamColores )
{
    int todoOk = 0;
    eAuto auxAuto;

    if(pAuto != NULL)
	{

		printf("Ingrese ID Marca: \n");
		mostrarMarcas(vecMarcas, tamMarcas);

		do{
		printf("Que opcion elige: \n");
		fflush(stdin);
		scanf("%d", &auxAuto.idMarca);
		}while(auxAuto.idMarca < 100 || auxAuto.idMarca > 104);
		pAuto->idMarca=auxAuto.idMarca;


		printf("Ingrese ID Color: \n");
		mostrarColores(vecColores, tamColores);

		do{
		printf("Que opcion elige: \n");
		fflush(stdin);
		scanf("%d", &auxAuto.idColor);
		}while(auxAuto.idColor < 100 || auxAuto.idColor > 104);
		pAuto->idColor=auxAuto.idColor;


		printf("Ingrese Tipo de Caja: (m / a)\n");
		fflush(stdin);
		scanf("%c", &auxAuto.caja);

		pAuto->caja=auxAuto.caja;



		pAuto->isEmpty = 0;

		todoOk = 1;
	}

    return todoOk;
}


int cargarTrabajo(eAuto vecAvion[], eMarca vecMarcas[], eColor vecColores[], int tamAutos, int tamMarcas, int tamColores, eTrabajo * pTrabajos, int tamTrabajos )
{
    int todoOk = 0;
    eTrabajo auxTrabajo;

    if(pTrabajos != NULL)
	{


		printf("Ingrese patente: \n");
		mostrarColores(vecColores, tamColores);
		printf("Que opcion elige: \n");
		fflush(stdin);
		scanf("%d", &auxTrabajo.patente);
		//validacion
		pTrabajos->patente=auxTrabajo.patente;

		printf("Ingrese Servicio: \n");
		printf("Que opcion elige: \n");
		fflush(stdin);
		scanf("%d", &auxTrabajo.patente);
		//validacion
		pTrabajos->patente=auxTrabajo.patente;


		printf("Ingrese Fecha de Nacimiento: \n");
		printf("Ingrese dia: ");
		scanf("%d", &auxTrabajo.fecha.dia);
		//validarFecha(&auxVuelo, 1);
		pTrabajos->fecha.dia=auxTrabajo.fecha.dia;

		printf("Ingrese mes: ");
		scanf("%d", &auxTrabajo.fecha.mes);
		//validarFecha(&auxVuelo, 2);
		pTrabajos->fecha.mes=auxTrabajo.fecha.mes;

		printf("Ingrese año: ");
		scanf("%d", &auxTrabajo.fecha.anio);
		//validarFecha(&auxVuelo, 3);
		pTrabajos->fecha.anio=auxTrabajo.fecha.anio;


		pTrabajos->isEmpty = 0;

		todoOk = 1;
	}

    return todoOk;
}

int cargarDescripcionMarca(int idMarcas, char descripcion[], eMarca vec[], int tam)
{
	int todoOk=0;
	if(descripcion!=NULL && vec !=NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(vec[i].id==idMarcas)
			{
				strcpy(descripcion, vec[i].descripcion);
				break;
			}
		}

		todoOk=1;
	}
	return todoOk;
}

int cargarDescripcionServicio(int idServicios, char descripcion[], eServicio vec[], int tam)
{
	int todoOk=0;
	if(descripcion!=NULL && vec !=NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(vec[i].id==idServicios)
			{
				strcpy(descripcion, vec[i].descripcion);
				break;
			}
		}

		todoOk=1;
	}
	return todoOk;
}

int cargarDescripcionColores(int idColores, char descripcion[], eColor vec[], int tam)
{
	int todoOk=0;
	if(descripcion!=NULL && vec !=NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(vec[i].id==idColores)
			{
				strcpy(descripcion, vec[i].nombreColor);
				break;
			}
		}

		todoOk=1;
	}
	return todoOk;
}

////////////////HARDCODEO

int hardcodearAutos(int* pLegajo ,eAuto vec[], int tam, int cant)
{
	int todoOk = 0;

    eAuto autos[] =
	{
		{1000, 1001, 100, 'm',},
		{1001, 1003, 102, 'a',},
		{1002, 1002, 101, 'm',},
		{1003, 1003, 103, 'a',},
		{1004, 1003, 102, 'a',},
		{1005, 1004, 101, 'm',},
		{1006, 1001, 100, 'm',},
		{1007, 1000, 100, 'a',},
		{1008, 1001, 101, 'a',},
	};


    if(vec != NULL && tam > 0 && cant <= tam && cant <= 10)
    {

      for(int i = 0 ; i < cant ; i++){

      vec[i] = autos[i];
      *pLegajo = *pLegajo + 1;
      }
        todoOk = 1;
    }
    return todoOk;
}

int hardcodearTrabajos(int* pId ,eTrabajo vec[], int tam, int cant)
{


    int todoOk = 0;

    eTrabajo vuelos[] =
	{
		{10000, 1000,20002, {2,8,2001}},
		{10001, 1002,20000, {19,6,2003}},
		{10002, 1003,20003, {25,11,2003}},
		{10003, 1004,20001, {30,11,1999}},
	};


    if(vec != NULL && tam > 0 && cant <= tam && cant <= 10)
    {

      for(int i = 0 ; i < cant ; i++){

      vec[i] = vuelos[i];
      *pId = *pId + 1;
      }
        todoOk = 1;
    }
    return todoOk;
}


