#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpi;
typedef vector<pll> vpll;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for(ll i = (a); i < (ll)(b); ++i)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define sz(x) (ll)x.size()
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


void solve(vll vet, vll aux, ll n, ll r) {
    for(ll i = 0; i < n; i++) {
        ll j = upper_bound(all(vet), aux[i]) - vet.begin();
        if (vet[j-1] < aux[i] && aux[i] < vet[j])
            vet[j] = aux[i];
    }

    ll count = 0;
    for(ll i = 0; i <= n; i++) {
        if (vet[i] < INF)
            count = i;
    }
    cout << count << "\n";
}

int main() {
    FASTIO;
    vll vet;
    vll aux;
    ll n, x, r = 1;
    cin >> n;

    for(ll  i = 0; i < n; i++){
        cin >> x;
        aux.PB(x);
    }

    vet.resize(n+1, INF);
    vet[0] = -INF;
    solve(vet, aux, n, r);
    return 0;
}