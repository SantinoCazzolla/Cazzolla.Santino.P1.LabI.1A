#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "AltaAutos.h"
#include "Baja.h"
#include "Modificar.h"
#include "Mostrar.h"



int modificarAutos(eAuto vecAuto[], eMarca vecMarca[],eColor vecColor[] ,int tamAutos, int tamMarca, int tamColor)
{
 int todoOk = 0;
	int legajo;
	int indice;
	char confirma;
	char seguir;
	int modificar;
	int flag = 0;
	eAuto auxAuto;

	if(vecAuto != NULL && tamAutos > 0)
	{
		printf("**** Modificar Alumno ****\n\n");

		flag=mostrarAutos(vecAuto,vecMarca,vecColor ,tamAutos,tamMarca , tamColor);
		if(flag==-1)
		{
			printf("Primero debe haber un algún auto dado de alta para realizar una modificacion\n\n");
		}
		else
		{
			do
			{
				printf("\nIngrese ID del auto a modificar: ");
				scanf("%d", &legajo);

				buscarAuto(&indice, legajo, vecAuto, tamAutos);
				if(indice == -1)
				{
					printf("No existe un auto con ese ID: %d\n", legajo);
				}
				else
				{
					mostrarAuto(vecAuto[indice], vecMarca,vecColor ,tamMarca,tamColor);
					modificar=subMenuModificar();

					switch(modificar)
					{
						case 1:
						//MODIFICAR NOMBRE
							printf("Ingrese nuevo color: ");
							scanf("%d", &auxAuto.idColor);
							//validarNombre(&auxAvion, 10);
							printf("Confirma modificacion?: ");
							fflush(stdin);
							confirma = getchar();
							if(confirma == 's')
							{
								vecAuto[indice].idColor=auxAuto.idColor;
								mostrarAuto(vecAuto[indice], vecMarca,vecColor, tamMarca, tamColor);
								printf("\n\nModificacion exitosa.\n\n");
							}
							else
							{
								printf("\n\nSe ha cancelado la modificacion.\n\n");
							}
							break;
						case 2:
							//MODIFICAR EDAD
							printf("\nIngrese Modelo: ");
							scanf("%d",&auxAuto.idMarca);
							//validarEdades(&auxAvion);
							printf("Confirma modificacion?: ");
							fflush(stdin);
							confirma = getchar();
							if(confirma == 's')
							{
								vecAuto[indice].idMarca=auxAuto.idMarca;
								mostrarAuto(vecAuto[indice], vecMarca,vecColor, tamMarca, tamColor);
								printf("\n\nModificacion exitosa.\n\n");
							}
							else
							{
								printf("Se ha cancelado la modificacion.\n\n");
							}
							break;

						default:
							break;
						}

						printf("Desea cambiar otra area?:");
						fflush(stdin);
						scanf("%c", &seguir);
						//validarCaracterSeguir(&seguir);

					}

			}while(seguir!='n');
		}
		todoOk = 1;
	}
	return todoOk;
}

int ordenarAutos(eAuto vecAuto[], eMarca vecMarca[],eColor vecColor[] ,int tamAutos, int tamMarcas, int tamColores)
{
	int todoOk = 0;
	eAuto aux;

		    if(vecAuto != NULL && tamAutos > 0)
		    {
		        for(int i = 0 ; i < tamAutos  - 1 ; i++)
		        {
		            for(int j = i + 1 ; j < tamAutos ; j++)
		            {
						if((vecAuto[i].idMarca > vecAuto[j].idMarca)
							||(vecAuto[i].idMarca == vecAuto[j].idMarca
							&& vecAuto[i].idColor > vecAuto[j].idColor ))
							{
								aux = vecAuto[i];
								vecAuto[i] = vecAuto[j];
								vecAuto[j] = aux;
							}
		            }
		        }
		        todoOk = 1;
		    }
		    return todoOk;
}
