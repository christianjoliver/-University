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
#include <stdlib.h>
#include <vector>


// *** 	FUNCOES DE INICIALIZACAO E EXECUCAO DO JOGADOR 1 ***
//	Implementacao da primeira estrategia de jogo (Busca Gulosa). Realizada a partir da estrutura arvore;

struct Node{	
	Node *n;
	Node *s;
	Node *l;
	Node *o;
	Node *f;
	char me;
	float custo;
};


Node *createNode(Node *p, char m){
	
	Node *no = (Node *)calloc(1, sizeof(Node));
	if(no){
		no->me = m;
		no->f = p;
	}
	return no;
}

Node *createPath(Node *no){	
	no->n = createNode(no, 'n');
	no->s = createNode(no, 's');
	no->l = createNode(no, 'l');
	no->o = createNode(no, 'o');
	return no;
}


int menorCusto(float vet[], int j){
	
	// funcao auxiliar que retorna o menor contida num vetor;
	// a variavel menor foi calculada a partir da maior distancia Euclidiana,
	// de acordo a dimensao do mapa (60 x 35), passada no enunciado.
	int menor = 50000, aux;
	
	for(int i = 0; i < j; i++){
		
		if(vet[i]>-1 && vet[i] < menor){
			aux = i;
			menor = vet[i];
		}
	}
	return aux;
}

Node *ptr;

void init_Player1() {
	
	// Player 1 - decide em qual caminho seguir por meio da heuristica dada;
	// A cada bifurcacao encontrada decide a partir da menor distancia Euclidiana 
	// qual caminho seguir...
	ptr = createNode(NULL, 'i');
	ptr = createPath(ptr);
}



const char *run_Player1() {
	
	const char *movimento;
	int i = 4;
	float vet[4] = {-1, -1, -1, -1};
	
	if(maze_VerCaminho("leste") == PAREDE || !ptr->l || ptr->me == 'o' || maze_VerMinotauro("leste") == true){
		free(ptr->l);
		ptr->l = NULL;
		i--;
	}
	if(maze_VerCaminho("sul") == PAREDE || !ptr->s || ptr->me == 'n' || maze_VerMinotauro("sul") == true){
		free(ptr->s);
		ptr->s = NULL;
		i--;
	}
	if(maze_VerCaminho("oeste") == PAREDE || !ptr->o || ptr->me == 'l' || maze_VerMinotauro("oeste") == true){
		free(ptr->o);
		ptr->o = NULL;
		i--;
	}
	if(maze_VerCaminho("norte") == PAREDE || !ptr->n || ptr->me == 's' || maze_VerMinotauro("norte") == true){
		free(ptr->n);
		ptr->n = NULL;
		i--;
	}
	
	// início do bloco de utilizacao da heuristica
	if(i > 1){
		// caso onde ha uma bifurcacao o algoritmo analisa qual dos caminhos 
		// possui a menor distancia euclidiana e opta por ele
		
		if(ptr->l){
			ptr->l->custo = maze_HeuristicaDistEuclidiana("leste");
			vet[0] = ptr->l->custo;	
		}if(ptr->s){
			ptr->s->custo = maze_HeuristicaDistEuclidiana("sul");
			vet[1] = ptr->s->custo;
		}if(ptr->o){
			ptr->o->custo = maze_HeuristicaDistEuclidiana("oeste");
			vet[2] = ptr->o->custo;	
		}if(ptr->n){
			ptr->n->custo = maze_HeuristicaDistEuclidiana("norte");
			vet[3] = ptr->n->custo;
		}
		
		// escolha do movimento
		if(ptr->l && menorCusto(vet, 4) == 0){
			movimento = "leste";
			ptr = createPath(ptr->l);
		}	
		else if(ptr->s && menorCusto(vet, 4) == 1){
			movimento = "sul";
			ptr = createPath(ptr->s);	
		}
		else if(ptr->o && menorCusto(vet, 4) == 2){
			movimento = "oeste";
			ptr = createPath(ptr->o);	
		}
		else if(ptr->n && menorCusto(vet, 4) == 3){
			movimento = "norte";
			ptr = createPath(ptr->n);
		}	
	// fim do bloco de decisao pela heuristica	
	}
	
	else if(i!=0){
		// bloco de decisao onde ha somente uma opcao de caminho
		
		if(ptr->l != NULL){
			ptr = createPath(ptr->l);			
			movimento = "leste";
		}
		else if(ptr->s != NULL){
			ptr = createPath(ptr->s);
			movimento = "sul";
		}
		else if(ptr->o != NULL){
			ptr = createPath(ptr->o);
			movimento = "oeste";
		}
		else if(ptr->n!=NULL){
			ptr = createPath(ptr->n);
			movimento = "norte";
		}
	}
	
	else{
		// bloco de decisao para o caso onde nao ha caminhos possiveis
		// e se faz necessario retroceder.		
		Node *aux = ptr;
		ptr = ptr->f;
		
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


// *** 	FUNCOES DE INICIALIZACAO E EXECUCAO DO JOGADOR 2 ***
//	Implementacao da segunda estrategia de jogo (A*). Realizada a partir de uma matriz;

vector<string> pilha;
Node *ptr2;
int mat[35][60];
int linha = 0;
int coluna = 0;
float vetx[4][2];

void zeraMat(){
	for(int i = 0; i<35; i++){
			for(int j = 0; j<60; j++)
				mat[i][j] = 0;
	}
}

void init_Player2(){
	// Player 2 - decide em qual caminho seguir por meio da heuristica somada com o custo ate o caminho atual;
	// A cada bifurcacao encontrada decide a partir da menor soma
	// qual caminho seguir...
	zeraMat();	
}

const char *run_Player2(){
	
	const char *movimento;	
	float vet[4] = {-1, -1, -1, -1};
	int u = 0;
	
	// 1 - verifica a existencia de caminhos possiveis calculando o custo total do caminho
	if (maze_VerCaminho("leste") == CAMINHO && mat[linha][coluna+1] == 0 && maze_VerMinotauro("leste") == false) {
		vet[0] = maze_HeuristicaDistEuclidiana("leste") + maze_CustoDoCaminho("leste");
		u++;
	}
	if (maze_VerCaminho("sul") == CAMINHO && mat[linha+1][coluna] == 0 && maze_VerMinotauro("sul") == false) {
		vet[1]= maze_HeuristicaDistEuclidiana("sul") + maze_CustoDoCaminho("sul");
		u++;
	}
	if (maze_VerCaminho("oeste") == CAMINHO && mat[linha][coluna-1] == 0 && maze_VerMinotauro("oeste") == false){
		vet[2] = maze_HeuristicaDistEuclidiana("oeste") + maze_CustoDoCaminho("oeste");
		u++;
	}
	if (maze_VerCaminho("norte") == CAMINHO && mat[linha-1][coluna] == 0 && maze_VerMinotauro("norte") == false){
		vet[3] = maze_HeuristicaDistEuclidiana("norte") + maze_CustoDoCaminho("norte");
		u++;
	}
	//final do primeiro bloco
	
	// 2 - avalia qual foi o menor custo entre os caminhos possiveis
	if (vet[0]>-1 && menorCusto(vet, 4)==0) {
		movimento = "leste";
		pilha.push_back("leste");
		mat[linha][coluna+1] = 1;
		coluna++;
	}
	else if (vet[1]>-1 && menorCusto(vet, 4)==1) {
		movimento = "sul";
		pilha.push_back("sul");
		mat[linha+1][coluna] = 1;
		linha++;
	}
	else if (vet[2]>-1 && menorCusto(vet, 4)==2){
		movimento = "oeste";
		pilha.push_back("oeste");
		mat[linha][coluna-1] = 1;
		coluna--;
	}
	else if (vet[3]>-1 && menorCusto(vet, 4)==3){	
		movimento = "norte";
		pilha.push_back("norte");
		mat[linha-1][coluna] = 1;
		linha--;
	}
	// final segundo bloco
	
	// 3 - retrocede o player caso nao haja caminhos possiveis
	else{
		
		int top = pilha.size()-1;
		
		if(pilha[top] == "leste"){
			movimento = "oeste";
			coluna--;
		}	
		else if(pilha[top] == "sul"){
			movimento = "norte";
			linha--;
		}	
		else if(pilha[top] == "oeste"){
			movimento = "leste";
			coluna++;
		}	
		else if(pilha[top] == "norte"){
			movimento = "sul";
			linha++;
		}
		pilha.pop_back();
	}
	return movimento;
}	
