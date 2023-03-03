#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll fibonacci[22] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711 };

bitset<25> vet;

int conv(ll x){
    do{
        auto pos = fibonacci.lower_bound(x);
        if(*pos!=)


    }while(x > 0);
}


int main(){
    FASTIO;
    ll t, x;
    cin >> t;
    for(ll i = 0; i < t; i++){
        cin >> x;
        conv(x);
    }
    return 0;
}