#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"


#define ELEMENTS 1000 ///CANTIDAD MAXIMA DE EMPLEADOS.

int main()
{
    int menuOpcionElegida;
    char menuPrinsipalMensaje[] =
                "\n1-Alta de Empleado\
                 \n2-Modificar Empleado\
                 \n3-Baja del Empleado\
                 \n4-Listar\
                 \n5-Salir\n\
                 \nIngrese opcion: ";
    char menuPrinsipalMensajeError[] = "\nSe debe elegir una opcion del 1 al 6";

    int opcion;
    int flag =0;
    float salarioPromedio;


    Employee eEmpleado[ELEMENTS];
    initEmployee(eEmpleado,ELEMENTS);

    do
    {

        menuOpcionElegida = 0;
        getValidInt(menuPrinsipalMensaje,menuPrinsipalMensajeError, &menuOpcionElegida , 0 , 9 , 2 );

        switch(menuOpcionElegida)
        {
        case 1:
            appendEmployee(eEmpleado,ELEMENTS);
            flag = 1;
            break;
        case 2:
            if(flag == 0)
            {
                printf("\nPrimero debe ingresar un empleado.\n");
                break;
            }

            modifyEmployee(eEmpleado,ELEMENTS);
            break;
        case 3:
            if(flag == 0)
            {
                printf("\nPrimero debe ingresar un empleado.\n");
                break;
            }

            lowEmployee(eEmpleado,ELEMENTS);
            break;
        case 4:
            if(flag == 0)
            {
                printf("\nPrimero debe ingresar un empleado.\n");
                break;
            }

            getValidInt("\n1- Listado de los empleados ordenados alfabeticamente por Apellido y Sector. \n2- Total y promedio de los salarios, y cuantos empleados superan el salario promedio.","\nError. La opcion elegidad debe ser 1 o 2.",&opcion,1,2,3);

                switch(opcion)
                {
                case 1:
                    sortEmployee(eEmpleado,ELEMENTS);
                    printEmployees(eEmpleado,ELEMENTS);
                    pause();
                    clearScreen();
                    break;
                case 2:
                    clearScreen();
                    salarioPromedio=getAverageSalary(eEmpleado,ELEMENTS);
                    printf("\nEl salario promedio es : %.2f",salarioPromedio);
                    aboveAverageSalaryReport(eEmpleado,ELEMENTS);
                    pause();
                    clearScreen();
                    break;
                }
        case 5:
            printf("*************************\n*************************\n**********ADIOS**********\n*************************\n*************************\n");
            break;

        default:
            printf("\nNO ES UNA OPCION VALIDA!!!\n\n");
            pause();
            break;
        }


    }while(menuOpcionElegida != 5);

    return 0;

}

