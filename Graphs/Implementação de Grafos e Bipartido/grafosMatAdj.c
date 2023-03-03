#include <stdio.h>
#include <stdlib.h>

typedef struct grafo{
    int V;
    int E;
    int **adj;
}Grafo;

int **alocaMatrizAdj(int V, int val){
    int i, j;
    int **m = (int **)malloc(V * sizeof(int *));
    for(i = 0; i < V; i++)
        m[i] = (int)malloc(sizeof(int));
    for(i = 0; i < V; i++)
        for(j = 0; j < V; j++)
            m[i][j] = val;
    return m;
}

Grafo *criaGrafo(int V){
    Grafo *G;
    G = (Grafo *)malloc(sizeof(Grafo));
    G->V = V;
    G->E = 0;
    G->adj = alocaMatrizAdj(V, 0);
    return G;
}

void insereAresta(Grafo *G, int v, int w){
    if(v != w && G->adj[v][w]==0){
        G->adj[v][w] = 1;
        G->adj[w][v] = 1;
        G->E++;
    }
}

void removeAresta(Grafo *G, int v, int w){
    if(G->adj[v][w]==1){
        G->E--;
        G->adj[w][v] = 0;
        G->adj[v][w] = 0;
    }
}

void imprimeGrafo(Grafo *G){
    int v, w;
    printf("    %2d ", 0);
    for(v=1; v<G->V; v++){
        printf("%2d ", v);
    }

    printf("\n");
    for(v=0; v<G->V; v++){
        printf("%2d:", v);
        for(w=0; w<G->V; w++)
            if(G->adj[v][w]==1) printf(" %2d", 1);
            else printf(" %2d", 0);
        printf("\n");
    }
}


int main(){
    int V;
    scanf("%d", &V);
    Grafo G = criaGrafo(V);



    return 0;
}