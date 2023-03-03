#include <stdio.h>
#include <stdlib.h>

void mergesort(int *vet, int ini, int fim);
void merge(int *vet, int ini, int meio, int fim);

int main(){
	
	int *vet;
	int i, tam;
	
	printf("Quantidade de elementos do vetor: ");	
	scanf("%d", &tam);
	
	vet = (int *)(malloc(tam * sizeof(int)));
	
	if(vet==NULL){
		printf("Erro: Sem memoria");
		system("pause");
		exit(1);
	}
	
	for(i=0; i<tam; i++){
		printf("Didige o numero para o indice [%d]: ", i);
		scanf("%d", &vet[i]);
	}
	
	
	mergesort(vet, 0, tam);
	
	
	for(int i = 0; i<tam; i++){
		if(i<tam-1)
			printf("%d, ", vet[i]);
		else
			printf("%d.", vet[i]);
	}
	
	free(vet);
	
	return 0;
}

void mergesort(int *vet, int ini, int fim){	
	
	int meio;
	
	if(fim-ini>1){
		meio = (ini+fim)/2;
		mergesort(vet, ini, meio);
		mergesort(vet, meio, fim);
		merge(vet, ini, meio, fim);
	}
}


void merge(int *vet, int ini, int meio, int fim){
	
	int tam_esq = meio-ini;
	int tam_dir = fim-meio;
	int i, pd=0, pe=0;
	
	int *esq, *dir, k;
	
	esq = (int *)(malloc(tam_esq * sizeof(int)));
	dir = (int *)(malloc(tam_dir * sizeof(int)));
	
	for(k=ini, i=0; k<meio; k++, i++)
		esq[i] = vet[k];
		
	for(k=meio, i=0; k<fim; k++, i++)
		dir[i] = vet[k];
	
	
	for(i = ini; i<fim; i++){
		
		if(pe>=tam_esq){
			vet[i] = dir[pd];
			pd++;
		}
		
		else if(pd>=tam_dir){
			vet[i] = esq[pe];
			pe++;
		}
		
		else if(esq[pe]<dir[pd]){
			vet[i] = esq[pe];
			pe++;
		}
		
		else{
			vet[i] = dir[pd];
			pd++;
		}	
	}
	free(esq);
	free(dir);	
}
