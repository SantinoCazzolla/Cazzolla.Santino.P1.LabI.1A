#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "AltaAutos.h"
#include "Baja.h"
#include "Modificar.h"
#include "Mostrar.h"

int confirmacionSalida(char* respuesta) {

	int retorno =0;
	char aux;

	printf("\n\nSeguro quiere salir del programa??: (S / N)  ");
	fflush(stdin);
	scanf("%c", &aux);

	if(aux == 's' || aux == 'S')
	{
		*respuesta = 's';
	}else
	{
		*respuesta = 'n';
	}

	return retorno;
}

void errorMenuInicio()
{

	printf("\n========================================="
			"\n|     Ingrese un valor correcto!!       |"
		   "\n=========================================");

}


void menuInicio()
{
	printf("\n\n|=================================================|\n"
		   "|           ADMINISTRACION DE LAVADERO            |\n"
		   "|=================================================|\n"
		   "| 1. ALTA DE AUTO                                 |\n"
		   "|                                                 |\n"
		   "| 2. MODIFICAR AUTO                               |\n"
		   "|                                                 |\n"
		   "| 3. BAJA DE  AUTO                                |\n"
		   "|                                                 |\n"
		   "| 4. LISTAR AUTOS                                 |\n"
		   "|                                                 |\n"
		   "| 5. LISTAR MARCAS                                |\n"
		   "|                                                 |\n"
		   "| 6. LISTAR COLORES                               |\n"
		   "|                                                 |\n"
		   "| 7. LISTAR SERVICIOS                             |\n"
		   "|                                                 |\n"
		   "| 8. ALTA TRABAJO                                 |\n"
		   "|                                                 |\n"
		   "| 9. LISTAR TRABAJOS                              |\n"
		   "|                                                 |\n"
		   "| 10. SALIR                                       |\n"
		   "|=================================================|\n");

}

int ingresoDeOpcionMenuPricipal(){
	int s;

	printf("\n\nIngrese la opcion que desea: ");
	scanf("%d", &s);

	return s;

}

int subMenuModificar()
{
	int opcion;

	printf("\n\nModificar Alumno\n\n");
	printf("1- Color\n");
	printf("2- Marca\n");
	printf("Que desea modificar?: ");
	scanf("%d", &opcion);

	return opcion;
}

int mostrarMarcas(eMarca vec[], int tam)
{
	int todoOk=0;

	if(vec!=NULL && tam > 0)
	{
		printf("    |***Lista de Marcas*** |\n");
		printf("----|------------------------|\n");
		printf(" ID |            Descripcion |\n");

		for(int i=0; i<tam;i++)
		{
			printf("%4d|   %20s |\n", vec[i].id, vec[i].descripcion);
		}
		printf("\n\n");

		todoOk=1;
	}
	return todoOk;
}

int mostrarColores(eColor vec[], int tam)
{
	int todoOk=0;

	if(vec!=NULL && tam > 0)
	{
		printf("    |***Lista de Colores*** |\n");
		printf("----|------------------------|\n");
		printf(" ID |            Descripcion |\n");

		for(int i=0; i<tam;i++)
		{
			printf("%4d|   %20s |\n", vec[i].id, vec[i].nombreColor);
		}
		printf("\n\n");

		todoOk=1;
	}
	return todoOk;
}

int mostrarServicios(eServicio vec[], int tam)
{
	int todoOk=0;

	if(vec!=NULL && tam > 0)
	{
		printf("     |***Lista de Servicios***            |\n");
		printf("-----|------------------------------------|\n");
		printf(" ID  |            Descripcion             |\n");

		for(int i=0; i<tam;i++)
		{
			printf("%4d|   %20s |    $%d   |\n", vec[i].id, vec[i].descripcion, vec[i].precio);
		}
		printf("\n\n");

		todoOk=1;
	}
	return todoOk;

}

int mostrarAutos(eAuto vecAuto[], eMarca vecMarca[],eColor vecColor[] ,int tamAutos, int tamMarcas, int tamColores)
{
    int todoOk = 0;
    int flag = 1;

    if(vecAuto != NULL && vecMarca != NULL && vecColor != NULL && tamAutos > 0 && tamAutos > 0 && tamMarcas > 0 && tamColores >0)
    {

        printf("**** Lista de AUTOS ****\n");
        printf("    ID AUTO      |        MARCA   |      COLOR   |    CAJA    |\n");
        printf("-----------------|----------------|--------------|------------\n");
        for(int i = 0 ; i < tamAutos ; i++)
        {
            if(!vecAuto[i].isEmpty)
            {
				mostrarAuto(vecAuto[i], vecMarca,vecColor, tamMarcas, tamColores);
				flag = 0;
				todoOk = 1;
            }
        }
        if(flag)
        {
            printf("\n*****************NO HAY ALUMNOS EN EL SISTEMA*****************\n\n");
            todoOk=-1;
        }
	}

    return todoOk;
}

int mostrarAuto(eAuto autos, eMarca vecMarca[],eColor vecColor[] , int tamMarcas, int tamColores )
{
    int todoOk = 0;






    printf("       %d      |      %d      |         %d  |           %c         |\n", autos.id, autos.idMarca, autos.idColor,autos.caja);

    return todoOk;
}







int mostrarTrabajos(eAuto vecAuto[], eMarca vecMarcas[],eColor vecColores[] ,int tamAutos, int tamMarcas, int tamColores, eTrabajo vecTrabajo[], int tamTrabajo)
{
    int todoOk = 0;
    int flag = 1;

    if(vecAuto != NULL && vecMarcas != NULL && vecColores != NULL && tamAutos > 0 && tamMarcas > 0 && tamColores > 0 && tamTrabajo >0)
    {

        printf("**** Lista de Trabajos ****\n");
        printf("ID        |   patente  |    ID servicio    |       FECHA       |\n");
        printf("----------|------------|-------------------|-------------------|\n");
        for(int i = 0 ; i < tamTrabajo ; i++)
        {
            if(!vecTrabajo[i].isEmpty)
            {
				mostrarTrabajo(vecAuto, vecMarcas, vecColores, tamMarcas, tamColores, vecTrabajo[i], tamTrabajo);
				flag = 0;
				todoOk = 1;
            }
        }
        if(flag)
        {
            printf("\n*****************NO HAY ALUMNOS EN EL SISTEMA*****************\n\n");
            todoOk=-1;
        }
	}

    return todoOk;
}

int mostrarTrabajo(eTrabajo trabajo[], eMarca vecMarcas[],eColor vecColores[] , int tamMarcas, int tamColores,  eTrabajo vecTrabajo, int tamTrabajo)
{
    int todoOk = 0;



    printf("%4d     |      %d  |       %d       |     %2d/%2d/%4d    |\n",
    		vecTrabajo.id,
			vecTrabajo.patente,
			vecTrabajo.idServicio,
			vecTrabajo.fecha.dia,
			vecTrabajo.fecha.mes,
			vecTrabajo.fecha.anio
			);

    return todoOk;
}


