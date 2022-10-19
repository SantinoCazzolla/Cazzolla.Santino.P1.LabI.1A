/*
 ============================================================================
 Name        : miAviones.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "AltaAutos.h"
#include "Baja.h"
#include "Modificar.h"
#include "Mostrar.h"

#define TAM 9
#define TAM_A 5
#define TAM_T 5
#define TAM_D 4
#define TAM_V 5


int main(void) {
	setbuf(stdout,NULL);

	eMarca listaMarca[TAM_A]=
		{
			{100, "Renault"},
			{101, "Ford"},
			{102, "Fiat"},
			{103, "Chevrolet"},
			{104, "Peugeot"}
		};
		eColor listaColor[TAM_T]=
		{
			{100, "Negro"},
			{101, "Blanco"},
			{102, "Rojo"},
			{103, "Gris"},
			{104, "Azul"},
		};

		eServicio listaServicio[TAM_D]=
		{
			{20000, "Lavado", 450},
			{20001, "Pulido", 500},
			{20002, "Encerado", 600},
			{20003, "Completo", 900},
		};

		eTrabajo listaTrabajo[TAM_V]=
		{
			{10000, 1000,20002, {2,8,2001}},
			{10001, 1002,20000, {19,6,2003}},
			{10002, 1003,20003, {25,11,2003}},
			{10003, 1004,20001, {30,11,1999}},
		};



	eAuto listaAutos[TAM];


	int opcionInicio;

	int todoOkInciadosAutos=0;
	int nextAutos = 1000;
	int nextTrabajos = 10000;
	char respuesta;


	todoOkInciadosAutos = inicializarAutos(listaAutos, TAM);

	if(todoOkInciadosAutos==1){
		hardcodearAutos(&nextAutos, listaAutos, TAM, 9);

	do
	{

	menuInicio();
	opcionInicio = ingresoDeOpcionMenuPricipal();


	switch (opcionInicio) {
		case 1:

		altaAutos(&nextAutos, listaAutos, listaMarca, listaColor ,TAM, TAM_A,TAM_T);
		break;

		case 2:
		modificarAutos(listaAutos, listaMarca, listaColor, TAM, TAM_A, TAM_T );
		break;
		case 3:
						bajaAuto(listaAutos, listaMarca, listaColor, TAM, TAM_A, TAM_T);
						break;
					case 4:
						ordenarAutos(listaAutos,listaMarca,listaColor,TAM, TAM_A,TAM_T);
						mostrarAutos(listaAutos,listaMarca,listaColor,TAM, TAM_A,TAM_T);
						break;
					case 5:
						mostrarMarcas(listaMarca, TAM_A);
						break;
					case 6:
						mostrarColores(listaColor, TAM_T);
						break;
					case 7:
						mostrarServicios(listaServicio, TAM_D);
						break;
					case 8:
						altaTrabajos(&nextTrabajos, listaAutos, listaMarca, listaColor ,TAM, TAM_A,TAM_T, listaTrabajo, TAM_V);
						break;
					case 9:
						mostrarTrabajos(listaAutos,listaMarca,listaColor,TAM, TAM_A,TAM_T, listaTrabajo, TAM_V);
						break;

					case 10:

						confirmacionSalida(&respuesta);

						break;
					default:

						errorMenuInicio();

						break;
				}
			}while(respuesta !='s');
	}
	else
	{
		printf("Hubo un problema al inicializar");
	}

	return EXIT_SUCCESS;
}

