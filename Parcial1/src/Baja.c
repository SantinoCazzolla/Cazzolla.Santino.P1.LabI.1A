#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "AltaAutos.h"
#include "Baja.h"
#include "Modificar.h"
#include "Mostrar.h"

int bajaAuto(eAuto vecAuto[], eMarca vecMarca[],eColor vecColor[] ,int tamAutos, int tamMarcas, int tamColores)
{

    int todoOk = 0;
    int legajo;
    int indice;
    char confirma;
    int flag;//para ver si hay o no gente para dar de baja
    if(vecAuto != NULL && tamAutos > 0)
    {
        printf("**** Baja Auto ****\n\n");

        flag=mostrarAutos(vecAuto,vecMarca,vecColor, tamAutos,tamMarcas,tamColores);
		if(flag==-1)
		{
			printf("Primero debe haber un algún auto dado de alta para realizar una baja\n\n");
		}
		else
		{
			printf("Ingrese id a dar de baja: ");
			scanf("%d", &legajo);

			buscarAuto(&indice, legajo, vecAuto, tamAutos);
			if(indice == -1)
			{
				printf("No existe un auto con legajo: %d\n", legajo);
			}
			else
			{
				mostrarAuto(vecAuto[indice], vecMarca,vecColor, tamMarcas, tamColores);
				printf("Confirma baja?: ");
				fflush(stdin);
				confirma = getchar();

				if(confirma == 's')
				{
					vecAuto[indice].isEmpty = 1;
					printf("Baja exitosa.\n");
				}
				else
				{
					printf("Se ha cancelado la baja.\n");
				}
			}
			todoOk = 1;
		}
    }
    return todoOk;
}


