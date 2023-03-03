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
#define FOR(a,b) for(ll i = (a); i < (ll)(b); ++i)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define sz(x) (ll)x.size()
#define MOD 1000000007ll
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll pd[10][90][2][90];


void getDigits(ll n, vll &vDigit){
    while(n){
        vDigit.push_back(n % 10);
        n /= 10;
    }
}

ll numbersCount(ll i, int t, ll s, ll p, ll valor, vll &digits){

    if(i == -1)
        return (s % p) == 0 && (valor % p) == 0;

    if(pd[i][s][t][valor%p] != -1 && t != 1)
        return pd[i][s][t][valor%p];

    ll r = 0;
    ll lim = (t) ? digits[i] : 9;
    ll j;

    for(j = 0; j <= lim; j++){

        ll nt = (digits[i] == j) ? t : 0; // mesma coisa que nt = (t && j==lim) ? 1 : 0;
        ll aux = (((valor * 10) % p) + (j % p)) % p;
        r += numbersCount(i-1, nt, s+j, p, aux, digits); // neste caso nao posso calcular a soma antes por conta do indice utilizado para acessar o digito no pd
    }

    if(!t)
        pd[i][s][t][valor%p] = r;

    return r;
}

void solve(){
    ll T, i, rd, re, x, k;
    cin >> T;
    for(i = 0; i < T; i++){
        vll vd, ve;
        cin >> x >> k;
        getDigits(x, vd);
        memset(pd, -1, sizeof(pd));
        rd = numbersCount(vd.size()-1, 1, 0, k, 0, vd);
        cout << rd-1 << "\n";
    }
}


int main(){
    FASTIO;
    solve();
    return 0;
}
