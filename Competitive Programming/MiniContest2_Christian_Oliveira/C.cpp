#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef vector<ll> vll;
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {

    ll n, liminf, limsup, sum, count = 0;
    cin >> n >> liminf >> limsup;
    vll v(n);

    for(ll i = 0; i < n; i++){ cin >> v[i];}

    for(ll i = 0; i < n; i++){
        for(ll j = i+1; j<n; j++){
            sum = v[i] + v[j];
            if(sum >= liminf && sum <= limsup)
                count++;
        }
    }
    cout << count << "\n";
    return 0;
}
