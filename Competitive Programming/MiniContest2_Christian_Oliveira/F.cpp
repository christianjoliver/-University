#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

long long maximo;
vector<long long> pai;
vector<long long> tam;

long long myFind(long long x){
    if(x==pai[x]) return x;
    else
        return pai[x] = myFind(pai[x]);
}

void myUnion(long long a, long long b){
    a = myFind(a);
    b = myFind(b);

    if(a!=b){
        if (tam[a] < tam[b])
            swap(a, b);
        pai[b] = a;
        tam[a] += tam[b];
        if(tam[a] > maximo)
            maximo = tam[a];

    }
}

bool verPatri(long long a, long long b){
    return myFind(a) == myFind(b);
}

int main(){
    FASTIO;
    long long n, m, a, b, i, j;
    cin >> n >> m;
    pai.resize(n + 1);
    tam.resize(n + 1, 1);
    for(i = 1; i < n; i++) pai[i] = i;

    for(i = 0, j = n; i < m; i++){
        cin >> a >> b;
        if(!verPatri(a, b)) j--;
        myUnion(a, b);
        if(j <= 0) j = 1;
        cout << j << " " << maximo << "\n";
    }
    return 0;
}