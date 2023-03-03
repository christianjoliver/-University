/*
	UFES/CEUNES
	Professora: Luciana Lee;
	Disciplina: Estrutura de Dados II;
	Avaliação 2: Arvore AVL para tipos Genericos de dados;
	Equipe: Christian Jonas Oliveira e Joao Victor do Rozario Recla.
*/

#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//	Estrutura de um elemento de uma AVL Generica:
//	key: tipo (void *), para armazenar dado Genérico;
//	left: tipo (struct AVL *), ponteiro para um elemento da AVL menor que o elemento pai;
//	right: tipo (struct AVL *), ponteiro para um elemento da AVL maior que o elemento pai;
typedef struct AVL{
    void *key;
    int balance;
    struct AVL *left, *right;   
}AVL;


//	Funcao create_AVL: aloca espaco para um novo elemento da AVL e realiza o apontamento do dado generico 'element' para o campo key.
//	Entrada: (void *) ponteiro para o dado generico;
//	Saida: 	 (AVL *) ponteiro para o novo elemento da AVL; 
AVL *create_AVL(void *element);


//	Funcao right_rotation: realiza as rotacoes a direita.
//	Entrada: (AVL *) ponteiro para um elemento da AVL, (int *) identificador de crescimento;
//	Saida:	 (AVL *) ponteiro para o elemento rotacionado;
AVL *right_rotation(AVL *node, int *h);


//	Funcao left_rotation: realiza as rotacoes a esquerda.
//	Entrada: (AVL *) ponteiro para um elemento da AVL, (int *) identificador de crescimento;
//	Saida: 	 (AVL *) ponteiro para o elemento rotacionado;
AVL *left_rotation(AVL *node, int *h);


//	Funcao insert_AVL: insere um novo elemento, com dado generico, na AVL.
//	Entrada: (AVL *) ponteiro para a AVL, (void *) elemento generico a ser inserido, 
//			 (int *) identificador de crescimento, funcao que compara as chaves;
//	Saida: 	 (AVL *) ponteiro pra a AVL com o novo elemento;
AVL *insert_AVL(AVL *node, void *element, int *h, int (*compare) (void *, void *));


//	Funcao search_AVL: busca um elemento, com dado generico, na AVL.
//	Entrada: (AVL *) ponteiro para a AVL, (void *) elemento generico a ser buscado, funcao que compara as chaves;
//	Saida: 	 (AVL *) ponteiro para o elemento da AVL caso seja encontrado, ou NULL;
AVL *search_AVL(AVL *node, void *element, int (*compare) (void *, void *));


//	Funcao height_AVL: calcula a altura de um elemento da AVL. 
//	Entrada: (AVL *) ponteiro para a AVL;
//	Saida: 	 (int) altura da AVL;
int height_AVL(AVL *node);


//	Funcao weight_AVL: calcula o peso de um elemento da AVL.
//	Entrada: (AVL *) ponteiro para a AVL;
//	Saida: 	 (int) peso da AVL;
int weight_AVL(AVL *node);


//	Funcao moreleft_AVL: busca o elemento que esta mais a esquerda da AVL.
//	Entrada: (AVL *) ponteiro para a AVL;
//	Saida: 	 (AVL *) ponteiro para o elemento mais a esquerda da AVL;
AVL *moreleft_AVL(AVL *node);


//	Funcao remove_AVL: remove um elemento, com dado generico, da AVL.
//	Entrada: (AVL *) ponteiro para AVL, (void *) elemento generico a ser buscado, funcao que compara as chaves;
//	Saida: 	 (AVL *) ponteiro pra a AVL sem o elemento, caso seja encontrado/removido;
AVL *remove_AVL(AVL *node, void *element, int (compare) (void *, void *));


//	Funcao print_AVL: printa todos os elementos da AVL.
//	Entrada: (AVL *) ponteiro para a AVL, funcao que imprime a chave;
//	Saida: void; 
void print_AVL(AVL *node, void (*print_node) (void *), int level);


void destroy_AVL(AVL *node, void (*destroy_node)(void *));

#endif
