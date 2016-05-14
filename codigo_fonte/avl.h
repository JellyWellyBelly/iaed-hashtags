/******************************************************************************
* File Name: avl.h
* Author:      Goncalo Marques (84719) / Manuel Sousa (84740)
* Revision:
* NAME
*      avl - prototipos
* SYNOPSIS:    #include <stdio.h>
	       #include <string.h> - strdup
	       #include <stdlib.h> 	- qsort
	       #include "item.h" - prototipos das funcoes que violam abstracao
* DESCRIPTION
*		Prototipos e estruturas da AVL TREE
* DIAGNOSTICS
*          OK
*****************************************************************************/
#ifndef _AVL_
#define _AVL_
#include <stdio.h>
#include <stdlib.h>
#include "item.h"

typedef struct STnode* link;

//no
struct STnode { 
	Item item; 
	link l, r; 
	int peso;
};

Item AVLprocura(link head, Key v);

Item searchR(link h, Key v);

void AVLinicializa(link*);

void AVLinsere(link*,Item);

void AVLapaga(link*,Key);

void AVLliberta(link*);

void decrescente(link h, void (*visit)(Item));

void AVLimprime(link ,void (*visit)(Item));

void AVLinicializa(link*);

void AVL_para_array(link h,Item *vec,int *i);

void decrescente(link h, void (*visit)(Item));

link NOVO(Item item, link l, link r);

link min(link h);

link max(link h);

link AVLbalance(link h);

link freeR(link h);

link rotR(link h);

link deleteR(link h, Key k) ;

link rotLR(link h);

link rotL(link h);

link rotRL(link h);

link insertR(link h, Item item);

int count(link h);

int AVLconta(link);

int peso(link h);

int Balance(link h);

#endif