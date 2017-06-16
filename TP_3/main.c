#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"
#include "funciones.c"

int main()
{
    EMovie movies[50];

    char seguir='s';

    int altamovie;
    int confirmar;
    int id=1000;

    inicializarPeliculas(movies, 50);

    do
    {
        switch(menu())
        {
        case 1:
            altamovie = agregarPelicula(movies, id, 50);
            if (altamovie!=-1)
            {
                id++;
            }
            break;
        case 2:
            borrarPelicula(movies, 50);
            break;
        case 3:
            modificarPelicula(movies, 50);
            break;
        case 4:
            generarPagina(movies, 1);
            printf("Pagina web creada.\n");
            system("pause");
            break;
        case 5:
            printf("Confirma salir? s/n\n");
            confirmar = tolower(getch());
            if (confirmar=='s')
            {
                seguir='n';
            }
            break;
        }system("cls");
    }while(seguir=='s');
return 0;
}



