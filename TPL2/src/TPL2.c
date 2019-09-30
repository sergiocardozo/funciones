/*
 ============================================================================
 Name        : TPL2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"

#define QTY_EMPLEADOS 1000

int main()
{
	int opcion;
	int opcionInformes;

	Employee empleados[QTY_EMPLEADOS];
	inicializarEmpleados(empleados,QTY_EMPLEADOS);

	do
	{
		printf("\n MENU DE OPCIONES \n\n1-ALTAS.\n2-MODIFICAR.\n3-BAJAS.\n4-LISTAR.\n5-INFORMES.\n6-SALIR.");
		utn_getInt(&opcion,"\n\nIngrese una opcion","\nERROR. Opcion no valida",1,6,10);
		switch(opcion)
		{
		case 1:
			getEmployee(empleados,QTY_EMPLEADOS);
			break;
		case 2:
			if(!existEmployee(empleados,QTY_EMPLEADOS))
			{
				modificaEmpleado(empleados,QTY_EMPLEADOS);

			}
			else
			{
				printf("\nNo existe empleado con ese ID");
			}
			break;
		case 3:
			if(!existEmployee(empleados,QTY_EMPLEADOS))
			{
				getDeleteEmployee(empleados,QTY_EMPLEADOS);

			}
			else
			{
				printf("\nNo existe empleado con ese ID");
			}
			break;
		case 4:
			if(!existEmployee(empleados,QTY_EMPLEADOS))
			            {
			                while(opcionInformes!=3)
			                {
			                    printf("/-----------------\n1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector\n2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n3.SALIR");
			                    utn_getInt(&opcionInformes,"\nSelecione una opcion: ","\nOpcion invalida",1,3,10);
			                    switch(opcionInformes)
			                    {
			                    case 1:
			                        sortEmployees(empleados,QTY_EMPLEADOS,1);
			                        printEmployees(empleados,QTY_EMPLEADOS);
			                        break;
			                    }
			                }
			            }

		}
	}while(opcion != 6);

return 0;
}
