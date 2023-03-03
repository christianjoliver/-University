/*
	UFES/CEUNES
	Professora: Luciana Lee;
	Disciplina: Estrutura de Dados II;
	Avaliação 2: Arvore AVL para tipos Genericos de dados;
	Equipe: Christian Jonas Oliveira e Joao Victor do Rozario Recla.
*/


#include "AVL.h"


//	Estrutura de um elemento de um Comanda:
//	Mesa: tipo (int), para armazenar o numero da mesa de um cliente;
//	Nome: tipo (char *), ponteiro para uma cadeia de caracteres com o nome de um cliente;
//	Ordem_de_chegada: tipo (int), para armazenar a ordem de chagada - (Chave da estrutura);
//	Gasto: tipo (float), para armazenar o gasto de um cliente;
typedef struct{
    int Mesa;
    char *Nome;
     int Ordem_de_chegada;
    float Gasto;
}Comanda;


//	Funcao create_comanda: aloca espaco para um novo elemento, do tipo Comanda, e insere os dados.
//	Entrada: (int) numero da mesa, (int) ordem de chegada, (char *) ponteiro para uma string, (float) gasto;
//	Saida: (Comanda *) ponteiro para o novo elemento, do tipo Comanda;
Comanda *create_comanda(int m, int o, char *n, float g){
	
	// alocacao de espaco de memoria para o novo elemento
	Comanda *new_comanda = (Comanda *)malloc(sizeof(Comanda));
	
	// verifica se a alocacao foi bem sucedida
	if(new_comanda){
		
		// atribuicao de valores aos seus devidos campos
		new_comanda->Mesa = m;
		new_comanda->Ordem_de_chegada = o;
		new_comanda->Nome = n;
		new_comanda->Gasto = g;
	}
	
	return new_comanda;
}


//	Funcao putInformation_comanda: realiza uma coleta de dados e cria uma nova Comanda.
//	Entrada: void;
//	Saida: (Comanda *) ponteiro para um elemento preenchido, do tipo Comanda;
Comanda *putInformation_comanda(){
	
	int m, o;
	float g;
	char *n = (char *)malloc(50*sizeof(char));
	
	// nome
	printf("\n\t Digite os dados do cliente:");	
	printf("\n\t Nome: ");
	getchar(); fgets(n, 50, stdin);
	
	// mesa
	printf("\n\t Num da Mesa: "); 
	scanf("%d", &m);
	
	// ordem de chegada
	printf("\n\t Ordem de Chegada: ");
	scanf("%d", &o);
	
	// gasto
	printf("\n\t Gasto: ");
	scanf("%f", &g);
	
	// remove o "ENTER" do nome
	int len = strlen(n);
	n[--len] = 0;
	
	// retorno da Comanda com os dados inseridos
	return create_comanda(m, o, n, g);
}


//	Funcao compare_comanda: compara a chave de duas estruturas genericas - (Comanda).
//	Entrada: (void *) ponteiro para 2 chaves genericas;
//	Saida: (int) -1 se as chaves forem iguais, 1 caso cm1 seja maior que cm2, 0 caso cm1 seja menor que cm2;
int compare_comanda(void *cm1, void *cm2){
	
	// conversao das chaves genericas para o tipo "Comanda"
	Comanda *Cm1 = (Comanda *)cm1;
	Comanda *Cm2 = (Comanda *)cm2;
	
	// comparacao das chaves
	if(Cm1->Ordem_de_chegada == Cm2->Ordem_de_chegada) return -1;
	else if(Cm1->Ordem_de_chegada > Cm2->Ordem_de_chegada) return 1;
	else return 0;
}


//	Funcao print_order: printa a chave de uma estrutura generica - (Comanda).
//	Entrada: (void *) ponteiro para uma chave generica;
//	Saida: void;
void print_order(void *cm){	

	// conversao da chave generica para o tipo "Comanda" e print da chave(Ordem_de_chegada)
	Comanda *Cm = (Comanda *)cm;
	printf("%d\n", Cm->Ordem_de_chegada);
}


//	Funcao print_comando: printa todos os dados de  uma Comanda.
//	Entrada: (Comanda *) ponteiro para um elemento do tipo Comando;
//	Saida: void;
void print_comanda(Comanda *cm){
	
	printf("\n");
	printf("\n\t Mesa: %d", cm->Mesa);
	printf("\n\t Nome do Cliente: %s", cm->Nome);
	printf("\n\t Ordem de Chegada: %d", cm->Ordem_de_chegada);
	printf("\n\t Gasto do cliente: R$ %.2f", cm->Gasto);
	printf("\n");	
}


//	Funcao destroy_comanda: deleta um elemento de uma estrutura generica - (Comanda).
//	Entrada: (void *) ponteiro para uma chave generica;
//	Saida: void;
void destroy_comanda(void *cm){
	
	// conversao da chave generica para o tipo "Comanda" e delecao dos dados
	Comanda *Cm = (Comanda *)cm;
	free(Cm->Nome);
	free(Cm);
}


//	Funcao print_menu: imprime o Menu na tela.
//	Entrada: void;
//	Saida: void;
void print_menu(){
	int i;
	
	printf("\n\n\t ");
	for (i = 0; i<40; i++) printf("-");
	printf("\n\t | 1 - Inserir um novo elemento na AVL\t|");
	printf("\n\t | 2 - Remover um elemento da AVL\t|");
	printf("\n\t | 3 - Buscar um elemento na AVL\t|");
	printf("\n\t | 4 - Imprimir a AVL\t\t\t|");
	printf("\n\t | 5 - Sair do programa\t\t\t|");
	printf("\n\t ");
	for (i = 0; i<40; i++) printf("-");
}

// Main
int main(){
	
	Comanda *cm;	
	AVL *tree = NULL, *node = NULL;
	
	int op, chave, h = 0;
	char *k = (char *)malloc(sizeof(char));
	*k = 'k';
		
	while(1){
		
		// chamada do menu e escolha da operacao
		print_menu();
		printf("\n\t Digite a operacao desejada: ");
		scanf("%d", &op);
		
		switch(op){	
		
			/* operacao: inserir novo elemento na AVL */
			case 1:		
			
				// criacao de um novo elemento do tipo Comanda
				cm = putInformation_comanda();
				
				// tratamento do caso onde o elemento foi criado e a chave inserida nao existe na AVL
				if(cm && !search_AVL(tree, cm, compare_comanda)){
					
					// insercao do elemento na AVL
					tree = insert_AVL(tree, cm, &h, compare_comanda);
					print_comanda(cm);																		// printa os dados do elemento inserido;
				}
				
				// tratamento do caso onde o elemento nao foi criado ou a chave inserida ja existe na AVL
				else{
					
					// libera o espaco de memoria alocado para o elemento do tipo Comanda
					destroy_comanda(cm);
					printf("\n\t Nao foi possivel inserir o elemento ou a Chave ja existe.");	
				}
				
				break;
			
			/* operacao: remover um elemento da AVL */	
			case 2:
				
				// chamada da funcao para imprimir a AVL
				printf("\n\n\n\n\n");
				print_AVL(tree, print_order, 1);
				printf("\n\n\n\n\n");
				
				// escolha da chave a ser deletada
				printf("\n\t Digite a chave que se deseja remover: ");
				scanf("%d", &chave);
				
				// busca na AVL pelo node que contem o elemento, do tipo Comanda, com a chave
				cm = create_comanda(-999, chave, k, 0);														// Comanda temporária, comanda de busca; 
				node = search_AVL(tree, cm, compare_comanda);
				
				// tratamento do caso onde o node com o elemento que contem a chave foi encontrado
				if(node){
					
					free(cm);																				// libera o espaco alocado para a Comanda temporaria;
					cm = node->key;																			// segura o elemento, do tipo Comanda, com a chave a ser deletada;
					tree = remove_AVL(tree, node->key, compare_comanda);									// libera o ponteiro do node para o elemento com a chave e deleta esse node da AVL;    
					print_comanda(cm);																		// printa os dados do elemento com a chave;
					free(cm->Nome);																	 		// libera o espaco de memoria para do campo Nome(char *);
				}
				else
					printf("\n\t Elemento nao encontrado.");
					
				free(cm);																					// libera o espaco alocado para cm;
				break;
			
			/* operacao: buscar um elemento na AVL */	
			case 3:
				
				// escolha da chave a ser buscada
				printf("\n\t Digite a chave que se deseja buscar: ");
				scanf("%d", &chave);
				
				// busca na AVL pelo node que contem o elemento, do tipo Comanda, com a chave
				cm = create_comanda(-999, chave, k, 0);														// Comanda temporária, comanda de busca;
				node = search_AVL(tree, cm, compare_comanda);
				
				// tratamento do caso onde o node com o elemento que contem a chave foi encontrado
				if(node){
					
					// chamada para printar os dados do elemento, do tipo Comanda
					print_comanda(node->key);
				}
				else
					printf("\n\t Elemento nao encontrado.");

				free(cm);																					// libera o espaco alocado para cm;
				break;
			
			/* operacao: imprimir a AVL */	
			case 4:
				
				// chamada da funcao para imprimir a AVL
				printf("\n\n\n\n\n");
				print_AVL(tree, print_order, 1);
				printf("\n\n\n\n\n");			
				break;
			
			/* operacao: sair do programa */	
			case 5:
				
				// chamada da funcao para deletar a AVL e os elementos do tipo Comanda
				destroy_AVL(tree, destroy_comanda);
				free(k);
				exit(0);
				break;
				
			default:
				break;
		}
		
		printf("\n\t ");
		printf("Digite enter para continuar...");
		getchar();
		getchar();
		system("clear");
	}
	
	return 0;
}


