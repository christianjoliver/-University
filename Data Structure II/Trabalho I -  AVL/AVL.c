#include "AVL.h"


AVL *create_AVL(void *element){
	
	// alocacao de espaco de memoria para o novo elemento
	AVL *node = (AVL *)malloc(sizeof(AVL));
	
	
	// verifica se a alocacao foi bem sucedida
	if(node){
		
		// atribuicao de valores aos seus devidos campos
		node->key = element;
		node->right = NULL;
		node->left = NULL;
		node->balance = 0;
	}
	return node;
}


AVL *right_rotation(AVL *node, int *h){
	
	AVL *u = node->left;
	AVL *z;
	
	// caso onde a arvore esta "pesada" para a esquerda - (Rotacao Simples a direita)
	if(u->balance == 1){
		
		node->left = u->right;
		u->right = node;
		node->balance = 0;
		node = u;
	}
	
	// caso onde a arvore esta "pesada" para a direita do filho a esquerda - (Rotacao Dupla a direita)
	else{
		
		z = u->right;
		u->right = z->left;
		z->left = u;
		node->left = z->right;
		z->right = node;
		
		if(z->balance == 1) node->balance = -1;
		else node->balance = 0;
		
		if(z->balance == -1) u->balance = 1;
		else u->balance = 0;
		
		if(z->balance == 0) u->balance = weight_AVL(u);
		
		node = z;
	}
	
	*h = 0;
	
	node->balance = weight_AVL(node);
	return node;
}


AVL *left_rotation(AVL *node, int *h){
		
	AVL *u = node->right;
	AVL *z;
	
	// caso onde a arvore esta "pesada" para a direita - (Rotacao Simples a esquerda)
	if(u->balance == -1){
		
		node->right = u->left;
		u->left = node;
		node->balance = 0;
		node = u;
	}
	
	// caso onde a arvore esta "pesada" pra esquerda do filho a direita - (Rotacao Dupla a esquerda)
	else{
		
		z = u->left;
		u->left = z->right;
		z->right = u;
		node->right = z->left;
		z->left = node;
		
		if(z->balance == 1) u->balance = -1;
		else u->balance = 0;
		
		if(z->balance == -1) node->balance = 1;
		else node->balance = 0;
		
		if(z->balance == 0) u->balance = weight_AVL(u);
		
		node = z;
	}
	
	*h = 0;
	node->balance = weight_AVL(node);
	return node;
}


AVL *insert_AVL(AVL *node, void *element, int *h, int (*compare) (void *, void *)){
		
	// verifica se a AVL eh vazia ou se chegou na folha
	if(!node){
			
		// aloca espaco de memoria para o novo node
		AVL *new_node = create_AVL(element);
		
		// verifica se o espaco foi alocado corretamente
		if(new_node) *h = 1;	// houve crescimento, logo h = 1

		return new_node;
	}
	
	else{
		
		// tratamento do caso onde a chave a ser inserida eh menor que a chave do node atual
		if(compare(element, node->key) == 0){
			
			// chamada da insercao para a sub-arvore a esquerda
			node->left = insert_AVL(node->left, element, h, compare);
			
			// caso haja crescimento
			if(*h == 1){
				
				// analise de casos de crescimento
				switch(node->balance){
					
					case -1: node->balance = 0; *h = 0; break;										// crescimento para a direita;
						
					case 0: node->balance = 1; break;												// equilibrado
						
					case 1: node = right_rotation(node, h); break;									// crescimento para a esquerda;
						
				}
			}
					
		}
		
		// tratamento do caso onde a chave a ser inserida eh maior que a chave do node atual
		else if(compare(element, node->key) == 1){
			
			// chamada da insercao para a sub-arvore a direita
			node->right = insert_AVL(node->right, element, h, compare);
			
			// caso haja crescimento
			if(*h == 1){
				
				// analise de casos de crescimento
				switch(node->balance){
					
					case -1: node = left_rotation(node, h); break;									// crescimento para a direita
						
					case 0: node->balance = -1; break;												// equilibrado
						
					case 1: node->balance = 0; *h = 0; break;										// crescimento para a esquerda;
				}
			}
		}
		
		// caso onde o elemento ja esta na AVL
	//	else return;
	}
	
	return node;
}


AVL *search_AVL(AVL *node, void *element, int (*compare) (void *, void *)){

	if(node){
		
		// caso onde o elemento buscado tem a chave maior
		if(compare(element, node->key) == 1)
			return search_AVL(node->right, element, compare);
		
		// caso onde o elemento buscado tem a chave menor
		else if(compare(element, node->key) == 0)
			return search_AVL(node->left, element, compare);
		
		// caso onde o elemento foi encontrado
		else
			return node;	
	}
	
	// caso onde o elemento nao foi encontrado ou seja Nulo
	return node;
}


int height_AVL(AVL *avl){
	int left, right;
	
	if(!avl) return 0;
	
	// calculo da altura das sub-arvores
	left = 1 + height_AVL(avl->left);
	right = 1 + height_AVL(avl->right);
	
	// retorno da altura da AVL
	if(left > right) return left;
	else return right;
}


int weight_AVL(AVL *avl){
	int left, right;
	
	// altura das sub-arvores da AVL
	left = height_AVL(avl->left);
	right = height_AVL(avl->right);
	
	// retorno do peso da AVL
	return left - right;
}


AVL *moreleft_AVL(AVL *node){
	
	// caso onde o elemento mais a esquerda ja eh o node
	
	if(!node || !node->left) return node;

	else return moreleft_AVL(node->left);
}



AVL *remove_AVL(AVL *node, void *element, int (compare) (void *, void *)){

    // caso onde a remo��o ocorre pela direita, olha-se o balanceamento da esquerda,
    // e o balanceamento da raiz da sub�rvore esquerda me dir� qual o tipo de rota��o
    // a ser feita. 
    int j = 0;

    if(!node) return node;

	// tratamento do caso onde o elemento a ser removido tem a chave menor
    if(compare(element, node->key) == 0){

        node->left = remove_AVL(node->left, element, compare);
        node->balance = weight_AVL(node);

        if(node->balance < -1) node = left_rotation(node, &j);
    } 

	// tratamento do caso onde o elemento a ser removido tem a chave maior
    else if(compare(element, node->key) == 1){
        
		node->right = remove_AVL(node->right, element, compare);
        node->balance = weight_AVL(node);

        if(node->balance > 1) node = right_rotation(node, &j);
    }
	
	// tratamento do caso onde o elemento foi encontrado
    else{
    	
    	// caso onde o elemento nao possui sub-arvore a esquerda
        if(!node->left){

            AVL *tree = node->right;

			node->key = NULL;
			free(node->key);
			free(node);
			
            return tree;
        }
		
		// caso onde o elemento nao possui sub-arvore a direita
        else if(!node->right){

            AVL *tree = node->left;

			node->key = NULL;
			free(node->key);
			free(node);
			
            return tree;
        }

		// caso onde o elemento possui sub-arvore a esquerda e a direita
        AVL *tree = moreleft_AVL(node->right);
        
        // reapontamento das chaves.....
        node->key = tree->key;     
      	node->right = remove_AVL(node->right,tree->key, compare);
        node->balance = weight_AVL(node);
		
		// caso onde a raiz tem balance == 2;
        if(node->balance > 1) node = right_rotation(node, &j);
        
    }
    return node;
}



void print_AVL(AVL *node, void (*print_node) (void *), int level){
	
	int i;
	
	// impressao da AVL por nivel, comecando da raiz ate a folha
	if(node){
		
		// chamada da impressao para a sub-arvore a direita
		print_AVL(node->right, print_node, level+1);
		
		for(i = 0; i<level; i++) printf("\t"); //Tabulacao dos elementos
		
		// impressao de um elemento da AVL
		print_node(node->key);
		
		// chamada da impressao para a sub-arvore a esquerda
		print_AVL(node->left, print_node, level+1);
	}	
}



void destroy_AVL(AVL *node, void (*destroy_node)(void *)){
	
	if(!node) return;
	
	// chama destroy_AVL pela esquerda
	destroy_AVL(node->left, destroy_node);
	
	// chama destroy_AVL pela direita
	destroy_AVL(node->right, destroy_node);
	
	// destroi efetivamente a key elemento em questao
	destroy_node(node->key);
	
	free(node);
	return;
}
