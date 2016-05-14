/******************************************************************************
* File Name: auxiliares.h
* Author:      Goncalo Marques (84719) / Manuel Sousa (84740)
* Revision:
* NAME
*      	auxiliares - prototipos
* SYNOPSIS:    #include <stdio.h>
	       #include <string.h>  - strdup
	       #include <stdlib.h>  - qsort
	       #include <stdbool.h> - bool's
* DESCRIPTION
*	       prototipos e constantes das funcoes auxiliares
* DIAGNOSTICS
*          OK
*****************************************************************************/
#ifndef _AUXILIARES_
#define _AUXILIARES_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//Numero de caracteres brancos
#define NUMSEP 11

//caracteres brancos
static const char separadores[] = {' ','\t',',',';','.','?','!','"','\n',':','\0'};

bool e_caracter_branco(char c);

#endif
