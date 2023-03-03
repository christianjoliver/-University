#include "AVL.c"


//	Estrutura de um elemento de um Comanda;
//	Mesa: tipo long int, armazena um inteiro onde sera guardado o numero da mesa de um cliente;
//	Nome: tipo (char *), armazena uma cadeia de caracteres onde sera guardado o nome de um cliente;
//	Gasto: tipo float, armazena um decimal onde sera guardado o gasto de um cliente;
typedef struct{
    int Mesa;
    int Ordem_de_chegada;
    char *Nome;
    float Gasto;
}Comanda;



//	Funcao compare_comanda: compara a chave de duas estruturas do tipo void (futuramente convertida em Comanda).
//	Entrada: dois ponteiros do tipo (void *);
//	Saida: -1 caso o a1 seja igual a a2, 1 caso seja maior e 0 caso seja menor;
int compare_comanda(void *a1, void *a2){
	
	Comanda *p1 = (Comanda *) a1;
	Comanda *p2 = (Comanda *) a2;
	
	if(p1->Ordem_de_chegada == p2->Ordem_de_chegada) return -1;
	else if(p1->Ordem_de_chegada > p2->Ordem_de_chegada) return 1;
	else return 0;
}



void print_order(void *cm){	
	Comanda *CM = (Comanda *)cm;
	printf("%d\n", CM->Ordem_de_chegada);
}


void print_comanda(Comanda *cm){
	
	printf("\n");
	printf("\n\t Nome do Cliente: %s", cm->Nome);
	printf("\n\t Ordem de Chegada: %d", cm->Ordem_de_chegada);
	printf("\n\t Mesa: %d", cm->Mesa);
	printf("\n\t Gasto do cliente: R$ %.2f", cm->Gasto);
	printf("\n");
	
}


Comanda *create_comanda(int m, int o, char *n, float g){
	
	Comanda *new_comanda = (Comanda *)malloc(sizeof(Comanda));
	
	if(new_comanda){
		new_comanda->Mesa = m;
		new_comanda->Ordem_de_chegada = o;
		new_comanda->Nome = n;
		new_comanda->Gasto = g;
	}
	return new_comanda;
}

void print_menu(){
	int i;
	printf("\n");
	printf("\n");
	printf("\t ");
	for (i = 0; i<40; i++) printf("-");
	printf("\n\t | 1 - Inserir um novo Elemento na AVL\t|");
	printf("\n\t | 2 - Remover um Elemento na AVL\t|");
	printf("\n\t | 3 - Buscar um Elemento na AVL\t|");
	printf("\n\t | 4 - Imprimir AVL\t\t\t|");
	printf("\n\t | 5 - Sair AVL\t\t\t\t|");
	printf("\n");
	printf("\t ");
	for (i = 0; i<40; i++) printf("-");

}


void destroy_comanda(void *CM){
	
	Comanda *cm = (Comanda *)CM;
	free(cm->Nome);
	free(cm);
}

Comanda *putInformation_comanda(){
	
	int m, o;
	char *n =(char *)malloc(50*sizeof(char));
	
	float g;
	
	printf("\n\t Digite os dados do cliente:");
	
	printf("\n\t Nome: ");
	
	getchar();
	fgets(n, 50, stdin);
	
	int len = strlen(n);
	n[--len] = 0;
	
	printf("\n\t Numero da Mesa: ");
	scanf("%d", &m);
	printf("\n\t Ordem de Chegada: ");
	scanf("%d", &o);
	printf("\n\t Gasto: ");
	scanf("%f", &g);
	
	return create_comanda(m, o, n, g);
}


int main(){
	
	
	int op, h = 0, aux;
	Comanda *cm;
	char *k = (char *)malloc(sizeof(char));
	*k = 'k';
	AVL *tree=NULL, *avl = NULL;
	
	
	while(1){
		print_menu();
		printf("\n\t Digite a operacao desejada: ");
		scanf("%d", &op);
		
		
		switch(op){
	
			case 1:
				
				cm = putInformation_comanda();
				
				if(cm && !search_AVL(tree, cm, compare_comanda)){
					tree = insert_AVL(tree, cm, &h, compare_comanda);
					print_comanda(cm);
				}
				
				else{
					
					free(cm->Nome);
					free(cm);
					printf("\n\t Nao foi possivel inserir o elemento ou a chave ja existe.\n");
					
				}
				
				break;
				
			case 2:
				printf("\n\n\n\n\n");
				print_AVL(tree, print_order, 1);
				printf("\n\n\n\n\n");
				
				printf("\n\t Digite a chave que se deseja remover: ");
				scanf("%d", &aux);
						
				cm = create_comanda(-999, aux, k, 0);
				
				avl = search_AVL(tree, cm, compare_comanda);
				
				if(avl){
					
					free(cm);
					cm = avl->key;
					tree = remove_AVL(tree, avl->key, compare_comanda);
					print_comanda(cm);	
					
				}
				else
					printf("\n\t Elemento nao encontrado.");
				
				free(cm);
				
				break;
				
			case 3:
				
				printf("\n\t Digite a chave que se deseja buscar: ");
				scanf("%d", &aux);
				
				cm = create_comanda(-999, aux, k, 0);
				
				avl = search_AVL(tree, cm, compare_comanda);
				
				if(avl){
					
					print_comanda(avl->key);
				}
				else
					printf("\n\t Elemento nao encontrado.");
				
				avl = NULL;
				free(cm);
				
				break;
				
			case 4:
				printf("\n\n\n\n\n");
				print_AVL(tree, print_order, 1);
				printf("\n\n\n\n\n");
				
				break;
				
			case 5:
				
				// lembrar de limpar os ponteiro//;;;;;;
				destroy_AVL(tree, destroy_comanda);
				free(k);
				exit(0);
				break;
				
			default:
				break;
		}
		
		printf("\n\t ");
		system("pause");
		system("cls");
	}
	return 0;
}


