#include "table.h"

void Init(){
	int i;
	heads = (link*)malloc(sizeof(link)*M);
	for (i = 0; i < M; i++){
		heads[i] = NULL;
	}
}