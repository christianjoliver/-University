/*
	UFES/CEUNES
	Professora: Luciana Lee;
	Disciplina: Estrutura de Dados II;
	Avaliacao 4: Algoritmo de Huffman;
	Equipe: Christian Jonas Oliveira e Joao Victor do Rozario Recla.
*/

#ifndef Huffman_h
#define Huffman_h
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000



//	Estrutura de um elemento de uma Arvore de decodificacao do codigo de Huffman;
//	left: (struct Tree *) ponteiro para um elemento a esquerda do no;
//	right:(struct Tree *) ponteiro para um elemento a direita do no;
//	freq:	  ( int )  inteiro que representa a frequencia de ocorrencia de um elemento;
//	elemento: ( char ) caractere que representa um elemento;
typedef struct Tree{

	struct Tree *left;
	struct Tree *right;
	int freq;
	char elemento;

}Tree;



//	Estrutura de um cabecalho da Arvore de decodificacao do codigo de Huffman;
//	vetor:	  (Tree **)	ponteiro para um vetor de elementos do tipo Tree;
//	tam:      ( int )	inteiro que representa o tamanho do vetor (atualizado durante o update_Priority);
//	qnt_elem: ( int )	inteiro que representa a quantidade de elementos da arvore (nao sera modificado);
//	qnt_nos:  ( int )	inteiro que representa a quantidade de nos da arvore (nao sera modificado);
//	qnt_Bits: ( int )	inteiro que representa a quantidade de bits a serem lidos;
typedef struct Head{

	Tree **vetor;
	int tam;
	int qnt_elem;
	int qnt_nos;
	int qnt_Bits;

}Head;


//	Estrutura de uma tabela para o codigo de Huffman de cada elemento;
//	tamanho:  ( int )   inteiro que representa o tamanho do codigo;
//	elemento: ( char )  caractere que representa o elemento;
//	cod:	  (char *)  ponteiro para a string que representa o codigo;
typedef struct Codigo{

	int tamanho;
	char elemento;
	char *cod;

}Codigo;


//	Funcao create_Tree:  funcao responsavel por alocar espaco de memoria para um novo no da Tree, atribuindo o elemento e sua frequencia;
//	Entrada: ( char )	 caractere a ser inserido, ( int ) frequencia do caractere;
//	Saida:   (Tree *)	 ponteiro para no da Tree;
Tree *create_Tree(char c, int qnt);



//	Funcao arq_Codigo:	 funcao responsavel por inserir os elementos da tabela de codigos de Huffman em um arquivo;
//	Entrada: (FILE *)	 ponteiro para um arquivo, (Codigo **) endereco de ponteiro para a tabela de codigos, ( int ) quantidade de elementos na tabela;
//	Saida:   void;
void arq_Codigo(FILE *fp, Codigo **ptr, int tam);



//	Funcao arq_Head: funcao responsavel por inserir um cabecalho de uma Arvore de decodificacao de Huffman em um arquivo;
//	Entrada: (FILE *)	 ponteiro para um arquivo, (Head *) ponteiro para um cabecalho de uma Arvore;
//	Saida:   void;
void arq_Head(FILE *fp, Head *c);



//	Funcao readFile_Zip: funcao responsavel por ler um arquivo a ser compactado;
//	Entrada: void;
//	Saida:   (char *)    vetor contendo todos os caracteres do arquivo;
char *readFile_Zip();



//	Funcao readFile_Unzip: funcao responsavel por ler a tabela de codigos de um arquivo compactado;
//	Entrada: (FILE *)	 ponteiro para um arquivo, ( int ) inteiro que representa a quantidade de elementos da tabela;
//	Saida:   (Codigo **) tabela de codigos de Huffman de cada caractere;
Codigo **readFile_Unzip(FILE *fp, int tam);



//	Funcao count_Freq:	 funcao responsavel por contar a frequencia dos elementos do arquivo a ser compactado;
//	Entrada: (char *)	 vetor contendo todos os caracteres do arquivo;
//	Saida:   (Head *)	 ponteiro para um cabecalho com um vetor dos elementos da Arvore;
Head *count_Freq(char *vet);



//	Funcao particao:	 funcao responsavel por reorganizar o vetor de caracteres passado atraves do particionamento do mesmo;
//	Entrada: (char *)	 vetor contendo todos os caracteres do arquivo, ( int ) posicao inicial do vetor, ( int ) posicao final do vetor;
//	Saida:   ( int )	 inteiro contendo a posicao do inicio do sub-vetor particionado no Quicksort;
int particao(char *vet, int ini, int fim);



//	Funcao particao_cab: funcao responsavel por reorganizar o vetor de elementos Tree passado atraves do particionamento do mesmo;
//	Entrada: (Head *)    cabecalho que segura o vetor contendo todos os nos da Arvore, ( int ) posicao inicial do vetor, ( int ) posicao final do vetor;
//	Saida:   ( int )     inteiro contendo a posicao do inicio do sub-vetor particionado no Quicksort;
int particao_cab(Head *cab, int ini, int fim);



//	Funcao QuickSort:	funcao responsavel por ordenar um vetor de caracteres;
//	Entrada: (char *)   vetor contendo todos os caracteres do arquivo, ( int ) posicao inicial do vetor, ( int ) posicao final do vetor;
//	Saida:   void;
void QuickSort(char *vet, int ini, int fim);



//	Funcao QuickSort_cab: funcao responsavel por ordenar um vetor de elementos do tipo Tree de acordo com sua frequencia;
//	Entrada: (Head *)   cabecalho que segura o vetor contendo todos os nos da Arvore, ( int ) posicao inicial do vetor, ( int ) posicao final do vetor;
//	Saida:   void;
void QuickSort_cab(Head *cab, int ini, int fim);



//	Funcao Huffman: funcao responsavel por montar a Arvore do codigo de Huffman;
//	Entrada: (Head *)   cabecalho que segura o vetor contendo todos os nos da Arvore;
//	Saida:   void;
void Huffman(Head *cab);



//	Funcao update_Priority: funcao responsavel por reoordenar o vetor passado em Huffman de acordo com a prioridade de seus elementos;
//	Entrada: (Head *)   cabecalho que segura o vetor contendo todos os nos da Arvore, (Tree *) elemento criado na funcao Huffman a ser inserido;
//	Saida:   void;
void update_Priority(Head *cab, Tree *elem);



//	Funcao create_Code: funcao responsavel por criar o codigo de Huffman para cada elemento com base na leitura de uma arvore;
//	Entrada: (Tree *)   ponteiro para raiz da arvore, (char *) vetor que armazena o codigo durante a recursao,
//			 (Codigo *) ponteiro para tabela que segura os codigos de cada elemento, (char *) vetor auxiliar que segurara um pedaco referente ao elemento,
//			 (int *)    ponteiro para contador auxiliar referente ao tamanho do vetor em cada iteracao, (int *) ponteiro para contador auxiliar para o indice da tabela de codigos;
//	Saida:   void;
void create_Code(Tree *ptr, char *codigo, Codigo **vet, char *vet_aux, int *tamCODE, int *iCODE);



//	Funcao create_vetSaida: funcao responsavel por codificar todo o texto com base na tabela de codigos;
//	Entrada: (Codigo **) ponteiro para tabela com os codigos, (char *) para o texto original lido, (Head *) ponteiro para cabecalho com os dados dos elementos;
//	Saida:	 (char *)	 ponteiro para o codigo de Huffman de todo o texto;
char *create_vetSaida(Codigo **ptr, char *org, Head *cab);



//	Funcao zip_File:	 funcao responsavel por compactar o codigo de Huffman e seus dados pertinentes;
//	Entrada: (FILE *)	 Ponteiro para um arquivo de saida, (char *) ponteiro para o codigo de Huffman do texto, (Head *) ponteiro para o cabecalho, (Codigo **) ponteiro para a tabela;
//	Saida:   void;
void zip_File(FILE *fp, char *vet, Head *cab, Codigo **ptr);



//	Funcao unzip_File:   funcao responsavel por descompactar o codigo de Huffman e seus dados pertinentes;
//	Entrada: (FILE *)	 Ponteiro para um arquivo compactado, (FILE *)	 Ponteiro para um arquivo descompactado e traduzido;
//	Saida:   void;
void unzip_File(FILE *fp, FILE *fp2);



//	Funcao imprime_Frequencia: funcao responsavel por imprimir cada elemento e sua frequencia;
//	Entrada: (Head *)	 Ponteiro para um cabecalho contendo os elementos;
//	Saida:   void;
void imprime_Frequencia(Head *cab);



//	Funcao printa_Codigo: funcao responsavel por imprimir cada elemento e o seu codigo de Huffman;
//	Entrada: (Codigo **)  Ponteiro para um tabela de codigos, ( int ) tamanho da tabela;
//	Saida:   void;
void printa_Codigo(Codigo **ptr, int tam);



//	Funcao destroy_Codigo: funcao responsavel por destruir uma tabela de codigos;
//	Entrada: (Codigo **)   Ponteiro para um tabela de codigos, ( int ) tamanho da tabela;
//	Saida:   void;
void destroy_Codigo(Codigo **code, int tam);



//	Funcao decode_File:    funcao responsavel por decodificar o codigo de Huffman descompactado convertendo-o novamente em texto;
//	Entrada: (Codigo **)   Ponteiro para um tabela de codigos, (char *) codigo de Huffman descompactado, (FILE *) ponteiro para arquivo destino,
//			 ( int )	   tamanho da tabela;
//	Saida:   void;
void decode_File(Codigo **c, char *codigo, FILE *decodificacao, int tam);



//	Funcao percorre_arvore: funcao responsavel por percorrer a arvore retornando a frequencia do elemento representado pelo codigo;
//	Entrada: (Tree *)      Ponteiro raiz da arvore que sera percorrida, (char *) codigo do elemento;
//	Saida:   ( int )	   inteiro que representa a frequencia do elemento cujo codigo foi passado;
int percorre_arvore(Tree *ptr, char *cod);



//	Funcao create_CodNode: funcao responsavel por criar um No cujo codigo sera inserido;
//	Entrada: ( char )      elemento que devera ser inserido no espaco de memoria criado, (char *) codigo do elemento;
//	Saida:   (Codigo *)    ponteiro para um novo elemento da tabela;
Codigo *create_CodNode(char elem, char *c);

#endif