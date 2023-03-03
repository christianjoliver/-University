#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>


typedef struct vertice{
    int no, w;
    struct vertice *prox;
} Vertice;

typedef struct Grafo{
    int V, E;
    Vertice* adj;
} Grafo;


Grafo* criaGrafo(int v){
    Grafo* G = (Grafo*)malloc(sizeof(Grafo));
    if (G != NULL){
        G->V = v;
        G->E = 0;
        G->adj = (Vertice*)calloc(v, sizeof(Vertice));
        for (int i = 0; i < G->V; i++) G->adj[i].no = i;
    }
    return G;
}

Vertice* criaVertice(int x, int w){
    Vertice* novo = (Vertice*)malloc(sizeof(Vertice));
    if(novo == NULL){printf("ERRO.\n"); exit(1);}
    novo->no = x;
    novo->w = w;
    novo->prox = NULL;
    return novo;
}

void insereAresta(Grafo* G, int v, int w, int p){

    if (G && v != w){
        Vertice* atual = G->adj[w].prox;
        while (atual != NULL) {
            if (atual->no == v) break;
            atual = atual->prox;
        }
        if (atual == NULL){
            Vertice* verticeV = criaVertice(v, p);
            verticeV->prox = G->adj[w].prox;
            G->adj[w].prox = verticeV;
            G->E++;
        }
    }
}

void removeAresta(Grafo* G, int v, int w){
    if (G && v != w){
        // removendo w de v
        Vertice* atual = &G->adj[v];
        while (atual != NULL){
            if (atual->prox && atual->prox->no == w) {
                atual->prox = atual->prox->prox;
                free(atual->prox);
                G->E--;
                break;
            }
            atual = atual->prox;
        }
        // removendo v de w
        atual = &G->adj[w];
        while (atual != NULL){
            if (atual->prox && atual->prox->no == v) {
                atual->prox = atual->prox->prox;
                free(atual->prox);
                G->E--;
                break;
            }
            atual = atual->prox;
        }
    }
}


void dijkstra(Grafo *G, int s, int c, int N){
    Vertice *v;
    int *dist = (int*)malloc(N * sizeof(int));
    bool *vis = (bool*)calloc(N, sizeof(bool));
	for (int i = 0; i < G->V; i++) dist[i] = 99999;

	dist[s] = 0;
	for (int i = 0; i < G->V; i++){
		int u = -1;
		for (int j = 0; j < G->V; j++){
            if (!vis[j] && (u == -1 || dist[j] < dist[u])) u = j;
        }
		if (dist[u] == 99999) break;

		vis[u] = true;
		for (v = G->adj[u].prox; v != NULL; v = v->prox){
			if (dist[u] + v->w < dist[v->no]) dist[v->no] = dist[u] + v->w;
		}
	}
	printf("%d\n", dist[c-1]);
}

void custoTotal(int N, int M, int C, int K){

    Grafo* Grafo = criaGrafo(N);
    for (int i = 0; i < M; ++i){
        int u, v, p;
        scanf("%d%d%d", &u, &v, &p);
        if (u >= C && v >= C || ((u < C) && (v < C) && (abs(u - v) == 1))) {
            insereAresta(Grafo, v, u, p);
            insereAresta(Grafo, u, v, p);
        }
        if (u >= C && v < C) insereAresta(Grafo, v, u, p);
        if (v >= C && u < C) insereAresta(Grafo, u, v, p);
    }
    dijkstra(Grafo, K, C, N);
}


int main (){
    int N, M, C, K;
	while (1){
	    scanf("%d%d%d%d", &N, &M, &C, &K);
	    if (N == 0 && M == 0 && C == 0 && K == 0) break;
        custoTotal(N, M, C, K);
	}

	return 0;
}
