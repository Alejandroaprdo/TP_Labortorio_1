//Funciones
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[25];
    int edad;
    float dni;
    int estado;
} ePersona;

/** \brief Imprime el menu de opciones
 *
 * \return Retorna opcion elegida int
 *
 */
int menu()
{
    int opcion=0;

    printf("*** MENU ***");
    printf("\n\n");
    printf("Elija una opcion\n\n");
    printf("1. Agregar una persona\n");
    printf("2. Borrar una persona\n");
    printf("3. Imprimir lista ordenada por nombre\n");
    printf("4. Imprimir grafico de edades\n");
    printf("5. Salir\n");
    printf("\n\n");

    printf("Opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

/** \brief Inicializa posiciones del estado en 0
 *
 * \param Recibe array de estructura personas[] ePersona
 * \param Recibe tamaño del array tam int
 * \return void
 *
 */
void inicializarPersonas(ePersona personas[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        personas[i].estado=0;
    }
}

/** \brief Busca posicio libre
 *
 * \param Recibe array de estructura personas[] ePersona
 * \param recibe tamaño del array tam int
 * \return retorna la posicion libre 0 -1 int
 *
 */
int buscarLibre(ePersona personas[], int tam)
{
    int indice=-1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(personas[i].estado==0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

/** \brief Busca DNI
 *
 * \param Recibe array de estructura personas[] ePersona
 * \param Recibe tamaño del array tam int
 * \param Recibe DNI dni float
 * \return Retorna la posicion del DNI o -1 int
 *
 */
int buscarDni(ePersona personas[], int tam, float dni)
{
    int indice=-1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(personas[i].dni==dni)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

/** \brief Imprime la lista de Personas ordenada por nombre
 *
 * \param Recibe array de estructura personas[] ePersona
 * \param Recibe tamaño del array tam int
 * \return void
 *
 */
void imprimirPersonas(ePersona personas[], int tam)
{
    int i;
    int f;

    for(i=0; i<tam-1; i++)
    {
        if(personas[i].estado==0)
        {
            continue;
        }
        for(f=i+1; f<tam; f++)
        {
            if(personas[f].estado==0)
            {
                continue;
            }

            if(strcmp(personas[i].nombre, personas[f].nombre)==1)
            {
                ePersona auxiliar=personas[i];
                personas[i]=personas[f];
                personas[f]=auxiliar;
            }
        }
    }

    printf("\nNOMBRE  EDAD  DNI\n\n");

    for(i=0; i<tam; i++)
    {
        if(personas[i].estado==1)
        {
            printf("%s - %d - %.0f\n", personas[i].nombre, personas[i].edad, personas[i].dni);
        }
    }
}

/** \brief Da el alta a las personas
 *
 * \param Recibe array de estructura personas[] ePersona
 * \param Recibe tamaño del array tam int
 * \return void
 *
 */
void altaPersonas(ePersona personas[], int tam)
{
    int posicionLibre=0;
    int busquedaDni=0;
    float dniAux=0;

    posicionLibre=buscarLibre(personas, tam);

    if(posicionLibre==-1)
    {
        printf("\nNo hay lugar disponible");
    }
    else
    {
        printf("\nIngrese DNI: ");
        fflush(stdin);
        scanf("%f", &dniAux);

        busquedaDni=buscarDni(personas, tam, dniAux);

        if(busquedaDni!=-1 && personas[busquedaDni].estado==1)
        {
            printf("\nLa persona ya se encuentra registrada");
        }
        else
        {
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(personas[posicionLibre].nombre);

            printf("Ingrese edad: ");
            fflush(stdin);
            scanf("%d", &personas[posicionLibre].edad);

            while(personas[posicionLibre].edad<1 || personas[posicionLibre].edad>100)
            {
                printf("Ingrese una edad valida (Entre 0 y 100): ");
                fflush(stdin);
                scanf("%d", &personas[posicionLibre].edad);
            }

            personas[posicionLibre].dni=dniAux;

            personas[posicionLibre].estado=1;
            printf("\nLa carga en el sistema ha sido realizada!");
        }
    }
}

/** \brief Da la baja de las personas
 *
 * \param Recibe array de estructura personas[] ePersona
 * \param Recibe tamaño del array tam int
 * \return void
 *
 */
void bajaPersonas(ePersona personas[], int tam)
{
    float dniAux=0;
    int indice=0;
    int confirmacion=0;

    printf("\nIngrese DNI de la persona a dar de baja: ");
    fflush(stdin);
    scanf("%f", &dniAux);

    indice=buscarDni(personas, tam, dniAux);

    if(indice==-1)
    {
        printf("\nEl DNI ingresado no existe");
    }
    else
    {
        printf("\nNOMBRE  EDAD  DNI");
        printf("\n\n");
        printf("%s - %d - %.0f", personas[indice].nombre, personas[indice].edad, personas[indice].dni);
        printf("\n\n");
        printf("Confirma la baja de esta persona?");
        printf("\n\n");
        printf("1. Si\n");
        printf("2. No\n");
        printf("\nOpcion: ");
        fflush(stdin);
        scanf("%d", &confirmacion);

        switch(confirmacion)
        {
            case 1:
                personas[indice].estado=0;
                printf("\nLa persona ha sido dada de baja!");
                break;
            case 2:
                break;
        }
    }
}

/** \brief Imprime grafico de edades, en base a las condiciones
 *
 * \param Recibe array de estructura personas[] ePersona
 * \param Recibe tamaño del array tam int
 * \return void
 *
 */
void grafico(ePersona personas[], int tam)
{
    int menor18=0;
    int entre19Y35=0;
    int mayor35=0;
    int i;
    int j;
    int mayorCantidad=0;

    for(i=0; i<tam; i++)
    {
        if(personas[i].estado==1)
        {
            if(personas[i].edad<=18)
            {
                menor18++;
            }
            else if(personas[i].edad>=19 && personas[i].edad<=35)
            {
                entre19Y35++;
            }
            else if(personas[i].edad>35)
            {
                mayor35++;
            }
        }
    }

    if(menor18>entre19Y35)
    {
        if(menor18>mayor35)
        {
            mayorCantidad=menor18;
        }
    }
    else
    {
        if(entre19Y35>=mayor35)
        {
            mayorCantidad=entre19Y35;
        }
        else
        {
            mayorCantidad=mayor35;
        }
    }

    char matriz[mayorCantidad][3];

    for(i=0; i<mayorCantidad; i++)
    {
        for(j=0; j<3; j++)
        {
            switch(j)
            {
            case 0:
                if(menor18>i)
                {
                    matriz[i][j]='*';
                }
                else
                {

                    matriz[i][j]=' ';
                }
                break;
            case 1:
                if(entre19Y35>i)
                {
                    matriz[i][j]='*';
                }
                else
                {

                    matriz[i][j]=' ';
                }
                break;
            case 2:
                if(mayor35>i)
                {
                    matriz[i][j]='*';
                }
                else
                {

                    matriz[i][j]=' ';
                }
                break;
            }
        }
    }

    printf("\n\n");

    for(i=mayorCantidad-1; i>=0; i--)
    {
        printf("%c      %c      %c      \n",matriz[i][0],matriz[i][1],matriz[i][2]);
    }

    printf("\n<18  18-35  >35");

}
