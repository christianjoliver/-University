/*
	UFES/CEUNES
	Professora: Luciana Lee;
	Disciplina: Estrutura de Dados II;
	Avaliacao 3: Arvore Rubro-Negra;
	Equipe: Christian Jonas Oliveira e Joao Victor do Rozario Recla.
*/


#include "ARN.h"



ARN *create_Sentinela(){
	
	ARN *newNode = (ARN *)malloc(sizeof(ARN));
	
	if(newNode){
		
		newNode->key = NULL;
		newNode->f = NULL;
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->color = 0;
		
	}
	return newNode;
}



ARN *create_ARN(artigo *element){
	
	ARN *newNode = (ARN *)malloc(sizeof(ARN));
	
	if(newNode){
		
		newNode->key = element;
		newNode->f = Sentinela;
		newNode->left = Sentinela;
		newNode->right = Sentinela;
		newNode->color = 1;
		
	}
	return newNode;
}



void left_Rotation(ARN **root, ARN **node){
	
	ARN *aux;
	
	aux = (*node)->right;
	
	(*node)->right = aux->left;
	
	if(aux->left!=Sentinela){
		aux->left->f = *node;
	}
	
	aux->f = (*node)->f;
	
	if((*node)->f==Sentinela) *root = aux;
	
	else{
		
		// caso o no que sofreu rotacao seja filho a esquerda do no pai, entao aux sera o novo filho a esquerda;
		if((*node) == (*node)->f->left) (*node)->f->left = aux;
		
		// caso o no que sofreu rotacao seja filho a direita do no pai, entao aux sera o novo filho a direita;
		else (*node)->f->right = aux;
	}
	aux->left = (*node);
	(*node)->f = aux;
}



void right_Rotation(ARN **root, ARN **node){
	
	ARN *aux;
	
	aux = (*node)->left;
	
	(*node)->left = aux->right;
	
	if(aux->right!=Sentinela){
		aux->right->f = (*node);
	}
	
	aux->f = (*node)->f;
	
	if((*node)->f==Sentinela) *root = aux;
	
	else{
		
		// caso o no que sofreu rotacao seja filho a esquerda do no pai, entao aux sera o novo filho a esquerda;
		if((*node) == (*node)->f->left) (*node)->f->left = aux;
		
		// caso o no que sofreu rotacao seja filho a direita do no pai, entao aux sera o novo filho a direita;
		else (*node)->f->right = aux;
	}
	aux->right = (*node);
	(*node)->f = aux;
}



int compare_Artigo(artigo *a1,  artigo *a2){
	
	if(a1->id > a2->id)	return 1;
	
	else if(a1->id < a2->id) return -1;
	
	return 0;
}



void insert_Fixup(ARN **root, ARN **node){
	
	ARN *aux1, *aux2, *aux3;
	
	while((*node)->f->color==1){
			
		aux1 = (*node)->f;
		
		aux2 = aux1->f;
		
		if(aux1 == aux2->left){
			
			aux3 = aux2->right;	
			
			// caso em que o irmao do pai do no a ser inserido eh rubro, violando a propriedade de
			// dois rubros seguidos.
			if(aux3->color==1){
				aux1->color = 0;
				aux3->color = 0;
				aux2->color = 1;
				(*node) = aux2;
			}
			
			else{
				
				// caso onde o irmao do pai do no a ser inserido eh negro e o no a ser inserido
				// eh filho a direita de seu pai;
				if((*node) == aux1->right){
					(*node) = aux1;
					left_Rotation(root, node);
				}
				
				// caso onde o irmao do pai do no a ser inserido eh negro e o no a ser inserido
				// eh filho a esquerda de seu pai;
				(*node)->f->color = 0;
				aux2->color = 1;
				right_Rotation(root, &aux2);
			}
		}
		
		
		//	analogo ao if, porem para o lado direito da arvore.
		else{
			
			aux3 = aux2->left;	
			
			
			if(aux3->color==1){
				aux1->color = 0;
				aux3->color = 0;
				aux2->color = 1;
				(*node) = aux2;
			}
			
			else{
				
				if((*node) == aux1->left){
					(*node) = aux1;
					right_Rotation(root, node);
				}
				
				(*node)->f->color = 0;
				aux2->color = 1;
				left_Rotation(root, &aux2);
			}
		}
	}
	
	(*root)->color = 0;	
}



int insert_ARN(ARN **root, ARN **node){
	
	ARN *aux1, *aux2;
	
	aux1 = (*root);
	
	aux2 = Sentinela;
	
	while(aux1 != Sentinela){
		
		// verifica se o node ja existe;
		if(compare_Artigo(aux1->key, (*node)->key) == 0) return 0;
		
		aux2 = aux1;
		
		// buscando a posicao no qual o novo no devera ser inserido;
		if(compare_Artigo((*node)->key, aux1->key) < 0) aux1 = aux1->left;
		
		else aux1 = aux1->right;
	}
	
	// ao findar do while aux1 estara na posicao cuja qual o no devera ser inserido;
	
	// nomeia quem sera o pai do novo no
	(*node)->f = aux2;
	
	if(aux2==Sentinela) (*root) = (*node);
	
	else{
		
		
		// caso seja filho a esquerda do no pai, entao node sera o novo filho a esquerda;
		if(compare_Artigo((*node)->key, aux2->key) < 0) aux2->left = (*node);
		
		// caso seja filho a direita do no pai, entao node sera o novo filho a direita;
		else aux2->right = (*node);	
	}
	
	// valores default de um novo no;
	(*node)->left = Sentinela;
	(*node)->right = Sentinela;
	(*node)->color = 1;
	insert_Fixup(root, node);
	
	return 1;
}



void transfer_NodeARN(ARN **root, ARN **n1, ARN **n2){
	
	if((*n1)->f==Sentinela) (*root) = *n2;
	
	else{
		
		// caso n1 seja filho a esquerda do pai dele;
		if(*n1 == (*n1)->f->left) (*n1)->f->left = *n2;
		
		// caso n1 seja filho a direita do pai dele;
		else (*n1)->f->right = *n2;
	}

	// troca de "pais" entre os nos;
	(*n2)->f = (*n1)->f;
}



void remove_Fixup(ARN **root, ARN **node){
	
	ARN *aux;
	
	while((*node != *root) && (*node)->color==0){
		
		// caso node seja filho a esquerda de seu pai;
		if(*node == (*node)->f->left){
			
			// aux recebe o seu irmao a direita;
			aux = (*node)->f->right;
			
			// CASO 1: caso onde onde node possui "duas cores iguais (duplo negro)", que "desbalanceia" a quantidade de nos negros ate o no sentinela
			// e o pai de node possui dois filhos, de cores diferentes, em que o filho rubro (aux) possui dois filhos negros;
			// aqui adapta-se a arvore de maneira que ela entre em algum dos proximos casos.
			
			if(aux->color==1){	
			
				aux->color = 0;
				(*node)->f->color = 1;
				left_Rotation(root, &(*node)->f);
				aux = (*node)->f->right;
			}
			
			
			// CASO 2: caso onde o node (negro) possui "duas cores iguais (duplo negro)". Aqui, verifica-se os filhos
			// do seu irmao que neste caso eh negro. Visto que ambos sao negro, "remove-se" uma cor negra de cada sub-arvore de root.
			// que antes "feria" a propriedade que um no so podera ter uma cor.
			if((aux->left->color==0) && (aux->right->color==0)){
				
				aux->color = 1;
				(*node) = (*node)->f;
			}
			
			
			else{
				
				// CASO 3: caso onde o node (negro) possui "duas cores iguais (duplo negro)".
				// Neste caso o irmao de node possui filhos de cores diferentes, Negro pela direita e rubro pela esquerda.
				// este caso pode desbalancear as subarvores de root, ja que a quantidade de nos negros eh diferente.
				// adaptase o caso 3 para o caso 4.
				if(aux->right->color == 0){
					
					aux->left->color = 0;
					aux->color = 1;
					right_Rotation(root, &aux);
					aux = (*node)->f->right;
				}
				
				// CASO 4: caso onde node eh duplo negro, e seu irmao possui filho a direita rubro.
				// aqui, realiza-se reapontamentos com o objetivo de remover uma das cores de node.
				aux->color = (*node)->f->color;
				(*node)->f->color = 0;
				aux->right->color = 0;
				left_Rotation(root, &(*node)->f);
				*node = *root;
			}		
		}
		
		// processo analogo a condicao anterior, porem
		// o node eh filho a direita de seu pai
		else{
			
			// aux recebe o seu irmao a esquerda;
			aux = (*node)->f->left;
			
			if(aux->color==1){	
				aux->color = 0;
				(*node)->f->color = 1;
				right_Rotation(root, &(*node)->f);
				aux = (*node)->f->left;
			}
			
				
			if((aux->left->color==0) && (aux->right->color==0)){
				
				
				aux->color = 1;
				(*node) = (*node)->f;
			}
			
			else{
				
				if(aux->left->color == 0){
					
					aux->right->color = 0;
					aux->color = 1;
					left_Rotation(root, &aux);
					aux = (*node)->f->left;
				}
				
				aux->color = (*node)->f->color;
				(*node)->f->color = 0;
				aux->left->color = 0;
				right_Rotation(root, &(*node)->f);
				*node = *root;
			}		
		}	
	}
	(*node)->color = 0;
}



ARN *moreleft_ARN(ARN *node){
	
	// caso onde o elemento mais a esquerda ja eh o node
	
	if(node == Sentinela || node->left == Sentinela) return node;

	else return moreleft_ARN(node->left);
}



void remove_ARN(ARN **root, ARN **node){
	
	int caux;
	ARN *a1, *a2;
	
	a2 = *node;
	caux = a2->color;
	
	// trata os caso em que o no a ser deletado nao possui filho a esquerda
	if((*node)->left == Sentinela){
		
		a1 = (*node)->right;
		transfer_NodeARN(root, node, &(*node)->right);
	}
	
	
	else{
		
		// tratamento do caso em que o no a ser deletado nao possui filho a direita
		if((*node)->right == Sentinela){
			
			a1 = (*node)->left;
			transfer_NodeARN(root, node, &(*node)->left);
		}
		
		
		else{
			
			// caso em que ele possui os dois filhos, onde precisamos pegar o seu sucessor
			a2 = moreleft_ARN((*node)->right);
			caux = a2->color;
			a1 = a2->right;
			
			// caso em o no a ser deletado eh pai do seu sucessor ou seja, o seu filho a direita;
			// consequencia do more_left retornar o proprio filho a direita;
			if(a2->f == *node) a1->f = a2; 
			
			
			// caso em que o sucessor do no a ser deletado é o filho mais a esquerda de seu filho a direita.
			else{
				transfer_NodeARN(root, &a2, &a2->right);
				a2->right = (*node)->right;
				a2->right->f = a2;
			}
			
			
			// reapontamentos necessarios para manter a estrutura da ARN pos-caso em 
			// que o no a ser deletado possui dois filhos;
			transfer_NodeARN(root, node, &a2);
			a2->left = (*node)->left;
			a2->left->f = a2;
			a2->color = (*node)->color;
		}	
	}
	
	// Fixup para as violacoes ocorridas
	if(caux == 0) remove_Fixup(root, &a1);
}



ARN *search_Artigo(ARN *root, int idn){
	
	ARN *aux = root;
	
	
	while(aux!=Sentinela){
		
		if(aux->key->id == idn) break;
		
		// caso a chave do no atual seja menor que a chave procurada, vá para a direita;
		else if(aux->key->id < idn) aux = aux->right;	
		
		// caso a chave do no atual seja maior que a chave procurada, vá para a esquerda;
		else if(aux->key->id > idn) aux = aux->left;
	}
	return aux;
}



void print_ARN(ARN *root, int level){
	
	int i;
	
	// impressao da AVL por nivel, comecando da raiz ate a folha
	if(root != Sentinela){
		
		// chamada da impressao para a sub-arvore a direita
		
		print_ARN(root->right, level+1);
		
		for(i = 0; i<level; i++) printf("\t\t"); //Tabulacao dos elementos
		
		// impressao de um elemento da ARN
		if(root->color==0) printf("[%d: N]\n\n", root->key->id);
		
		else printf("[%d: R]\n\n", root->key->id);
		
		// chamada da impressao para a sub-arvore a esquerda
		
		print_ARN(root->left, level+1);
	}	
}



void destroy_ARN(ARN **root){
	
	if(*root == Sentinela) return;
	
	// chama destroy_ARN pela esquerda
	destroy_ARN(&(*root)->left);
	
	// chama destroy_ARN pela direita
	destroy_ARN(&(*root)->right);
	
	// destroi efetivamente a key elemento em questao
	free((*root)->key);
	free(*root);
	
	return;
}
