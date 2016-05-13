#include "auxiliares.h"

bool e_caracter_branco(char c){
	int i = 0;

	for (; i < NUMSEP; i++){
		if (separators[i] == c)
			return true;
	}
	return false;
}

char* criaItem(char* item, int rep){
	char *string = (char*)malloc(sizeof(char)*165);
	sprintf(string, "%d%s", rep, item);
	return string;
}