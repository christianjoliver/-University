/*
	UFES/CEUNES
	Professora: Luciana Lee;
	Disciplina: Estrutura de Dados II;
	Avaliacao 4: Algoritmo de Huffman;
	Equipe: Christian Jonas Oliveira e Joao Victor do Rozario Recla.
*/

#include "Huffman.h"



Tree *create_Tree(char c, int qnt){

	// alocacao de um espaco de memoria para um node da arvore
	Tree *Node = NULL;
	Node = (Tree *)malloc(sizeof(Tree));

	// iniciando seus campos
	if(Node){
		Node->elemento = c;
		Node->freq = qnt;
		Node->left = NULL;
		Node->right = NULL;
	}

	return Node;
}



Codigo *create_CodNode(char elem, char *c){

	// alocacao e inicializacao de um novo elemento Codigo, que guarda o caractere e seu codigo
	Codigo *novo = (Codigo *)malloc(sizeof(Codigo));

	if(novo){
		novo->tamanho = strlen(c);
		novo->elemento = elem;
		novo->cod = (char *)calloc(strlen(c), sizeof(char));
		strcpy(novo->cod, c);
	}
	return novo;
}



void arq_Codigo(FILE *fp, Codigo **ptr, int tam){


	// move o ponteiro para o incio do arquivo
	int i;
	rewind(fp);

	// move o ponteiro para a posicao a frente do  cabecalho
	fseek(fp, sizeof(Head), SEEK_SET);

	// salvamento dos campos da estrutura que guarda os codigos de Huffman de cada caractere
	for(i = 0; i<tam; i++){
		fwrite(ptr[i], sizeof(Codigo), 1, fp);
		fwrite(ptr[i]->cod, ptr[i]->tamanho * sizeof(char), 1, fp);
	}

}



void arq_Head(FILE *fp, Head *c){

	// move o ponteiro para o inicio do arquivo e escreve o cabecalho nele
	rewind(fp);
	fwrite(c, sizeof(Head), 1, fp);
}



char *readFile_Zip(){

	FILE *fp = NULL;
	char S[50], c;
	int qnt=0, i=0;

	// entrada e tratamento do nome do arquivo (le caracteres de ATE 8 bits)
	getchar();
	printf("\n\t Digite o nome do arquivo a ser lido (sem o .txt): ");
	fgets(S, 50, stdin);
	S[strcspn(S, "\n")] = 0;
	strcat(S,".txt");

	fp = fopen(S, "r");
	if(!fp){
		printf("\n\tErro de abertura");
		exit(1);

	}

	// leitura da quantidade de caracteres do arquivo
	while(fscanf(fp, "%c", &c)!=EOF){
		qnt++;

	}

	rewind(fp);

	char *vet = (char *)calloc(qnt, sizeof(char));

	// leitura dos caracteres do arquivo de entrada
	if(vet){

		while(fscanf(fp, "%c", &c)!=EOF){
			vet[i] = c;
			i++;
		}

		vet[strlen(vet)] = 0;
	}

	fclose(fp);


	return vet;
}



Codigo **readFile_Unzip(FILE *fp, int tam){

	Codigo **c = (Codigo **)malloc(tam * sizeof(Codigo));

	int i;

	// move o ponteiro do arquivo para a posicao a frente do cabecalho
	fseek(fp, sizeof(Head), SEEK_SET);

	// leitura da tabela que guarda o codigo e os elementos contidos na codificacao
	for(i = 0; i < tam; i++){

		c[i] = (Codigo *)calloc(1, sizeof(Codigo));
		fread(c[i], sizeof(Codigo), 1, fp);
		c[i]->cod = (char *)calloc(1, c[i]->tamanho * sizeof(char));
		fread(c[i]->cod, c[i]->tamanho * sizeof(char), 1, fp);
	}

	return c;
}



Head *count_Freq(char *vet){

	int i = 0, j, k = 0;
	int qnt;
	char c;

	Tree *No = NULL;
	Tree **aux;
	aux = (Tree **)malloc(strlen(vet) * sizeof(Tree));
	Head *cab = NULL;
	cab = (Head *)malloc(sizeof(Head));

	// conta a frequencia de cada caractere e aloca em um vetor do tipo Tree preenchendo seus campos com um elemento e sua frequencia
	// retorna um ponteiro para um cabecalho que contera um vetor de Nos preenchidos
	while(i < strlen(vet)){

		qnt = 0;
		c = vet[i];
		j = i;
		while(j < strlen(vet) && vet[j] == c){

			qnt++;
			j++;
			i++;
		}

		No = create_Tree(c, qnt);

		if(No){

			aux[k] = No;
			k++;
		}

		else{
			printf("\n\t Erro de alocacao");
			exit(1);
		}

	}

	cab->qnt_nos = k;
	cab->vetor = aux;
	cab->tam = k;
	cab->qnt_elem = k;

	return cab;
}



void QuickSort(char *vet, int ini, int fim){
	int p;

	// chamada recursiva da funcao, particionando um vetor de caracteres afim de ordena-lo
	if(ini<fim){
		p = particao(vet, ini, fim);
		QuickSort(vet, ini, p-1);
		QuickSort(vet, p+1, fim);
	}
}



int particao(char *vet, int ini, int fim){

	char pivot = vet[fim];
	char aux;
	int i = ini-1, j;

	// funcao reponsavel por "quebrar" o vetor ao meio reordenando-o
	for(j=ini; j<fim; j++){
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



void QuickSort_cab(Head *cab, int ini, int fim){
	int p;

	// chamada recursiva da funcao, particionando um vetor de Nos afim de ordena-lo pela frequência
	if(ini<fim){
		p = particao_cab(cab, ini, fim);
		QuickSort_cab(cab, ini, p-1);
		QuickSort_cab(cab, p+1, fim);
	}
}



int particao_cab(Head *cab, int ini, int fim){

	Tree **vet = cab->vetor;
	Tree *pivot = vet[fim];
	Tree *aux;
	int i = ini-1, j;

	// funcao reponsavel por "quebrar" o vetor ao meio reordenando-o (de acordo com sua frequencia)
	for(j=ini; j<fim; j++){

		if(vet[j]->freq <= pivot->freq){
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



void Huffman(Head *cab){

	int i;
	Tree *x, *y, *z;
	int n = cab->tam;
	QuickSort_cab(cab, 0, (cab->tam)-1);

	// gera a arvore de huffman a partir de um vetor ordenado
	for(i = 0; i<n-1; i++){

		z = create_Tree('#', 0);

		if(z){
			x = cab->vetor[0];
			y = cab->vetor[1];
			z->left = x;
			z->right = y;
			z->freq = x->freq + y->freq;
			cab->qnt_nos++;
			update_Priority(cab, z);

		}

		else{
			printf("\n\t Erro de Alocacao");
			exit(1);
		}
	}

}



void update_Priority(Head *cab, Tree *elem){

	int i;

	// auxiliar Huffman que reordena  o vetor de acordo com a retirada do menor elemento
	for(i = 2; i < cab->tam; i++){

		if(elem->freq < cab->vetor[i]->freq){
			cab->vetor[i-2] = elem;
			elem = cab->vetor[i];

		}

		else if(elem->freq >= cab->vetor[i]->freq)
			cab->vetor[i-2] = cab->vetor[i];


		if(i+1 == cab->tam)
			cab->vetor[i-1] = elem;

	}

	if(cab->tam==2){

		cab->vetor[0] = elem;
	}

	// liberacao do espaco de memoria do no sobresaliente
	cab->vetor[i-1] = NULL;
	free(cab->vetor[i-1]);
	cab->tam--;

}



void create_Code(Tree *ptr, char *codigo, Codigo **vet, char *vet_aux, int *tamCODE, int *iCODE){

	// cria o codigo de um caractere a partir do deslocamento necessario na arvore para "chegar" ate ele
	if(!ptr){
		*tamCODE-=1;
	}

	else{

		// chamada da sub-arvore esquerda
		if(ptr->left){
			codigo[*tamCODE] = '0';
			*tamCODE+=1;
			create_Code(ptr->left, codigo, vet, vet_aux, tamCODE, iCODE);
		}

		// chamada da sub-arvore direita
		if(ptr->right){
			codigo[*tamCODE] = '1';
			*tamCODE+=1;
			create_Code(ptr->right, codigo, vet, vet_aux, tamCODE, iCODE);
		}

		// caso encontre o elemento, aloca novo no e o guarda no vetor de codigos
		else{

			strncpy(vet_aux, codigo, *tamCODE);
			vet_aux[*tamCODE] = '\0';
			vet[*iCODE] = create_CodNode(ptr->elemento, vet_aux);
			*iCODE+=1;
		}
	}
	*tamCODE-=1;
}



int percorre_arvore(Tree *ptr, char *cod){

	int i;

	// auxiliar da create_vetSaida, responsavel por percorrer a arvore e retornar a frequencia de um elemento
	for(i = 0; i<strlen(cod); i++){

		if(cod[i]=='0')
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}
	return ptr->freq;
}



char *create_vetSaida(Codigo **ptr, char *org, Head *cab){


	int i, j;
	int soma = 0;

	// cria o vetor com o codigo de Huffman referente ao texto inteiro lido

	for(i = 0; i < cab->qnt_elem; i++){
		soma += percorre_arvore(cab->vetor[0], ptr[i]->cod) * strlen(ptr[i]->cod);
	}

	char *saida = (char *)calloc(soma, sizeof(char));

	for(i = 0; i < strlen(org); i++){

		for(j = 0; j < cab->qnt_elem; j++) {

			if(ptr[j]->elemento == org[i]){
				strcat(saida, ptr[j]->cod);
				break;
			}
		}
	}
	return saida;
}



void zip_File(FILE *fp, char *vet, Head *cab, Codigo **ptr){

	// realiza o deslocamento necessario dos elementos do codigo de Huffman para assim, compacta-lo
	unsigned char saida[strlen(vet)];

	memset(saida, 0, strlen(vet));
	int pos = 0, posbyte, posbit, i, k;

	unsigned char aux;
	int cv[strlen(vet)];

	for(k = 0; k<strlen(vet); k++){

		if(vet[k]=='0') cv[k] = 0;
		else cv[k] = 1;
	}

	// deslocamento
	for(i = 0; i < strlen(vet); i++){
		posbyte = pos/8;
		posbit = pos%8;
		aux = cv[i];
		aux = aux << (8 - posbit - 1);
		saida[posbyte] = saida[posbyte] | aux;
		pos++;
	}

	// gravacao no arquivo
	cab->qnt_Bits = strlen(vet);
	arq_Head(fp, cab);
	arq_Codigo(fp, ptr, cab->qnt_elem);
	fwrite(saida, sizeof(saida), 1, fp);
}



void decode_File(Codigo **c, char *codigo, FILE *decodificacao, int tam){

	// decodifica o codigo do arquivo compactado e o compara com o Codigo de Huffman traduzindo-o
	// e o escrevendo no arquivo de saida descompactado
	int i, j, k = 0;
	char ptr[MAX];
	int growup = 0;
	memset(ptr, 0, MAX);

	printf("\n\t Texto descompactado: ");

	for(i = 0; i < strlen(codigo); i++){
		ptr[k] = codigo[i];

		for(j = 0; j < tam; j++){

			if(strncmp(ptr, c[j]->cod, c[j]->tamanho)==0){
				growup = 1;
				printf("%c", c[j]->elemento);
				fwrite(&c[j]->elemento, sizeof(char), 1, decodificacao);
				memset(ptr, 0, MAX);
				k = 0;
				break;
			}
		}

		if(growup==0)
			k++;

		growup = 0;

	}
}



void unzip_File(FILE *fp, FILE *fp2){

	// le o arquivo compactado e o transforma no codigo de Huffman
	int posbyte, posbit, pos, i;
	unsigned char aux;
	int s = 8, t;

	Head *cab = (Head *)malloc(sizeof(Head));
	fread(cab, sizeof(Head), 1, fp);
	cab->tam = cab->qnt_elem;
	Codigo **c = readFile_Unzip(fp, cab->qnt_elem);
	// calculo da quantidade de bits necessarios para alocar o codigo de Huffman apos descompactacao
	if((cab->qnt_Bits/8) != 0){

		t = cab->qnt_Bits/8;
		s = t * 8 + 8;
	}

	unsigned char vet[s];
	char *result = (char *)calloc(s, sizeof(char));
	fread(vet, s, 1, fp);
	pos = cab->qnt_Bits;

	// deslocamento e traducao do codigo lido
	for (i=0; i<pos; i++) {
	        posbyte = i/8;
	        posbit = i%8;
	        aux = 1;
	        aux = aux << (8 - posbit - 1);
	        aux = vet[posbyte] & aux;
	        aux = aux >> (8 - posbit - 1);
	        if(aux == 0) result[i] = '0';
			else result[i] = '1';
	}

	decode_File(c, result, fp2, cab->qnt_elem);
}



void imprime_Frequencia(Head *cab){

	// imprime a frequencia de cada caractere
	int i;
	Tree **aux = cab->vetor;
	printf("\n");
	printf("\n\t Elemento\t|\tFrequencia");
	printf("\n");
	for(i = 0; i<cab->tam; i++){

		if(aux[i]->elemento=='\n')
			printf("\n\t enter \t\t|\t %d", aux[i]->freq);

		else if(aux[i]->elemento==' ')
			printf("\n\t espaco \t|\t %d", aux[i]->freq);

		else printf("\n\t %c \t\t|\t %d", aux[i]->elemento, aux[i]->freq);

		printf("\n");
	}
	printf("\n");
}



void printa_Codigo(Codigo **aux, int tam){

	// imprime o codigo referente a cada caractere
	int i;
	printf("\n");
	printf("\n\t Elemento\t|\tCodigo");
	printf("\n");
	for(i = 0; i < tam; i++){

		if(aux[i]->elemento=='\n')
			printf("\n\t enter \t\t|\t %s", aux[i]->cod);
		else if(aux[i]->elemento==' ')
			printf("\n\t espaco \t|\t %s", aux[i]->cod);
		else printf("\n\t %c \t\t|\t %s", aux[i]->elemento, aux[i]->cod);

		printf("\n");

	}
	printf("\n");
}


void destroy_Codigo(Codigo **code, int tam){

	// destroi um vetor de Codigos
	int i;
	for(i = 0; i < tam; i++){

		free(code[i]->cod);
		free(code[i]);
	}

	free(code);
}