


#ifndef ARITMETICA_H_
#define ARITMETICA_H_

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int id;
	char descripcion[20];
}eMarca;

typedef struct
{
	int id;
	char nombreColor[20];
}eColor;

typedef struct
{
	int id;
	int idMarca;
	int idColor;
	int caja;
	int isEmpty;
}eAuto;

typedef struct
{
	int id;//comienza en 20 000
	char descripcion[20];
	int precio;
}eServicio;

typedef struct
{
	int id;//autoincremental
	int patente;
	int idServicio;
	eFecha fecha;
	int isEmpty;
}eTrabajo;

#endif
