/*
 * utn.h
 *
 *  Created on: 29 sep. 2019
 *      Author: sergp
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getString(  char *pResult,
                char *pMsg,
                char *pMsgError,
                int min,
                int max,
                int attemps);

int utn_isValidInt (char* string);

int utn_isValidFloat(char* string);

int utn_isValidName (char* string);

int utn_isValidName (char* string);

int utn_isValidAddress (char* string);

int utn_getInt(  int *pResult,
                char *pMsg,
                char *pMsgError,
                int min,
                int max,
                int attempts);

int utn_getFloat(   float *pResult,
                    char *pMsg,
                    char *pMsgError,
                    int min,
                    int max,
                    int attempts);

int utn_getName(    char *pResult,
                    int len,
                    char *pMsg,
                    char *pMsgError,
                    int minChars,
                    int maxChars,
                    int attempts);

int utn_getAddress( char *pResult,
                    int len,
                    char *pMsg,
                    char *pMsgError,
                    int minChars,
                    int maxChars,
                    int attempts);

#endif /* UTN_H_ */
