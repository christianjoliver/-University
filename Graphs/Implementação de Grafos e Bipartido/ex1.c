/*TAD Grafos por Lista de Adjacencias*/
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
    G-> E = 0;
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

int Bipartido(Grafo *G){

    int Alc[G->V];
    int Niv[G->V];
    int alc;
    int i;
    int pos, pos2;
    Vertice* fila = NULL;
    Vertice* adj = NULL;

    for(i = 0; i < G->V; i++){Alc[i] = 0; Niv[i] = 0;}

    fila = insereNaFila(fila, 0);
    alc = 1;
    Alc[0] = 1;
    Niv[0] = 1;

    while(fila != NULL){
        for(adj = G->adj[fila->no].prox; adj != NULL; adj = adj->prox){
            if(Alc[adj->no] == 0){
                fila = insereNaFila(fila, adj->no);
                Alc[adj->no] = ++alc;
                Niv[adj->no] = Niv[fila->no] + 1;
            }
            if(Alc[fila->no] < Alc[adj->no]){
                if(Niv[fila->no] == Niv[adj->no]){
                    destroiFila(fila);
                    return 0;
                }
            }
        }
        fila = removerDaFila(fila);
    }
    return 1;
}

int main(){
    int numAlunos=1, a, b, i;
    char verif;
    Grafo *G;
    scanf("%d", &numAlunos);
    while(numAlunos!=0){
        G = criaGrafo(numAlunos);
        for(i=1; i<=numAlunos; i++){
            scanf("%d", &a);
            while(1){
                scanf("%d%c", &b, &verif);
                insereAresta(G, a-1, b-1);
                if(verif=='\n') break;
            }
        }
        //imprimeGrafo(G);
        if(Bipartido(G)) printf("SIM\n");
        else printf("NAO\n");
        scanf("%d", &numAlunos);
    }
    return 0;
}