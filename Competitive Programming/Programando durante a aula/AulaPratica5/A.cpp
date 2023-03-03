#include <bits/stdc++.h>

using namespace std;

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
    }
}

bool verPatri(long long a, long long b){
    return myFind(a) == myFind(b);
}

int main(){
    char a;
    long long N, K, x, y;
    cin >> N >> K;
    pai.resize(N + 1);
    tam.resize(N + 1, 1);
    for(int i=1; i<N; i++) pai[i] = i;

    for(int i = 0; i<K; i++){
        cin >> a >> x >> y;
        if(a == 'F')
            myUnion(x, y);

        else if(a == 'C'){
            if(verPatri(x, y)) cout << 'S' << "\n";
            else cout << 'N' << "\n";
        }
    }
    return 0;
}