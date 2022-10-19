/*
 * Mostrar.h
 *
 *  Created on: 19 oct. 2022
 *      Author: cazzo
 */

#ifndef MOSTRAR_H_
#define MOSTRAR_H_



#endif /* MOSTRAR_H_ */

int confirmacionSalida(char* respuesta);

void errorMenuInicio();

void menuInicio();

int ingresoDeOpcionMenuPricipal();

int subMenuModificar();

int mostrarMarcas(eMarca vec[], int tam);

int mostrarColores(eColor vec[], int tam);

int mostrarServicios(eServicio vec[], int tam);

int mostrarAutos(eAuto vecAuto[], eMarca vecMarca[],eColor vecColor[] ,int tamAutos, int tamMarcas, int tamColores);

int mostrarAuto(eAuto avion, eMarca vecMarca[],eColor vecColor[] , int tamMarcas, int tamColores );

int mostrarTrabajos(eAuto vecAuto[], eMarca vecMarcas[],eColor vecColores[] ,int tamAutos, int tamMarcas, int tamColores, eTrabajo vecTrabajo[], int tamTrabajo);

int mostrarTrabajo(eTrabajo trabajo[], eMarca vecMarcas[],eColor vecColores[] , int tamMarcas, int tamColores,  eTrabajo vecTrabajo, int tamTrabajo);
;
