

#ifndef ALTAAUTOS_H_
#define ALTAAUTOS_H_
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
	char caja;
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

int inicializarAutos(eAuto vec[], int tam);

int inicializarTrabajos(eTrabajo vec[], int tam);

int buscarLibreAutos(int* pIndice, eAuto vec[], int tam);

int buscarLibreTrabajos(int* pIndice, eTrabajo vec[], int tam);

int buscarAuto(int* pIndice, int id, eAuto vec[], int tam);

int altaAutos(int* pIdAuto, eAuto vecAuto[], eMarca vecMarcas[], eColor vecColores[], int tamAutos, int tamMarcas, int tamColores);

int altaTrabajos(int* pIdTrabajo, eAuto vecAvion[], eMarca vecMarcas[], eColor vecColores[], int tamAutos, int tamMarcas, int tamColores, eTrabajo vecTrabajos[], int tamTrabajos);

int cargarAuto(eAuto * pAuto, eMarca vecMarcas[], eColor vecColores[], int tamAutos, int tamMarcas, int tamColores );

int cargarTrabajo(eAuto vecAvion[], eMarca vecMarcas[], eColor vecColores[], int tamAutos, int tamMarcas, int tamColores, eTrabajo * pTrabajos, int tamTrabajos );

int cargarDescripcionMarca(int idMarcas, char descripcion[], eMarca vec[], int tam);

int cargarDescripcionServicio(int idServicios, char descripcion[], eServicio vec[], int tam);

int cargarDescripcionColores(int idColores, char descripcion[], eColor vec[], int tam);



int hardcodearAutos(int* pLegajo ,eAuto vec[], int tam, int cant);

int hardcodearTrabajos(int* pId ,eTrabajo vec[], int tam, int cant);
