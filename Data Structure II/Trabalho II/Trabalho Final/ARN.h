/*
	UFES/CEUNES
	Professora: Luciana Lee;
	Disciplina: Estrutura de Dados II;
	Avaliacao 3: Arvore Rubro-Negra;
	Equipe: Christian Jonas Oliveira e Joao Victor do Rozario Recla.
*/

#ifndef ARN_H
#define ARN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct artigo{
	
	int id;
	int ano;
	char autor[200];
	char titulo[200];
	char revista[200];
	char DOI[20];
	char palavraChave[200];
	
}artigo;


//	Estrutura de um elemento de uma ARN:
//	key: tipo (artigo *) ponteiro para um elemento do tipo artigo;
//	f: (struct ARN *) ponteiro para um elemento da ARN pai do no atual;
//	left: (struct ARN *) ponteiro para um elemento da ARN menor que o elemento pai;
//	right: (struct ARN *) ponteiro para um elemento da ARN maior que o elemento pai;
//	color: ( int ) inteiro que representa a cor de um no da ARN, 1 para Rubro e 0 para Negro;

typedef struct ARN{
	
	artigo *key;
	struct ARN *f;
	struct ARN *left;
	struct ARN *right;
	int color;
	
}ARN;


// No Sentinela;
ARN *Sentinela;


//	Funcao create_ARN: aloca espaco de memoria para um novo no da ARN, atribuindo a chave;
//	Entrada: (artigo *) ponteiro para um artigo, que eh a chave a ser atribuida;
//	Saida: (ARN *) ponteiro para no ARN;
ARN *create_ARN(artigo *element);


//	Funcao search_Artigo: busca na ARN uma chave atraves do id do artigo;
//	Entrada: (ARN *) ponteiro para ARN, ( int ) chave a ser buscada;
//	Saida: (ARN *) ponteiro para no que contem a chave buscada;
ARN *search_Artigo(ARN *root, int idn);


//	Funcao create_Sentinela: aloca espaco de memoria para um no Sentinela;
//	Entrada: void
//	Saida: (ARN *) ponteiro para no ARN Sentinela;
ARN *create_Sentinela();


//	Funcao insert_ARN: funcao que insere um novo elemento na ARN;
//	Entrada: (ARN **) endereco do ponteiro para ARN em que o no sera inserido, (ARN **) endereco do ponteiro para novo no a ser inserido;
//	Saida: ( int ) 1 para elemento inserido e 0 caso contrario;
int insert_ARN(ARN **root, ARN **node);


//	Funcao insert_Fixup: funcao auxiliar da insert_ARN, responsavel por reorganizar os nos, realizando os devidos reapontamentos e trocas de cor;
//	Entrada: (ARN **) enredero do ponteiro para ARN em que a reoganizacao devera acontecer, (ARN **) endereco de ponteiro para o no critico;
//	Saida: void;
void insert_Fixup(ARN **root, ARN **node);


///	Funcao left_rotation: funcao auxiliar que realiza as rotacoes a esquerda.
//	Entrada: (ARN **) endereco do ponteiro para um elemento da ARN, (ARN **) endereco do ponteiro para o no critico; 
//	Saida: void
void left_Rotation(ARN **root, ARN **node);


///	Funcao right_rotation: funcao auxiliar que realiza as rotacoes a direita.
//	Entrada: (ARN **) endereco do ponteiro para um elemento da ARN, (ARN **) endereco do ponteiro para o no critico; 
//	Saida: void;
void right_Rotation(ARN **root, ARN **node);


//	Funcao print_ARN: funcao que imprime todos os elementos da ARN;
//	Entrada: (ARN *) raiz da arvore a ser impressa;
//	Saida: void;
void print_ARN(ARN *root, int level);


//	Funcao transfer_NodeARN: funcao auxiliar da remove_ARN responsavel por realizar a troca dos pais do n1 para o n2;
//	Entrada: (ARN **) endereco do ponteiro da ARN, (ARN **) enderecos do ponteiros de dois nos da arvore;
//	Saida: void;
void transfer_NodeARN(ARN **root, ARN **n1, ARN **n2);


//	Funcao moreleft_ARN: funcao auxiliar da remove_ARN responsavel por buscar o elemento que esta mais a esquerda da ARN;
//	Entrada: (ARN *) ponteiro para a ARN;
//	Saida: 	 (ARN *) ponteiro para o elemento mais a esquerda da ARN;
ARN *moreleft_ARN(ARN *node);


//	Funcao remove_Fixup: funcao auxiliar da remove_ARN, responsavel por reorganizar os nos, realizando os devidos reapontamentos e trocas de cor;
//	Entrada: (ARN **) enredero do ponteiro para ARN em que a reoganizacao devera acontecer, (ARN **) endereco de ponteiro para o no critico;
//	Saida: void;
void remove_Fixup(ARN **root, ARN **node);


//	Funcao remove_ARN: funcao auxiliar da remove_ARN responsavel por remover um elemento da ARN;
//	Entrada: (ARN **) endereco do ponteiro para a ARN que contem o elemento a ser removido, (ARN **) endereco do ponteiro para o no a ser removido;
//	Saida: void;
void remove_ARN(ARN **root, ARN **node);


//	Funcao compare_Artigo: funcao responsavel por comparar as chaves (id) de dois artigos dados;
//	Entrada: (artigo *) ponteiro para dois artigos a serem comparados;
//	Saida: ( int ) 1 caso o primeiro seja maior que o segundo, -1 caso seja menor e 0 caso sejam iguais;
int compare_Artigo(artigo *a1, artigo *a2);


//	Funcao destroy_ARN: funcao responsavel por destruir toda a ARN;
//	Entrada: (ARN **) endereco de ponteiro para ARN;
//	Saida: void
void destroy_ARN(ARN **root);

#endif
