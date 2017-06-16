//Prototipos

typedef struct
{
    char nombre[25];
    int edad;
    float dni;
    int estado;
} ePersona;

int menu();
void inicializarPersonas(ePersona personas[], int tam);
int buscarLibre(ePersona personas[], int tam);
int buscarDni(ePersona personas[], int tam, float dni);
void imprimirPersonas(ePersona personas[], int tam);
void altaPersonas(ePersona personas[], int tam);
void bajaPersonas(ePersona personas[], int tam);
void grafico(ePersona personas[], int tam);
