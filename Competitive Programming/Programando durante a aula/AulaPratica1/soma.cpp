#include <bits/stdc++.h>


using namespace std;

int main(){

    long long soma = 0, a, n, i, aux;

    cin >> n;

    for(i=0; i<n-1; i++){
        cin >> a;
        soma += a;
    }

    aux = (n * (1 + n))/2 - soma;

    cout << aux;

    return 0;
}