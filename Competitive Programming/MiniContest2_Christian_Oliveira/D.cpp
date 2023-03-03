#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using namespace __gnu_pbds;
template <class T>
using indexed_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;

indexed_set<ll> vet;


void mediana(vector<ll> v, ll tam, ll jan){
    ll x;
    for(ll i = 0; i < jan; i++){ vet.insert(v[i]); }

    // caso onde a janela eh par
    if(!(jan & 1)){
        x = *vet.find_by_order((jan/2) - 1);
        cout << x;
        for(ll i = 0; i < tam-jan; i++){
            auto aux = vet.lower_bound(v[i]);
            aux--;
            vet.erase(aux);
            vet.insert(v[i + jan]);
            x = *vet.find_by_order((jan/2) - 1);
            cout << " " << x;
        }
    }
    // caso onde a janela eh impar
    else{
        x = *vet.find_by_order(jan/2);
        cout << x;
        for(ll i = 0; i < tam-jan; i++){
            auto aux = vet.lower_bound(v[i]);
            aux--;
            vet.erase(aux);
            vet.insert(v[i + jan]);
            x = *vet.find_by_order(jan/2);
            cout << " " << x;
        }
    }
}

int main(){
    FASTIO;
    ll k, n, x;
    cin >> n >> k;
    vector<ll> v(n);
    for(ll i = 0; i < n; i++){ cin >> v[i]; }
    mediana(v, n, k);
    cout << "\n";
    return 0;
}




