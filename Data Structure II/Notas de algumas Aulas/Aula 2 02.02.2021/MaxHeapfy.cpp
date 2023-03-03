#include <stdio.h>
#include <stdlib.h>


#define MAX_TAM 40


void MaxHeapify(int *vet, int i);
int Pai(i);
int Esquerdo(i);
int Direito(i);


int main(){
	
	int *vet;
	int i, tam;
	
	printf("Quantidade de elementos do vetor: ");	
	scanf("%d", &tam);
	
	vet = (int *)(malloc(MAX_TAM * sizeof(int)));
	
	if(vet==NULL){
		printf("Erro: Sem memoria");
		system("pause");
		exit(1);
	}
	
	vet[0] = tam;
	
	for(i=1; i<=tam; i++){
		printf("Didige o numero para o indice [%d]: ", i);
		scanf("%d", &vet[i]);
	}
	
	
	###################################################
	
	
	for(int i = 1; i<=tam; i++){
		if(i<tam)
			printf("%d, ", vet[i]);
		else
			printf("%d.", vet[i]);
	}
	
	free(vet);
	
	return 0;
}

void MaxHeapify(int *vet, int i){
	
	int l = Esquerdo(i);
	int r = Direito(i);
	int maior = -1, aux;
	
	if(l <= vet[0] && vet[l]>vet[i])
		maior = l;
	else
		maior = i;
	
	if(r<=vet[0] && A[r]>A[maior])
		maior = r;
		
	if (maior != i){
		aux = vet[i];
		vet[i] = vet[maior];
		vet[maior] = aux;
		MaxHeapify(A, maior);
	}
}


void ContruirHeapMax(int *vet){
	int i;
	
	
}


int Pai(i){
	return i/2;
}

int Esquerdo(i){
	return 2*i
}

int Direito(i){
	return 2*i+1;
}





