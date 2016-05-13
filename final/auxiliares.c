#include "auxiliares.h"

bool e_caracter_branco(char c){
	int i = 0;

	for (; i < NUMSEP; i++){
		if (separators[i] == c)
			return true;
	}
	return false;
}