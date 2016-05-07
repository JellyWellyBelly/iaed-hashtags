#ifndef _AUX_
#define _AUX_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUMSEP 11

static const char separators[] = {' ','\t',',',';','.','?','!','"','\n',':','\0'};

bool e_caracter_branco(char c);

#endif