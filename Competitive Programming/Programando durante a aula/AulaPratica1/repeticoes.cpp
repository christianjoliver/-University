#include<bits/stdc++.h>

using namespace std;

int main(){
    string bal;
    cin >> bal;

    long long maior = 0, intermediario = 1, i, tam = bal.size();

    for(i=0; i<tam; i++){
        if(bal[i+1]==bal[i])
            intermediario+=1;
        else{
            maior = (intermediario>maior)? intermediario : maior;
            intermediario = 1;
        }
    }

    cout << maior;

    return 0;
}