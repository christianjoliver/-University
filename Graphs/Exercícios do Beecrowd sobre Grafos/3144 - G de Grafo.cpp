#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

vll pai;
vll tamanho;

typedef struct Aresta{
    ll u, v, peso;
    bool operator < (Aresta &other){
        return peso < other.peso;
    }
}Aresta;

vector<Aresta> Grafo;

void init_Grafo(ll N){
    Grafo.resize(N);
}

ll find(ll x) {
    if(x == pai[x])
        return x;
    else
        return pai[x] = find(pai[x]);
}

void init_union(ll N) {
    ll i;
    pai.resize(N + 1);
    tamanho.resize(N + 1, 1);
    for(i = 1; i <= N; i++)
        pai[i] = i;
}

void join(ll a, ll b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (tamanho[a] < tamanho[b])
            swap(a, b);
        pai[b] = a;
        tamanho[a] += tamanho[b];
    }
}

int kruskal(int M, int N){
    ll i, cont = 0;
    sort(Grafo.begin(), Grafo.end());
    init_union(M);

    for(i = 0; i < M; i++){
        if(find(Grafo[i].u) != find(Grafo[i].v)){
            cont += Grafo[i].peso;
            join(Grafo[i].u, Grafo[i].v);
        }
    }
    return cont;
}

int main() {
    ll N, M, O, i;
    cin >> N >> M;
    cin >> O;
    init_Grafo(M);

    for(i = 0; i < M; i++){
        cin >> Grafo[i].u >> Grafo[i].v >> Grafo[i].peso;
    }

    cout << 2*kruskal(M, N) << "\n";

	return 0;
}