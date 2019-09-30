/*
 * employee.c
 *
 *  Created on: 29 sep. 2019
 *      Author: sergp
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"

/** \brief Generate and keep track of the ids.
 * \return int Return the next id to use.
 *
 */
static int idGen(void)
{
    static int idMax=0;
    return idMax++;

}

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int inicializarEmpleados(Employee* list, int len)
{
    int i;
    int ret= -1;
    if(list!=NULL&&len>0)
    {
        for(i=0;i<len;i++)
        {
            list[i].id=0;
            list[i].isEmpty = 1;
            strcpy(list[i].name,"");
            list[i].salary=0;
            list[i].sector=0;
        }
        ret=0;
    }
    return ret;
}
/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int buscarEspacioLibre(Employee* list, int len)
{

	int ret = -1;
    for(int i=0;i<len;i++)
    {
        if(list[i].isEmpty==1)
        {
            ret=i;
            break;
        }
    }
    return ret;
}
int altaEmpleado(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int i;
    int ret= -1;
    i= buscarEspacioLibre(list,len);
    if(list!=NULL&&len>0)
    {
    	if(i>=0)
    	{
    		list[i].id=id;
    		list[i].isEmpty=0;
    		list[i].salary=salary;
    		list[i].sector=sector;
    		strncpy(list[i].name,name,sizeof(list[0].name));
    		strncpy(list[i].lastName,lastName,sizeof(list[0].lastName));
    		ret=0;
    	}
    	else
    	{
    		printf("No hay espacio libre");
    	}

    }
    return ret;
}

int findEmployeeById(Employee* list, int len,int id)
{
    int ret= -1;
    if(list!=NULL&&len>0)
    {
        for(int i=0;i<len;i++)
        {
            if(list[i].id==id)
            {
                ret=i;
                break;
            }
        }
    }
    return ret;
}

int removeEmployee(Employee* list, int len, int id)
{
    int index;
    int ret= -1;
    index=findEmployeeById(list,len,id);
    if(list!=NULL && len>0 && index>=0)
    {
        list[index].id=0;
        list[index].isEmpty = 1;
        strcpy(list[index].name,"");
        list[index].salary=0;
        list[index].sector=0;
        ret=0;
    }
    return ret;
}

int sortEmployees(Employee* list, int len, int order)
{
    int i;
    Employee buffer;
    int swap;
    int ret= -1;
    if(list!=NULL && len>0 && (order==0 || order==1))
    {
        do
        {
            swap=0;
            for(i=0;i<len-1;i++)
            {
                if(strcmp(list[i].lastName,list[i+1].lastName)==0)
                {
                    if(order==0 && list[i].sector<list[i+1].sector)
                    {
                        buffer = list[i];
                        list[i] = list [i+1];
                        list[i+1] = buffer;
                        swap=1;
                    }
                    if(order==1 && list[i].sector>list[i+1].sector)
                    {
                    	buffer = list[i];
                        list[i] = list [i+1];
                        list[i+1] = buffer;
                        swap=1;
                    }
                }
                if(order==0 && strcmp(list[i].name,list[i+1].name)<0)
                {
                	buffer = list[i];
                    list[i] = list [i+1];
                    list[i+1] = buffer;
                    swap=1;
                }
                if(order==1 && strcmp(list[i].name,list[i+1].name)>0)
                {
                	buffer = list[i];
                    list[i] = list [i+1];
                    list[i+1] = buffer;
                    swap=1;
                }
            }
        }while(swap!=0);
        ret=0;
    }
    return ret;
}

int printEmployees(Employee* list, int length)
{
    int i;
    int ret= -1;
    if(list!=NULL && length>0)
    {
        for(i=0;i<length;i++)
        {
            if(list[i].isEmpty==0)
            {
                printf("id: %d\n1. Nombre: %s\n2. Apellido: %s\n3. Salario %.2f\n4. Sector: %d\n", list[i].id,
                                                                                                list[i].name,
                                                                                                list[i].lastName,
                                                                                                list[i].salary,
                                                                                                list[i].sector);
            }

        }
    }
    return ret;
}
int modificaEmpleado(Employee *list,int len)
{
    int ret=-1;
    int auxId;
    int option;
    char bufferName[51];
    char bufferLastname[51];
    float bufferSalary;
    int bufferSector;
    utn_getInt(&auxId,"\nIngrese id: ","\nValor invalido",0,9999,10);
    if(findEmployeeById(list,len,auxId)>=0)
    {

        while(option!=5)
        {
            printEmployees(list,len);
            printf("5. Salir");
            utn_getInt(&option,"\nSeleccione campo a modificar: ","\nOpcion invalida",1,5,10);
            switch(option)
            {
            case 1:
            {
                if(!utn_getName(bufferName,51,"\nIngrese nombre: ","\nValor invalido",3,50,10))
                {
                    strncpy(list[auxId].name,bufferName,50);
                }
                break;
            }
            case 2:
            {
                if(!utn_getName(bufferLastname,50,"\nIngrese apellido: ","\nValor invalido",3,50,10))
                {
                    strncpy(list[auxId].lastName,bufferLastname,50);
                }
                break;
            }
            case 3:
            {
                if(!utn_getFloat(&bufferSalary,"\nIngrese salario: ","\nValor invalido",0,32000000,10))
                {
                    list[auxId].salary=bufferSalary;
                }
                break;
            }
            case 4:
            {
                if(!utn_getInt(&bufferSector,"\nIngrese sector: ","\nValor invalido",1,1000,10))
                {
                    list[auxId].sector=bufferSector;
                }
                break;
            }
            }
        }
        ret=0;
    }
    else
    {
        printf("\nId invalido");
    }
    return ret;
}

int getEmployee(Employee* list,int len)
{
    int ret=-1;
    char bufferName[51];
    char bufferLastname[51];
    float bufferSalary;
    int bufferSector;
    int freeIndex=buscarEspacioLibre(list,len);

    if( !utn_getName(bufferName,51,"\nIngrese nombre: ","\nValor invalido",3,50,10)&&
        !utn_getName(bufferLastname,50,"\nIngrese apellido: ","\nValor invalido",3,50,10)&&
        !utn_getFloat(&bufferSalary,"\nIngrese salario: ","\nValor invalido",0,32000000,10)&&
        !utn_getInt(&bufferSector,"\nIngrese sector: ","\nValor invalido",1,1000,10)&&
        freeIndex>=0)
    {
        altaEmpleado(list,len,idGen(),bufferName,bufferLastname,bufferSalary,bufferSector);
        ret=0;
    }
    return ret;
}

int existEmployee(Employee* list,int len)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==0)
        {
            ret=0;
            break;
        }
    }
    return ret;
}
int getDeleteEmployee(Employee *list,int len)
{
    int ret=-1;
    int auxId;
    utn_getInt(&auxId,"\nIngrese id: ","\nValor invalido",0,9999,10);
    if(findEmployeeById(list,len,auxId)>=0)
    {
        removeEmployee(list,len,auxId);
        ret=0;
    }
    else
    {
        printf("\nId invalido");
    }
    return ret;
}
