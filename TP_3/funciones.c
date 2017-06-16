#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"
#include <conio.h>


void inicializarPeliculas(EMovie p[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
       p[i].estado=0;
    }
}


int menu()
{
    int opcion;

        printf("\n  ->Menu de opciones<-  \n\n");
        printf("1. Agregar pelicula\n");
        printf("2. Borrar pelicula\n");
        printf("3. Modificar pelicula\n");
        printf("4. Generar pagina web\n");
        printf("5. Salir\n\n");

        printf("Elija opcion: ");
        scanf("%d", &opcion);
        if (opcion<1 || opcion>5)
        {
            printf("Error. Debe estar entre 1 y 5.\n");
            system("pause");
        }
    return opcion;
}

int agregarPelicula(EMovie p[], int id, int tam)
{
    int indice;
    char auxiliarCad[50];
    int auxiliar;
    indice = obtenerEspacioLibre(p, tam);

    if (indice==-1)
    {
        printf("\nLimite alcanzado. No se pueden ingresar mas peliculas.\n\n");
    }
    else
        {
          p[indice].id=id;
          printf("\nID: %d\n", p[indice].id);
          printf("Ingrese titulo de la pelicula: ");
          fflush(stdin);
          gets(auxiliarCad);
          while (strlen(auxiliarCad)>20)
                {
                    printf("Titulo excede los caracteres permitidos. Reingrese: ");
                    fflush(stdin);
                    gets(auxiliarCad);
                }
         strcpy(p[indice].titulo, auxiliarCad);

         printf("Ingrese genero de la pelicula: ");
         fflush(stdin);
         gets(auxiliarCad);
         while (strlen(auxiliarCad)>20)
                {
                    printf("Genero excede los caracteres permitidos. Reingrese: ");
                    fflush(stdin);
                    gets(auxiliarCad);
                }
         strcpy(p[indice].genero, auxiliarCad);

         printf("Ingrese duracion de la pelicula: ");
         fflush(stdin);
         scanf("%d", &auxiliar);
         while (auxiliar<0)
         {
             printf("La duracion debe ser mayor a 0. Reingrese: ");
             fflush(stdin);
             scanf("%d", &auxiliar);
         }
         p[indice].duracion=auxiliar;

         printf("Ingrese la descripcion de la pelicula (maximo 50 caracteres): ");
         fflush(stdin);
         gets(auxiliarCad);
         while (strlen(auxiliarCad)>50)
         {
             printf("Excedio los 50 caracteres. Reingrese: ");
             fflush(stdin);
             gets(auxiliarCad);
         }
         strcpy(p[indice].descripcion, auxiliarCad);

         printf("Ingrese puntaje de la pelicula: ");
         fflush(stdin);
         scanf("%d", &auxiliar);
         while (auxiliar<0)
         {
             printf("Error. Puntaje debe ser entre 1 y 10. Reingrese: ");
             fflush(stdin);
             scanf("%d", &auxiliar);
         }
         p[indice].puntaje=auxiliar;
         p[indice].estado=1;

         printf("\nPelicula ingresada con exito.\n");
         system("pause");
        }
        return indice;
}

void mostrarPelicula(EMovie movieOne)
{
    printf("\nID: %d\n", movieOne.id);
    printf("Titulo: %s\n", movieOne.titulo);
    printf("Genero: %s\n", movieOne.genero);
    printf("Descripcion: %s\n", movieOne.descripcion);
    printf("Puntaje: %d\n", movieOne.puntaje);
    printf("Duracion: %d\n", movieOne.duracion);
}

int obtenerEspacioLibre (EMovie p[], int tam)
{
    int indice=-1;
    int i;
    for (i=0;i<tam;i++)
    {
        if(p[i].estado == 0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

void borrarPelicula(EMovie p[], int tam)
{
    int confirmar;
    int indice;
    int id;

    printf("Ingrese ID de la pelicula que desea borrar: ");
    fflush(stdin);
    scanf("%d", &id);

    indice = buscarPorId(p, tam, id);
    if (indice==-1)
    {
        printf("La pelicula de ID %d no esta cargada en sistema.\n", id);
    }
    else
        {
            printf("Usted va a borrar la pelicula '%s'. confirmar: s/n\n", p[indice].titulo);

            confirmar = tolower(getch());

            if (confirmar =='s')
            {
                p[indice].estado=2;

                printf("\nHa eliminado la pelicula con exito.\n\n");
            }
            else
            {
                printf("\nHa cancelado la eliminacion de la pelicula.\n");
            }
        }

    system("pause");

}

void modificarPelicula(EMovie p[], int tam)
{
    char auxiliarCad[60];
    int opcion;
    int indice;
    int id;
    int auxiliar;

    printf("Ingrese ID de la pelicula que desea modificar: ");
    fflush(stdin);
    scanf("%d", &id);

    indice=buscarPorId(p, tam, id);
    if (indice==-1)
    {
        printf("La pelicula de ID %d no esta cargada en sistema.\n", id);
        system("pause");
    }
    else
        {
            printf("\n   Datos de la pelicula que eligio:  \n");
            mostrarPelicula(p[indice]);

            printf("\n1. titulo\n");
            printf("2. genero\n");
            printf("3. duracion\n");
            printf("4. descripcion\n");
            printf("5. puntaje\n");
            printf("Que desea modificar?: ");
            scanf("%d", &opcion);

            switch(opcion)
            {
            case 1:
                printf("Ingrese titulo de la pelicula: ");
                fflush(stdin);
                gets(auxiliarCad);
                while (strlen(auxiliarCad)>20)
                    {
                    printf("Titulo excede los caracteres permitidos. Reingrese: ");
                    fflush(stdin);
                    gets(auxiliarCad);
                    }
                strcpy(p[indice].titulo, auxiliarCad);
                break;

            case 2:
                printf("Ingrese genero de la pelicula: ");
                fflush(stdin);
                gets(auxiliarCad);
                while (strlen(auxiliarCad)>20)
                {
                    printf("Genero excede los caracteres permitidos. Reingrese: ");
                    fflush(stdin);
                    gets(auxiliarCad);
                }
                strcpy(p[indice].genero, auxiliarCad);
                break;

            case 3:
                 printf("Ingrese la duracion de la pelicula: ");
                 fflush(stdin);
                 scanf("%d", &auxiliar);
                 while (auxiliar<0)
                 {
                     printf("La duracion no puede ser menor a 0. Reingrese: ");
                     fflush(stdin);
                     scanf("%d", &auxiliar);
                 }
                 p[indice].duracion=auxiliar;
                 break;

            case 4:
                printf("Ingrese descripcion de la pelicula (maximo 50 caracteres): ");
                fflush(stdin);
                gets(auxiliarCad);
                while (strlen(auxiliarCad)>50)
                 {
                 printf("Sobrepaso los 50 caracteres. Vuelva a intentarlo: ");
                 fflush(stdin);
                 gets(auxiliarCad);
                 }
                strcpy(p[indice].descripcion, auxiliarCad);
                break;

            case 5:
                printf("Ingrese puntaje de la pelicula: ");
                fflush(stdin);
                scanf("%d", &auxiliar);
                while (auxiliar<0)
                {
                printf("El puntaje debe estar entre 1 y 10. Reingrese: ");
                fflush(stdin);
                scanf("%d", &auxiliar);
                }
                p[indice].puntaje=auxiliar;
                break;
            }
        }
}

void generarPagina(EMovie movies[], int tam)
{
    FILE* a;
    FILE* bin;
    int i;
    a=fopen("index.html", "w");

    if (a==NULL)
    {
        printf("Error al abrir el archivo.");
        exit(1);
    }

    for (i=0;i<tam;i++)
    {
        fprintf(a, "<html>");
        fprintf(a, "<article class='col-md-4 article-intro'>");
        fprintf(a, "<a href='#'>");
        fprintf(a, "<img class='img-responsive img-rounded' src='https://k61.kn3.net/D/9/7/9/A/3/195.jpg");
        fprintf(a, "'alt=''>");
        fprintf(a, "</a>");
        fprintf(a, "<h3>");
        fprintf(a, "<a href='#'>");
        fprintf(a, movies[i].titulo);
        fprintf(a, "</a>");
        fprintf(a, "</h3>");
        fprintf(a, "<ul>");
        fprintf(a, "<li>Género: ");
        fprintf(a, movies[i].genero);
        fprintf(a, "</li>");
        fprintf(a, "<li>Puntaje: ");
        fprintf(a, "%d", movies[i].puntaje);
        fprintf(a, "</li>");
        fprintf(a, "<li>Duracion: ");
        fprintf(a, "%d", movies[i].duracion);
        fprintf(a, "</li>");
        fprintf(a, "<p>");
        fprintf(a, movies[i].descripcion);
        fprintf(a, "</p>");
        fprintf(a, "</article>");
        fprintf(a, "</html>");
    }

    fclose(a);

    bin=fopen("bin.dat", "w");

    if (bin==NULL)
    {
        printf("Error al abrir el archivo.");
        exit(1);
    }

    fwrite(&movies, sizeof(EMovie), 50, bin);

    fclose(bin);

}

int buscarPorId (EMovie p[], int tam, int id)
{
    int indice=-1;
    int i;

    for (i=0;i<tam;i++)
    {
        if(p[i].id == id)
        {
            indice=i;
            break;
        }
    }
    return indice;
}













