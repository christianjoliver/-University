#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


Vertice *insereNaFila(Vertice *fila, int n){
    if(fila==NULL) return novoVertice(n);
    Vertice *v1, *v2;
    v2 = fila;
    for(v1 = v2->prox; v1 != NULL; v1 = v1->prox) v2 = v1;
    v2->prox = novoVertice(n);
    return fila;
}

Vertice *removerDaFila(Vertice *fila){
    if(fila==NULL) return fila;
    Vertice *v1 = fila->prox;
    free(fila);
    return v1;
}

void destroiFila(Vertice *fila){

    Vertice *aux1 = fila;
    Vertice *aux2 = NULL;
    while(aux1 != NULL){
        aux2 = aux1->prox;
        free(aux1);
        aux1 = aux2;
    }
}

int verificaConect(Grafo *G){
    int *Alc = (int *)calloc(G->V, sizeof(int));
    int v, i, j, alc = 0, count = 0;
    Vertice* fila = NULL;
    Vertice* adj = NULL;

    //percorrendo o vetor de Arestas
    while(alc < G->V){
        count++;
        //percorrendo o vetor de alcancados para buscar o proximo elemento nao alcancado
        for(j = 0; j < G->V; j++){
            if(Alc[j]==0){
                fila = insereNaFila(fila, j);
                Alc[j] = ++alc;
                break;
            }
        }
        while(fila != NULL){
            for(adj = G->adj[fila->no].prox; adj != NULL; adj = adj->prox){
                if(Alc[adj->no] == 0){
                    fila = insereNaFila(fila, adj->no);
                    Alc[adj->no] += alc + 1;
                    alc++;
                }
            }
            fila = removerDaFila(fila);
        }
    }

    free(Alc);
    destroiFila(fila);
    return count;
}

void destroiGrafo(Grafo *G){
    int i;
    Vertice *adj;
    for(i = 0; i < G->V; i++)
        destroiFila(G->adj[i].prox);
    free(G->adj);
    free(G);
}

int main(){

    int N, M, T, X, Y, i, j;
    Grafo *G;
    scanf("%d", &T);

    for(i = 0; i < T; i++){
        scanf("%d %d", &N, &M);
        G = criaGrafo(N);

        for(j=0; j < M; j++){
            scanf("%d %d", &X, &Y);
            insereAresta(G, X-1, Y-1);
        }

        j = verificaConect(G);
        j--;

       if(M==0) j = G->V - 1;

        if(!j)
            printf("Caso #%d: a promessa foi cumprida\n", i+1);
        else
            printf("Caso #%d: ainda falta(m) %d estrada(s)\n", i+1, j);

        destroiGrafo(G);
    }
    return 0;
}