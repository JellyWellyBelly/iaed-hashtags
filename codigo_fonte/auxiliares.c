/******************************************************************************************
* File Name:   auxiliares.c
* Author:      Goncalo Marques (84719) / Manuel Sousa (84740)
* Revision:
* NAME:        Hashtags - IST/IAED - 2015/2016 2º Semestre
* SYNOPSIS:    #include "auxiliares.h" - prototipos e constantes das funcoes auxiliares
* DESCRIPTION: funcoes auxiliares que suportam a funcao main (main.c)
* DIAGNOSTICS: tested
*****************************************************************************************/
#include "auxiliares.h"

/******************************************************************************************
* e_caracter_branco()
*
* Arguments:    c:  caracter
*
* Returns: bool retorna true se for um caracter branco, false caso contrario
* Description:  verifica se um caracter e considerado branco ou nao
*****************************************************************************************/
bool e_caracter_branco(char c){
	int i = 0;

	for (; i < NUMSEP; i++){
		if (separadores[i] == c)
			return true;
	}
	return false;
}
