/*
 * utn.c
 *
 *  Created on: 13 sep. 2019
 *      Author: sergio
 */
#include <stdio.h>
#include <stdlib.h>

int getInt(char mensaje[]){
	int auxiliar;
	printf("%s",mensaje);
	scanf("%d" ,&auxiliar);

return auxiliar;
}

float getFloat(char mensaje[]){
	float auxiliar;
	printf("%s",mensaje);
	scanf("%f" ,&auxiliar);

return auxiliar;
}

char getChar(char mensaje[]){
	char auxiliar;
	printf("%s",mensaje);
	fpurge(stdin);
	scanf("%c" ,&auxiliar);
	return auxiliar;
}
