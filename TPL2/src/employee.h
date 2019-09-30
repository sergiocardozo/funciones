/*
 * employee.h
 *
 *  Created on: 29 sep. 2019
 *      Author: sergp
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

typedef struct
{
    int id;
    int isEmpty;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
}Employee;

int inicializarEmpleados(Employee* list, int len);
int buscarEspacioLibre(Employee* list, int len);
int altaEmpleado(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int length);
int modificaEmpleado(Employee *list,int len);
int getEmployee(Employee* list,int len);
int existEmployee(Employee* list,int len);
int getDeleteEmployee(Employee *list,int len);


#endif /* EMPLOYEE_H_ */
