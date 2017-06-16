#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"
#define TAM 20

int main()
{
    ePersona personas[TAM];
    char seguir='s';
    inicializarPersonas(personas, TAM);

    do
    {
        system("cls");

        switch(menu())
        {
            case 1:
                altaPersonas(personas, TAM);
                break;
            case 2:
                bajaPersonas(personas, TAM);
                break;
            case 3:
                imprimirPersonas(personas, TAM);
                break;
            case 4:
                grafico(personas, TAM);
                break;
            case 5:
                seguir='n';
                break;
            default:
                printf("\nOpcion invalida, vuelva a intentarlo!");
        }

        printf("\n");
        system("pause");

    } while(seguir=='s');

    return 0;
}
