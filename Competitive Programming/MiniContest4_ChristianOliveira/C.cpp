#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpi;
typedef vector<pll> vpll;
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


typedef struct vertice{
    int no;
    int group;
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
    novo->group = -1;
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

void Bipartido(Grafo *G){
    int alc, bp = 1;
    Vertice* adj = NULL;
    vector<int> Alc(G->V, 0);
    vector<int> Niv(G->V, 1);
    queue<int> fila;
    fila.push(0);
    alc = 1;
    Alc[0] = 1;
    Niv[0] = 1;


    while(fila.size()){
        for(adj = G->adj[fila.front()].prox; adj != NULL; adj = adj->prox){

            if(Alc[adj->no] == 0){
                fila.push(adj->no);
                Alc[adj->no] = ++alc;
                Niv[adj->no] = Niv[fila.front()] + 1;
            }

            if(Alc[fila.front()] < Alc[adj->no]){
                if(Niv[fila.front()] == Niv[adj->no]){ bp = 0; break; }
            }
        }
        if(!bp) break;
        fila.pop();

        if(alc < G->V && !fila.size()){
            for(ll i = 0; i < G->V; i++){
                if(Alc[i]==0) {
                    fila.push(i);
                    Alc[i] = alc++;
                    Niv[i] = 1;
                    break;
                }
            }
        }
    }

    if(!bp) cout << "IMPOSSIVEL\n";
    else{
        for(ll i = 0; i < G->V; i++){
            if(Niv[i]%2==0) cout << 2;
            else cout << 1;
            if(i+1 != G->V) cout << " ";
        }
        cout << endl;
    }
}

int main(){
    FASTIO;
    ll m, n, a, b;
    cin >> n >> m;
    Grafo *G = criaGrafo(n);

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        if(i == 0) r = a;
        insereAresta(G, a-1, b-1);
    }
    Bipartido(G);
    return 0;
}