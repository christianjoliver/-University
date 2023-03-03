/*
	UFES/CEUNES
	Professora: Luciana Lee;
	Disciplina: Estrutura de Dados II;
	Avaliacao 3: Arvore Rubro-Negra;
	Equipe: Christian Jonas Oliveira e Joao Victor do Rozario Recla.
*/

#include "ARN.c"



artigo *putInformation_artigo(){
	
	// alocacao de um espaco de memoria para um novo artigo a ser inserido;
	artigo *newArtigo = (artigo *)malloc(sizeof(artigo));
	char a[200];
	
	
	// verificacao se a alocacao foi bem sucedida e insercao dos elementos na estrutura;
	if(newArtigo){
		int len;
		
		printf("\n\t Digite as informacoes do artigo: ");
		
		printf("\n\t ID: ");
		scanf("%d", &newArtigo->id);
		
		printf("\n\t Ano de publicacao: ");
		scanf("%d", &newArtigo->ano);	
		
		printf("\n\t Autor: ");
		getchar();
		fgets(a, 200, stdin);
		len = strlen(a);
		a[--len] = 0;
		strcpy(newArtigo->autor, a);
		
		printf("\n\t Titulo: ");
		fgets(a, 200, stdin);
		len = strlen(a);
		a[--len] = 0;
		strcpy(newArtigo->titulo, a);
		
		printf("\n\t Revista: ");
		fgets(a, 200, stdin);
		len = strlen(a);
		a[--len] = 0;
		strcpy(newArtigo->revista, a);
		
		printf("\n\t DOI: ");
		fgets(a, 200, stdin);
		len = strlen(a);
		a[--len] = 0;
		strcpy(newArtigo->DOI, a);
		
		printf("\n\t Palavra Chave: ");
		fgets(a, 200, stdin);
		len = strlen(a);
		a[--len] = 0;
		strcpy(newArtigo->palavraChave, a);
	}
	

	return newArtigo;
}



void print_artigo(artigo *art){

	printf("\n");
	printf("\n\t ID: %d", art->id);
	printf("\n\t Ano: %d", art->ano);
	printf("\n\t Autor: %s", art->autor);
	printf("\n\t Titulo: %s", art->revista);
	printf("\n\t Revista: %s", art->revista);
	printf("\n\t DOI: %s", art->DOI);
	printf("\n\t Palavra Chave: %s", art->palavraChave);
	printf("\n");
	
}



void print_menu(){
	int i;
	printf("\n");
	printf("\n");
	printf("\t ");
	for (i = 0; i<40; i++) printf("-");
	printf("\n\t | 1 - Inserir um novo Elemento na ARN\t|");
	printf("\n\t | 2 - Remover um Elemento na ARN\t|");
	printf("\n\t | 3 - Buscar um Elemento na ARN\t|");
	printf("\n\t | 4 - Imprimir ARN\t\t\t|");
	printf("\n\t | 5 - Sair AVL\t\t\t\t|");
	printf("\n");
	printf("\t ");
	for (i = 0; i<40; i++) printf("-");

}


int main(){
	
	int op, aux, i;
	Sentinela = create_Sentinela();
	ARN *root = Sentinela, *node;
	artigo *art;
	
	
	while(1){
		
		print_menu();
		printf("\n\t Digite a operacao desejada: ");
		scanf("%d", &op);
		
		
		switch(op){
	
			case 1:
				
				art = putInformation_artigo();
				node = create_ARN(art);
				
				if(art && node && insert_ARN(&root, &node)){
					
					print_artigo(art);
					printf("\n\t Elemento inserido com sucesso!");
				}
				
				else{
					
					free(art);
					free(node);
					printf("\n\t Nao foi possivel inserir o elemento ou a chave ja existe.\n");
					
				}
				
				break;
				
			case 2:
				printf("\n\n\n\n\n");
				print_ARN(root, 1);
				printf("\n\n\n\n\n");
				
				printf("\n\t Digite a chave que se deseja remover: ");
				scanf("%d", &aux);
				
				node = search_Artigo(root, aux);
				
				if(node!=Sentinela){
					print_artigo(node->key);	
					remove_ARN(&root, &node);
					free(node->key);
					free(node);
				}
				
				else
					printf("\n\t Elemento nao encontrado.");
				
				break;
				
			case 3:
				
				printf("\n\t Digite a chave que se deseja buscar: ");
				scanf("%d", &aux);
				node = search_Artigo(root, aux);
				
				if(node!=Sentinela){
					
					print_artigo(node->key);
				}
				
				else
					printf("\n\t Elemento nao encontrado.");
				
				break;
				
			case 4:
				printf("\n\n\n\n\n");
				print_ARN(root, 1);
				printf("\n\n\n\n\n");
				
				break;
				
			case 5:
				
				destroy_ARN(&root);
				free(Sentinela);
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
