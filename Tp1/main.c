 #include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"
int main()
{
    float num1 = 0, num2 = 0, resultado;
    int opcion, flag = 0;
    char seguir = 'n';
     while (seguir == 'n')
     {
       printf("Ingrese una opsion\n");
                 if (num1 != 0)
                 {
                   printf("1 Ingresar el primer numero (A = %.2f).\n", num1);
                 }
                 else
                 {
                   printf("1 Ingresar el primer numero (A).\n");
                 }
                 if (num2 != 0)
                 {
                   printf("2 Ingresar el segundo numero (B = %.2f).\n", num2);
                 }
                 else
                 {
                   printf("2 Ingresar el segundo numero(B).\n");
                 }
                 printf("3 Sumar.\n");
                 printf("4 Restar.\n");
                 printf("5 Multiplicar.\n");
                 printf("6 Division.\n");
                 printf("7 Factoreal.\n");
                 printf("8 Hacer todas las operaciones.\n");
                 printf("9 Salir.\n");
       scanf("%d", &opcion);
    	switch(opcion)
    	{

        	case 1 :
				 printf ("Ingrese un numero  (A):  \n");
				num1 = ingresarNumeros (num1);
				printf("El operando A es: %.2f\n", num1);
         	   break;
        	case 2 :
				 printf ("Ingrese un otro numero  (B):  \n");
				num2 = ingresarNumeros(num2);
				printf ("El operando B es: %.2f\n", num2);
            	break;
        	case 3 :
        	    resultado = sumar (num1, num2);
            	if (resultado != 0)
            	{
            		printf("La suma es: %f\n", resultado);
            	}
            	else
            	{
            		if (num1 ==0 && num2 != 0)
            		{
            		 printf ("No se realizo la suma ya que solo ingreso B = %f.\n", num2);
            		}
            		else if (num1 != 0 && num2 == 0)
            		{
            			printf ("No se realizo la suma ya que solo ingreso A = %f.\n", num1);
            		}
            		else if ( num1 == 0 && num2 == 0)
            		{
            			printf ("No se realizo la suma ya que  no ingreso un valor.\n");
            		}
            	}
           	 break;
        	case 4 :
            	resultado = restar (num1, num2);
            	if (num1 != 0 && num2 != 0)
                {
                    printf ("La resta es: %f\n", resultado);
                }
                else if (num1 == 0 && num2 != 0)
                {
                    printf("Usted solo ingreso 0 en el primer numero A\nSu resultado es: -%f\n", num2);
                }
                else if (num1 != 0 && num2 == 0)
                {
                    printf("Usted solo ingreso  0 em el segundo numero B\nSu resultado es: %f\n", num1);
                }
                else
                {
                        printf("Usted no ingreso numeros validos");
                }
            	break;
        	case 5 :
            	resultado = multiplicar (num1, num2);
                if (num1 != 0 && num2 != 0)
                {
                    printf("La multiplicacion es: %f\n", resultado);
                }
            	else if (num1 == 0 && num2 != 0)
                {
                    printf("Usted solo ingreso 0 en el primer numero A\nSu resultado es: 0");
                }
                else if (num1 != 0 && num2 == 0)
                {
                    printf("Usted solo ingreso 0 em el segundo numero B\nSu resultado es: 0");
                }
                else
                {
                        printf("Usted no ingreso numeros validos");
                }
            	break;
        	case 6 :
            	resultado = dividir(num1, num2);
            	if (num1 != 0 && num2 != 0)
                {
                    printf ("La division es: %f\n", resultado);
                }
                else if (num1 == 0 && num2 != 0)
                {
                    printf("Usted inreso 0 en el primer numero A\nLa division es: 0");
                }
                else if (num1 != 0 && num2 == 0)
                {
                    printf("No existe la divicion por  0");
                }
                else
                {
                    printf("No ingreso operandos");
                }
            	break;
        	case 7 :
            	resultado = factorear (num1, num2);
            	if (num1 > 0)
                {
                    printf("El factoreal es: %f\n", resultado);
                }
            	else if (num1 == 0)
                {
                    printf("Usted no ingrenso el operando A o ingreso 0");
                }
                else if ( resultado == -1)
                {
                    printf("No se puede factorizar un numero decimal");
                }
                else
                {
                    printf("Usted ingreso un numero negativo");
                }

            	break;
        	case 8 :
                resultado = sumar (num1, num2);
            	if (resultado != 0)
            	{
            		printf("La suma es: %f\n", resultado);
            	}
            	else
            	{
            		if (num1 ==0 && num2 != 0)
            		{
            		 printf ("No se realizo la suma ya que solo ingreso B = %f.\n", num2);
            		}
            		else if (num1 != 0 && num2 == 0)
            		{
            			printf ("No se realizo la suma ya que solo ingreso A = %f.\n", num1);
            		}
            		else if ( num1 == 0 && num2 == 0)
            		{
            			printf ("No se realizo la suma ya que  no ingreso un valor.\n");
            		}
            	}
            	resultado = restar (num1, num2);
            	if (num1 != 0 && num2 != 0)
                {
                    printf ("La resta es: %f.\n", resultado);
                }
                else if (num1 == 0 && num2 != 0)
                {
                    printf("Usted solo ingreso un operando o 0 en el operando A\nLa resta es: -%f.\n", num2);
                }
                else if (num1 != 0 && num2 == 0)
                {
                    printf("Usted solo ingreso un operando o 0 en el operando B\nLa resta es: %f.\n", num1);
                }
                else
                {
                        printf("No se realizo la resta ya que usted no ingreso numeros validos.\n");
                }
                resultado = multiplicar (num1, num2);
                if (num1 != 0 && num2 != 0)
                {
                    printf("La multiplicacion es: %f.\n", resultado);
                }
            	else if (num1 == 0 && num2 != 0)
                {
                    printf("Usted solo ingreso un operando o 0 en el operando A\nLa multiplicacion es: 0.\n");
                }
                else if (num1 != 0 && num2 == 0)
                {
                    printf("Usted solo ingreso un operando o 0 en el operando B\nLa multiplicacion es: 0.\n");
                }
                else
                {
                        printf("No se realizo la multiplicacion ya que usted no ingreso numeros validos.\n");
                }
                resultado = dividir(num1, num2);
            	if (num1 != 0 && num2 != 0)
                {
                    printf ("La division es: %f.\n", resultado);
                }
                else if (num1 == 0 && num2 != 0)
                {
                    printf("Usted inreso 0 o nada en el operando A\nLa division es: 0.\n");
                }
                else if (num1 != 0 && num2 == 0)
                {
                    printf("No se puede dividir por 0.\n");
                }
                else
                {
                    printf("No se realizo la division ya que usted no ingreso numeros validos.\n");
                }
                resultado = factorear (num1, num2);
            	if (num1 > 0)
                {
                    printf("El factorial es: %f.\n", resultado);
                }
            	else if (num1 == 0)
                {
                    printf("Usted no ingrenso el operando A o ingreso 0.\n");
                }
                else
                {
                    printf("Usted ingreso un numero negativo en el operando A.\n");
                }
                break;
        	case 9 :

                getchar();
        		printf("Desea cerrar el programa (s/n)? ");
        		seguir = getc(stdin);
        		flag = 3;
        		break;
            default:
        		  printf(" ingrese una opcion valida");
        		  getchar();
        		  opcion = SeleccionarOpcion(opcion);
    	    }
     }
    return 0;
}
