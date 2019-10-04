#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"


static int findEmptyPlace(Employee* eEmpleado, int len);

/** \brief  To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* is the array in which to search
 * \param len Indicates the logitude of the array
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int initEmployee(Employee* eEmpleado, int len)
{
    int i;
    int retorno=-1;
    if(eEmpleado != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            (eEmpleado+i)->isEmpty = EMPLOYEE_EMPTY;
        }
        retorno = 0;
    }
    return retorno;
}

/** \brief Take the data to add an employee
 * \param list Employee* is the array in which to search
 * \param len Indicates the logitude of the array
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int appendEmployee(Employee* eEmpleado, int len)
{
    char nombre[50];
    char apellido[50];


    int sector;
    int retorno=-1;
    int id;

    float salary;

    system("cls");
    printf("--------*****ALTA*****--------\n");

    retorno = getValidInt("\nIngrese el ID del empleado a dar de alta: ","\nDebe elegir entre el 1 y 4", &id,1,1000,3);
    if(retorno == 0)
    {
            retorno = getValidString("\nIngrese el nombre del empleado a dar de alta: ","\nNo es un nombre valido","\nLongitud maxima 50", nombre,51,3);
            if(retorno == 0)
            {
                retorno = getValidString("\nIngrese el apellido del empleado a dar de alta: ","\nNo es un apellido valido","\nLongitud maxima 50", apellido,50,3);
                if(retorno == 0)
                {
                    retorno = getValidInt("\nIngrese el sector del empleado a dar de alta: \n1 - Contabilidad.\n2 - Legales.\n3 - Marketing.\n4 - Sistemas.\n ","\nDebe elegir entre el 1 y 4", &sector,1,4,3);
                    if(retorno == 0)
                    {
                        retorno = getValidFloat("\nIngrese el sueldo del empleado: ","El salario deben ser solo numeros",&salary,1.0,1000000.0,3);
                        if(retorno==0)
                        {
                            addEmployee(eEmpleado,len,id, sector,nombre,apellido,salary);
                            clearScreen();
                        }
                    }
                }
            }
    }
    return retorno;

}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee* is the array in which to search
 * \param len Indicates the logitude of the array
 * \param id It is the value that is sought
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */

int removeEmployee(Employee* eEmpleado, int len, int id)
{
    Employee* eAuxEmpleado;
    int retorno = -1;

    eAuxEmpleado = findEmployeeById(eEmpleado, len, id);
    if(eAuxEmpleado != NULL)
    {
        eAuxEmpleado->isEmpty = EMPLOYEE_DELETE;
        retorno = 0;
    }

    return retorno;
}


/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee* is the array in which to search
 * \param len Indicates the logitude of the array
 * \param id It is the value that is sought
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */

Employee* findEmployeeById(Employee* eEmpleado, int len, int id)
{
    Employee* eRetorno = NULL;
    int i;
    if(eEmpleado != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if((eEmpleado+i)->id == id && (eEmpleado+i)->isEmpty == EMPLOYEE_USED)
            {
                eRetorno = (eEmpleado+i);
                break;
            }
        }
    }
    return eRetorno;
}


/** \brief Load the id data to modify
 *
 * \param list Employee* is the array in which to search
 * \param int len Indicates the logitude of the array
 * \param int id Employee id
 * \param name[] char Name of the employee
 * \param lastName[] char last name of the employee
 * \param salary float salary of employee
 * \param sector int sector of employee
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */

int updateEmployee(Employee* eEmpleado, int len, int id, char* nombre, char* apellido,int sector, float salary)
{
    int retorno=-1;
    Employee* eAuxEmployee;

    if(eEmpleado != NULL && len > 0)
    {
        eAuxEmployee = findEmployeeById(eEmpleado, len,id);
        if(eAuxEmployee != NULL)
        {
            strcpy(eAuxEmployee->name,nombre);
            strcpy(eAuxEmployee->lastName,apellido);

            retorno=0;
        }
    }
    return retorno;
}
/** \brief Take the employee data to modify
 * \param list Employee* is the array in which to search
 * \param len Indicat
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */

int modifyEmployee(Employee* eEmpleado, int len)
{
    char nombre[51];
    char apellido[51];

    int id;
    int sector;
    int retorno=-1;

    float salary;

    clearScreen();
    printf("--------*****MODIFICAR EMPLEADO*****--------\n");
    retorno = getValidInt("\nID a Modificar: ","\nRango valido 0-999", &id,0,9999,3);

    if(retorno == 0)
    {
        if(findEmployeeById(eEmpleado, len, id) == NULL)
        {
            printf("El empleado elegido no existe\n");
            pause();

        }
        else
        {
        retorno = getValidString("\nIngrese el nombre del empleado a dar de alta: ","\nNo es un nombre valido","\nLongitud maxima 50", nombre,51,3);
        if(retorno == 0)
        {
            retorno = getValidString("\nIngrese el apellido del empleado a dar de alta: ","\nNo es un apellido valido","\nLongitud maxima 50", apellido,50,3);
            if(retorno == 0)
            {
                retorno = getValidInt("\nIngrese el sector del empleado a dar de alta: \n1 - Contabilidad.\n2 - Legales.\n3 - Marketing.\n4 - Sistemas.\n ","\nDebe elegir entre el 1 y 4", &sector,1,4,3);
                if(retorno == 0)
                {
                    retorno = getValidFloat("\nIngrese el sueldo del empleado: ","El salario deben ser solo numeros",&salary,1.0,1000000.0,3);
                    if(retorno==0)
                    {
                        retorno = updateEmployee(eEmpleado, len, id, nombre, apellido,sector,salary);
                        clearScreen();
                    }
                }
            }
        }

}
}
return retorno;
}

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list Employee* is the array in which to search
 * \param int len Indicates the logitude of the array
 * \param int id Employee id
 * \param name[] char Name of the employee
 * \param lastName[] char last name of the employee
 * \param salary float salary of employee
 * \param sector int sector of employee
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 */

int addEmployee(Employee* eEmpleado, int len,int id, int sector, char nombre[],char apellido[],float salary)
{

    int retorno=-1;
    int index;
    if(eEmpleado != NULL && len > 0)
    {
        index = findEmptyPlace(eEmpleado, len);
        if(index != -1)
        {
            (eEmpleado+index)->id = id;
            strcpy((eEmpleado+index)->name,nombre);
            strcpy((eEmpleado+index)->lastName,apellido);
            (eEmpleado+index)->sector = sector;
            (eEmpleado+index)->salary= salary;
            (eEmpleado+index)->isEmpty = EMPLOYEE_USED;
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Take the employee  data to unsubscribe
 * \param list Employee* is the array in which to search
 * \param len Indicates the logitude of the array
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */

int lowEmployee(Employee* eEmpleado, int len)
{
    int id;

    int retorno=-1;

    clearScreen();
    printf("--------*****BAJA EMPLEADO*****--------\n");
    retorno = getValidInt("\nID a dar de Baja: ","\nRango valido 1-999", &id,0,9999,3);

    if(retorno == 0)
    {
        if(findEmployeeById(eEmpleado, len, id) == NULL)
        {
            printf("El empleado elegido no existe\n");
            pause();
        }
        else
        {
            retorno = removeEmployee(eEmpleado, len, id);
        }
    }
    return retorno;
}


/** \brief Sort the elements in the array of employees
 *
 * \param list Employee* is the array in which to search
 * \param len Indicates the logitude of the array
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int sortEmployee(Employee* eEmpleado,int len)
{

    Employee EmployeeAux;
    int i,j;
    int retorno =-1;
    for(i=0; i < len - 1; i++)
    {
        if((eEmpleado+i)->isEmpty == 0)
        {
            continue;
        }
        for(j=i+1; j < len; j++)
        {
            if((eEmpleado+j)->isEmpty == 0)
            {
                continue;
            }
            if((eEmpleado+i)->sector > (eEmpleado+j)->sector)
            {
                EmployeeAux = eEmpleado[j];
                eEmpleado[j] = eEmpleado[i];
                eEmpleado[i] = EmployeeAux;
            }
            else if((eEmpleado+i)->sector == (eEmpleado+j)->sector)
            {
                if(strcmp((eEmpleado+i)->lastName,(eEmpleado+i)->lastName) > 0)
                {
                    EmployeeAux = eEmpleado[j];
                    eEmpleado[j] = eEmpleado[i];
                    eEmpleado[i] = EmployeeAux;
                    retorno =0;
                }
            }
        }
    }
    return retorno;

}

/** \brief print the content of employees array
 *
 * \param list Employee* is the array in which to search
 * \param len Indicates the logitude of the array
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */

int printEmployees(Employee* eEmpleado, int len)
{
    int retorno=-1,i;
    if(eEmpleado != NULL && len > 0)
    {
        clearScreen();
        printf("\n\n%4s - %-20s - %-20s - %-8s - %-6s\n"," ID","    NOMBRE","    APELLIDO","   SALARIO","      SECTOR");
        for(i=0;i<len;i++)
        {
            if((eEmpleado+i)->isEmpty == EMPLOYEE_USED)
                printf("%4d - %-20s - %-20s - %-8.2f   - %-6d\n",(eEmpleado+i)->id,(eEmpleado+i)->name,(eEmpleado+i)->lastName,(eEmpleado+i)->salary,(eEmpleado+i)->sector);
        }
        retorno = 0;
    }
    return retorno;
}

/** \brief Find the average price
 * \param list Employee*  is the array in which to search
 * \param len Indicates the logitude of the array
 * \return If there are no active employees (-1) and if there is the price of that product
 *
 */

float getAverageSalary(Employee* eEmpleado,int len)
{
    int i;
    float totalSalary = 0;
    int activeEmployees = 0;

    for(i=0;i < len; i++)
    {
        if((eEmpleado+i)->isEmpty == EMPLOYEE_USED)
        {
            totalSalary = totalSalary + (eEmpleado+i)->salary;
            activeEmployees++;
        }
    }
    if(activeEmployees == 0)
        return -1;

    return (totalSalary / (float)activeEmployees);

}

/** \brief Find employees that are above average
 * \param list Employee* is the array in which to search
 * \param len Indicates the logitude of the array
 * \return If there are no active employees (-1) and if there is the price of that product
 *
 */

int aboveAverageSalaryReport(Employee* eEmpleado,int len)
{
    int salaryAux=0;
    int i;
    int aboveAux=0;
    salaryAux = getAverageSalary(eEmpleado,len);
    if(salaryAux == -1)
    {
        printf("\nNo hay salarios ingresados\n");
        return -1;
    }
    printf("\n\n%4s - %-20s - %-20s - %-8s - %-6s\n"," ID","    NOMBRE","    APELLIDO","   SALARIO","      SECTOR");
    for(i=0;i < len; i++)
    {
        if((eEmpleado+i)->salary > salaryAux && (eEmpleado+i)->isEmpty == 1)
        {
            printf("%4d - %-20s - %-20s - %-8.2f   - %-6d\n",(eEmpleado+i)->id,(eEmpleado+i)->name,(eEmpleado+i)->lastName,(eEmpleado+i)->salary,(eEmpleado+i)->sector);
            aboveAux++;
        }

    }

    printf("\nLa cantidad de empleados que superan el salario promedio son: %d", aboveAux);

    return 0;

}

/** \brief Search the array for the first free position
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

static int findEmptyPlace(Employee* eEmpleado, int len)
{
    int i;
    int retorno=-1;
    if(eEmpleado != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if((eEmpleado+i)->isEmpty == EMPLOYEE_EMPTY)
            {
                retorno = i;
                break;
            }
        }

    }
    return retorno;
}


