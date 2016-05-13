/******************************************************************************
* File Name: auxiliares.h
* Author:    Goncalo / Manuel
* Revision:
* NAME
*      auxiliares - prototipos
* SYNOPSIS
*      #include <stdio.h>
*      #include <stdlib.h>
*      #include <string.h>
*      #include <stdbool.h>
* DESCRIPTION
*		Implements input auxiliary functions
* DIAGNOSTICS
*          OK
*****************************************************************************/
#ifndef _AUXILIARES_
#define _AUXILIARES_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NUMSEP 11

static const char separators[] = {' ','\t',',',';','.','?','!','"','\n',':','\0'};

bool e_caracter_branco(char c);

#endif
