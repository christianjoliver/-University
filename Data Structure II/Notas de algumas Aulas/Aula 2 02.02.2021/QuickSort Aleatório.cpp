#include <stdio.h>
#include <stdlib.h>

int particao(int *vet, int ini, int fim);
void QuickSort(int *vet, int ini, int fim);
int randomize(int *vet, int ini, int fim);

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
	
	
	QuickSort(vet, 0, tam-1);
	
	
	for(int i = 0; i<tam; i++){
		if(i<tam-1)
			printf("%d, ", vet[i]);
		else
			printf("%d.", vet[i]);
	}
	
	free(vet);
	
	return 0;
}


void QuickSort(int *vet, int ini, int fim){
	int p;
	if(ini<fim){
		p = randomize(vet, ini, fim);
		QuickSort(vet, ini, p-1);
		QuickSort(vet, p+1, fim);
	}
}

int randomize(int *vet, int ini, int fim){
	
	int i;
	int aux;
	i = ini+(rand() % (fim-ini));
	aux = vet[fim];
	vet[fim] = vet[i];
	vet[i] = aux;
	
	return particao(vet, ini, fim);
}

int particao(int *vet, int ini, int fim){
	int pivot = vet[fim];
	int aux, j;
	int i = ini-1;
	
	for(j=ini; j<=fim-1; j++){
		if(vet[j]<=pivot){
			i++;
			aux = vet[j];
			vet[j] = vet[i];
			vet[i] = aux;
		}	
	}
	aux = vet[fim];
	vet[fim] = vet[i+1];
	vet[i+1] = aux;
	
	return i+1;
}


