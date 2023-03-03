#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
typedef long long ll;

vector<ll> valores;
string aux;
ll limite;
ll maior;

void geraSubconjuntos(ll n, ll i, ll soma, string val) {

    if (soma > limite) return;

    if(soma > maior && soma <= limite){
        maior = soma;
        aux = val;
    }

    if (i == n) return;

    geraSubconjuntos(n, i + 1, soma + valores[i], val + (to_string(i+1) + " "));
    geraSubconjuntos(n, i + 1, soma, val);
}

int main(){
    FASTIO;
    ll m, x;

    while(cin >> limite){
        maior = 0;
        aux = "";
        cin >> m;
        valores.resize(m);
        for(ll i = 0; i < m; i++){ cin >> valores[i]; }
        geraSubconjuntos(m, 0, 0, "");
        cout << aux << "soma: " << maior << "\n";
    }
    return 0;
}