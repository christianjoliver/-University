#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int no;
    struct vertice *prox;
}Vertice;

typedef struct grafo{
    int V;
    int E;
    Vertice *adj;
}Grafo;

Grafo *criaGrafo(int V){
    Grafo *G = (Grafo *)malloc(sizeof(Grafo));
    G->V = V;
    G->E = 0;
    G->adj = (Vertice *)calloc(V, sizeof(Vertice));
    return G;
}

Vertice *novoVertice(int x){
    Vertice *novo = (Vertice *)malloc(sizeof(Vertice));
    if(novo == NULL){printf("ERRO.\n"); exit(1);}
    novo->no=x;
    novo->prox=NULL;
    return novo;
}

void insereAresta(Grafo *G, int v, int w){
    if(v != w){

        // inserindo v em w
        Vertice *p = G->adj[v].prox;
        while(p != NULL){
            if(p->no == w) break;
            p = p->prox;
        }
        if(p == NULL){
            Vertice *novo = novoVertice(w);
            novo->prox = G->adj[v].prox;
            G->adj[v].prox = novo;
            G->E++;
        }

        // inserindo w em v
        p = G->adj[w].prox;
        while(p != NULL){
            if(p->no == v) break;
            p = p->prox;
        }
        if(p == NULL){
            Vertice *novo = novoVertice(v);
            novo->prox = G->adj[w].prox;
            G->adj[w].prox = novo;
            G->E++;
        }
    }
}

void removeAresta(Grafo *G, int v, int w){

    // removendo w de v
    if(G->adj[v].prox !=NULL){
        Vertice *aux = G->adj[v].prox;
        Vertice *preaux = &(G->adj[v]);
        while(aux !=NULL){
            if(aux->no == w) break;
                preaux = aux;
                aux = aux->prox;
        }
        if(aux != NULL){
            G->E--;
            preaux->prox = aux->prox;
            free(aux);
        }
    }

    // removendo v de w
    if(G->adj[w].prox !=NULL){
        Vertice *aux = G->adj[w].prox;
        Vertice *preaux = &(G->adj[w]);

        while(aux !=NULL){
            if(aux->no == v) break;
                preaux = aux;
                aux = aux->prox;
        }
        if(aux != NULL){
            G->E--;
            preaux->prox = aux->prox;
            free(aux);
        }
    }
}

void imprimeGrafo(Grafo *G){
    int v;
    Vertice *w;
    for(v = 0; v < G->V; v++){
        printf("%2d: ", v);
        w = G->adj[v].prox;
        while(w != NULL){
            printf(" %2d", w->no);
            w = w->prox;
        }
        printf("\n");
    }
}

//calcula o grau de determinado vertice no grafo
int calculaGrau(Grafo *G, int V){

    if(G->adj==NULL) {printf("ERRO.\n"); exit(1);}

    Vertice *aux = G->adj[V].prox;
    int count=0;

    while(aux!=NULL){
        count++;
        aux = aux->prox;
    }
    return count;
}





int main(){

    int numAlunos, a, b, i;
    char verif;
    Grafo *G;

    while(numAlunos!=0){
        printf("Quantidade Alunos: ");
        scanf("%d", &numAlunos);
        G = criaGrafo(numAlunos);
        imprimeGrafo(G);
        for(i=1; i<=numAlunos; i++){
            scanf("%d", &a);
            while(1){
                scanf("%d%c", &b, &verif);
                insereAresta(G, a-1, b-1);
                if(verif=='\n') break;
            }
        }
    }
    imprimeGrafo(G);

    return 0;
}