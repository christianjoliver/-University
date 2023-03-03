/*
	Autor: Luis Otavio Rigo Junior
	Objetivo: 
		Este arquivo destina-se a implementacao das estrategias de jogo dos agentes.
	
	Devem ser implementados os 4 prototipos:
		init_Player1 - executada uma unica vez e contem as funcoes de inicializacao da estrategia do jogador 1;
		run_Player1 - executado a cada passo do jogo e retorna uma string com a direcao de movimento do jogador 1;
		init_Player2 - executada uma unica vez e contem as funcoes de inicializacao da estrategia do jogador 2;
		run_Player2 - executado a cada passo do jogo e retorna uma string com a direcao de movimento do jogador 2.
	
	Funcoes que podem ser chamadas pelo jogador (agente):
		char *maze_VerAmbiente(char tipo[MAXLINE]);
			- Utilizada para verificar alguma informacao da celula. Ex.: id;
		bool maze_VerCaminho(const char *direcao);
			- Retorna se existe um caminho naquela direcao (verdadeiro ou falso).
		bool maze_VerMinotauro(const char *direcao);
			- Retorna se o minotauro estah naquela direcao (verdadeiro ou falso).
		float maze_CustoDoCaminho(const char *direcao);
			- Retorna o custo de executar um passo naquela direcao.
		float maze_HeuristicaDistEuclidiana(const char *direcao);
			- Retorna o a distancia heuclidiana da celula que estah naquela direcao ateh a saida.
	
	Constantes que podem ser usadas pelo jogador (agente):
		#define NUMCAMINHOS 4
		const char *id_Caminhos[NUMCAMINHOS] = {"norte", "sul", "oeste", "leste"};
		const char *id_Retornos[NUMCAMINHOS] = {"sul", "norte", "leste", "oeste"};
		typedef struct str_PosicaoPlano {
			int x,y;
		} tipo_PosicaoPlano;
*/


#include <stdio.h>
#include <stdlib.h>\
#include <conio.h>

// Estrutura Tree auxiliar da implementacao da busca


struct Tree{
	char me;
    Tree* n;
    Tree* s;
    Tree* l;
    Tree* o;
    Tree* p;
    
};

Tree* createTree(Tree *f, char m){
    Tree* ptr = (Tree*)calloc(1, sizeof(Tree));
    if(ptr){
    	ptr->me = m;
    	ptr->p = f;
    }
    return ptr;
}

Tree *createPath(Tree *Node){
	
	Node->n = createTree(Node, 'n');
	Node->s = createTree(Node, 's');
	Node->l = createTree(Node, 'l');
	Node->o = createTree(Node, 'o');
	
	return Node;
}


// *** 	FUNCOES DE INICIALIZACAO E EXECUCAO DO JOGADOR 1 ***
//	Implementacao da primeira estrategia de jogo.

Tree *ptr;
Tree *ptr2;
void init_Player1() {
	ptr = createTree(NULL, 'i');
	ptr = createPath(ptr);
}

const char *run_Player1() {
	
	const char *movimento;
	
	if(maze_VerCaminho("leste") == PAREDE || ptr->me == 'o'){
		
		free(ptr->l);
		ptr->l = NULL;
		
	}
	if(maze_VerCaminho("sul") == PAREDE || ptr->me == 'n'){
		
		free(ptr->s);
		ptr->s = NULL;
		
	}
	if(maze_VerCaminho("oeste") == PAREDE || ptr->me == 'l'){
		
		free(ptr->o);
		ptr->o = NULL;
	}
	if(maze_VerCaminho("norte") == PAREDE || ptr->me == 's'){
		
		free(ptr->n);
		ptr->n = NULL;	
	}
	
	if(ptr->l!=NULL){
		ptr = createPath(ptr->l);
		movimento = "leste";
	}
	
	else if(ptr->s!=NULL){
		ptr = createPath(ptr->s);
		movimento = "sul";
	}
	
	else if(ptr->o!=NULL){
		ptr = createPath(ptr->o);
		movimento = "oeste";
	}
	
	else if(ptr->n!=NULL){
		ptr = createPath(ptr->n);
		movimento = "norte";
	}
	
	
	else{
		
		Tree *aux = ptr;
		ptr = ptr->p;
		
		if(ptr->l == aux){
			ptr->l = NULL;
			movimento = "oeste";
			free(aux);
		}
		else if(ptr->s == aux){
			ptr->s = NULL;
			movimento = "norte";
			free(aux);
		}
		else if(ptr->o == aux){
			ptr->o = NULL;
			movimento = "leste";
			free(aux);
		}
		else if(ptr->n == aux){
			ptr->n = NULL;
			movimento = "sul";
			free(aux);
		}			
	}
		
	return movimento;
}



void init_Player2(){
	ptr2 = createTree(NULL, 'i');
	ptr2 = createPath(ptr2);
}

const char *run_Player2(){
	
	
	const char *movimento;
	
	if(maze_VerCaminho("norte") == PAREDE || ptr2->me == 's'){
		
		free(ptr2->n);
		ptr2->n = NULL;	
	}
	
	if(maze_VerCaminho("sul") == PAREDE || ptr2->me == 'n'){
		
		free(ptr2->s);
		ptr2->s = NULL;
		
	}
	if(maze_VerCaminho("oeste") == PAREDE || ptr2->me == 'l'){
		
		free(ptr2->o);
		ptr2->o = NULL;
	}
	if(maze_VerCaminho("leste") == PAREDE || ptr2->me == 'o'){
		
		free(ptr2->l);
		ptr2->l = NULL;
		
	}
	
	if(ptr2->n!=NULL){
		ptr2 = createPath(ptr2->n);
		movimento = "norte";
	}
	
	
	else if(ptr2->s!=NULL){
		ptr2 = createPath(ptr2->s);
		movimento = "sul";
	}
	
	else if(ptr2->o!=NULL){
		ptr2 = createPath(ptr2->o);
		movimento = "oeste";
	}
	
	else if(ptr2->l!=NULL){
		ptr2 = createPath(ptr2->l);
		movimento = "leste";
	}
	
	
	else{
		
		Tree *aux = ptr2;
		ptr2 = ptr2->p;
		
		if(ptr2->l == aux){
			ptr2->l = NULL;
			movimento = "oeste";
			free(aux);
		}
		else if(ptr2->s == aux){
			ptr2->s = NULL;
			movimento = "norte";
			free(aux);
		}
		else if(ptr2->o == aux){
			ptr2->o = NULL;
			movimento = "leste";
			free(aux);
		}
		else if(ptr2->n == aux){
			ptr2->n = NULL;
			movimento = "sul";
			free(aux);
		}			
	}
	
	
	
	return movimento;
	
}
