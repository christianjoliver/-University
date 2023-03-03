#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);



typedef struct vertice{
    int no;
    struct vertice *prox;
}Vertice;

typedef struct grafo{
    int V;
    int E;
    Vertice *adj;
}Grafo;

Grafo* criaGrafo (int V)
{
    Grafo* G = (Grafo*)malloc(sizeof(Grafo));

    G->V = V;
    G->E = 0;
    G->adj = (Vertice*)calloc(V, sizeof(Vertice));

    for (int i = 0; i < G->V; i++) G->adj[i].no = i;

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

ll ct;

void auxCount(Grafo *graph, Vertice *v, ll *alc, ll *Alc){
    *alc += 1;
    Alc[v->no] += *alc;
    Vertice *w = v->prox;

    while(w != NULL){
        if(Alc[w->no]==0)
            auxCount(graph, &graph->adj[w->no], alc, Alc);
        w = w->prox;
    }
}

void countComponents(Grafo *graph, ll V){

    ll alc;
    ll *Alc = (ll *)calloc(V, sizeof(ll));

    alc = 0;

    auxCount(graph, &graph->adj[0], &alc, Alc);
    ct++;

    for(ll i = 0; i < V; i++){

        if(Alc[i] == 0){
            auxCount(graph, &graph->adj[i], &alc, Alc);
            ct++;
        }
    }
}

int main(){

    FASTIO;
    int n, m, a, b, i;

    cin >> n >> m;

    Grafo* graph = criaGrafo(n);

    for (i = 0; i < m; i++) {
        cin >> a >> b;
        insereAresta(graph, a-1, b-1);
    }

    ct = 0;
    countComponents(graph, n);
    cout << ct-1 << "\n";
    return 0;
}